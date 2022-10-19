#include "ProcessImage.h"
#include <QComboBox>
#include <QGridLayout>
#include <QPushButton>
#include <QGroupBox>
#include <QLabel>
#include <QVBoxLayout>
#include <iostream>

std::string current_img;

ProcessImage::ProcessImage(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	ok_btn = new QPushButton("ok", this);
	run_btn = new QPushButton("runProgram", this);

	QHBoxLayout* main_layout = new QHBoxLayout();
	QComboBox* filter = new QComboBox;
	QComboBox* filter_size = new QComboBox;

	oriImg = new QLabel(this);
	procImg = new QLabel(this);

	QHBoxLayout* row_layout = new QHBoxLayout();
	//QHBoxLayout* process_layout = new QHBoxLayout();
	QVBoxLayout* vbox_layout = new QVBoxLayout(this);

	main_layout->addWidget(filter);
	main_layout->addWidget(filter_size);

	vbox_layout->addWidget(oriImg);
	vbox_layout->addWidget(procImg);

	row_layout->addWidget(ok_btn, 0);
	row_layout->addWidget(run_btn, 0);

	vbox_layout->addLayout(row_layout);
	vbox_layout->addLayout(main_layout);
	//vbox_layout->addLayout(process_layout);

	filter->addItem("Median");
	filter->addItem("Mean");
	filter->addItem("Laplacian");
	filter_size->addItem("3x3");
	filter_size->addItem("5x5");

	ui.centralWidget->setLayout(vbox_layout);

	connect(run_btn, &QPushButton::clicked, this, &ProcessImage::Process);
	connect(ok_btn, &QPushButton::clicked, this, &ProcessImage::GetProcParam);
}

ProcessImage::~ProcessImage()
{}

void ProcessImage::ShowImg(std::string img)
{
	
	cv::Mat cur_img = cv::imread(img, cv::IMREAD_COLOR);
	cv::Mat imgRGB;
	cv::cvtColor(cur_img, imgRGB, cv::COLOR_BGR2RGB);
	
	current_img = img;
	QImage qt_image = QImage((const unsigned char*)(imgRGB.data), imgRGB.cols, imgRGB.rows, imgRGB.step1(), QImage::Format_RGB888);
	oriImg->setPixmap(QPixmap::fromImage(qt_image));
	oriImg->resize(oriImg->pixmap()->size());
	//procImg->setPixmap(QPixmap::fromImage(qt_image));
	//procImg->resize(procImg->pixmap()->size());
}

void ProcessImage::Process()
{
	cv::Mat cur_img = cv::imread(current_img, cv::IMREAD_COLOR);
	cv::Mat Process_img;
	cv::cvtColor(cur_img, Process_img, cv::COLOR_BGR2RGB);
	cv::Mat img_gaussian, img_lap, img_median;
	GaussianBlur(Process_img, img_gaussian, cv::Size(3, 3), 0, 0, 4);
	//Laplacian(img_gaussian, img_lap, CV_8U, 3, (1.0), (0, 0), 4);
	medianBlur(Process_img, img_median,5);
	//QString qstr = QString::fromStdString(current_img);
	////procImg->setText(qstr);
	//cv::Mat cur_img = cv::imread(current_img, cv::IMREAD_COLOR);
	//cv::Mat imgRGB;
	//cv::cvtColor(cur_img, imgRGB, cv::COLOR_BGR2GRAY);
	// 
	//QImage proc_image = QImage((const unsigned char*)(imgRGB.data), imgRGB.cols, imgRGB.rows, imgRGB.step1(), QImage::Format_RGB888);

	QPixmap plz_img;
	plz_img = QPixmap::fromImage(QImage((unsigned char*)(img_median.data), img_median.cols, img_median.rows,
		 QImage::Format_RGB888));

	int cur_width = plz_img.width();
	int cur_height = plz_img.height();
	//procImg->setPixmap(QPixmap::fromImage(proc_image));
	//procImg->resize(procImg->pixmap()->size());
	procImg->setPixmap(plz_img.scaled(cur_width, cur_height, Qt::IgnoreAspectRatio));
}

void ProcessImage::GetProcParam()
{

}