#include "ComFunc.h"

QString comGetImageFormat(QImage::Format e)
{
	QString str;
	switch (e)
	{
	case QImage::Format_Invalid:
		str = "Format_Invalid";
		break;
	case QImage::Format_Mono:
		str = "Format_Mono";
		break;
	case QImage::Format_MonoLSB:
		str = "Format_MonoLSB";
		break;
	case QImage::Format_Indexed8:
		str = "Format_Indexed8";
		break;
	case QImage::Format_RGB32:
		str = "Format_RGB32";
		break;
	case QImage::Format_ARGB32:
		str = "Format_ARGB32";
		break;
	case QImage::Format_ARGB32_Premultiplied:
		str = "Format_ARGB32_Premultiplied";
		break;
	case QImage::Format_RGB16:
		str = "Format_RGB16";
		break;
	case QImage::Format_ARGB8565_Premultiplied:
		str = "Format_ARGB8565_Premultiplied";
		break;
	case QImage::Format_RGB666:
		str = "Format_RGB666";
		break;
	case QImage::Format_ARGB6666_Premultiplied:
		str = "Format_ARGB6666_Premultiplied";
		break;
	case QImage::Format_RGB555:
		str = "Format_RGB555";
		break;
	case QImage::Format_ARGB8555_Premultiplied:
		str = "Format_ARGB8555_Premultiplied";
		break;
	case QImage::Format_RGB888:
		str = "Format_RGB888";
		break;
	case QImage::Format_RGB444:
		str = "Format_RGB444";
		break;
	case QImage::Format_ARGB4444_Premultiplied:
		str = "Format_ARGB4444_Premultiplied";
		break;
	case QImage::Format_RGBX8888:
		str = "Format_RGBX8888";
		break;
	case QImage::Format_RGBA8888:
		str = "Format_RGBA8888";
		break;
	case QImage::Format_RGBA8888_Premultiplied:
		str = "Format_RGBA8888_Premultiplied";
		break;
	case QImage::Format_BGR30:
		str = "Format_BGR30";
		break;
	case QImage::Format_A2BGR30_Premultiplied:
		str = "Format_A2BGR30_Premultiplied";
		break;
	case QImage::Format_RGB30:
		str = "Format_RGB30";
		break;
	case QImage::Format_A2RGB30_Premultiplied:
		str = "Format_A2RGB30_Premultiplied";
		break;
	case QImage::Format_Alpha8:
		str = "Format_Alpha8";
		break;
	case QImage::Format_Grayscale8:
		str = "Format_Grayscale8";
		break;
	default:
		break;
	}

	return str;
}

QImage::Format comGetImageFormat(const QString & str)
{
	QImage::Format e = QImage::Format_Invalid;
	if (str == "Format_Invalid")
	{
		e = QImage::Format_Invalid;
	}
	else if (str == "Format_Mono")
	{
		e = QImage::Format_Mono;
	}
	else if (str == "Format_MonoLSB")
	{
		e = QImage::Format_MonoLSB;
	}
	else if (str == "Format_Indexed8")
	{
		e = QImage::Format_Indexed8;
	}
	else if (str == "Format_RGB32")
	{
		e = QImage::Format_RGB32;
	}
	else if (str == "Format_ARGB32")
	{
		e = QImage::Format_ARGB32;
	}
	else if (str == "Format_ARGB32_Premultiplied")
	{
		e = QImage::Format_ARGB32_Premultiplied;
	}
	else if (str == "Format_RGB16")
	{
		e = QImage::Format_RGB16;
	}
	else if (str == "Format_ARGB8565_Premultiplied")
	{
		e = QImage::Format_ARGB8565_Premultiplied;
	}
	else if (str == "Format_RGB666")
	{
		e = QImage::Format_RGB666;
	}
	else if (str == "Format_ARGB6666_Premultiplied")
	{
		e = QImage::Format_ARGB6666_Premultiplied;
	}
	else if (str == "Format_RGB555")
	{
		e = QImage::Format_RGB555;
	}
	else if (str == "Format_ARGB8555_Premultiplied")
	{
		e = QImage::Format_ARGB8555_Premultiplied;
	}
	else if (str == "Format_RGB888")
	{
		e = QImage::Format_RGB888;
	}
	else if (str == "Format_RGB444")
	{
		e = QImage::Format_RGB444;
	}
	else if (str == "Format_ARGB4444_Premultiplied")
	{
		e = QImage::Format_ARGB4444_Premultiplied;
	}
	else if (str == "Format_RGBX8888")
	{
		e = QImage::Format_RGBX8888;
	}
	else if (str == "Format_RGBA8888")
	{
		e = QImage::Format_RGBA8888;
	}
	else if (str == "Format_RGBA8888_Premultiplied")
	{
		e = QImage::Format_RGBA8888_Premultiplied;
	}
	else if (str == "Format_BGR30")
	{
		e = QImage::Format_BGR30;
	}
	else if (str == "Format_A2BGR30_Premultiplied")
	{
		e = QImage::Format_A2BGR30_Premultiplied;
	}
	else if (str == "Format_RGB30")
	{
		e = QImage::Format_RGB30;
	}
	else if (str == "Format_A2RGB30_Premultiplied")
	{
		e = QImage::Format_A2RGB30_Premultiplied;
	}
	else if (str == "Format_Alpha8")
	{
		e = QImage::Format_Alpha8;
	}
	else if (str == "Format_Grayscale8")
	{
		e = QImage::Format_Grayscale8;
	}

	return e;
}

