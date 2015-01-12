/*
 * Author: MATLLE - (CRIXUS)
 * Created at: Saturday 10 January 2015
 *
 * Role: 
 * For create new typeResident or for edit old typeResident.
 *
 */


#ifndef HEADER_TYPERESIDENTDIALOG
#define HEADER_TYPERESIDENTDIALOG

#include <QtGui>
#include <QtSql>

class TypeResidentDialog : public QDialog { 

    Q_OBJECT

    public:
      TypeResidentDialog(QWidget *parent);
      TypeResidentDialog(QVariantList list, QWidget *parent);
      void saveNewTypeResident();
      void saveEditedTypeResident(const QModelIndex&, int);

    public slots:

    protected:
      QLineEdit *m_name;

      QPushButton *m_okBtn;
      QPushButton *m_cancelBtn;
 
};

#endif
