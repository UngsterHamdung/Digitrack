#pragma once

#include <QMainWindow>
#include "ui_ChangeWindow.h"
#include "ProcessImage.h"
#include "ImageUpload.h"

class ChangeWindow : public QMainWindow
{
	Q_OBJECT

public:
	ChangeWindow(QWidget *parent = nullptr);
	~ChangeWindow();

public slots:
	void Change(std::string imgWindow);
private:
	Ui::ChangeWindowClass ui;
};
