/*
 * ToolModelGeometryItem.cpp
 *
 * Created: 06 2018 by Ashley
 *
 * Copyright 2018 Octronic. All rights reserved.
 *
 * This file may be distributed under the terms of GNU Public License version
 * 3 (GPL v3) as defined by the Free Software Foundation (FSF). A copy of the
 * license should have been included with this file, or the project in which
 * this file belongs to. You may also find the details of GPL v3 at:
 * http://www.gnu.org/licenses/gpl-3.0.txt
 *
 * If you have any questions regarding the use of this file, feel free to
 * contact the author of this file, or the owner of the project in which
 * this file belongs to.
 */

#include "Model/Settings/Tool/Tool.h"
#include "ToolGeometry.h"
#include <QtDebug>

ToolGeometry::ToolGeometry
(Tool* parent, int id, int index, float height, float upper, float lower, int faces)
    : AbstractDatabaseRecord(id),
      mParentHandle(parent),
      mIndex(index),
      mHeight(height),
      mUpperDiameter(upper),
      mLowerDiameter(lower),
      mFaces(faces)
{
    qDebug() << "ToolModelGeometryItem: Creating with index" << index;
}

ToolGeometry::ToolGeometry(const ToolGeometry& other)
    : AbstractDatabaseRecord (other.getID()),
      mIndex(other.mIndex),
      mHeight(other.mHeight),
      mUpperDiameter(other.mUpperDiameter),
      mLowerDiameter(other.mLowerDiameter),
      mFaces(other.mFaces)
{
    qDebug() << "ToolModelGeometryItem: Creating ToolGeometry(other&)"
             << "ID" << getID()
             << "H_ID" <<  getToolID()
             << "IDX" <<  mIndex
             << "H" <<  mHeight
             << "L_D" <<  mLowerDiameter
             << "U_D" <<  mUpperDiameter
             << "Faces "<< mFaces;
}

bool ToolGeometry::operator==(const ToolGeometry& other)
{
   return getID() == other.getID() && getIndex() == other.getIndex();
}

float ToolGeometry::getUpperDiameter() const
{
    return mUpperDiameter;
}

void ToolGeometry::setUpperDiameter(float upperDiameter)
{
    mUpperDiameter = upperDiameter <= 0 ? 1 : upperDiameter;
}

float ToolGeometry::getLowerDiameter() const
{
    return mLowerDiameter;
}

void ToolGeometry::setLowerDiameter(float lowerDiameter)
{
    mLowerDiameter = lowerDiameter <= 0 ? 1 : lowerDiameter;
}

float ToolGeometry::getHeight() const
{
    return mHeight;
}

void ToolGeometry::setHeight(float height)
{
    mHeight = height <= 0 ? 1 : height;
}

int ToolGeometry::getIndex() const
{
    return mIndex;
}

void ToolGeometry::setIndex(int index)
{
    mIndex = index;
}

int ToolGeometry::getToolID() const
{
    return mParentHandle->getID();
}

Tool* ToolGeometry::getParentHandle() const
{
    return mParentHandle;
}

void ToolGeometry::setParentHandle(Tool* parentHandle)
{
    mParentHandle = parentHandle;
}

int ToolGeometry::getFaces() const
{
    return mFaces;
}

void ToolGeometry::setFaces(int faces)
{
    mFaces = faces;
}
