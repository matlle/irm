#include "batdialog.h"
#include "common.h"


BatDialog::BatDialog(QWidget *parent = 0): QDialog(parent) {
   
    //m_name = new QLineEdit(this);
    /*QFormLayout *form = new QFormLayout;
        form->addRow("Nom: ", m_name);*/

      updateBatTree();

       m_batTree = new QTreeView(this);
    m_batTree->setModel(m_model);
    
    QVBoxLayout *batLayout = new QVBoxLayout;
        batLayout->addWidget(m_batTree);

    QGroupBox *group = new QGroupBox("Liste batiments et chambres");
        group->setLayout(batLayout);

    m_newBat = new QPushButton("Nouveau Batiment");
                 m_newBat->setIcon(QIcon("img/bat.png"));
    m_newChamb = new QPushButton("Nouvelle Chambre");
                 m_newChamb->setIcon(QIcon("img/bed.png"));
    m_removeEle = new QPushButton("Supprimer");
                 m_removeEle->setIcon(QIcon("img/button_cancel.png"));
                 m_removeEle->setEnabled(false);
    QVBoxLayout *actionBtnLayout = new QVBoxLayout;
        actionBtnLayout->addWidget(m_newBat);
        actionBtnLayout->addWidget(m_newChamb);
        actionBtnLayout->addWidget(m_removeEle);
        actionBtnLayout->addStretch(60);

        

    m_okBtn = new QPushButton("Ok");
        m_okBtn->setIcon(QIcon("img/apply.png"));
    /*m_cancelBtn = new QPushButton("Annuler");
        m_cancelBtn->setIcon(QIcon("img/button_cancel.png"));*/
    QHBoxLayout *btnLayout = new QHBoxLayout;
        btnLayout->addWidget(m_okBtn);
        //btnLayout->addWidget(m_cancelBtn);
        btnLayout->setAlignment(Qt::AlignRight);

    QHBoxLayout *listLayout = new QHBoxLayout;
        listLayout->addWidget(group);
        listLayout->addLayout(actionBtnLayout);

    QVBoxLayout *mainLayout = new QVBoxLayout;
        mainLayout->addLayout(listLayout);
        mainLayout->addLayout(btnLayout);
    
    resize(600, 500);
    setWindowTitle("Batiments/Chambres - IRM");
    setLayout(mainLayout); 


    QObject::connect(m_newBat, SIGNAL(clicked()), this, SLOT(saveNewBat()));
    QObject::connect(m_batTree, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(saveEditedBat(QModelIndex)));
    QObject::connect(m_batTree, SIGNAL(clicked(QModelIndex)), this, SLOT(onItemChanged(QModelIndex)));
    QObject::connect(m_removeEle, SIGNAL(clicked()), this, SLOT(removeBat()));
    QObject::connect(m_okBtn, SIGNAL(clicked()), this, SLOT(accept()));

}


/*TypeResidentDialog::TypeResidentDialog(QVariantList list, QWidget *parent = 0) :QDialog(parent) {

         m_name = new QLineEdit(list[1].toString(), this);
         QFormLayout *form = new QFormLayout;
         form->addRow("Nom: ", m_name);


    QGroupBox *group = new QGroupBox("Nouveau Type Resident");
        group->setLayout(form);

    m_okBtn = new QPushButton("Ok");
        m_okBtn->setIcon(QIcon("img/apply.png"));
    m_cancelBtn = new QPushButton("Annuler");
        m_cancelBtn->setIcon(QIcon("img/button_cancel.png"));
    QHBoxLayout *btnLayout = new QHBoxLayout;
        btnLayout->addWidget(m_okBtn);
        btnLayout->addWidget(m_cancelBtn);
        btnLayout->setAlignment(Qt::AlignRight);

    QVBoxLayout *mainLayout = new QVBoxLayout;
        mainLayout->addWidget(group);
        mainLayout->addLayout(btnLayout);
    
    resize(400, 100);
    setWindowTitle("Nouveau type resident - IRM");
    setLayout(mainLayout); 

    QObject::connect(m_okBtn, SIGNAL(clicked()), this, SLOT(accept()));
    QObject::connect(m_cancelBtn, SIGNAL(clicked()), this, SLOT(reject()));

}*/


