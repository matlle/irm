#include "pages.h"
#include "DBFactory.h"

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

     QTreeView *residentName = new QTreeView;
         QStandardItemModel *nomModel = new QStandardItemModel;

         QSqlQuery query("SELECT resident_nom FROM resident");
         if(query.lastError().isValid())
             QMessageBox::critical(this, "Error", query.lastError().text());
         else {
             QSqlRecord results = query.record();
             if(!results.isEmpty()) {
                 while(query.next())
                     nomModel->appendRow(new QStandardItem(query.value(results.indexOf("resident_nom")).toString()));
             }
        }
             

         nomModel->setHorizontalHeaderLabels(QStringList("Nom Resident"));

         residentName->setModel(nomModel);
         residentName->setIndentation(0);
         residentName->setMinimumWidth(130);
         residentName->setSortingEnabled(true);
        

     QWidget *infosResident = new QWidget(this);
         QLabel *textInfos = new QLabel(this);
                 textInfos->setText(QString("Informations: de la diaspora\nPays: Unknown\nSituation: Critical..."));
                 textInfos->setAlignment(Qt::AlignLeft);
                 textInfos->setIndent(20);
         QLabel *picResident = new QLabel(this);
                 picResident->setPixmap(QPixmap("img/michael.png"));
                 picResident->setAlignment(Qt::AlignLeft | Qt::AlignTop);
                 picResident->setMaximumHeight(250);
                 picResident->setMaximumWidth(221);
         QLabel *nameResident = new QLabel(this);
                 nameResident->setText(QString("Michael Scott"));
                 nameResident->setFont(QFont("DejaVu Sans", 22, QFont::Bold));
                 nameResident->setAlignment(Qt::AlignLeft | Qt::AlignTop);
         QVBoxLayout *picnameLayout = new QVBoxLayout;
                      picnameLayout->addWidget(picResident);
                      picnameLayout->addWidget(nameResident);
         QHBoxLayout *infosLayout = new QHBoxLayout;
             infosLayout->addSpacing(30);
             infosLayout->addLayout(picnameLayout);
             infosLayout->addWidget(textInfos);
             infosLayout->addStretch(58);
         infosResident->setStyleSheet("background-color: white;");
         infosResident->setLayout(infosLayout);

     splitter->addWidget(typeResident);
     splitter->addWidget(residentName);
     splitter->addWidget(infosResident);

     QHBoxLayout *mainLayout = new QHBoxLayout;
     mainLayout->addWidget(splitter);
     setLayout(mainLayout);
     
 }



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
