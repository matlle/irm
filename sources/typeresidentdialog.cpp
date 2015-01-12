#include "typeresidentdialog.h"
#include "pages.h"
#include "common.h"


TypeResidentDialog::TypeResidentDialog(QWidget *parent = 0): QDialog(parent) {
   
    m_name = new QLineEdit(this);
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

}


TypeResidentDialog::TypeResidentDialog(QVariantList list, QWidget *parent = 0) :QDialog(parent) {

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

}


void TypeResidentDialog::saveNewTypeResident() {

  
     if(!m_name->text().isEmpty()) {

      QSqlQuery queryNtr;
      queryNtr.prepare("INSERT INTO type_resident(type_resident_name)" 
                            "VALUES (:name)"
                      );
            
            queryNtr.bindValue(":name", m_name->text());

            if(!queryNtr.exec()) 
                QMessageBox::critical(this, "Huston, we got a error :)", queryNtr.lastError().text());
            else {
                
                int lid = queryNtr.lastInsertId().toInt();
                
                QSqlQuery queryNi;
                queryNi.prepare("SELECT type_resident_name FROM type_resident WHERE type_resident_id = :id");
                queryNi.bindValue(":id", lid);
                if(!queryNi.exec())
                    QMessageBox::critical(this, "Huston, we got a error :)", queryNi.lastError().text());
                else {
                    QSqlRecord result = queryNi.record();
                    if(!result.isEmpty()) {
                        while(queryNi.next()) {
                            QString sni = queryNi.value(result.indexOf("type_resident_name")).toString();
                            QStandardItem *nii = new QStandardItem(sni);
                            QString ts = QString::number(lid);
                            nii->setAccessibleText(ts);
                            nii->setEditable(false);
                            nii->setCheckable(true);
                            nii->setIcon(QIcon("img/resource-group.png"));

                            ex_typeModel->appendRow(nii);
                        }
                    }
                }
             QMessageBox::information(this, "Succès", "Type Resident enregistré!");

            }

  } else {
      QMessageBox::critical(this, "Erreur - Le nouveau type resident n'a pu être enregistré", "Vous devez saisir le nom du type");
  }
  
  
      
}


void TypeResidentDialog::saveEditedTypeResident(const QModelIndex &index, int trid) {
  
      
      if(!m_name->text().isEmpty()) {

          
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
  }  
  
}

