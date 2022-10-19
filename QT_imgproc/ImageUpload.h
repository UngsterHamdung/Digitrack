#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ImageUpload.h"
#include <QFileDialog>
#include <string>
#include "ProcessImage.h"

class ImageUpload : public QMainWindow
{
    Q_OBJECT
signals:
    void GetImage();

public:
    ImageUpload(QWidget *parent = nullptr);
    ~ImageUpload();
    QFileDialog *UploadImage = new QFileDialog;
    

public slots:
    void ImageOpen();
    //void Change();
private:
    Ui::ImageUploadClass ui;
};
