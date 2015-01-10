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
