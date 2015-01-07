#include "pages.h"
#include "Window.h"
#include "ResidentDialog.h"
#include "common.h"
#include "DBFactory.h"

QSortFilterProxyModel *ex_proxyModel;
QStandardItemModel *ex_nomModel;

ResidentPage::ResidentPage(QWidget *parent): QWidget(parent) {
     QSqlDatabase db = DBFactory::getConnection(this); 
     QSplitter *splitter = new QSplitter(this);

     QTreeView *typeResident = new QTreeView;
         QStandardItemModel *typeModel = new QStandardItemModel;
         QStandardItem *type1 = new QStandardItem("Etudiant");
                        type1->setCheckable(true);
         QStandardItem *type2 = new QStandardItem("Professionnel");
                        type2->setCheckable(true);
         QStandardItem *type3 = new QStandardItem("Autre");
                        type3->setCheckable(true);
         typeModel->appendRow(type1);
         typeModel->appendRow(type2);
         typeModel->appendRow(type3);
         typeModel->setHorizontalHeaderLabels(QStringList("Type Resident"));

         typeResident->setModel(typeModel);
         typeResident->setMinimumWidth(130);

     m_residentName = new QTreeView(this);
         ex_nomModel = new QStandardItemModel(this);
         ex_proxyModel = new QSortFilterProxyModel(this);

         QSqlQuery query("SELECT resident_id, resident_nom, resident_prenom, resident_photo_name FROM resident");
         if(query.lastError().isValid())
             QMessageBox::critical(this, "Error", query.lastError().text());
         else {
             QSqlRecord results = query.record();
             if(!results.isEmpty()) {
                 while(query.next()) {
                     QString rphoto = query.value(results.indexOf("resident_photo_name")).toString(); 
                     QString rn = query.value(results.indexOf("resident_nom")).toString();
                             rn += " " + query.value(results.indexOf("resident_prenom")).toString();
                     QStandardItem *ni = new QStandardItem(rn);
                     ni->setAccessibleText(query.value(results.indexOf("resident_id")).toString());
                     ni->setEditable(false);
                     if(!rphoto.isNull() && !rphoto.isEmpty())
                         ni->setIcon(QIcon(rphoto));
                     else
                         ni->setIcon(QIcon("img/user-icon.png"));
                     ex_nomModel->appendRow(ni);
                }
             }
        }

        // updateResidentList(); 

         ex_nomModel->setHorizontalHeaderLabels(QStringList("Nom Resident"));

         ex_proxyModel->setSourceModel(ex_nomModel);
         ex_proxyModel->setFilterCaseSensitivity(Qt::CaseInsensitive);
         ex_proxyModel->setDynamicSortFilter(true);

         m_residentName->setModel(ex_proxyModel);
         m_residentName->setIndentation(0);
         m_residentName->setMinimumWidth(130);
         m_residentName->setSortingEnabled(true);
         m_residentName->setAlternatingRowColors(true);
         
         QObject::connect(m_residentName, SIGNAL(activated(QModelIndex)), this, SLOT(showEdit(QModelIndex)));
         QObject::connect(m_residentName, SIGNAL(clicked(QModelIndex)), this, SLOT(showResidentInfos(QModelIndex)));

     QWidget *infosResident = new QWidget(this);
         m_textInfos = new QLabel(this);
                 //textInfos->setText(QString("Informations: de la diaspora\nPays: Unknown\nSituation: Critical..."));
                 m_textInfos->setAlignment(Qt::AlignLeft);
                 m_textInfos->setIndent(20);
         m_picResident = new QLabel(this);
                 m_picResident->setAlignment(Qt::AlignLeft | Qt::AlignTop);
                 m_picResident->setMaximumHeight(250);
                 //picResident->setMaximumWidth(221);
         m_nameResident = new QLabel(this);
                 m_nameResident->setFont(QFont("DejaVu Sans", 18, QFont::Bold));
                 m_nameResident->setAlignment(Qt::AlignLeft | Qt::AlignTop);
         QVBoxLayout *picnameLayout = new QVBoxLayout;
                      picnameLayout->addWidget(m_picResident);
                      picnameLayout->addWidget(m_nameResident);
         QHBoxLayout *infosLayout = new QHBoxLayout;
             infosLayout->addSpacing(30);
             infosLayout->addLayout(picnameLayout);
             infosLayout->addWidget(m_textInfos);
             infosLayout->addStretch(58);
         infosResident->setStyleSheet("background-color: white;");
         infosResident->resize(1100, infosResident->height());
         infosResident->setLayout(infosLayout);

     splitter->addWidget(typeResident);
     splitter->addWidget(m_residentName);
     splitter->addWidget(infosResident);

     QHBoxLayout *mainLayout = new QHBoxLayout;
     mainLayout->addWidget(splitter);
     setLayout(mainLayout);
     
 }

