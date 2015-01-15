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
#include <QModelIndex>

class ResidentDialog : public QDialog { 
    Q_OBJECT
    public:
      ResidentDialog(QWidget *parent);
      ResidentDialog(QVariantList list, QWidget *parent);
      void saveNewResident();
      QModelIndex saveEditedResident(const QModelIndex&, int);
      void remove_old_photo(int);
      void updateTypeResidentComboBox();

    public slots:
        void selectPhoto();
    protected:
      QLineEdit *m_nom;
      QLineEdit *m_prenom;
      QDateEdit *m_dateNaissance;
      QLineEdit *m_lieuNaissance;
      QLineEdit *m_profession;
      QComboBox *m_genre;
      QSpinBox  *m_taille;
      QLineEdit *m_matricule;
      QLineEdit *m_telephone1;
      QLineEdit *m_telephone2;
      QLineEdit *m_telephone3;
      QLineEdit *m_email;

      QComboBox *m_typeResident;
      QLabel *m_chambre;
      QPushButton *m_btnPhoto;
      QString *m_photoname;
      QPushButton *m_okBtn;
      QPushButton *m_cancelBtn;
 
};

#endif
