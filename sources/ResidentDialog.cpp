#include "ResidentDialog.h"
#include "pages.h"
#include "common.h"


ResidentDialog::ResidentDialog(QWidget *parent = 0): QDialog(parent) {
    
    m_typeResident = new QComboBox(this);
    m_typeResident->addItem("Edutiant");
    m_typeResident->addItem("Professionel");
    m_typeResident->addItem("Autres");

    QFormLayout *listForm = new QFormLayout;
    listForm->addRow("Groupe: ", m_typeResident);

    m_okBtn = new QPushButton("Ok");
    m_okBtn->setIcon(QIcon("img/apply.png"));
    m_cancelBtn = new QPushButton("Annuler");
    m_cancelBtn->setIcon(QIcon("img/button_cancel.png"));
    QTabWidget *onglets = new QTabWidget(this);

    QWidget *page1 = new QWidget;
        QPushButton *btnPhoto = new QPushButton; 
                     btnPhoto->setIcon(QIcon("img/user-icon.png"));
                     btnPhoto->setIconSize(QSize(200, 200));
        QVBoxLayout *photoLayout = new QVBoxLayout;
                     photoLayout->addWidget(btnPhoto);
        QGroupBox *groupPhoto = new QGroupBox("Photo");
        groupPhoto->setLayout(photoLayout);

        m_nom = new QLineEdit(this);
        m_prenom = new QLineEdit(this);
        m_dateNaissance = new QDateEdit(this);
                   m_dateNaissance->setCalendarPopup(true);
                   m_dateNaissance->setDisplayFormat(QString("dd/MM/yyyy"));
        m_lieuNaissance = new QLineEdit(this);
        m_genre = new QComboBox(this);
                   m_genre->addItem("Homme");
                   m_genre->addItem("Femme");
        m_taille = new QSpinBox;
                  m_taille->setMaximum(300);
        m_matricule = new QLineEdit(this);
        m_telephone1 = new QLineEdit(this);
            m_telephone1->setInputMask(QString("99-99-99-99"));
        m_telephone2 = new QLineEdit(this);
            m_telephone2->setInputMask(QString("99-99-99-99"));
        m_telephone3 = new QLineEdit(this);
            m_telephone3->setInputMask(QString("99-99-99-99"));
        m_email = new QLineEdit(this);

        QFormLayout *infosForm = new QFormLayout;
        infosForm->addRow("Nom: ", m_nom);
        infosForm->addRow("Prenom: ", m_prenom);
        infosForm->addRow("Date de naissance: ", m_dateNaissance);
        infosForm->addRow("Lieu de naissance: ", m_lieuNaissance);
        infosForm->addRow("Genre: ", m_genre);
        infosForm->addRow("Taille (cm): ", m_taille);
        infosForm->addRow("Matricule: ", m_matricule);
        infosForm->addRow("Email : ", m_email);
        infosForm->addRow("Téléphone 1: ", m_telephone1);
        infosForm->addRow("Téléphone 2: ", m_telephone2);
        infosForm->addRow("Téléphone 3: ", m_telephone3);

        QGroupBox *groupInfos = new QGroupBox("Informations");
        groupInfos->setLayout(infosForm);

        QHBoxLayout *mainLayoutPage1 = new QHBoxLayout;
        mainLayoutPage1->addWidget(groupInfos);
        mainLayoutPage1->addWidget(groupPhoto);

        page1->setLayout(mainLayoutPage1);


    QWidget *page2 = new QWidget;
       QLabel *labelSelectBat = new QLabel(this);
               labelSelectBat->setText(QString("Batiment: "));
       QComboBox *selected_bat = new QComboBox(this);
           selected_bat->addItem("Batiment A");
           selected_bat->addItem("Batiment B");
           selected_bat->addItem("Batiment C");
           selected_bat->addItem("Batiment D");
       QHBoxLayout *selectBatLayout = new QHBoxLayout;
           selectBatLayout->addWidget(labelSelectBat);
           selectBatLayout->addWidget(selected_bat);
           selectBatLayout->addStretch(100);

       QGridLayout *rooms_in_bat_layout = new QGridLayout;
           QPushButton *room1 = new QPushButton("Chambre 1");
                     room1->setIcon(QIcon("img/bed.png"));
                     room1->setIconSize(QSize(50, 70));
           QPushButton *room2 = new QPushButton("Chambre 2");
                     room2->setIcon(QIcon("img/bed.png"));
                     room2->setIconSize(QSize(50, 70));
           QPushButton *room3 = new QPushButton("Chambre 3");
                     room3->setIcon(QIcon("img/bed.png"));
                     room3->setIconSize(QSize(50, 70));
           QPushButton *room4 = new QPushButton("Chambre 4");
                     room4->setIcon(QIcon("img/bed.png"));
                     room4->setIconSize(QSize(50, 70));
           QPushButton *room5 = new QPushButton("Chambre 5");
                     room5->setIcon(QIcon("img/bed.png"));
                     room5->setIconSize(QSize(50, 70));
                     room5->setStyleSheet("background-color: green;");

          QPushButton *room6 = new QPushButton("Chambre 6");
                     room6->setIcon(QIcon("img/bed.png"));
                     room6->setIconSize(QSize(50, 70));

          QPushButton *room7 = new QPushButton("Chambre 7");
                     room7->setIcon(QIcon("img/bed.png"));
                     room7->setIconSize(QSize(50, 70));
                     room7->setStyleSheet("background-color: red;");

          QPushButton *room8 = new QPushButton("Chambre 8");
                     room8->setIcon(QIcon("img/bed.png"));
                     room8->setIconSize(QSize(50, 70));




           rooms_in_bat_layout->addWidget(room1, 0, 0);
           rooms_in_bat_layout->addWidget(room2, 0, 1);
           rooms_in_bat_layout->addWidget(room3, 0, 2);
           rooms_in_bat_layout->addWidget(room4, 0, 3);
           rooms_in_bat_layout->addWidget(room5, 0, 4);
           rooms_in_bat_layout->addWidget(room6, 1, 0);
           rooms_in_bat_layout->addWidget(room7, 1, 1);
           rooms_in_bat_layout->addWidget(room8, 1, 2);
           rooms_in_bat_layout->setAlignment(Qt::AlignTop);
           //rooms_in_bat_layout->addStretch(100);

       QVBoxLayout *mainLayoutPage2 = new QVBoxLayout;
            mainLayoutPage2->addLayout(selectBatLayout);
            mainLayoutPage2->addLayout(rooms_in_bat_layout);

       page2->setLayout(mainLayoutPage2);


    QWidget *page3 = new QWidget;
        QGroupBox *groupCantine = new QGroupBox("Mange à la Cantine?");
                   groupCantine->setCheckable(true);
                   groupCantine->setChecked(true);
                   QCheckBox *matin = new QCheckBox(this);
                   QCheckBox *midi = new QCheckBox(this);
                   QCheckBox *soir = new QCheckBox(this);
        QFormLayout *cantineLayout = new QFormLayout;
            cantineLayout->addRow("Petit dejener: ", matin);
            cantineLayout->addRow("Dejener: ", midi);
            cantineLayout->addRow("Diner: ", soir);
        groupCantine->setLayout(cantineLayout);

        QGroupBox *groupVisite = new QGroupBox("Reçoit des visites?");
                   groupVisite->setCheckable(true);
                   groupVisite->setChecked(false);
                   QCheckBox *onePers = new QCheckBox(this);
                   QCheckBox *twoPers = new QCheckBox(this);
                   QCheckBox *manyPers = new QCheckBox(this);
                   QLineEdit *otherNb = new QLineEdit(this);
        QFormLayout *visiteLayout = new QFormLayout;
            visiteLayout->addRow("Une personne: ", onePers);
            visiteLayout->addRow("Deux personnes: ", twoPers);
            visiteLayout->addRow("Plusieurs personnes: ", manyPers);
            visiteLayout->addRow("Autre: ", otherNb);
        groupVisite->setLayout(visiteLayout);
 
        QHBoxLayout *mainLayoutPage3 = new QHBoxLayout;
            mainLayoutPage3->addWidget(groupCantine);
            mainLayoutPage3->addWidget(groupVisite);

        page3->setLayout(mainLayoutPage3);

    QWidget *page4 = new QWidget;
         QGroupBox *groupMttc = new QGroupBox("Paiement");
         QLineEdit *mttc = new QLineEdit(this);
         QFormLayout *mttcLayout = new QFormLayout;
             mttcLayout->addRow("Montant total à payer: ", mttc);
         groupMttc->setLayout(mttcLayout);

         
         QGroupBox *groupMont1 = new QGroupBox("(1) Premier versement");
              QDateEdit *dateVers1 = new QDateEdit(QDate::currentDate(), this);
                   dateVers1->setCalendarPopup(true);
                   dateVers1->setDisplayFormat(QString("dd/MM/yyyy"));
              QLineEdit *mont1 = new QLineEdit(this);
              QFormLayout *mont1Layout = new QFormLayout;
                  mont1Layout->addRow("date: ", dateVers1);
                  mont1Layout->addRow("Montant: ", mont1);
          groupMont1->setLayout(mont1Layout);


         QGroupBox *groupMont2 = new QGroupBox("(2) Deuxième versement");
              QDateEdit *dateVers2 = new QDateEdit(QDate::currentDate(), this);
                   dateVers2->setCalendarPopup(true);
                   dateVers2->setDisplayFormat(QString("dd/MM/yyyy"));
              QLineEdit *mont2 = new QLineEdit(this);
              QFormLayout *mont2Layout = new QFormLayout;
                  mont2Layout->addRow("date: ", dateVers2);
                  mont2Layout->addRow("Montant: ", mont2);
          groupMont2->setLayout(mont2Layout);


          QGroupBox *groupMont3 = new QGroupBox("(3) Troisième versement");
              QDateEdit *dateVers3 = new QDateEdit(QDate::currentDate(), this);
                   dateVers3->setCalendarPopup(true);
                   dateVers3->setDisplayFormat(QString("dd/MM/yyyy"));
              QLineEdit *mont3 = new QLineEdit(this);
              QFormLayout *mont3Layout = new QFormLayout;
                  mont3Layout->addRow("date: ", dateVers3);
                  mont3Layout->addRow("Montant: ", mont3);
          groupMont3->setLayout(mont3Layout);
 
         
          QGroupBox *groupMont4 = new QGroupBox("(4) Quatrième versement");
              QDateEdit *dateVers4 = new QDateEdit(QDate::currentDate(), this);
                   dateVers4->setCalendarPopup(true);
                   dateVers4->setDisplayFormat(QString("dd/MM/yyyy"));
              QLineEdit *mont4 = new QLineEdit(this);
              QFormLayout *mont4Layout = new QFormLayout;
                  mont4Layout->addRow("date: ", dateVers4);
                  mont4Layout->addRow("Montant: ", mont4);
          groupMont4->setLayout(mont4Layout);
 



         QVBoxLayout *mainLayoutPage4 = new QVBoxLayout;
            mainLayoutPage4->addWidget(groupMttc);
            mainLayoutPage4->addWidget(groupMont1);
            mainLayoutPage4->addWidget(groupMont2);
            mainLayoutPage4->addWidget(groupMont3);
            mainLayoutPage4->addWidget(groupMont4);
    page4->setLayout(mainLayoutPage4);




    onglets->addTab(page1, "Informations personnelles");
    onglets->addTab(page2, "Chambre");
    onglets->addTab(page3, "Divers");
    onglets->addTab(page4, "Paiements");

    
    QHBoxLayout *btnLayout = new QHBoxLayout;
    btnLayout->addWidget(m_okBtn);
    btnLayout->addWidget(m_cancelBtn);
    btnLayout->setAlignment(Qt::AlignRight);


    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(listForm);
    mainLayout->addWidget(onglets);
    mainLayout->addLayout(btnLayout);

    resize(800, 500);
    setWindowTitle("Nouveau resident - IRM ");
    setLayout(mainLayout);
    
    QObject::connect(m_okBtn, SIGNAL(clicked()), this, SLOT(accept()));
    QObject::connect(m_cancelBtn, SIGNAL(clicked()), this, SLOT(reject()));
}