void ResidentPage::showEdit(const QModelIndex &pro_index) {
    QModelIndex model_index = ex_proxyModel->mapToSource(pro_index);
    QStandardItem *item = ex_nomModel->itemFromIndex(model_index);
    int rid = item->accessibleText().toInt();
    if(item != 0) {
        QString rsname = item->text();
        QStringList list = rsname.split(" ");
        QString nom = (QString) list.first();
        QVariantList v;
        QSqlQuery querySr;
        querySr.prepare("SELECT * FROM resident WHERE resident_id = :id");
        querySr.bindValue(":id", rid);
        if(!querySr.exec())
            QMessageBox::critical(this, "Huston, we've a problem... :)", querySr.lastError().text());
        else {
            QSqlRecord resInfos = querySr.record();
            if(!resInfos.isEmpty()) {
                while(querySr.next()) {
                       v << querySr.value(resInfos.indexOf("resident_id")); // 0
                       v << querySr.value(resInfos.indexOf("resident_nom")); // 1
                       v << querySr.value(resInfos.indexOf("resident_prenom")); // 2
                       v << querySr.value(resInfos.indexOf("resident_email")); // 3
                       v << querySr.value(resInfos.indexOf("resident_phone_number")); // 4
                       v << querySr.value(resInfos.indexOf("type_resident_id")); // 5
                       v << querySr.value(resInfos.indexOf("resident_photo_name")); // 6
                       v << querySr.value(resInfos.indexOf("resident_lieu_naissance")); // 7
                       v << querySr.value(resInfos.indexOf("resident_genre")); // 8
                       v << querySr.value(resInfos.indexOf("resident_taille")); // 9
                       v << querySr.value(resInfos.indexOf("resident_matricule")); // 10
                       v << querySr.value(resInfos.indexOf("resident_phone_number2")); // 11
                       v << querySr.value(resInfos.indexOf("resident_phone_number3")); // 12
                       v << querySr.value(resInfos.indexOf("resident_date_naissance")); // 13
                       v << querySr.value(resInfos.indexOf("resident_photo_name")); // 14
                }
            }
        }
          
        
        ResidentDialog *editResident = new ResidentDialog(v, this);
        int intret = editResident->exec();
        if (intret == QDialog::Accepted) {
            editResident->saveEditedResident(rid);
        }else if(intret == QDialog::Rejected) {
            if(!ex_photoName->isNull() && !ex_photoName->isEmpty()) {
                QFile photoFile(*ex_photoName, this);
                if(!photoFile.remove())
                    QMessageBox::warning(this, "Huston, we got a problem...", "Erreur de suppression du fichier temporaire\n " + *ex_photoName);
                *ex_photoName = "";
            }
        }

    }
}


/*void ResidentPage::updateResidentList() {
    QSqlQuery query("SELECT resident_nom FROM resident");
         if(query.lastError().isValid())
             QMessageBox::critical(this, "Error", query.lastError().text());
         else {
             QSqlRecord results = query.record();
             if(!results.isEmpty()) {
                 while(query.next()) {
                    QStandardItem  *ni =  new QStandardItem(query.value(results.indexOf("resident_nom")).toString());
                    ni->setEditable(false);
                    ni->setIcon(QIcon("img/user-icon.png"));
                     ex_nomModel->appendRow(ni);
                 }
             }
        }


}*/




void ResidentPage::contextMenuEvent(QContextMenuEvent *event) {

    QMenu ResMenu(this);
        QAction *actionEditResi = new QAction("Modifier resident", this);
            actionEditResi->setStatusTip("Apporter des modification au resident selectioné");
            actionEditResi->setIcon(QIcon("img/edit.png"));
        QAction *actionDelResi = new QAction("Supprimer resident", this);
            actionDelResi->setIcon(QIcon("img/button_cancel.png"));
            actionDelResi->setStatusTip("Supprimer definitivement le resident selectioné du logiciel");

    ResMenu.addAction(actionNewResident);
    ResMenu.addAction(actionNewTypeResident);
    ResMenu.addSeparator();
    ResMenu.addAction(actionNewChambre);
    ResMenu.addAction(actionNewBatiment);
    ResMenu.addSeparator();
    ResMenu.addAction(actionEditResi);
    ResMenu.addAction(actionDelResi);
    ResMenu.exec(event->globalPos());
}


