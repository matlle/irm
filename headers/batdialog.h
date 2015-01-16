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
      void saveNewBat();
      void saveEditedBat(const QModelIndex&, int);

    public slots:

    protected:
      QLineEdit *m_name;

      QPushButton *m_newBtn;
      QPushButton *m_editBtn;
      QPushButton *m_okBtn;
      QPushButton *m_cancelBtn;
 
};

#endif
