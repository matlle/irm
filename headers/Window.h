/*
 * Author: MATLLE - (CRIXUS)
 * Created at: Monday 08 December 2014
 *
 * Role: 
 * The main window of the irm program.
 *
 */


#ifndef HEADER_WINDOW
#define HEADER_WINDOW

#include <QtGui>
#include <QtSql>

class QListWidget;
class QListWidgetItem;
class QStackedWidget;

class Window : public QMainWindow { 

    Q_OBJECT

    public:
      Window();
      void onOpen();
      void onSave();
      void initMainWindow();
    
    public slots:
        void changePage(QListWidgetItem *current, QListWidgetItem *previous);
        void manageResident();
    
    protected:
        void createIcons();

        QListWidget *m_contentsWidget;
        QStackedWidget *m_pagesWidget;

};

#endif
