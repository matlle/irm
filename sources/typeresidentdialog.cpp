#include "typeresidentdialog.h"
#include "pages.h"
#include "common.h"


TypeResidentDialog::TypeResidentDialog(QWidget *parent = 0): QDialog(parent) {
   
    QLineEdit *name = new QLineEdit(this);
    QFormLayout *form = new QFormLayout;
        form->addRow("Nom: ", name);


    QGroupBox *group = new QGroupBox("Type Resident");
        group->setLayout(form);

    QPushButton *okBtn = new QPushButton("Ok");
    QPushButton *cancelBtn = new QPushButton("Annuler");
    QHBoxLayout *btnLayout = new QHBoxLayout;
        btnLayout->addWidget(okBtn);
        btnLayout->addWidget(cancelBtn);
        btnLayout->setAlignment(Qt::AlignRight);

    QVBoxLayout *mainLayout = new QVBoxLayout;
        mainLayout->addWidget(group);
        mainLayout->addLayout(btnLayout);
    
    resize(300, 100);
    setWindowTitle("Nouveau type resident - IRM");
    setLayout(mainLayout);


    QObject::connect(okBtn, SIGNAL(clicked()), this, SLOT(accept()));
    QObject::connect(cancelBtn, SIGNAL(clicked()), this, SLOT(reject()));

}


TypeResidentDialog::TypeResidentDialog(QVariantList list, QWidget *parent) {
}


void TypeResidentDialog::saveNewTypeResident() {
    ;
}

void TypeResidentDialog::saveEditedTypeResident(const QModelIndex&, int) {
    ;
}

