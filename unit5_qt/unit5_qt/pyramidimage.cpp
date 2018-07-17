#include "pyramidimage.h"

PyramidImage::PyramidImage()
{
    filename.shrink_to_fit();
    images.shrink_to_fit();
    SetCoefficient(coefficient_default);
}

PyramidImage::PyramidImage(QString& filename, QPixmap *original, float coefficient)
{
    this->filename = filename;
    SetCoefficient(coefficient);
    SetOriginalImage(original,filename);
}

PyramidImage::~PyramidImage()
{
    clearGeneratedCopies();
    filename.clear();
    images.clear();
}

void PyramidImage::SetOriginalImage(QPixmap *original, QString& filename)
{
    QSize size = original->size();
    images.resize(maxCopies(&size, coefficient)+1);//+1 for original in index 0
    std::fill(images.begin(), images.end(), nullptr);
    images.insert(0,original);
    this->filename = filename;
    //GenerateCopiedImages();//Генерация по требованию
}

QString &PyramidImage::GetFileName()
{
    return filename;
}

void PyramidImage::GenerateCopiedImages()
{
    for(int i=1; i<=CountCopies();i++){
        images.insert(i,GenerateCopiedImageWithNoSave(i));
    }
}

int PyramidImage::CountCopies()
{
    return images.size()-1;//return m. m+1 == size
    //return -1, if images is empty
}

QPixmap *PyramidImage::GetImage(int i)
{
    //any image
    if(i>=0 && i<=CountCopies()){
        if(images[i] == nullptr)
            images.insert(i,GenerateCopiedImageWithNoSave(i));
        return images[i];
    }
    return nullptr;
}

int PyramidImage::GetWidthImage(int i)
{
    //any image
    if(i>=0 && i<=CountCopies()){
        if(images[i]!=nullptr){
            return images[i]->width();
        }
        else{
            double temp = pow(coefficient,i);
            return (int)(images[0]->width()/temp);
        }
    }
    return 0;
}

int PyramidImage::GetHeightImage(int i)
{
    //any image
    if(i>=0 && i<=CountCopies()){
        if(images[i]!=nullptr){
            return images[i]->height();
        }
        else{
            double temp = pow(coefficient,i);
            return (int)(images[0]->height()/temp);
        }
    }
    return 0;
}

QSize *PyramidImage::GetSize(int i)
{
    //any image
     if(i>=0 && i<=CountCopies()){
         return new QSize(GetWidthImage(i),GetHeightImage(i));
     }
     return new QSize(0,0);
}

QPixmap *PyramidImage::GenerateCopiedImageWithNoSave(int i)
{
    //only copies
    if(i>=1 && i<=CountCopies()){

        return new QPixmap(images[0]->scaled(
                    GetWidthImage(i),
                    GetHeightImage(i),
                    Qt::AspectRatioMode::IgnoreAspectRatio,
                    Qt::TransformationMode::FastTransformation).
                scaled(
                    GetWidthImage(0),
                    GetHeightImage(0),
                    Qt::AspectRatioMode::IgnoreAspectRatio,
                    Qt::TransformationMode::SmoothTransformation));
    }
    return nullptr;
}

void PyramidImage::SetCoefficient(float coefficient)
{
    if(coefficient <= 1)
        coefficient = coefficient_default;
    if(this->coefficient != coefficient)
    {
        clearGeneratedCopies();
        this->coefficient = coefficient;
        //resize vector
        if(CountCopies()>0)
        {
            QPixmap* original = images[0];
            QSize size = original->size();
            images.resize(
                        maxCopies(&size, coefficient)
                        +1);//+1 for original in index 0
            std::fill(images.begin(), images.end(), nullptr);
            images.insert(0,original);
        }
    }
}

float PyramidImage::GetCoefficient()
{
    return coefficient;
}

void PyramidImage::clearGeneratedCopies()
{
    for(int i=0;i<images.size();i++)
    {
        if(images[i]!=nullptr)
        {
            images[i]->~QPixmap();
            images.insert(i,nullptr);
        }
    }
}

int PyramidImage::maxCopies(QSize *size, float coefficient)
{
    //get smallest dimension
    int n = size->width()>size->height()?size->height():size->width();
    if(n>1){
        //m is smaller than log(n,coefficient), but m is integer.
        int m = floor(log(n,coefficient));
        return m;
    }
    return 0;
}

double PyramidImage::log(double x, double base)
{
    return std::log(x)/std::log(base);
}
