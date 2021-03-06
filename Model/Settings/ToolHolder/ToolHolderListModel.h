/*
 * ToolHolderModelListModel.h
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

#pragma once

#include <QAbstractListModel>
#include <QSharedPointer>

class Profile;
class ToolHolder;

class ToolHolderListModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit ToolHolderListModel(Profile* profile, QObject *parent = nullptr);
    void initialise(QList<QSharedPointer<ToolHolder>> data);

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    ToolHolder* getData(int);
    void remove(ToolHolder* item);
    QList<ToolHolder*> getDataHandles();
    void clear();
    QModelIndex indexOf(ToolHolder* holder);
    QModelIndex getIndexByID(int id);
    ToolHolder* getToolHolderByID(int);
    bool setData(const QModelIndex& index, const QVariant& value, int role) override;
    ToolHolder* getSelected() const;
    void setSelected(ToolHolder* selected);

    void insertItem(QSharedPointer<ToolHolder> newItem);
    void deleteItem(ToolHolder* selected);

signals:

private:
    QList<QSharedPointer<ToolHolder>> mData;
    Profile* mProfileHandle;
    ToolHolder* mSelected;

};
