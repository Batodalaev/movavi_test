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

bool Widget::CreatePyramidImages(QStringList filenames)
{
    for(int i=0;i<filenames.length();i++)
    {
        //проверка на доступность
        QFile file(filenames.at(i));
        if (!file.open(QIODevice::ReadOnly)) {
            QMessageBox::information(this, tr("&Unable to open file"),
                file.errorString());
            return false;
        }
    }
    for(int i=0;i<filenames.length();i++)
    {
        QPixmap* pm = new QPixmap();
        pm->load(filenames.at(i));
        if(!pm->isNull()){
            AddImage(pm,filenames[i]);

        }
    }
    std::sort(images.begin(),images.end(),cmp);
    setCurrentIndexImage(0);
    ui->comboBoxImage->clear();
    ui->comboBoxImage->setMaxVisibleItems(images.length());
    ui->comboBoxImage->addItems(filenames);

    comboBoxImageEnable(true);
    return true;
}

//obsolete
bool Widget::CreatePyramidImage(QString &filename)
{
    //проверка на доступность
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
        std::sort(images.begin(),images.end(),cmp);
        setCurrentIndexImage(0);
        comboBoxImageEnable(true);
    }
    return pm->isNull();

}

void Widget::AddImage(QPixmap *image, QString& filename)
{
    images.push_back(new PyramidImage(
                      filename, image, getCurrentCoefficient()));

    labelSizeChanged(filename);
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
    if(images.count()>0 && index>=0)
    {
        currentIndexImage = index;
        setCoefficient(images[currentIndexImage]->GetCoefficient());
        ui->doubleSpinBoxCoefficient->setValue(
                images[currentIndexImage]->GetCoefficient());
        updateComboBoxLayer();

        ui->scrollAreaWidgetContents->setGeometry(0,0,
                                                  images[currentIndexImage]->GetWidthImage(0),
                                                  images[currentIndexImage]->GetHeightImage(0)
                                                  );
        ui->scrollArea->setWidget(ui->scrollAreaWidgetContents);
    }
}

void Widget::setCurrentIndexLayer(int index)
{
    if(images.count()>0 && images[currentIndexImage]->CountCopies()>0 && index>=0)
    {
        currentIndexLayer = index;
        QPixmap* layer = images[currentIndexImage]->
                GetImage(currentIndexLayer);

        labelSizeChanged(labelSize(*(images[currentIndexImage]->GetSize(index))));
        labelImageChanged(*layer);
    }
}

void Widget::setCoefficient(double coefficient)
{
    if(images.count()>0 && coefficient>1.0)
    {
        setCurrentIndexLayer(0);
        images[currentIndexImage]->SetCoefficient(coefficient);

        updateComboBoxLayer();
    }
    else{
        ui->doubleSpinBoxCoefficient->setValue(2.0);
    }
}

void Widget::openFiles()
{
    QStringList filenames =
            QFileDialog::
            getOpenFileNames(this,
                             tr("Open image files"), "",
                             tr("&Images (*.BMP *.GIF *.JPG *.JPEG *.PNG);"));

    if (filenames.isEmpty())
            return;
    else {
        CreatePyramidImages(filenames);
    }
}

void Widget::closeFiles()
{
    if(images.count()>0)
    {
        Clear();
        labelSizeChanged(labelSize(*(new QSize(0,0))));
        labelImageChanged(*(new QPixmap()));
        comboBoxImageEnable(false);
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
    openAct = new QAction(tr("&Open Files"),this);
    openAct->setStatusTip(tr("&Open files"));
    connect(openAct, &QAction::triggered, this, &Widget::openFiles);

    closeAct = new QAction(tr("&Close Files"),this);
    closeAct->setStatusTip(tr("&Close files"));
    connect(closeAct, &QAction::triggered, this, &Widget::closeFiles);

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
    fileMenu->addAction(closeAct);
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

void Widget::updateComboBoxLayer()
{
    setCurrentIndexLayer(0);
    ui->comboBoxLayer->setCurrentIndex(0);
    ui->comboBoxLayer->clear();
    ui->comboBoxImage->setMaxVisibleItems(images[currentIndexImage]->CountCopies()+1);
    for(int i=0;i<images[currentIndexImage]->CountCopies();i++){
        ui->comboBoxLayer->addItem(QString::number(i));
    }
}
