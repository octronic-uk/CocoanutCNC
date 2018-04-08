/*
 * SqlSettingsModel.h
 *
 * Created: 07 2018 by Ashley
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

#pragma once

#include <QtSql>

#include "Model/Settings/AbstractSettingsModel.h"
#include "Model/Settings/ToolHolder/ToolHolder.h"
#include "Model/Settings/ToolHolder/ToolHolderListModel.h"
#include "Model/Settings/Profile/ProfilesListModel.h"
#include "Model/RecentFilesModel.h"

class SqlSettingsModel : public AbstractSettingsModel
{
    Q_OBJECT
public:
    SqlSettingsModel(QObject* parent = nullptr);
    ~SqlSettingsModel() override;

    bool getOpen() const;
    void setOpen(bool open);

protected:
    // Profile
    int getProfilesFromDB();
    bool updateProfileInDB(const Profile& profile);
    // Recent Gcode Files
    int getRecentGcodeFilesFromDB();
    bool insertRecentGcodeFileInDB();
    // Tool Holder
    int getToolHoldersFromDB();
    bool insertToolHolderInDB(const ToolHolder& item);

    // Tool Holder Geometry
    int getToolHoldersGeometryFromDB();


signals:
    void recentGcodeFilesModel_ModelReady_Signal(QSharedPointer<RecentFilesModel>);
    void recentHeightMapFilesModel_ModelReady_Signal(QSharedPointer<RecentFilesModel>);
    void toolHolderModel_ListModelReady_Signal(QSharedPointer<ToolHolderModelListModel>);
    void profilesListModel_ListModelReady_Signal(QSharedPointer<ProfilesListModel>);

public slots:
    void onCurrentProfileChanged(Profile profile);

private:
    const static QString DB_FILE_NAME;
    const static QString SQLITE_DB;

    // Profiles
    const static QString CREATE_PROFILES_TABLE_QUERY;
    const static QString INSERT_DEFAULT_PROFILE_QUERY;
    const static QString SELECT_ALL_PROFILES_QUERY;
    const static QString UPDATE_PROFILE_WHERE_ID_QUERY;

    // Recent Files
    const static QString CREATE_RECENT_GCODE_FILES_TABLE_QUERY;
    const static QString SELECT_RECENT_GCODE_FILES_BY_PROFILE_ID_QUERY;

    // Recent HeightMep Files
    const static QString CREATE_RECENT_HEIGHT_MAP_FILES_TABLE_QUERY;
    const static QString SELECT_RECENT_HEIGHT_MAP_FILES_BY_PROFILE_ID_QUERY;

    // Connection
    const static QString CREATE_CONNECTION_TABLE_QUERY;

    // Interface
    const static QString CREATE_INTERFACE_TABLE_QUERY;

    // Machine
    const static QString CREATE_MACHINE_TABLE_QUERY;

    // Tool Holders
    const static QString CREATE_TOOL_HOLDERS_TABLE_QUERY;
    const static QString INSERT_TOOL_HOLDER_QUERY;
    const static QString SELECT_TOOL_HOLDER_BY_ID_QUERY;
    const static QString SELECT_ALL_TOOL_HOLDERS_WHERE_PROFILE_ID_QUERY;
    const static QString DELETE_TOOL_HOLDER_BY_ID_QUERY;

    // Tool Holders Geometry
    const static QString CREATE_TOOL_HOLDERS_GEOMETRY_TABLE_QUERY;
    const static QString INSERT_TOOL_HOLDERS_GEOMETRY_QUERY;
    const static QString SELECT_TOOL_HOLDERS_GEOMETRY_BY_TOOL_HOLDER_ID_QUERY;
    const static QString DELETE_TOOL_HOLDERS_GEOMETRY_BY_ID_QUERY;

    QDir mSettingsDirectory;
    QString mFilePath;
    Profile mCurrentProfile;
    QSharedPointer<ToolHolderModelListModel> mToolHoldersListModel;
    QSharedPointer<ProfilesListModel> mProfilesListModel;
    QSharedPointer<RecentFilesModel> mRecentGcodeFilesModel;
    QSharedPointer<RecentFilesModel> mRecentHeightMapFilesModel;

    // AbstractSettingsModel interface
    void createTables();
    bool createProfilesTable();
    bool createRecentGcodeFilesTable();
    bool createRecentHeightMapFilesTable();
    bool createToolHoldersTable();
    bool createToolHoldersGeometryTable();

    bool insertDefaultProfile();

public slots:
    void onSaveSettings() override;
    void onLoadSettings() override;
    void onSettingChanged(QString groupName, QString settingName, QVariant value) override;
};
