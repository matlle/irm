/*
 * Author: MATLLE - (CRIXUS)
 * Created at: Monday 08 December 2014
 *
 * Role:
 * The main window of the irm program.
 *
 */

#include "Window.h"
#include "DBFactory.h"
#include "pages.h"
#include "ResidentDialog.h"
#include "common.h"

QSqlDatabase db;
Window::Window() {
    initMainWindow();
    db = DBFactory::getConnection(this);
}

void Window::initMainWindow() {

    this->setStyleSheet("QListWidget#m_contentsWidget {background-color: #ccc;}");
    
    setWindowTitle("ISTCJF RESIDENSE MANAGEMENT (IRM)");
    setWindowIcon(QIcon("img/logo.png"));

    QWidget *mainContainer = new QWidget;

    // Menu stuff
    QMenu *menuFile = menuBar()->addMenu("&Fichier");
        QMenu *newElement = menuFile->addMenu("&Nouveau");
            QAction *actionNewResident = newElement->addAction("Nouveau resident");
            QAction *actionNewTypeResident = newElement->addAction("Nouveau type resident");
            newElement->addSeparator();
            QAction *actionNewBatiment = newElement->addAction("Nouveau batiment");
            QAction *actionNewChambre = newElement->addAction("Nouvelle chambre");
        QMenu *exporter = menuFile->addMenu("&Exporter");
            QAction *actionDocx = exporter->addAction("Exporter comme DOCX");
            QAction *actionPdf = exporter->addAction("Exporter comme PDF");
        QAction *actionPrint = new QAction("&Imprimer", this);
        QAction *actionPrintPreview = new QAction("&Aperçu avant impression", this);
        QAction *actionDisconnect = new QAction("&Deconnexion", this);
        QAction *actionExit = new QAction("&Quitter", this);

        // set shortcut
        actionExit->setShortcut(QKeySequence("Ctrl+Q"));

        // set icons
        actionNewResident->setIcon(QIcon("img/add_user.png"));
        actionNewTypeResident->setIcon(QIcon("img/add_user_group.png"));
        actionNewBatiment->setIcon(QIcon("img/bat.png"));
        actionNewChambre->setIcon(QIcon("img/bed.png"));
        actionPrint->setIcon(QIcon("img/filequickprint.png"));
        actionPrintPreview->setIcon(QIcon("img/fileprint.png"));
        actionDisconnect->setIcon(QIcon("img/exit.png"));
        actionExit->setIcon(QIcon("img/stop.png"));

        menuFile->addSeparator();
        menuFile->addAction(actionPrint);
        menuFile->addAction(actionPrintPreview);
        menuFile->addSeparator();
        menuFile->addAction(actionDisconnect);
        menuFile->addAction(actionExit);
   


    QMenu *menuEdit = menuBar()->addMenu("&Edition");
    QMenu *menuView = menuBar()->addMenu("&Affichage");
    QMenu *menuSettings = menuBar()->addMenu("&Paramètre");
    QMenu *menuHelp = menuBar()->addMenu("&Aide");
    



    // Toolbar stuff
    QToolBar *toolbar = addToolBar("IrmToolbar");
    QLineEdit *searchField = new QLineEdit(this);
              QString ss = "Rechercher";
              searchField->setPlaceholderText(ss);
    toolbar->addAction(actionNewResident);
    toolbar->addAction(actionNewTypeResident);
    toolbar->addAction(actionNewBatiment);
    toolbar->addAction(actionNewChambre);
    toolbar->addSeparator();
    toolbar->addWidget(searchField);


    // Window main widget and children
    m_contentsWidget = new QListWidget;
    m_contentsWidget->setViewMode(QListView::IconMode);
    m_contentsWidget->setIconSize(QSize(96, 84));
    m_contentsWidget->setMovement(QListView::Static);
    m_contentsWidget->setMaximumWidth(117);
    m_contentsWidget->setMinimumWidth(117);
    m_contentsWidget->setSpacing(6);
    m_contentsWidget->setObjectName("m_contentsWidget");

    m_pagesWidget = new QStackedWidget;
    m_pagesWidget->addWidget(new ResidentPage);
    m_pagesWidget->addWidget(new UpdatePage);
    m_pagesWidget->addWidget(new QueryPage);
    

    createIcons();
    m_contentsWidget->setCurrentRow(0);


    QHBoxLayout *horizontalLayout = new QHBoxLayout;
    horizontalLayout->addWidget(m_contentsWidget);
    horizontalLayout->addWidget(m_pagesWidget, 1);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(horizontalLayout);
    mainLayout->addSpacing(12);
    
    mainContainer->setLayout(mainLayout);
    setCentralWidget(mainContainer);
    statusBar()->showMessage("Ready");
    showMaximized(); 


    // Events
    QObject::connect(actionNewResident, SIGNAL(triggered()), this, SLOT(newResident()));
    QObject::connect(searchField, SIGNAL(textEdited(QString)), ex_proxyModel, SLOT(setFilterFixedString(QString)));
    QObject::connect(actionExit, SIGNAL(triggered()), qApp, SLOT(quit()));

}



void Window::createIcons() {

    QListWidgetItem *firstItem = new QListWidgetItem(m_contentsWidget);
    firstItem->setIcon(QIcon("img/residents.png"));
    firstItem->setText("Resident");
    firstItem->setTextAlignment(Qt::AlignHCenter);
    firstItem->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);


    QListWidgetItem *secondItem = new QListWidgetItem(m_contentsWidget);
    secondItem->setIcon(QIcon("img/bat.png"));
    secondItem->setText("Batiment\n et chambre");
    secondItem->setTextAlignment(Qt::AlignHCenter);
    secondItem->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    
    QListWidgetItem *thirdItem = new QListWidgetItem(m_contentsWidget);
    thirdItem->setIcon(QIcon("img/blockdevice.png"));
    thirdItem->setText("Evenement");
    thirdItem->setTextAlignment(Qt::AlignHCenter);
    thirdItem->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    connect(m_contentsWidget,
            SIGNAL(currentItemChanged(QListWidgetItem*, QListWidgetItem*)),
            this, SLOT(changePage(QListWidgetItem*, QListWidgetItem*))
            );

}


void Window::changePage(QListWidgetItem *current, QListWidgetItem *previous) {
    
    if(!current)
        current = previous;
    m_pagesWidget->setCurrentIndex(m_contentsWidget->row(current));
}

void Window::newResident() {
    ResidentDialog *resident = new ResidentDialog(this);
    int intAct = resident->exec();
    if (intAct == QDialog::Accepted) {
       resident->saveNewResident();
    }


}



