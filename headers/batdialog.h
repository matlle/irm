/*
 * Author: MATLLE - (CRIXUS)
 * Created at: Friday 16 January 2015
 *
 * Role: 
 * For create create manage batiments.
 *
 */


#ifndef HEADER_BATDIALOG
#define HEADER_BATDIALOG

#include <QtGui>
#include <QtSql>

class BatDialog : public QDialog { 

    Q_OBJECT

    public:
      BatDialog(QWidget *parent);
      //BatDialog(QVariantList list, QWidget *parent);
      void updateBatTree();
      bool isBatHasCha(int);
      QStringList getAllChaByBatId(int);

    public slots:
      void saveNewBat();
      void saveEditedBat(const QModelIndex&);
      void onItemChanged(QModelIndex);
      void removeBat();

    protected:
      QLineEdit *m_name;
      
      QStandardItemModel *m_model;
      QTreeView *m_batTree;

      QPushButton *m_newBat;
      QPushButton *m_newChamb;
      QPushButton *m_removeEle;
      QPushButton *m_okBtn;
      QPushButton *m_cancelBtn;
 
};

#endif
