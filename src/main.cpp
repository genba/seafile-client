#include <QApplication>
#include <QMessageBox>
#include <QTranslator>
#include <QLocale>
#include <QLibraryInfo>
#include <QWidget>

#include <glib-object.h>
#include <stdio.h>

#include "utils/process.h"
#include "seafile-applet.h"
#include "QtAwesome.h"
#ifdef Q_WS_MAC
#include "Application.h"
#endif

int main(int argc, char *argv[])
{
#ifdef Q_WS_MAC
    Application app(argc, argv);
#else
    QApplication app(argc, argv);
#endif

    if (count_process("seafile-applet") > 1) {
        QMessageBox::warning(NULL, SEAFILE_CLIENT_BRAND,
                             QObject::tr("%1 is already running").arg(SEAFILE_CLIENT_BRAND),
                             QMessageBox::Ok);
        return -1;
    }


    app.setQuitOnLastWindowClosed(false);

    // see QSettings documentation
    QCoreApplication::setOrganizationName(SEAFILE_CLIENT_BRAND);
    QCoreApplication::setOrganizationDomain("seafile.com");
    QCoreApplication::setApplicationName(QString("%1 Client").arg(SEAFILE_CLIENT_BRAND));

    // initialize i18n
    QTranslator qtTranslator;
    qtTranslator.load("qt_" + QLocale::system().name(),
                      QLibraryInfo::location(QLibraryInfo::TranslationsPath));
    app.installTranslator(&qtTranslator);

    QTranslator myappTranslator;
    myappTranslator.load(QString(":/i18n/seafile_%1.qm").arg(QLocale::system().name()));
    app.installTranslator(&myappTranslator);


#if !GLIB_CHECK_VERSION(2, 35, 0)
    g_type_init();
#endif
#if !GLIB_CHECK_VERSION(2, 31, 0)
    g_thread_init(NULL);
#endif

    awesome = new QtAwesome(qApp);
    awesome->initFontAwesome();

    seafApplet = new SeafileApplet;
    seafApplet->start();

    return app.exec();
}
