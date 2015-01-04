#ifndef PAGES_H
#define PAGES_H

#include <QWidget>
#include <QAbstractItemModel>
#include <QTreeView>



class ResidentPage : public QWidget {
    Q_OBJECT
    public:
        ResidentPage(QWidget *parent = 0);
        void updateResidentList();
        void insertNewResident(int);

    public slots:
        void showEdit(const QModelIndex&);
    protected:
        QTreeView          *m_residentName;
        
    
    
        
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
