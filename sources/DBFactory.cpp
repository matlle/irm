#include "DBFactory.h"

QString DBFactory::m_url = QString("localhost");
QString DBFactory::m_database = QString("irm");
QString DBFactory::m_user = QString("matlle");
QString DBFactory::m_password = QString("cromagnon");
QSqlDatabase *DBFactory::m_db = NULL;


QSqlDatabase DBFactory::getConnection(QWidget *parent) {

    if(m_db == NULL) {
        m_db = new QSqlDatabase();
        *m_db = QSqlDatabase::addDatabase("QMYSQL");
        m_db->setHostName(m_url);
        m_db->setDatabaseName(m_database);
        m_db->setUserName(m_user);
        m_db->setPassword(m_password);

        if(!m_db->open()) {
            QMessageBox::critical(parent, "Erreur de connexion à la base de donnée",
                                 m_db->lastError().text());
        }

    }
    
    return *m_db;
}