void ResidentDialog::saveNewResident() {
      QSqlQuery queryNr;
      queryNr.prepare("INSERT INTO resident(resident_nom, resident_prenom, resident_date_naissance, resident_email, resident_phone_number, resident_phone_number2, resident_phone_number3, resident_lieu_naissance, resident_genre, resident_taille, resident_matricule)" 
                            "VALUES (:nom, :prenom, :dateNais, :email, :phone1, :phone2, :phone3, :lieuNais, :genre, :taille, :matricule)");
            
            queryNr.bindValue(":nom", m_nom->text());
            queryNr.bindValue(":prenom", m_prenom->text());
            queryNr.bindValue(":dateNais", m_dateNaissance->date().toString("dd/MM/yyyy"));
            queryNr.bindValue(":email", m_email->text());
            queryNr.bindValue(":phone1", m_telephone1->text());
            queryNr.bindValue(":phone2", m_telephone2->text());
            queryNr.bindValue(":phone3", m_telephone3->text());
            queryNr.bindValue(":lieuNais", m_lieuNaissance->text());
            queryNr.bindValue(":genre", m_genre->currentText());
            queryNr.bindValue(":taille", m_taille->value());
            queryNr.bindValue(":matricule", m_matricule->text());

            if(!queryNr.exec()) 
                QMessageBox::critical(this, "Huston, we got a error :)", queryNr.lastError().text());
            else {
                
                int lid = queryNr.lastInsertId().toInt();
                //QMessageBox::information(this, "Succès!", "Nouveau resident enregistré! " + queryNr.lastInsertId().toString());                
                
                QSqlQuery queryNi;
                queryNi.prepare("SELECT resident_nom, resident_prenom FROM resident WHERE resident_id = :id");
                queryNi.bindValue(":id", lid);
                if(!queryNi.exec())
                    QMessageBox::critical(this, "Huston, we got a error :)", queryNi.lastError().text());
                else {
                    QSqlRecord result = queryNi.record();
                    if(!result.isEmpty()) {
                        while(queryNi.next()) {
                            QString sni = queryNi.value(result.indexOf("resident_nom")).toString();
                            sni += " " + queryNi.value(result.indexOf("resident_prenom")).toString();
                            QStandardItem *nii = new QStandardItem(sni);
                            nii->setEditable(false);
                            nii->setIcon(QIcon("img/user-icon.png"));
                            ex_nomModel->appendRow(nii);
                        }
                    }
                }

            }


}
