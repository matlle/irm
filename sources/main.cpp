#include <QApplication>
#include <QtGui>
#include "Window.h"

int main(int argc, char *argv[]) {
  
    QApplication app(argc, argv);
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));

    Window win;
    win.show();

    return app.exec();
}
