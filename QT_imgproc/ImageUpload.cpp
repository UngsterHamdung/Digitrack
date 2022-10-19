#include "ImageUpload.h"
#include <QPushButton>
#include <QFileDialog>
#include <QGridLayout>
#include "ChangeWindow.h"
void ImageUpload::ImageOpen()
{
    std::string img_name;
    QStringList file_path = UploadImage->getOpenFileNames(this, "upload image", "C:/", "Image Files (*.png *.jpg *.bmp)");
    img_name = file_path[0].toStdString();
    ChangeWindow* a;
    emit a->Change(img_name);
}

ImageUpload::ImageUpload(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    QGridLayout* main_layout = new QGridLayout;
    ui.centralWidget->setLayout(main_layout);
    QPushButton* btn = new QPushButton("ImageUpload");
    main_layout->addWidget(btn);
    connect(btn, SIGNAL(clicked()), this, SLOT(ImageOpen()));
    ChangeWindow a;
    connect(this, SIGNAL(GetImage()), &a, SLOT(&ChangeWindow::Change));
    //ProcessImage b;
    
}

ImageUpload::~ImageUpload()
{}

