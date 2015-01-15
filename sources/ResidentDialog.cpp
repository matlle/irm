#include "ResidentDialog.h"
#include "pages.h"
#include "common.h"
#include "photopreview.h"

QString *ex_photoName = new QString();

ResidentDialog::ResidentDialog(QWidget *parent = 0): QDialog(parent) {
    
    m_typeResident = new QComboBox(this);
        updateTypeResidentComboBox();

    QFormLayout *listForm = new QFormLayout;
    listForm->addRow("Groupe: ", m_typeResident);

    m_okBtn = new QPushButton("Ok");
    m_okBtn->setIcon(QIcon("img/apply.png"));
    m_cancelBtn = new QPushButton("Annuler");
    m_cancelBtn->setIcon(QIcon("img/button_cancel.png"));
    QTabWidget *onglets = new QTabWidget(this);

    // tab1
    QWidget *page1 = new QWidget;
        m_btnPhoto = new QPushButton; 
                     m_btnPhoto->setIcon(QIcon("img/user-icon.png"));
                     m_btnPhoto->setIconSize(QSize(200, 200));
        QVBoxLayout *photoLayout = new QVBoxLayout;
                     photoLayout->addWidget(m_btnPhoto);
        QGroupBox *groupPhoto = new QGroupBox("Photo");
        groupPhoto->setLayout(photoLayout);

        m_nom = new QLineEdit(this);
        m_prenom = new QLineEdit(this);
        m_dateNaissance = new QDateEdit(this);
                   m_dateNaissance->setCalendarPopup(true);
                   m_dateNaissance->setDisplayFormat(QString("dd/MM/yyyy"));
        m_lieuNaissance = new QLineEdit(this);
        m_profession = new QLineEdit(this);
        m_genre = new QComboBox(this);
                   m_genre->addItem("Homme");
                   m_genre->addItem("Femme");
        m_taille = new QSpinBox(this);
                  m_taille->setRange(1, 300);
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
        infosForm->addRow("Profession: ", m_profession);
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


    // tab2
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

    // tab3
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

    // tab4
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
    
    QObject::connect(m_btnPhoto, SIGNAL(clicked()), this, SLOT(selectPhoto()));
    QObject::connect(m_okBtn, SIGNAL(clicked()), this, SLOT(accept()));
    QObject::connect(m_cancelBtn, SIGNAL(clicked()), this, SLOT(reject()));
}




