#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    menuBar = new QMenuBar(this);
    menuBar->setMinimumWidth(600);

    createActions();
    createMenus();

    ui->setupUi(this);


}

Widget::~Widget()
{
    delete ui;
}

bool Widget::CreatePyramidImage(QString &filename)
{
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(this, tr("&Unable to open file"),
            file.errorString());
        return false;
    }
    QPixmap* pm = new QPixmap();
    pm->load(filename);

    if(!pm->isNull()){
        AddImage(pm,filename);
    }
    return pm->isNull();

}

void Widget::AddImage(QPixmap *image, QString& filename)
{
    images.append(new PyramidImage(
                      filename, image, getCurrentCoefficient()));

    std::sort(images.begin(),images.end(),cmp);

    labelSizeChanged(filename);

    setCurrentIndexImage(0);

    comboBoxImageEnable(true);
}

void Widget::RemoveImage(int index)
{
    images.removeAt(index);
}

void Widget::Clear()
{
    images.clear();
}

void Widget::setCurrentIndexImage(int index)
{
    if(images.count()>0)
    {
        currentIndexImage = index;
        setCoefficient(images[currentIndexImage]->GetCoefficient());
        ui->doubleSpinBoxCoefficient->setValue(
                images[currentIndexImage]->GetCoefficient());
        setCurrentIndexLayer(0);
        ui->comboBoxLayer->setCurrentIndex(0);
    }
}

void Widget::setCurrentIndexLayer(int index)
{
    if(images.count()>0)
    {
        currentIndexLayer = index;
        QPixmap* layer = images[currentIndexImage]->
                GetImage(currentIndexLayer);

        labelSizeChanged(labelSize(layer->size()));
        labelImageChanged(*layer);
    }
}

void Widget::setCoefficient(double coefficient)
{
    if(images.count()>0)
    {
        setCurrentIndexLayer(0);
        ui->comboBoxLayer->setCurrentIndex(0);

        images[currentIndexImage]->SetCoefficient(coefficient);
    }
}

void Widget::openFile()
{
    QString filename = QFileDialog::getOpenFileName(this,
            tr("&Open image file"), "",
            tr("&Images (*.BMP, *.GIF, *.JPG, *.JPEG, *.PNG);"));

    if (filename.isEmpty())
            return;
    else {
        CreatePyramidImage(filename);
    }
}

void Widget::about()
{
    QMessageBox::about(this,
                       tr("About application"),
                       tr("Author - <a href='https://github.com/Batodalaev'>ya_sayanb</a>. <br>Test Juniour C++ developer. <br>Movavi."));
}

bool Widget::cmp(PyramidImage* a, PyramidImage* b)
{
    //в порядке увеличения изображения
    //true - если картинка a меньше по размеру b.
    return a->GetWidthImage(0)+a->GetHeightImage(0)
            <b->GetWidthImage(0)+b->GetHeightImage(0);
}

QString Widget::labelSize(QSize size)
{
    return
            QString::number(size.width()) +
            "x"+
            QString::number(size.height());
}

void Widget::createActions()
{
    openAct = new QAction(tr("&Open File"),this);
    openAct->setStatusTip(tr("&Open a file"));
    connect(openAct, &QAction::triggered, this, &Widget::openFile);

    exitAct = new QAction(tr("&Exit"),this);
    exitAct->setStatusTip(tr("&Exit the application"));
    connect(exitAct, &QAction::triggered, this, &QApplication::exit);

    aboutAct = new QAction(tr("&About"),this);
    aboutAct->setStatusTip(tr("&About the application"));
    connect(aboutAct, &QAction::triggered, this, &Widget::about);

    aboutQtAct = new QAction(tr("&About Qt"),this);
    aboutQtAct->setStatusTip(tr("&About Qt"));
    connect(aboutQtAct, &QAction::triggered, this, &QApplication::aboutQt);

}

void Widget::createMenus()
{
    fileMenu = menuBar->addMenu(tr("&File"));
    fileMenu->addAction(openAct);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAct);

    helpMenu = menuBar->addMenu(tr("&Help"));
    helpMenu->addAction(aboutAct);
    helpMenu->addAction(aboutQtAct);
}

double Widget::getCurrentCoefficient()
{
    return ui->doubleSpinBoxCoefficient->value();
}
