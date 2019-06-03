#include "OpenCVDemo.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	OpenCVDemo w;
	w.show();
	return a.exec();
}