ResidentDialog::ResidentDialog(QVariantList listInfos, QWidget *parent = 0): QDialog(parent) {
    
    m_typeResident = new QComboBox(this);
        updateTypeResidentComboBox();

    if(!listInfos[16].isNull() && !listInfos[16].toInt() == 0 && !listInfos[16].toString().isEmpty()) {

             int etrid = listInfos[16].toInt();
             QString trname;
             QSqlQuery queryTrid;
              queryTrid.prepare("SELECT type_resident_name FROM type_resident WHERE type_resident_id = :etrid");
              queryTrid.bindValue(":etrid", etrid);
              if(!queryTrid.exec())
                  QMessageBox::critical(this, "Huston, we got a error :)", queryTrid.lastError().text());
              else {
                  QSqlRecord  tre = queryTrid.record();
                  if(!tre.isEmpty()) {
                      while(queryTrid.next()) {
                          trname = queryTrid.value(tre.indexOf("type_resident_name")).toString();
                      }
                  }

              }

        int myInt = m_typeResident->findText(trname);
        m_typeResident->setCurrentIndex(myInt);

    } 
     


    QFormLayout *listForm = new QFormLayout;
    listForm->addRow("Groupe: ", m_typeResident);

    m_okBtn = new QPushButton("Ok");
    m_okBtn->setIcon(QIcon("img/apply.png"));
    m_cancelBtn = new QPushButton("Annuler");
    m_cancelBtn->setIcon(QIcon("img/button_cancel.png"));
    QTabWidget *onglets = new QTabWidget(this);

    QWidget *page1 = new QWidget;
        m_photoname = new QString();
        m_btnPhoto = new QPushButton; 
                     if(!listInfos[14].isNull() && !listInfos[14].toString().isEmpty()) {
                         m_btnPhoto->setIcon(QIcon(listInfos[14].toString()));
                         *m_photoname =  QString(listInfos[14].toString());
                     } else
                         m_btnPhoto->setIcon(QIcon("img/user-icon.png"));

                     m_btnPhoto->setIconSize(QSize(200, 200));
        QVBoxLayout *photoLayout = new QVBoxLayout;
                     photoLayout->addWidget(m_btnPhoto);
        QGroupBox *groupPhoto = new QGroupBox("Photo");
        groupPhoto->setLayout(photoLayout);

        m_nom = new QLineEdit(listInfos[1].toString(), this);

        m_prenom = new QLineEdit(listInfos[2].toString(), this);

        // recreate a date object :)
        QString sdate = listInfos[13].toString();
        QStringList ldate = sdate.split("/");
        int y = ldate[2].toInt();
        int m = ldate[1].toInt();
        int d = ldate[0].toInt();
        QDate nd = QDate(y, m, d);
        m_dateNaissance = new QDateEdit(nd, this);
                   m_dateNaissance->setCalendarPopup(true);
                   m_dateNaissance->setDisplayFormat(QString("dd/MM/yyyy"));

        m_lieuNaissance = new QLineEdit(listInfos[7].toString(), this);
        m_profession = new QLineEdit(listInfos[15].toString(), this);

        m_genre = new QComboBox(this);
                   m_genre->addItem("Homme");
                   m_genre->addItem("Femme");
                   if(listInfos[8].toString() == "Homme")
                       m_genre->setCurrentIndex(0);
                   else if(listInfos[8].toString() == "Femme")
                       m_genre->setCurrentIndex(1);

        m_taille = new QSpinBox(this);
                  m_taille->setRange(1, 300);
                  m_taille->setValue(listInfos[9].toInt());

        m_matricule = new QLineEdit(listInfos[10].toString(), this);

        m_telephone1 = new QLineEdit(listInfos[4].toString(), this);
            m_telephone1->setInputMask(QString("99-99-99-99"));

        m_telephone2 = new QLineEdit(listInfos[11].toString(), this); 
            m_telephone2->setInputMask(QString("99-99-99-99"));

        m_telephone3 = new QLineEdit(listInfos[12].toString(), this);
            m_telephone3->setInputMask(QString("99-99-99-99"));

        m_email = new QLineEdit(listInfos[3].toString(), this);

        QFormLayout *infosForm = new QFormLayout;
        infosForm->addRow("Nom: ", m_nom);
        infosForm->addRow("Prenom: ", m_prenom);
        infosForm->addRow("Date de naissance: ", m_dateNaissance);
        infosForm->addRow("Lieu de naissance: ", m_lieuNaissance);
        infosForm->addRow("Profession: ", m_profession);
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
    setWindowTitle("Modifier resident - IRM ");
    setLayout(mainLayout);
    
    QObject::connect(m_btnPhoto, SIGNAL(clicked()), this, SLOT(selectPhoto()));
    QObject::connect(m_okBtn, SIGNAL(clicked()), this, SLOT(accept()));
    QObject::connect(m_cancelBtn, SIGNAL(clicked()), this, SLOT(reject()));
}






void ResidentDialog::updateTypeResidentComboBox() {

         QSqlQuery query("SELECT type_resident_id, type_resident_name FROM type_resident");
         if(query.lastError().isValid())
             QMessageBox::critical(this, "Error", query.lastError().text());
         else {
             QSqlRecord results = query.record();
             if(!results.isEmpty()) {
                 while(query.next()) {
                     QString trname = query.value(results.indexOf("type_resident_name")).toString();
                     //QStandardItem *ni = new QStandardItem(rn);
                     //ni->setAccessibleText(query.value(results.indexOf("type_resident_id")).toString());
                     
                     m_typeResident->addItem(trname);

                }
             }
        }

}




