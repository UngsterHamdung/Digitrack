#pragma once

#include <QMainWindow>
#include "ui_ProcessImage.h"
#include <QPushButton>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <QLabel>

class ProcessImage : public QMainWindow
{
	Q_OBJECT

public:
	ProcessImage(QWidget *parent = nullptr);
	~ProcessImage();
	QPushButton* ok_btn;
	QPushButton* run_btn;
	QLabel* oriImg;
	QLabel* procImg;

public slots:
	//void GetFInfo();
	void ShowImg(std::string img);
	void Process();
	void GetProcParam();
private:
	Ui::ProcessImageClass ui;
};
