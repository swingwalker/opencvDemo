#include "OpenCVDemo.h"
#include "ComFunc.h"

#include <QFileDialog>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/videoio/videoio.hpp>
#include <QDebug>
#include <QGraphicsPixmapItem>

OpenCVDemo::OpenCVDemo(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	initDlg();
}

void OpenCVDemo::initDlg()
{
	ui.menuBar->hide();
	// 获取图片
	connect(ui.pushButton_SelectImg, SIGNAL(clicked()), this, SLOT(getImgByFileName()));

	// 初始化格式列表
	QStringList strList;
	for (int i = 0; i < (int)QImage::NImageFormats; i++)
	 {
		strList.push_back(comGetImageFormat((QImage::Format)i));
	 }
	ui.comboBox_ImgFormat->addItems(strList);
	ui.comboBox_ImgFormat_Gray->addItems(strList);
	ui.comboBox_ImgFormat_Canny->addItems(strList);
	connect(ui.comboBox_ImgFormat, SIGNAL(currentTextChanged(const QString &)), this, SLOT(changeImgFormat(const QString &)));
	connect(ui.comboBox_ImgFormat_Gray, SIGNAL(currentTextChanged(const QString &)), this, SLOT(changeImgFormat(const QString &)));
	connect(ui.comboBox_ImgFormat_Canny, SIGNAL(currentTextChanged(const QString &)), this, SLOT(changeImgFormat(const QString &)));
	_imgFormat = QImage::Format_Invalid;
	_grayFormat = QImage::Format_Invalid;
	_cannyFormat = QImage::Format_Invalid;

	// 降采样设置
	connect(ui.spinBox_Downsampling, SIGNAL(valueChanged(int)), this, SLOT(createPyrDown(int)));

	// 生成灰度图
	connect(ui.pushButton_Gray, SIGNAL(clicked()), this, SLOT(createGray()));
	connect(ui.pushButton_Canny, SIGNAL(clicked()), this, SLOT(creatCanny()));
}

void OpenCVDemo::getImgByFileName()
{
	_strImgPath = QFileDialog::getOpenFileName(this, QStringLiteral("选择图片"), "", "Images (*.png *.xpm *.jpg)");
	ui.lineEdit_ImgName->setText(_strImgPath);
	_cvImg = cv::imread(_strImgPath.toStdString(), -1);
	showImg(_cvImg, _imgFormat, ui.graphicsView);
}

void OpenCVDemo::changeImgFormat(const QString & str)
{
	QComboBox * comboBox = (QComboBox *)sender();
	if (comboBox == ui.comboBox_ImgFormat)
	{
		_imgFormat = comGetImageFormat(str);
		showImg(_cvImg, _imgFormat, ui.graphicsView);
	}
	else if (comboBox == ui.comboBox_ImgFormat_Gray)
	{
		_grayFormat = comGetImageFormat(str);
		createGray();

	}
	else if (comboBox == ui.comboBox_ImgFormat_Canny)
	{
		_cannyFormat = comGetImageFormat(str);
		creatCanny();
	}
}

QGraphicsPixmapItem * OpenCVDemo::showImg(cv::Mat cvImg, QImage::Format eFormat, QGraphicsView * view, int dx /*= 0*/, int dy /*= 0*/)
{
	QGraphicsScene * pScene = view->scene();
	if (pScene == NULL)
	{
		pScene = new QGraphicsScene();
	}

	QList<QGraphicsItem *> itemList = pScene->items();
	for (size_t i = 0; i < itemList.size(); i++)
	{
		pScene->removeItem(itemList[i]);
	}

	QImage img = QImage((const uchar*)(cvImg.data),
		cvImg.cols, cvImg.rows,cvImg.cols * cvImg.channels(), eFormat);

	QGraphicsPixmapItem * imgItem = pScene->addPixmap(QPixmap::fromImage(img));
	imgItem->moveBy(dx, dy);
	view->setScene(pScene);

	return imgItem;
}

void OpenCVDemo::createPyrDown(int iPyr)
{
	cv::Mat cvPyrImg = _cvImg;
	for (size_t i = 0; i < iPyr; i++)
	{
		cv::pyrDown(cvPyrImg, cvPyrImg);
	}

	showImg(cvPyrImg, _imgFormat, ui.graphicsView_2);
}

void OpenCVDemo::createGray()
{
	cv::Mat cvGrayImg;
	cv::cvtColor(_cvImg, cvGrayImg, cv::COLOR_BGR2GRAY);
	showImg(cvGrayImg, _grayFormat, ui.graphicsView_3);
}

void OpenCVDemo::creatCanny()
{
	cv::Mat cvGrayImg;
	cv::Mat cvCannyImg;
	cv::cvtColor(_cvImg, cvGrayImg, cv::COLOR_BGR2GRAY);
	cv::Canny(cvGrayImg, cvCannyImg, 10, 200, 3, true);
	showImg(cvGrayImg, _grayFormat,ui.graphicsView_3);
	showImg(cvCannyImg, _cannyFormat, ui.graphicsView_4);
}
