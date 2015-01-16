#ifndef PAGES_H
#define PAGES_H

#include <QWidget>
#include <QAbstractItemModel>
#include <QStandardItem>
#include <QTreeView>
#include <QLabel>



class ResidentPage : public QWidget {
    Q_OBJECT
    public:
        ResidentPage(QWidget *parent = 0);
        void updateResidentList();
        void insertNewResident(int);
        void updateResidentTree();
        void updateTypeResidentTree();

    public slots:
        void showEdit(const QModelIndex&);
        void showEditOnEditAction();
        void showEditTypeResident(const QModelIndex&);
        void showEditTypeResiOnEditAction();
        void contextMenuEvent(QContextMenuEvent *event);
        void showResidentInfos(const QModelIndex&);
        void removeResident();
        void removeTypeResident();
        void onItemChanged(QStandardItem*);

    protected:
        QTreeView  *m_residentName;
        QTreeView  *m_typeResident;
        QLabel     *m_picResident;
        QLabel     *m_nameResident;         
        QLabel     *m_textInfos;
    
    
        
};

class BatChaPage: public QWidget {

    public:
        BatChaPage(QWidget *parent = 0);

};

class EventsPage : public QWidget {

    public:
        EventsPage(QWidget *parent = 0);
};

#endif
