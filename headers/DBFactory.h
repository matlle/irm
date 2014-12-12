/*
 * Author: MATLLE - (CRIXUS)
 * Created at: Friday 12 December 2014
 *
 * Role: 
 * The database factory class header
 *
 */

#include <QtSql>
#include <QtGui>

#ifndef HEADER_DBFACTORY
#define HEADER_DBFACTORY

class DBFactory { 

    public:
        QSqlDatabase static getConnection(QWidget *parent = 0);
         ~DBFactory();

    protected:
        static QString m_url;
        static QString m_database;
        static QString m_user;
        static QString m_password;
        static QSqlDatabase *m_db;

 
};

#endif
