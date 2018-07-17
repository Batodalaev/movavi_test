#ifndef PYRAMIDIMAGE_H
#define PYRAMIDIMAGE_H
#include <QVector>
#include <QPixmap>
#include <QString>
#include <cmath> //for floor
using namespace std;
class PyramidImage
{

public:
    PyramidImage();
    PyramidImage(QString& filename, QPixmap* original, float coefficient = coefficient_default);
    ~PyramidImage();

    void SetOriginalImage(QPixmap* original, QString& filename);//no generate//генерация по требованию
    QString& GetFileName();
    void GenerateCopiedImages();
    int CountCopies();// return m
    QPixmap* GetImage(int i);//i - 0..m//если не существует, сгенерировать и добавить в вектор.
    int GetWidthImage(int i);//i - 0..m
    int GetHeightImage(int i);//i - 0..m
    QSize* GetSize(int i);

    QPixmap* GenerateCopiedImageWithNoSave(int i);//i - 1..m
    void SetCoefficient(float coefficient);//coefficient>1
    float GetCoefficient();

    void clearGeneratedCopies();
private:
    QString filename;
    QVector<QPixmap*> images;
    float coefficient;//>1
    static int maxCopies(QSize* size, float coefficient);
    static double log(double x, double base);
    static const int coefficient_default = 2.0f;
};

#endif // PYRAMIDIMAGE_H
