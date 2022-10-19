#include "ImageUpload.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ImageUpload w;
    w.show();
    return a.exec();
}
