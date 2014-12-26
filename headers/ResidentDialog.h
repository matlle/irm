/*
 * Author: MATLLE - (CRIXUS)
 * Created at: Wednesday 24 December 2014
 *
 * Role: 
 * For create new resident or edit old resident.
 *
 */


#ifndef HEADER_RESIDENTDIALOG
#define HEADER_RESIDENTDIALOG

#include <QtGui>

class ResidentDialog : public QDialog { 

    public:
      ResidentDialog(QWidget *parent);

    protected:

    private:
      QComboBox *m_typeResident;
      QPushButton *m_okBtn;
      QPushButton *m_cancelBtn;
 
};

#endif
