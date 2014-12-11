/*
 * Author: MATLLE - (CRIXUS)
 * Created at: Monday 08 December 2014
 *
 * Role:
 * The main window of the irm program.
 *
 */

#include "Window.h"
#include "pages.h"

Window::Window() {
    
    initMainWindow();
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
            QAction *actionNewBatiment = newElement->addAction("Nouveau batiment");
            QAction *actionNewChambre = newElement->addAction("Nouvelle chambre");
        QAction *actionPrint = new QAction("&Imprimer", this);
        QAction *actionPrintPreview = new QAction("&Aperçu avant impression", this);
        QAction *actionDisconnect = new QAction("&Deconnexion", this);
        QAction *actionExit = new QAction("&Quitter", this);
        actionExit->setShortcut(QKeySequence("Ctrl+Q"));

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
    QLineEdit *searchField = new QLineEdit;
    toolbar->addAction(actionNewResident);
    toolbar->addAction(actionNewBatiment);
    toolbar->addAction(actionNewChambre);
    toolbar->addSeparator();
    toolbar->addWidget(searchField);


    // Window main widget and children
    m_contentsWidget = new QListWidget;
    m_contentsWidget->setViewMode(QListView::IconMode);
    m_contentsWidget->setIconSize(QSize(96, 84));
    m_contentsWidget->setMovement(QListView::Static);
    m_contentsWidget->setMaximumWidth(110);
    m_contentsWidget->setMinimumWidth(110);
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
    
    // Events
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