void ResidentDialog::saveNewResident() {

      if(!m_nom->text().isEmpty()) {
      
          QString trcname = m_typeResident->currentText();
          int ttrid = 0;

          if(!trcname.isNull() && !trcname.isEmpty()) {
              QSqlQuery queryTrid;
              queryTrid.prepare("SELECT type_resident_id FROM type_resident WHERE type_resident_name = :trname");
              queryTrid.bindValue(":trname", trcname);
              if(!queryTrid.exec())
                  QMessageBox::critical(this, "Huston, we got a error :)", queryTrid.lastError().text());
              else {
                  QSqlRecord  tre = queryTrid.record();
                  if(!tre.isEmpty()) {
                      while(queryTrid.next()) {
                          ttrid = queryTrid.value(tre.indexOf("type_resident_id")).toInt();
                      }
                  }

              }
          }



      QSqlQuery queryNr;
      queryNr.prepare("INSERT INTO resident(resident_nom, resident_prenom, resident_date_naissance, resident_profession, resident_email, resident_phone_number, resident_phone_number2, resident_phone_number3, resident_lieu_naissance, resident_genre, resident_taille, resident_matricule, resident_photo_name, type_resident_id)" 
                            "VALUES (:nom, :prenom, :dateNais, :prof, :email, :phone1, :phone2, :phone3, :lieuNais, :genre, :taille, :matricule, :photo, :trid)");
            
            queryNr.bindValue(":nom", m_nom->text());
            queryNr.bindValue(":prenom", m_prenom->text());
            queryNr.bindValue(":dateNais", m_dateNaissance->date().toString("dd/MM/yyyy"));
            queryNr.bindValue(":prof", m_profession->text());
            queryNr.bindValue(":email", m_email->text());
            queryNr.bindValue(":phone1", m_telephone1->text());
            queryNr.bindValue(":phone2", m_telephone2->text());
            queryNr.bindValue(":phone3", m_telephone3->text());
            queryNr.bindValue(":lieuNais", m_lieuNaissance->text());
            queryNr.bindValue(":genre", m_genre->currentText());
            queryNr.bindValue(":taille", m_taille->value());
            queryNr.bindValue(":matricule", m_matricule->text());
            queryNr.bindValue(":photo", *ex_photoName);
            queryNr.bindValue(":trid", ttrid);

            if(!queryNr.exec()) 
                QMessageBox::critical(this, "Huston, we got a error :)", queryNr.lastError().text());
            else {
                
                int lid = queryNr.lastInsertId().toInt();
                
                QSqlQuery queryNi;
                queryNi.prepare("SELECT resident_nom, resident_prenom, resident_photo_name FROM resident WHERE resident_id = :id");
                queryNi.bindValue(":id", lid);
                if(!queryNi.exec())
                    QMessageBox::critical(this, "Huston, we got a error :)", queryNi.lastError().text());
                else {
                    QSqlRecord result = queryNi.record();
                    if(!result.isEmpty()) {
                        while(queryNi.next()) {
                            QString sni = queryNi.value(result.indexOf("resident_nom")).toString();
                            sni += " " + queryNi.value(result.indexOf("resident_prenom")).toString();
                            QString nrpic = queryNi.value(result.indexOf("resident_photo_name")).toString();
                            QStandardItem *nii = new QStandardItem(sni);
                            QString ts = QString::number(lid);
                            nii->setAccessibleText(ts);
                            nii->setEditable(false);
                            if(!nrpic.isNull() && !nrpic.isEmpty())
                                nii->setIcon(QIcon(nrpic));
                            else
                                nii->setIcon(QIcon("img/user-icon.png"));

                            ex_nomModel->appendRow(nii);
                        }
                    }
                }
                //queryNi.finish();
             *ex_photoName = ""; 
             QMessageBox::information(this, "Succès", "Resident enregistré!");

            }

  } else {
      QMessageBox::critical(this, "Erreur - Le nouveau resident n'a pu être enregistré", "Vous devez saisir au moins le nom du resident");
  }

}





void ResidentDialog::remove_old_photo(int reid) {

              QSqlQuery queryPhoto;
              queryPhoto.prepare("SELECT resident_photo_name FROM resident WHERE resident_id = :tid");
              queryPhoto.bindValue(":tid", reid);
              if(!queryPhoto.exec())
                  QMessageBox::critical(this, "Huston, we got a problem...", "Impossible d'obetenir l'anciene photo du resident");
              QSqlRecord resphoto = queryPhoto.record();
              if(!resphoto.isEmpty()) {
                  while(queryPhoto.next()) {
                      QString picname = queryPhoto.value(resphoto.indexOf("resident_photo_name")).toString();
                      if(!picname.isNull() && !picname.isEmpty()) {
                          QFile picFile(picname, this);
                          if(!picFile.remove())
                              QMessageBox::warning(this, "Huston, we got a problem...", "Erreur lors de la suppression de l'anciene photo du resident\n" + picname);
                      }
                 }
              }

}