void BatDialog::saveNewBat() {
 bool ok = false;
 QString batname = QInputDialog::getText(this, "Batiment",
         "Nom du batiment:", QLineEdit::Normal, QString(), &ok); 

 if(ok && batname.isEmpty()) {
     QMessageBox::critical(this, "Error - Impossible d'enregistrer le batiment", "Vous devez entrer le nom du batiment");
     return;
 }


    QSqlQuery query;
      query.prepare("INSERT INTO batiment(batiment_name)" 
                         "VALUES (:name)");
            
            query.bindValue(":name", batname);

            if(!query.exec()) 
                QMessageBox::critical(this, "Huston, we got a error :)", query.lastError().text());
            else {
                
                int lid = query.lastInsertId().toInt();
                
                QSqlQuery queryNi;
                queryNi.prepare("SELECT * FROM batiment WHERE batiment_id = :id");
                queryNi.bindValue(":id", lid);
                if(!queryNi.exec())
                    QMessageBox::critical(this, "Huston, we got a error :)", queryNi.lastError().text());
                else {
                    QSqlRecord result = queryNi.record();
                    if(!result.isEmpty()) {
                        while(queryNi.next()) {
                            QString sni = queryNi.value(result.indexOf("batiment_name")).toString();
                            QStandardItem *nii = new QStandardItem(sni);
                            QString ts = QString::number(lid);
                            nii->setAccessibleText(ts);
                            nii->setEditable(false);
                            nii->setIcon(QIcon("img/bat.png"));
                            //nii->appendRow(new QStandardItem("Chambre 125")); 

                            m_model->appendRow(nii);
                        }
                    }
                }


      }
      
}


void BatDialog::saveEditedBat(const QModelIndex &index) {
  QStandardItem *item = m_model->itemFromIndex(index);
  QString curName = item->text();
  int bid = item->accessibleText().toInt();
  bool ok = false;
  QString batname = QInputDialog::getText(this, "Batiment",
         "Nom du batiment:", QLineEdit::Normal, curName, &ok); 

  if(ok && batname.isEmpty()) {
      QMessageBox::critical(this, "Error - Impossible de modifier le batiment", "Vous devez entrer le nom du batiment");
     return;
  } else if(ok) {




  QSqlQuery query;
      query.prepare("UPDATE batiment \ 
                    SET batiment_name = :name \
                    WHERE batiment_id = :id");
            
            query.bindValue(":id", bid);
            query.bindValue(":name", batname);

            if(!query.exec()) 
                QMessageBox::critical(this, "Huston, we got a error :)", query.lastError().text());
            else {
                
                
                QSqlQuery queryNi;
                queryNi.prepare("SELECT * FROM batiment WHERE batiment_id = :id");
                queryNi.bindValue(":id", bid);
                if(!queryNi.exec())
                    QMessageBox::critical(this, "Huston, we got a error :)", queryNi.lastError().text());
                else {
                    QSqlRecord result = queryNi.record();
                    if(!result.isEmpty()) {
                        while(queryNi.next()) {
                            QString sni = queryNi.value(result.indexOf("batiment_name")).toString();
                            QStandardItem *nii = new QStandardItem(sni);
                            QString ts = QString::number(bid);
                            nii->setAccessibleText(ts);
                            nii->setEditable(false);
                            nii->setIcon(QIcon("img/bat.png"));
                            //nii->appendRow(new QStandardItem("Chambre 125")); 

                            QStandardItem *oitem = m_model->itemFromIndex(index);
                            int oitemRow = oitem->row();
                            
                            m_model->removeRow(oitemRow);
                            m_model->appendRow(nii);
                        }
                    }
                }


      }


  }
  
}



/*void BatDialog::saveEditedBatOnBtnClick() {
  QModelIndex index = m_batTree->currentIndex();
  QStandardItem *item = m_model->itemFromIndex(index);
  QString curName = item->text();
  int bid = item->accessibleText().toInt();
  bool ok = false;
  QString batname = QInputDialog::getText(this, "Batiment",
         "Nom du batiment:", QLineEdit::Normal, curName, &ok); 

  if(ok && batname.isEmpty()) {
      QMessageBox::critical(this, "Error - Impossible de modifier le batiment", "Vous devez entrer le nom du batiment");
     return;
  }




  QSqlQuery query;
      query.prepare("UPDATE batiment \ 
                    SET batiment_name = :name \
                    WHERE batiment_id = :id");
            
            query.bindValue(":id", bid);
            query.bindValue(":name", batname);

            if(!query.exec()) 
                QMessageBox::critical(this, "Huston, we got a error :)", query.lastError().text());
            else {
                
                
                QSqlQuery queryNi;
                queryNi.prepare("SELECT * FROM batiment WHERE batiment_id = :id");
                queryNi.bindValue(":id", bid);
                if(!queryNi.exec())
                    QMessageBox::critical(this, "Huston, we got a error :)", queryNi.lastError().text());
                else {
                    QSqlRecord result = queryNi.record();
                    if(!result.isEmpty()) {
                        while(queryNi.next()) {
                            QString sni = queryNi.value(result.indexOf("batiment_name")).toString();
                            QStandardItem *nii = new QStandardItem(sni);
                            QString ts = QString::number(bid);
                            nii->setAccessibleText(ts);
                            nii->setEditable(false);
                            nii->setIcon(QIcon("img/bat.png"));
                            //nii->appendRow(new QStandardItem("Chambre 125")); 

                            QStandardItem *oitem = m_model->itemFromIndex(index);
                            int oitemRow = oitem->row();
                            
                            m_model->removeRow(oitemRow);
                            m_model->appendRow(nii);
                        }
                    }
                }


      }


  
}*/




bool BatDialog::isBatHasCha(int bid) {
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) \
                   FROM chambre WHERE batiment_id = :bid");
    query.bindValue(":bid", bid);
    
    if(!query.exec()) {
        QMessageBox::critical(this, "Huston, we got a error :)", query.lastError().text());
        return false;
    } else {
        int nbRow = query.size();
        if(nbRow == -1) return false;
        else return true;
    }
}





