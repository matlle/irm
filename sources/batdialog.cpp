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
    m_editEle = new QPushButton("Modifier");
                 m_editEle->setIcon(QIcon("img/edit.png"));
    m_removeEle = new QPushButton("Supprimer");
                 m_removeEle->setIcon(QIcon("img/button_cancel.png"));
    QVBoxLayout *actionBtnLayout = new QVBoxLayout;
        actionBtnLayout->addWidget(m_newBat);
        actionBtnLayout->addWidget(m_newChamb);
        actionBtnLayout->addWidget(m_editEle);
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
    
    resize(400, 500);
    setWindowTitle("Batiments/Chambres - IRM");
    setLayout(mainLayout); 


    QObject::connect(m_newBat, SIGNAL(clicked()), this, SLOT(saveNewBat()));
    QObject::connect(m_okBtn, SIGNAL(clicked()), this, SLOT(accept()));
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

      
}


void BatDialog::saveEditedBat(const QModelIndex &index, int trid) {
  
      
      /*if(!m_name->text().isEmpty()) {

          
      QSqlQuery queryNr;
      queryNr.prepare("UPDATE type_resident \
                       SET type_resident_name = :name \
                       WHERE type_resident_id = :trid");
            
            queryNr.bindValue(":trid", trid);
            queryNr.bindValue(":name", m_name->text());
            
            if(!queryNr.exec()) 
                QMessageBox::critical(this, "Huston, we got a error :)", queryNr.lastError().text());
            else {
                
                 
                QSqlQuery queryUi;
                queryUi.prepare("SELECT type_resident_id, type_resident_name FROM type_resident WHERE type_resident_id = :id");
                queryUi.bindValue(":id", trid);
                if(!queryUi.exec())
                    QMessageBox::critical(this, "Huston, we got a error :)", queryUi.lastError().text());
                else {
                    QSqlRecord result = queryUi.record();
                    if(!result.isEmpty()) {
                        while(queryUi.next()) {
                            QString sui = queryUi.value(result.indexOf("type_resident_name")).toString();
                            QStandardItem *uii = new QStandardItem(sui);
                            QString ts = QString::number(trid);
                            uii->setAccessibleText(ts);
                            uii->setEditable(false);
                            uii->setCheckable(true);
                            uii->setIcon(QIcon("img/resource-group.png"));
                            

                            QStandardItem *oitem = ex_typeModel->itemFromIndex(index);
                            int oitemRow = oitem->row();
            
                            ex_typeModel->removeRow(oitemRow);
                            ex_typeModel->appendRow(uii);
                            //ex_nomModel->insertRow(0, uii);
                        }

                    }
                }

            }
   
  } else {
      QMessageBox::critical(this, "Erreur - Le type de resident n'a pu être modifié", "Vous devez saisir le nom du type");
  }*/
  
}


void BatDialog::updateBatTree() {

    m_model = new QStandardItemModel;
        m_model->setHorizontalHeaderLabels(QStringList("Batiments/chambres"));
    QStandardItem *item = new QStandardItem("Batiment 1");
    m_model->appendRow(item);
    item->appendRow(new QStandardItem("Chambre Atible"));


    QStandardItem *item2 = new QStandardItem("Batiment 2");
    m_model->appendRow(item2);
    item2->appendRow(new QStandardItem("Chambre Atible"));


    QStandardItem *item3 = new QStandardItem("Batiment 3");
    m_model->appendRow(item3);
    item3->appendRow(new QStandardItem("Chambre Atible"));


}
