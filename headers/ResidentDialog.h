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
#include <QtSql>

class ResidentDialog : public QDialog { 

    public:
      ResidentDialog(QWidget *parent);
      ResidentDialog(QVariantList list, QWidget *parent);
      void saveNewResident();
      void saveEditedResident();

    protected:
      QLineEdit *m_nom;
      QLineEdit *m_prenom;
      QDateEdit *m_dateNaissance;
      QLineEdit *m_lieuNaissance;
      QComboBox *m_genre;
      QSpinBox  *m_taille;
      QLineEdit *m_matricule;
      QLineEdit *m_telephone1;
      QLineEdit *m_telephone2;
      QLineEdit *m_telephone3;
      QLineEdit *m_email;

      QComboBox *m_typeResident;
      QLabel *m_chambre;
      QPushButton *m_okBtn;
      QPushButton *m_cancelBtn;
 
};

#endif
