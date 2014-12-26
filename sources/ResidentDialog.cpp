#include "ResidentDialog.h"

ResidentDialog::ResidentDialog(QWidget *parent = 0): QDialog(parent) {
    
    m_typeResident = new QComboBox(this);
    m_typeResident->addItem("Edutiant");
    m_typeResident->addItem("Professionel");
    m_typeResident->addItem("Autres");

    QFormLayout *listForm = new QFormLayout;
    listForm->addRow("Ajouter à: ", m_typeResident);

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

        QLineEdit *nom = new QLineEdit;
        QLineEdit *prenom = new QLineEdit;
        QDateEdit *dateNaissance = new QDateEdit;
                   dateNaissance->setCalendarPopup(true);
                   dateNaissance->setDisplayFormat(QString("dd/MM/yyyy"));
        QLineEdit *lieuNaissance = new QLineEdit;
        QComboBox *genre = new QComboBox(this);
                   genre->addItem("Homme");
                   genre->addItem("Femme");
        QSpinBox *taille = new QSpinBox;
                  taille->setMaximum(300);
        QLineEdit *matricule = new QLineEdit;

        QFormLayout *infosForm = new QFormLayout;
        infosForm->addRow("Nom: ", nom);
        infosForm->addRow("Prenom: ", prenom);
        infosForm->addRow("Date de naissance: ", dateNaissance);
        infosForm->addRow("Lieu de naissance: ", lieuNaissance);
        infosForm->addRow("Genre: ", genre);
        infosForm->addRow("Taille (cm): ", taille);
        infosForm->addRow("Matricule: ", matricule);

        QGroupBox *groupInfos = new QGroupBox("Informations");
        groupInfos->setLayout(infosForm);

        QHBoxLayout *mainLayoutPage1 = new QHBoxLayout;
        mainLayoutPage1->addWidget(groupInfos);
        mainLayoutPage1->addWidget(groupPhoto);

        page1->setLayout(mainLayoutPage1);


    QWidget *page2 = new QWidget;
    QWidget *page3 = new QWidget;
    QWidget *page4 = new QWidget;
    QWidget *page5 = new QWidget;

    onglets->addTab(page1, "Informations personnelles");
    onglets->addTab(page2, "Chambre");
    onglets->addTab(page3, "Divers");
    onglets->addTab(page4, "Informations personnelles");
    onglets->addTab(page5, "Informations personnelles");

    
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
    
    QObject::connect(m_cancelBtn, SIGNAL(clicked()), this, SLOT(accept()));
}
