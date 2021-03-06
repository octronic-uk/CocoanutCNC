// This file is a part of "CoconutCNC" application.
// Copyright 2015-2016 Hayrullin Denis Ravilevich

#pragma once

#include <QColor>
#include <QIcon>
#include <QImage>
#include <QAbstractButton>
#include <QVector3D>
#include <QVector4D>
#include <QEventLoop>

class Util
{
public:
    static double nMin(double v1, double v2)
    {
        if (!qIsNaN(v1) && !qIsNaN(v2)) return qMin<double>(v1, v2);
        else if (!qIsNaN(v1)) return v1;
        else if (!qIsNaN(v2)) return v2;
        else return qQNaN();
    }

    static double nMax(double v1, double v2)
    {
        if (!qIsNaN(v1) && !qIsNaN(v2)) return qMax<double>(v1, v2);
        else if (!qIsNaN(v1)) return v1;
        else if (!qIsNaN(v2)) return v2;
        else return qQNaN();
    }

    static QVector4D colorToVector(QColor color)
    {
        return QVector4D(color.redF(), color.greenF(), color.blueF(), color.alphaF());
    }

    static bool floatsAreEqual(float a, float b)
    {
       // TODO - Cry in corner
       return QString::number(a,'f',3) == QString::number(b,'f',3);
    }

    static QIcon invertIconColors(QIcon icon)
    {
        QImage img = icon.pixmap(icon.actualSize(QSize(64, 64))).toImage();
        img.invertPixels();

        return QIcon(QPixmap::fromImage(img));
    }

    static void invertButtonIconColors(QAbstractButton *button)
    {
        button->setIcon(invertIconColors(button->icon()));
    }

    static double toMetric(double value)
    {
        return value * 25.4;
    }

    static bool compareCoordinates(QVector3D machine, double x, double y, double z)
    {
        return machine.x() == x && machine.y() == y && machine.z() == z;
    }
};