void ResidentPage::showResidentInfos(const QModelIndex &pindex) {
    QModelIndex model_index = ex_proxyModel->mapToSource(pindex);
    QStandardItem *item = ex_nomModel->itemFromIndex(model_index);
    int rid = item->accessibleText().toInt();
    
    QSqlQuery queryRi;
        queryRi.prepare("SELECT * FROM resident WHERE resident_id = :id");
        queryRi.bindValue(":id", rid);
    if(!queryRi.exec())
        QMessageBox::critical(this, "Huston, we've a problem... :)", queryRi.lastError().text());
    
     QSqlRecord resRi = queryRi.record();
         if(!resRi.isEmpty()) {
             while(queryRi.next()) {
                 QString rname = queryRi.value(resRi.indexOf("resident_nom")).toString(); 
                 QString rprenom = queryRi.value(resRi.indexOf("resident_prenom")).toString(); 
                 QString rdnais = queryRi.value(resRi.indexOf("resident_date_naissance")).toString(); 
                 QString rlnais = queryRi.value(resRi.indexOf("resident_lieu_naissance")).toString(); 
                 QString rgenre = queryRi.value(resRi.indexOf("resident_genre")).toString(); 
                 int rtaille = queryRi.value(resRi.indexOf("resident_taille")).toInt(); 
                 QString rphone1 = queryRi.value(resRi.indexOf("resident_phone_number")).toString(); 
                 QString rphone2 = queryRi.value(resRi.indexOf("resident_phone_number2")).toString(); 
                 QString rphone3 = queryRi.value(resRi.indexOf("resident_phone_number3")).toString(); 
                 QString remail = queryRi.value(resRi.indexOf("resident_email")).toString(); 
                 QString rmatricule = queryRi.value(resRi.indexOf("resident_matricule")).toString(); 
                 QString rpic = queryRi.value(resRi.indexOf("resident_photo_name")).toString(); 

                 if(!rpic.isNull() && !rpic.isEmpty())
                     m_picResident->setPixmap(QPixmap(rpic));
                 else
                     m_picResident->setPixmap(QPixmap("img/user-icon.png"));
                 
                 m_nameResident->setText(QString(rname));
                 QString inf = "<span style='color: gray;'><b>Nom:</b></span>  ";
                 inf += rname;
                 inf += "<br/>";

                 if(!rprenom.isNull() && !rprenom.isEmpty()) {
                     inf += "<span style='color: gray;'><b>Prenom:</b></span>  ";
                     inf += rprenom;
                     inf += "<br/>";
                 }
                 
                 if(!rdnais.isNull() && !rdnais.isEmpty()) {
                     inf += "<span style='color: gray;'><b>Date de naissance:</b></span>  ";
                     inf += rdnais;
                     inf += "<br/>";
                 }

                 if(!rlnais.isNull() && !rlnais.isEmpty()) {
                     inf += "<span style='color: gray;'><b>Lieu de naissance:</b></span>  ";
                     inf += rlnais;
                     inf += "<br/>";
                 }

                 if(!rgenre.isNull() && !rgenre.isEmpty()) {
                     inf += "<span style='color: gray;'><b>Genre:</b></span>  ";
                     inf += rgenre;
                     inf += "<br/>";
                 }
 
                 if(rtaille > 1) {
                     inf += "<span style='color: gray;'><b>Taille:</b></span>  ";
                     inf += QString::number(rtaille) + " cm";
                     inf += "<br/>";
                 }

                 if(!rphone1.isNull() && !rphone1.isEmpty() && rphone1 != "---") {
                     inf += "<span style='color: gray;'><b>Téléphone1:</b></span>  ";
                     inf += rphone1;
                     inf += "<br/>";
                 }

                 if(!rphone2.isNull() && !rphone2.isEmpty() && rphone2 != "---") {
                     inf += "<span style='color: gray;'><b>Téléphone2:</b></span>  ";
                     inf += rphone2;
                     inf += "<br/>";
                 }

                 if(!rphone3.isNull() && !rphone3.isEmpty() && rphone3 != "---") {
                     inf += "<span style='color: gray;'><b>Téléphone3:</b></span>  ";
                     inf += rphone3;
                     inf += "<br/>";
                 }

                 if(!remail.isNull() && !remail.isEmpty()) {
                     inf += "<span style='color: gray;'><b>Email:</b></span>  ";
                     inf += remail;
                     inf += "<br/>";
                 }

                 if(!rmatricule.isNull() && !rmatricule.isEmpty()) {
                     inf += "<span style='color: gray;'><b>Matricule:</b></span>  ";
                     inf += rmatricule;
                     inf += "<br/>";
                 }




                 m_textInfos->setText(QString(inf));
                 QFont myfont = QFont("DejaVu Sans", 12, 40); 
                 m_textInfos->setFont(myfont);
             }
         }


}





