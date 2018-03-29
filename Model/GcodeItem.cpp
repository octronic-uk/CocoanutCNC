/*
 * GcodeItem.cpp
 *
 * Created: 28 2018 by Ashley
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
#include "GcodeItem.h"

GcodeItem::GcodeItem()
{

}

GcodeItem::~GcodeItem()
{

}

QString GcodeItem::getCommand() const
{
    return mCommand;
}

void GcodeItem::setCommand(const QString& command)
{
    mCommand = command;
}

QString GcodeItem::getResponse() const
{
    return mResponse;
}

void GcodeItem::setResponse(const QString& response)
{
    mResponse = response;
}

QStringList GcodeItem::getArgs() const
{
    return mArgs;
}

void GcodeItem::setArgs(const QStringList& args)
{
    mArgs = args;
}

char GcodeItem::getState() const
{
    return mState;
}

void GcodeItem::setState(char state)
{
    mState = state;
}

int GcodeItem::getLine() const
{
    return mLine;
}

void GcodeItem::setLine(int line)
{
    mLine = line;
}