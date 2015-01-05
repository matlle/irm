/*
 * Author: MATLLE - (CRIXUS)
 * Created at: Monday 05 January 2015
 *
 * Role: 
 * A dialog box for show preview of user upload photos before save them.
 *
 */


#ifndef HEADER_PHOTOPREVIEW
#define HEADER_PHOTOPREVIEW

#include <QtGui>

class PhotoPreview : public QDialog { 

    public:
      PhotoPreview(QPixmap pixmap, QWidget *parent);

    protected:
    QLabel *m_PpLabel;
    QPushButton *m_PpOkBtn;
    QPushButton *m_PpCancelBtn;
 
};

#endif
