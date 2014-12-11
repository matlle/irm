#ifndef PAGES_H
#define PAGES_H

#include <QWidget>

class ResidentPage : public QWidget {

    public:
        ResidentPage(QWidget *parent = 0);
};

class QueryPage: public QWidget {

    public:
        QueryPage(QWidget *parent = 0);

};

class UpdatePage : public QWidget {

    public:
        UpdatePage(QWidget *parent = 0);
};

#endif