QModelIndex ResidentDialog::saveEditedResident(const QModelIndex &ind, int rid) {

      if(!m_nom->text().isEmpty()) {

              int ttrid = 0;      
              QSqlQuery queryTrid;
              queryTrid.prepare("SELECT type_resident_id FROM type_resident WHERE type_resident_name = :trname");
              queryTrid.bindValue(":trname", m_typeResident->currentText());
              if(!queryTrid.exec())
                  QMessageBox::critical(this, "Huston, we got a error :)", queryTrid.lastError().text());
              else {
                  QSqlRecord  tre = queryTrid.record();
                  if(!tre.isEmpty()) {
                      while(queryTrid.next()) {
                          ttrid = queryTrid.value(tre.indexOf("type_resident_id")).toInt();
                      }
                  }

              }


          
      QSqlQuery queryNr;
      queryNr.prepare("UPDATE resident \
                       SET resident_nom = :nom, \
                           resident_prenom = :prenom, \
                           resident_date_naissance = :dateNais, \
                           resident_profession = :prof, \
                           resident_email = :email, \
                           resident_phone_number = :phone1, \ 
                           resident_phone_number2 = :phone2, \
                           resident_phone_number3 = :phone3, \
                           resident_lieu_naissance = :lieuNais, \
                           resident_genre = :genre, \
                           resident_taille = :taille, \
                           resident_matricule = :matricule, \
                           resident_photo_name = :photo, \
                           type_resident_id = :trid \
                       WHERE resident_id = :rid");
            
            queryNr.bindValue(":rid", rid);
            queryNr.bindValue(":nom", m_nom->text());
            queryNr.bindValue(":prenom", m_prenom->text());
            queryNr.bindValue(":dateNais", m_dateNaissance->date().toString("dd/MM/yyyy"));
            queryNr.bindValue(":prof", m_profession->text());
            queryNr.bindValue(":email", m_email->text());
            queryNr.bindValue(":phone1", m_telephone1->text());
            queryNr.bindValue(":phone2", m_telephone2->text());
            queryNr.bindValue(":phone3", m_telephone3->text());
            queryNr.bindValue(":lieuNais", m_lieuNaissance->text());
            queryNr.bindValue(":genre", m_genre->currentText());
            queryNr.bindValue(":taille", m_taille->value());
            queryNr.bindValue(":matricule", m_matricule->text());
            queryNr.bindValue(":trid", ttrid);

            if(!ex_photoName->isNull() && !ex_photoName->isEmpty()) {
                queryNr.bindValue(":photo", *ex_photoName);
                remove_old_photo(rid);
            }
            else if(!m_photoname->isNull() && !m_photoname->isEmpty())
                queryNr.bindValue(":photo", *m_photoname);

            QModelIndex nIndex;
            if(!queryNr.exec()) 
                QMessageBox::critical(this, "Huston, we got a error :)", queryNr.lastError().text());
            else {
                       
                
                QSqlQuery queryUi;
                queryUi.prepare("SELECT resident_nom, resident_prenom, resident_photo_name FROM resident WHERE resident_id = :id");
                queryUi.bindValue(":id", rid);
                if(!queryUi.exec())
                    QMessageBox::critical(this, "Huston, we got a error :)", queryUi.lastError().text());
                else {
                    QSqlRecord result = queryUi.record();
                    if(!result.isEmpty()) {
                        while(queryUi.next()) {
                            QString sui = queryUi.value(result.indexOf("resident_nom")).toString();
                            sui += " " + queryUi.value(result.indexOf("resident_prenom")).toString();
                            QString rpicn = queryUi.value(result.indexOf("resident_photo_name")).toString();
                            QStandardItem *uii = new QStandardItem(sui);
                            QString ts = QString::number(rid);
                            uii->setAccessibleText(ts);
                            uii->setEditable(false);
                            if(!rpicn.isNull() && !rpicn.isEmpty())
                                uii->setIcon(QIcon(rpicn));
                            else
                                uii->setIcon(QIcon("img/user-icon.png"));
                            

                            QModelIndex mindex = ex_proxyModel->mapToSource(ind);
                            QStandardItem *oitem = ex_nomModel->itemFromIndex(mindex);
                            int oitemRow = oitem->row();
            
                            ex_nomModel->removeRow(oitemRow);
                            ex_nomModel->appendRow(uii);

                            //nIndex = ex_nomModel->indexFromItem(uii);
                            nIndex = uii->index();
                        }

                    }
                }
             *ex_photoName = ""; 

            }
           
            return nIndex;
   
  } else {
      QMessageBox::critical(this, "Erreur - Le resident n'a pu être modifié", "Vous devez saisir au moins le nom du resident");
  }
 
}


void ResidentDialog::selectPhoto() {
    QString photoFileName = QFileDialog::getOpenFileName(this, "Sélectioner une photo", "/home", "Images (*.png *.jpg *jpeg)");

    if(!photoFileName.isNull()) {
        QImage image(photoFileName);
        if(image.isNull()) {
            QMessageBox::warning(this, "Sélectioner une photo", "Impossible d'ouvrir le fichier ' " + photoFileName + " '");
            return;
        }
        
        QImage imageScaled = image.scaledToHeight(250);

        PhotoPreview *pp = new PhotoPreview(QPixmap::fromImage(imageScaled), this); 
        int ret = pp->exec();

        QString nuid = QUuid::createUuid().toString();
        nuid.replace(QString("{"), QString(""));
        nuid.replace(QString("}"), QString(""));
        nuid.replace(QString("-"), QString("_"));
        int randid = qrand();
        nuid += "_" + QString::number(randid);
        
        QString nicon = "img/uploads/userphoto/" + nuid + ".png";
        
        if(ret == Accepted) {
            QImageWriter writer(nicon, "png");
            writer.setQuality(100);

            if(!writer.write(imageScaled)) {
                QMessageBox::critical(this, "Sélectioner une photo", writer.errorString());
            }

            m_btnPhoto->setIcon(QIcon(nicon));
            *ex_photoName = nicon;
        }

    }

}
