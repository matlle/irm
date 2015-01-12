#include <QApplication>
#include <QtGui>
#include <QTranslator>
#include <QLocale>
#include <QLibraryInfo>
#include "Window.h"

int main(int argc, char *argv[]) {
  
    QApplication app(argc, argv);
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));

    QString locale = QLocale::system().name().section('_', 0, 0);
    QTranslator translator;
    translator.load(QString("qt_") + locale,
        QLibraryInfo::location(QLibraryInfo::TranslationsPath));
    app.installTranslator(&translator);

    //app.setStyle("plastique");

    
    Window win;
    win.show();

    return app.exec();
}