QMap<QString, QString> BatDialog::getAllChaByBatId(int bid) {
    QMap<QString, QString> chaNames;
    QSqlQuery query;
    query.prepare("SELECT * \
                   FROM chambre WHERE batiment_id = :bid");
    query.bindValue(":bid", bid);
    
    if(!query.exec()) {
        QMessageBox::critical(this, "Huston, we got a error :)", query.lastError().text());
    } else {
        QSqlRecord result = query.record();
        if(!result.isEmpty()) {
            while(query.next()) {
                chaNames["chambre_id"] << query.value(result.indexOf("chambre_id")).toString();
                chaNames["chambre_name"] << query.value(result.indexOf("chambre_name")).toString();
            }
        }
    }
    return chaNames;
}






void BatDialog::updateBatTree() {

    m_model = new QStandardItemModel;
        m_model->setHorizontalHeaderLabels(QStringList("Batiments/chambres"));

  
                QSqlQuery query("SELECT * FROM batiment");
                if(!query.exec())
                    QMessageBox::critical(this, "Huston, we got a error :)", query.lastError().text());
                else {
                    QSqlRecord result = query.record();
                    if(!result.isEmpty()) {
                        while(query.next()) {
                            QString sui = query.value(result.indexOf("batiment_name")).toString();
                            //QString chaName = query.value(result.indexOf("chambre_name")).toString();
                            int bid = query.value(result.indexOf("batiment_id")).toInt();
                            QStandardItem *uii = new QStandardItem(sui);
                            if(isBatHasCha(bid) == true) {
                                QMap<QString, QString> roomsName = getAllChaByBatId(bid);
                                for(int c = 0; c < roomsName.size(); c++) {
                                    QStandardItem *ichild = new QStandardItem(roomsName[c]);
                                       ichild->setAccessibleText(ts);
                                       ichild->setEditable(false);
                                       ichild->setIcon(QIcon("img/bed.png"));
                                    uii->appendRow(ichild);
                                }

                            }
                            QString ts = QString::number(bid);
                            uii->setAccessibleText(ts);
                            uii->setEditable(false);
                            uii->setIcon(QIcon("img/bat.png"));
                            m_model->appendRow(uii);
                        }

                    }
                }


    
}



void BatDialog::onItemChanged(QModelIndex index) {

    //if(!m_batTree->currentIndex().isValid()) {
    //        m_removeEle->setEnabled(false);
    //    } else {
            m_removeEle->setEnabled(true);
    //    }


}




void BatDialog::removeBat() {
     QModelIndex bat_index = m_batTree->currentIndex();
     QStandardItem *item = m_model->itemFromIndex(bat_index);
     QString batiment_name = item->text();

    int retanswer = QMessageBox::question(this, "Supprimer Type Resident?", 
            "Etes vous sûr de vouloir supprimer definitivement le batiment "
           "<b> <br/>" + batiment_name + "</b> selectionné du logiciel?", 
            QMessageBox::No | QMessageBox::Yes);

    if(retanswer == QMessageBox::Yes) {
        int bid = item->accessibleText().toInt();
        int itemRow = item->row();

       
       // delete from db
        QSqlQuery queryRd;
            queryRd.prepare("DELETE FROM batiment WHERE batiment_id = :id");
            queryRd.bindValue(":id", bid);
        if(!queryRd.exec()) {
            QMessageBox::critical(this, "Huston, we've a problem... :)", queryRd.lastError().text());
            return;
        }

        m_model->removeRow(itemRow);

     }

}
