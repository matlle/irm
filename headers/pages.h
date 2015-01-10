#ifndef PAGES_H
#define PAGES_H

#include <QWidget>
#include <QAbstractItemModel>
#include <QTreeView>
#include <QLabel>



class ResidentPage : public QWidget {
    Q_OBJECT
    public:
        ResidentPage(QWidget *parent = 0);
        void updateResidentList();
        void insertNewResident(int);

    public slots:
        void showEdit(const QModelIndex&);
        void showEditOnEditAction();
        void contextMenuEvent(QContextMenuEvent *event);
        void showResidentInfos(const QModelIndex&);
        void removeResident();

    protected:
        QTreeView  *m_residentName;
        QTreeView  *m_typeResident;
        QLabel     *m_picResident;
        QLabel     *m_nameResident;         
        QLabel     *m_textInfos;
    
    
        
};

class QueryPage: public QWidget {

    public:
        QueryPage(QWidget *parent = 0);

};

class UpdatePage : public QWidget {

    public:
        UpdatePage(QWidget *parent = 0);
};

#endif
