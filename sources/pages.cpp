#include "pages.h"
#include "Window.h"
#include "ResidentDialog.h"
#include "typeresidentdialog.h"
#include "common.h"
#include "DBFactory.h"

QSortFilterProxyModel *ex_proxyModel;
QStandardItemModel *ex_nomModel;
QStandardItemModel *ex_typeModel;
QList<QStandardItem *> *ex_items_type;

ResidentPage::ResidentPage(QWidget *parent): QWidget(parent) {
     ex_items_type = new QList<QStandardItem *>;

     QSqlDatabase db = DBFactory::getConnection(this); 
     QSplitter *splitter = new QSplitter(this);

     m_typeResident = new QTreeView;
         ex_typeModel = new QStandardItemModel;

         updateTypeResidentTree();
         
         ex_typeModel->setHorizontalHeaderLabels(QStringList("Type Resident"));

         m_typeResident->setModel(ex_typeModel);
         m_typeResident->setMinimumWidth(130);

     m_residentName = new QTreeView(this);
     m_residentName->setSelectionBehavior(QAbstractItemView::SelectItems);
     m_residentName->setSelectionMode(QAbstractItemView::SingleSelection);
         ex_nomModel = new QStandardItemModel(this);
         ex_proxyModel = new QSortFilterProxyModel(this);

         updateResidentTree();

         ex_nomModel->setHorizontalHeaderLabels(QStringList("Nom Resident"));

         ex_proxyModel->setSourceModel(ex_nomModel);
         ex_proxyModel->setFilterCaseSensitivity(Qt::CaseInsensitive);
         ex_proxyModel->setDynamicSortFilter(true);

         m_residentName->setModel(ex_proxyModel);
         m_residentName->setIndentation(0);
         m_residentName->setMinimumWidth(130);
         m_residentName->setSortingEnabled(true);
         m_residentName->setAlternatingRowColors(true);
         
         QObject::connect(actionDelResi, SIGNAL(triggered()), this, SLOT(removeResident()));
         QObject::connect(actionEditResi, SIGNAL(triggered()), this, SLOT(showEditOnEditAction()));
         QObject::connect(actionDelTypeResi, SIGNAL(triggered()), this, SLOT(removeTypeResident()));
         QObject::connect(actionEditTypeResi, SIGNAL(triggered()), this, SLOT(showEditTypeResiOnEditAction()));
         QObject::connect(ex_typeModel,SIGNAL(itemChanged(QStandardItem*)),SLOT(onItemChanged(QStandardItem*)));
         QObject::connect(m_typeResident, SIGNAL(activated(QModelIndex)), this, SLOT(showEditTypeResident(QModelIndex)));
         QObject::connect(m_residentName, SIGNAL(activated(QModelIndex)), this, SLOT(showEdit(QModelIndex)));
         QObject::connect(m_residentName, SIGNAL(clicked(QModelIndex)), this, SLOT(showResidentInfos(QModelIndex)));

     QWidget *infosResident = new QWidget(this);
         m_textInfos = new QLabel(this);
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

     splitter->addWidget(m_typeResident);
     splitter->addWidget(m_residentName);
     splitter->addWidget(infosResident);

     QHBoxLayout *mainLayout = new QHBoxLayout;
     mainLayout->addWidget(splitter);
     setLayout(mainLayout);
     
 }




