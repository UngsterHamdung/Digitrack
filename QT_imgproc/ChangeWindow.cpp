#include "ChangeWindow.h"

ChangeWindow::ChangeWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

ChangeWindow::~ChangeWindow()
{}

void ChangeWindow::Change(std::string imgWindow)
{	
	ProcessImage* move_window = new ProcessImage;
	move_window->show();
	move_window->ShowImg(imgWindow);
}