#pragma once
#include <QString>
#include <QtGui/QImage>

QString comGetImageFormat(QImage::Format);
QImage::Format comGetImageFormat( const QString &);
