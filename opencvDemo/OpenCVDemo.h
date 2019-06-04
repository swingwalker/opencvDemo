#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_OpenCVDemo.h"
#include <opencv2/opencv.hpp>

class QGraphicsPixmapItem;

class OpenCVDemo : public QMainWindow
{
	Q_OBJECT

public:
	OpenCVDemo(QWidget *parent = Q_NULLPTR);

private:
	Ui::OpenCVDemoClass ui;
	QLabel * statuLabel;

	QString _strImgPath;
	cv::Mat _cvImg;
	QImage::Format _imgFormat;
	QImage::Format _grayFormat;
	QImage::Format _cannyFormat;

	void initDlg();
	QGraphicsPixmapItem * showImg(cv::Mat, QImage::Format, QGraphicsView *,int dx = 0, int dy = 0 );

private slots:
	void getImgByFileName();
	void changeImgFormat(const QString &);

	void createPyrDown(int);
	void createGray();

	void creatCanny();
	void moreimg();
};
