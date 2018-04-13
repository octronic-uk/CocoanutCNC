/*
 * InterfaceSettings.cpp
 *
 * Created: 10 2018 by Ashley
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

#include "InterfaceSettings.h"
#include "Model/Settings/Profile/Profile.h"
#include <QtDebug>

InterfaceSettings::InterfaceSettings(Profile* parent, int id)
    : AbstractDatabaseRecord(id),
      mParentHandle(parent),
      mLineWidth(0.0f),
      mFpsLock(60),
      mAntiAliasing(true),
      mVsync(true),
      mMsaa(true),
      mZbuffer(true),
      mGcodeDrawMode(false),
      mSimplifyGeometry(false),
      mSimplifyPrecision(1.0),
      mGrayscaleSegments(false),
      mGrayscaleCode(false)
{
    qDebug() << "InterfaceSettings: Constructing";
}

Profile* InterfaceSettings::getParentHandle() const
{
    return mParentHandle;
}

int InterfaceSettings::getParentID()
{
   return mParentHandle->getID();
}

float InterfaceSettings::getLineWidth() const
{
    return mLineWidth;
}

void InterfaceSettings::setLineWidth(float lineWidth)
{
    mLineWidth = lineWidth;
}

int InterfaceSettings::getFpsLock() const
{
    return mFpsLock;
}

void InterfaceSettings::setFpsLock(int fpsLock)
{
    mFpsLock = fpsLock;
}

bool InterfaceSettings::getAntiAliasing() const
{
    return mAntiAliasing;
}

void InterfaceSettings::setAntiAliasing(bool antiAliasing)
{
    mAntiAliasing = antiAliasing;
}

bool InterfaceSettings::getVsync() const
{
    return mVsync;
}

void InterfaceSettings::setVsync(bool vsync)
{
    mVsync = vsync;
}

bool InterfaceSettings::getMsaa() const
{
    return mMsaa;
}

void InterfaceSettings::setMsaa(bool msaa)
{
    mMsaa = msaa;
}

bool InterfaceSettings::getZbuffer() const
{
    return mZbuffer;
}

void InterfaceSettings::setZbuffer(bool zbuffer)
{
    mZbuffer = zbuffer;
}

bool InterfaceSettings::getGcodeDrawMode() const
{
    return mGcodeDrawMode;
}

void InterfaceSettings::setGcodeDrawMode(bool gcodeDrawMode)
{
    mGcodeDrawMode = gcodeDrawMode;
}

bool InterfaceSettings::getSimplifyGeometry() const
{
    return mSimplifyGeometry;
}

void InterfaceSettings::setSimplifyGeometry(bool simplifyGeometry)
{
    mSimplifyGeometry = simplifyGeometry;
}

float InterfaceSettings::getSimplifyPrecision() const
{
    return mSimplifyPrecision;
}

void InterfaceSettings::setSimplifyPrecision(float simplifyPrecision)
{
    mSimplifyPrecision = simplifyPrecision;
}

bool InterfaceSettings::getGrayscaleSegments() const
{
    return mGrayscaleSegments;
}

void InterfaceSettings::setGrayscaleSegments(bool grayscaleSegments)
{
    mGrayscaleSegments = grayscaleSegments;
}

bool InterfaceSettings::getGrayscaleCode() const
{
    return mGrayscaleCode;
}

void InterfaceSettings::setGrayscaleCode(bool grayscaleCode)
{
    mGrayscaleCode = grayscaleCode;
}