/* <========================= End ResidentPage =============================> */



UpdatePage::UpdatePage(QWidget *parent)
     : QWidget(parent)
 {
     QGroupBox *updateGroup = new QGroupBox(tr("Package selection"));
     QCheckBox *systemCheckBox = new QCheckBox(tr("Update system"));
     QCheckBox *appsCheckBox = new QCheckBox(tr("Update applications"));
     QCheckBox *docsCheckBox = new QCheckBox(tr("Update documentation"));

     QGroupBox *packageGroup = new QGroupBox(tr("Existing packages"));

     QListWidget *packageList = new QListWidget;
     QListWidgetItem *qtItem = new QListWidgetItem(packageList);
     qtItem->setText(tr("Qt"));
     QListWidgetItem *qsaItem = new QListWidgetItem(packageList);
     qsaItem->setText(tr("QSA"));
     QListWidgetItem *teamBuilderItem = new QListWidgetItem(packageList);
     teamBuilderItem->setText(tr("Teambuilder"));

     QPushButton *startUpdateButton = new QPushButton(tr("Start update"));

     QVBoxLayout *updateLayout = new QVBoxLayout;
     updateLayout->addWidget(systemCheckBox);
     updateLayout->addWidget(appsCheckBox);
     updateLayout->addWidget(docsCheckBox);
     updateGroup->setLayout(updateLayout);

     QVBoxLayout *packageLayout = new QVBoxLayout;
     packageLayout->addWidget(packageList);
     packageGroup->setLayout(packageLayout);

     QVBoxLayout *mainLayout = new QVBoxLayout;
     mainLayout->addWidget(updateGroup);
     mainLayout->addWidget(packageGroup);
     mainLayout->addSpacing(12);
     mainLayout->addWidget(startUpdateButton);
     mainLayout->addStretch(1);
     setLayout(mainLayout);
 }

 QueryPage::QueryPage(QWidget *parent)
     : QWidget(parent)
 {
     QGroupBox *packagesGroup = new QGroupBox(tr("Look for packages"));

     QLabel *nameLabel = new QLabel(tr("Name:"));
     QLineEdit *nameEdit = new QLineEdit;

     QLabel *dateLabel = new QLabel(tr("Released after:"));
     QDateTimeEdit *dateEdit = new QDateTimeEdit(QDate::currentDate());

     QCheckBox *releasesCheckBox = new QCheckBox(tr("Releases"));
     QCheckBox *upgradesCheckBox = new QCheckBox(tr("Upgrades"));

     QSpinBox *hitsSpinBox = new QSpinBox;
     hitsSpinBox->setPrefix(tr("Return up to "));
     hitsSpinBox->setSuffix(tr(" results"));
     hitsSpinBox->setSpecialValueText(tr("Return only the first result"));
     hitsSpinBox->setMinimum(1);
     hitsSpinBox->setMaximum(100);
     hitsSpinBox->setSingleStep(10);

     QPushButton *startQueryButton = new QPushButton(tr("Start query"));

     QGridLayout *packagesLayout = new QGridLayout;
     packagesLayout->addWidget(nameLabel, 0, 0);
     packagesLayout->addWidget(nameEdit, 0, 1);
     packagesLayout->addWidget(dateLabel, 1, 0);
     packagesLayout->addWidget(dateEdit, 1, 1);
     packagesLayout->addWidget(releasesCheckBox, 2, 0);
     packagesLayout->addWidget(upgradesCheckBox, 3, 0);
     packagesLayout->addWidget(hitsSpinBox, 4, 0, 1, 2);
     packagesGroup->setLayout(packagesLayout);

     QVBoxLayout *mainLayout = new QVBoxLayout;
     mainLayout->addWidget(packagesGroup);
     mainLayout->addSpacing(12);
     mainLayout->addWidget(startQueryButton);
     mainLayout->addStretch(1);
     setLayout(mainLayout);
 }
