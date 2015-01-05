#include "photopreview.h"

PhotoPreview::PhotoPreview(QPixmap pix, QWidget *parent = 0) : QDialog(parent) {
    
    QLabel *helpTextLabel = new QLabel(this);
        helpTextLabel->setText(QString("Clicker sur 'Ok' pour enregistrer la photo ou 'Annuler' pour annuler."));
    m_PpLabel = new QLabel(this);
        m_PpLabel->setPixmap(pix);
    m_PpOkBtn = new QPushButton("Ok");
        m_PpOkBtn->setIcon(QIcon("img/apply.png"));
    m_PpCancelBtn = new QPushButton("Annuler");
        m_PpCancelBtn->setIcon(QIcon("img/button_cancel.png"));
    
    QHBoxLayout *PpBtnLayout = new QHBoxLayout;
       PpBtnLayout->addWidget(m_PpOkBtn);
       PpBtnLayout->addWidget(m_PpCancelBtn);
       PpBtnLayout->setAlignment(Qt::AlignRight);
    
    QVBoxLayout *PpMainLayout = new QVBoxLayout;
        PpMainLayout->addWidget(helpTextLabel);
        PpMainLayout->addWidget(m_PpLabel);
        PpMainLayout->addLayout(PpBtnLayout);

    setLayout(PpMainLayout);
    setWindowTitle("Photo resident - IRM");

    QObject::connect(m_PpOkBtn, SIGNAL(clicked()), this, SLOT(accept()));
    QObject::connect(m_PpCancelBtn, SIGNAL(clicked()), this, SLOT(reject()));

}