void ResidentPage::showEditOnEditAction() {
    QModelIndex pro_index = m_residentName->currentIndex();
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
                       v << querySr.value(resInfos.indexOf("resident_profession")); // 15
                       v << querySr.value(resInfos.indexOf("type_resident_id")); // 16
                }
            }
        }
          
        
        ResidentDialog *editResident = new ResidentDialog(v, this);
        int intret = editResident->exec();
        if (intret == QDialog::Accepted) {
            QModelIndex ti = editResident->saveEditedResident(pro_index, rid);

            if(ti.isValid()) {
                m_residentName->setCurrentIndex(ti);
                showResidentInfos(ti);
            }


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
                       v << querySr.value(resInfos.indexOf("resident_profession")); // 15
                       v << querySr.value(resInfos.indexOf("type_resident_id")); // 16
                }
            }
        }
          
        
        ResidentDialog *editResident = new ResidentDialog(v, this);
        int intret = editResident->exec();
        if (intret == QDialog::Accepted) {
            QModelIndex ti = editResident->saveEditedResident(pro_index, rid);
            if(ti.isValid()) {
                m_residentName->setCurrentIndex(ti);
                showResidentInfos(ti);
            }

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



void ResidentPage::showEditTypeResident(const QModelIndex &type_index) {
    QStandardItem *item = ex_typeModel->itemFromIndex(type_index);
    int trid = item->accessibleText().toInt();
    if(item != 0) {
        QString rsname = item->text();
        QVariantList v;
        QSqlQuery querySr;
        querySr.prepare("SELECT * FROM type_resident WHERE type_resident_id = :id");
        querySr.bindValue(":id", trid);
        if(!querySr.exec())
            QMessageBox::critical(this, "Huston, we've a problem... :)", querySr.lastError().text());
        else {
            QSqlRecord resInfos = querySr.record();
            if(!resInfos.isEmpty()) {
                while(querySr.next()) {
                       v << querySr.value(resInfos.indexOf("type_resident_id")); // 0
                       v << querySr.value(resInfos.indexOf("type_resident_name")); // 1
                }
            }
        }
          
        
        TypeResidentDialog *editTypeResident = new TypeResidentDialog(v, this);
        int intret = editTypeResident->exec();
        if (intret == QDialog::Accepted) {
            editTypeResident->saveEditedTypeResident(type_index, trid);
            //showResidentInfos(m_residentName->currentIndex());
        }

    }
}



void ResidentPage::showEditTypeResiOnEditAction() {

    QModelIndex type_index = m_typeResident->currentIndex();
    QStandardItem *item = ex_typeModel->itemFromIndex(type_index);
    int trid = item->accessibleText().toInt();

    if(item != 0) {
        QString rsname = item->text();
        QVariantList v;
        QSqlQuery querySr;
        querySr.prepare("SELECT * FROM type_resident WHERE type_resident_id = :id");
        querySr.bindValue(":id", trid);
        if(!querySr.exec())
            QMessageBox::critical(this, "Huston, we've a problem... :)", querySr.lastError().text());
        else {
            QSqlRecord resInfos = querySr.record();
            if(!resInfos.isEmpty()) {
                while(querySr.next()) {
                       v << querySr.value(resInfos.indexOf("type_resident_id")); // 0
                       v << querySr.value(resInfos.indexOf("type_resident_name")); // 1
                }
            }
        }
          
        
        TypeResidentDialog *editTypeResident = new TypeResidentDialog(v, this);
        int intret = editTypeResident->exec();
        if (intret == QDialog::Accepted) {
            editTypeResident->saveEditedTypeResident(type_index, trid);
            //showResidentInfos(m_residentName->currentIndex());
        }

    }
}



void ResidentPage::onItemChanged(QStandardItem *item) {

    QList<int> listId;
    for(int i = 0; i < ex_items_type->size(); i++) {
        QStandardItem *titem; 
        titem = ex_items_type->at(i);
        Qt::CheckState tstate = titem->checkState();
        if(tstate == Qt::Unchecked) {
            int id = titem->accessibleText().toInt();
            listId.append(id);
        }
    }
    
    QString qs = "";
    int oInt;
    if(listId.size() == 1) {
        oInt = listId.first();
        qs += "!= " + QString::number(oInt);
    } else if(listId.size() > 1){
        qs = "";
        for(int c = 0; c < listId.size(); c++) {
            if(c + 1 == listId.size()) 
                qs += "!= " + QString::number(listId.at(c));
            else
                qs += "!= " + QString::number(listId.at(c)) + " AND type_resident_id ";

        }
    }


    //Qt::CheckState state = item->checkState();
    //if(state == Qt::Unchecked) {
       // int trid = item->accessibleText().toInt(); 

     QSqlQuery query("SELECT resident_id, resident_nom, resident_prenom, resident_photo_name FROM resident WHERE type_resident_id " + qs);
         //query.bindValue(":trid", trid);
         if(!query.exec())
             QMessageBox::critical(this, "Huston, we got a problem... :)", query.lastError().text());
         else {
             QSqlRecord results = query.record();
             delete ex_nomModel;
             ex_nomModel = new QStandardItemModel(this);
                 ex_nomModel->setHorizontalHeaderLabels(QStringList("Nom Resident"));
             if(!results.isEmpty()) {
                 while(query.next()) {

                     QString rphoto = query.value(results.indexOf("resident_photo_name")).toString(); 
                     QString rn = query.value(results.indexOf("resident_nom")).toString();
                             rn += " " + query.value(results.indexOf("resident_prenom")).toString();
                     QStandardItem *ni = new QStandardItem(rn);
                     QString tid = QString::number(query.value(results.indexOf("resident_id")).toInt());
                     ni->setAccessibleText(tid);
                     ni->setEditable(false);
                     if(!rphoto.isNull() && !rphoto.isEmpty())
                         ni->setIcon(QIcon(rphoto));
                     else
                         ni->setIcon(QIcon("img/user-icon.png"));

                     ex_nomModel->appendRow(ni);

                }
             }
             ex_proxyModel->setSourceModel(ex_nomModel);
        }


    //}



}






void ResidentPage::contextMenuEvent(QContextMenuEvent *event) {

    QMenu ResMenu(this);


    if(!m_residentName->currentIndex().isValid()) {
        actionDelResi->setEnabled(false);
        actionEditResi->setEnabled(false);
    } else {
        actionDelResi->setEnabled(true);
        actionEditResi->setEnabled(true);
    }



    if(!m_typeResident->currentIndex().isValid()) {
        actionDelTypeResi->setEnabled(false);
        actionEditTypeResi->setEnabled(false);
    } else {
        actionDelTypeResi->setEnabled(true);
        actionEditTypeResi->setEnabled(true);
    }





    ResMenu.addAction(actionNewResident);
    ResMenu.addAction(actionNewTypeResident);
    ResMenu.addSeparator();
    ResMenu.addAction(actionNewChambre);
    ResMenu.addAction(actionNewBatiment);
    ResMenu.addSeparator();
    ResMenu.addAction(actionEditResi);
    ResMenu.addAction(actionDelResi);
    ResMenu.addSeparator();
    ResMenu.addAction(actionEditTypeResi);
    ResMenu.addAction(actionDelTypeResi);
    ResMenu.exec(event->globalPos());
    

}


void ResidentPage::removeResident() {
     QModelIndex ind = m_residentName->currentIndex();
     QModelIndex model_index = ex_proxyModel->mapToSource(ind);
     QStandardItem *item = ex_nomModel->itemFromIndex(model_index);
     QString resident_name = item->text();

    int retanswer = QMessageBox::question(this, "Supprimer Resident?", 
            "Etes vous sûr de vouloir supprimer definitivement "
           "<b> <br/>" + resident_name + "</b> du logiciel?", 
            QMessageBox::No | QMessageBox::Yes);

    if(retanswer == QMessageBox::Yes) {
        int rid = item->accessibleText().toInt();
        int itemRow = item->row();

       // remove photo file
       QSqlQuery queryPhoto;
           queryPhoto.prepare("SELECT resident_photo_name FROM resident WHERE resident_id = :tid");
               queryPhoto.bindValue(":tid", rid);
                   if(!queryPhoto.exec()) {
                       QMessageBox::critical(this, "Huston, we got a problem...", "Impossible d'obetenir l'anciene photo du resident");
                       return;
                    }
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



       // delete from db
        QSqlQuery queryRd;
            queryRd.prepare("DELETE FROM resident WHERE resident_id = :id");
            queryRd.bindValue(":id", rid);
        if(!queryRd.exec()) {
            QMessageBox::critical(this, "Huston, we've a problem... :)", queryRd.lastError().text());
            return;
        }

        QModelIndex indexA = m_residentName->indexAbove(ind);
        QModelIndex indexB = m_residentName->indexBelow(ind);
        ex_nomModel->removeRow(itemRow);
        if(indexA.isValid())
            showResidentInfos(m_residentName->currentIndex());
        else if(indexB.isValid())
            showResidentInfos(m_residentName->currentIndex());

     }

}




void ResidentPage::removeTypeResident() {
     QModelIndex type_index = m_typeResident->currentIndex();
     QStandardItem *item = ex_typeModel->itemFromIndex(type_index);
     QString type_resident_name = item->text();

    int retanswer = QMessageBox::question(this, "Supprimer Type Resident?", 
            "Etes vous sûr de vouloir supprimer definitivement le type "
           "<b> <br/>" + type_resident_name + "</b> du logiciel?", 
            QMessageBox::No | QMessageBox::Yes);

    if(retanswer == QMessageBox::Yes) {
        int trid = item->accessibleText().toInt();
        int itemRow = item->row();

       
       // delete from db
        QSqlQuery queryRd;
            queryRd.prepare("DELETE FROM type_resident WHERE type_resident_id = :id");
            queryRd.bindValue(":id", trid);
        if(!queryRd.exec()) {
            QMessageBox::critical(this, "Huston, we've a problem... :)", queryRd.lastError().text());
            return;
        }

        ex_typeModel->removeRow(itemRow);

        /*QModelIndex indexA = m_residentName->indexAbove(ind);
        QModelIndex indexB = m_residentName->indexBelow(ind);
        ex_nomModel->removeRow(itemRow);
        if(indexA.isValid())
            showResidentInfos(m_residentName->currentIndex());
        else if(indexB.isValid())
            showResidentInfos(m_residentName->currentIndex());*/

     }

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
                 QString rprof = queryRi.value(resRi.indexOf("resident_profession")).toString(); 
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


                 if(!rprof.isNull() && !rprof.isEmpty()) {
                     inf += "<span style='color: gray;'><b>Profession:</b></span>  ";
                     inf += rprof;
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



void ResidentPage::updateResidentTree() {
             

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


}





void ResidentPage::updateTypeResidentTree() {
 
         //ex_items_type = new QList<QStandardItem *>;
        
         QSqlQuery query("SELECT type_resident_id, type_resident_name FROM type_resident");
         if(query.lastError().isValid())
             QMessageBox::critical(this, "Error", query.lastError().text());
         else {
             QSqlRecord results = query.record();
             if(!results.isEmpty()) {
                 while(query.next()) {
                     QString rn = query.value(results.indexOf("type_resident_name")).toString();
                     QStandardItem *ni = new QStandardItem(rn);
                     ni->setAccessibleText(query.value(results.indexOf("type_resident_id")).toString());
                     ni->setEditable(false);
                     ni->setCheckable(true);
                     ni->setCheckState(Qt::Checked);
                     ni->setIcon(QIcon("img/resource-group.png"));
                     ex_typeModel->appendRow(ni);
                     
                     ex_items_type->append(ni);
                }
             }
        }

}



/* <========================= End ResidentPage =============================> */



BatChaPage::BatChaPage(QWidget *parent) : QWidget(parent)
 {

      //QWidget *page2 = new QWidget;
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

          QPushButton *room8 = new QPushButton("chambre 8");
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

       setLayout(mainLayoutPage2);





      }


/* <========================= End BatChaPage =============================> */





 EventsPage::EventsPage(QWidget *parent)
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
     //setLayout(mainLayout);
 }
