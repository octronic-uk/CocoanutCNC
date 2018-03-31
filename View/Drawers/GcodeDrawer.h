// This file is a part of "CocoanutCNC" application.
// Copyright 2015-2016 Hayrullin Denis Ravilevich

#pragma once

#include <QObject>
#include <QVector3D>
#include "../../Model/Parser/LineSegment.h"
#include "../../Model/Parser/GcodeViewParse.h"
#include "ShaderDrawable.h"

class GcodeDrawer : public QObject, public ShaderDrawable
{
    Q_OBJECT
public:
    enum GrayscaleCode
    {
        S, Z
    };
    enum DrawMode
    {
        Vectors, Raster
    };

    explicit GcodeDrawer();
    GcodeDrawer(const GcodeDrawer& other);

    void update();
    void update(QList<int> indexes);
    bool updateData();

    QVector3D getSizes();
    QVector3D getMinimumExtremes();
    QVector3D getMaximumExtremes();

    void setViewParser(GcodeViewParse *viewParser);
    GcodeViewParse* viewParser();

    bool simplify() const;
    void setSimplify(bool simplify);

    double simplifyPrecision() const;
    void setSimplifyPrecision(double simplifyPrecision);

    bool geometryUpdated();

    QColor colorNormal() const;
    void setColorNormal(const QColor &colorNormal);

    QColor colorHighlight() const;
    void setColorHighlight(const QColor &colorHighlight);

    QColor colorZMovement() const;
    void setColorZMovement(const QColor &colorZMovement);

    QColor colorDrawn() const;
    void setColorDrawn(const QColor &colorDrawn);

    QColor colorStart() const;
    void setColorStart(const QColor &colorStart);

    QColor colorEnd() const;
    void setColorEnd(const QColor &colorEnd);

    bool getIgnoreZ() const;
    void setIgnoreZ(bool ignoreZ);

    bool getGrayscaleSegments() const;
    void setGrayscaleSegments(bool grayscaleSegments);

    GrayscaleCode grayscaleCode() const;
    void setGrayscaleCode(const GrayscaleCode &grayscaleCode);

    int grayscaleMin() const;
    void setGrayscaleMin(int grayscaleMin);

    int grayscaleMax() const;
    void setGrayscaleMax(int grayscaleMax);

    DrawMode drawMode() const;
    void setDrawMode(const DrawMode &drawMode);

    GcodeParser getParser() const;
    void setParser(const GcodeParser& parser);

signals:

public slots:

private slots:
    void onTimerVertexUpdate();

private:
    GcodeViewParse *m_viewParser;
    DrawMode m_drawMode;
    bool m_simplify;
    double m_simplifyPrecision;
    bool m_ignoreZ;
    bool m_grayscaleSegments;
    GrayscaleCode m_grayscaleCode;
    int m_grayscaleMin;
    int m_grayscaleMax;
    QColor m_colorNormal;
    QColor m_colorDrawn;
    QColor m_colorHighlight;
    QColor m_colorZMovement;
    QColor m_colorStart;
    QColor m_colorEnd;
    QTimer m_timerVertexUpdate;
    QImage m_image;
    QList<int> m_indexes;
    bool m_geometryUpdated;

    bool prepareVectors();
    bool updateVectors();
    bool prepareRaster();
    bool updateRaster();

    int getSegmentType(LineSegment *segment);
    QVector4D getSegmentColorVector(LineSegment *segment);
    QColor getSegmentColor(LineSegment *segment);
    void setImagePixelColor(QImage &image, double x, double y, QRgb color) const;
};
