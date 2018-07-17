#ifndef WIDGET_H
#define WIDGET_H
#include <QList>
#include <QWidget>
#include <QPixmap>
#include <QMenuBar>

#include <QFileDialog>
#include <QMessageBox>
#include "pyramidimage.h"
using namespace std;

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    /* Список названий файлов - картинок, что нужно загрузить.
     * Если какой-нибудь файл не получится загрузить,
     * то выдать ошибку и отменить весь прогресс.
     */
    bool CreatePyramidImages(QVector<QString> filenames);
    //Загрузка 1 картинки
    bool CreatePyramidImage(QString& filename);
    void AddImage(QPixmap* image, QString& filename);
    void RemoveImage(int index);
    void AddImageRange(QVector<QPixmap*>& images);
    void Clear();

public slots:
    void setCurrentIndexImage(int index);
    void setCurrentIndexLayer(int index);
    void setCoefficient(double coefficient);

    void openFile();
    void about();

signals:
    void labelSizeChanged(QString text);
    void labelImageChanged(QPixmap image);
    void comboBoxImageEnable(bool enable);
    ;
private:
    QList<PyramidImage*> images;
    int currentIndexImage;
    int currentIndexLayer;
    Ui::Widget *ui;
    QMenuBar* menuBar;

    static bool cmp(PyramidImage* a, PyramidImage* b);
    static QString labelSize(QSize size);

    void createActions();
    void createMenus();
    double getCurrentCoefficient();

    QMenu *fileMenu;
    QMenu *helpMenu;

    QAction *openAct;
    QAction *aboutAct;
    QAction *aboutQtAct;
    QAction *exitAct;

};

#endif // WIDGET_H
