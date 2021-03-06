/*
 * Profile.cpp
 *
 * Created: 08 2018 by Ashley
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
#include "Profile.h"

#include <QtDebug>

Profile::Profile(int id, QString name, bool selected)
    : AbstractDatabaseRecord(id),
      mName(name),
      mSelected(selected)
{
    qDebug() << "Profile: Constructing"
             << id << name << selected;
    mConnectionSettings = QSharedPointer<ConnectionSettings>::create(this);
    mInterfaceSettings = QSharedPointer<InterfaceSettings>::create(this);
    mMachineSettings = QSharedPointer<MachineSettings>::create(this);
    mToolsListModel = QSharedPointer<ToolListModel>::create(this);
    mToolHoldersListModel = QSharedPointer<ToolHolderListModel>::create(this);
    mRecentGcodeFilesModel = QSharedPointer<RecentFilesModel>::create(this);
    mRecentHeightMapFilesModel = QSharedPointer<RecentFilesModel>::create(this);
}

Profile::~Profile()
{

}

Profile::Profile(const Profile& other)
    : AbstractDatabaseRecord (other.getID()),
      mName(other.mName),
      mSelected(other.mSelected)
{
    qDebug() << "Profile: Constructing(Profile&)"
             << getID() << mName << mSelected;
}

QString Profile::getName() const
{
    return mName;
}

void Profile::setName(const QString& name)
{
    mName = name;
}

bool Profile::getSelected() const
{
    return mSelected;
}

void Profile::setSelected(bool selected)
{
    mSelected = selected;
}

InterfaceSettings* Profile::getInterfaceSettingsHandle()
{
   return mInterfaceSettings.data();
}

MachineSettings*Profile::getMachineSettingsHandle()
{
   return mMachineSettings.data();
}

ToolListModel* Profile::getToolListModelHandle()
{
   return mToolsListModel.data();
}

ToolHolderListModel* Profile::getToolHolderListModelHandle()
{
   return mToolHoldersListModel.data();
}

RecentFilesModel*Profile::getRecentGcodeFilesModelHandle()
{
   return mRecentGcodeFilesModel.data();
}

RecentFilesModel*Profile::getRecentHeightMapFilesModelHandle()
{
   return mRecentHeightMapFilesModel.data();
}

ConnectionSettings* Profile::getConnectionSettingsHandle()
{
    return mConnectionSettings.data();
}
