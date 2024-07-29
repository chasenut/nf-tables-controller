#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "Global.h"
#include "Controller.h"
#include "IpBlockController.h"
#include <QtWidgets/qapplication.h>

/// enable nftables
// sudo systemctl enable nftables
// sudo systemctl start nftables

int main(int argc, char *argv[])
{

    //QGuiApplication app(argc, argv);
    QApplication app(argc, argv);
    system("sudo systemctl enable nftables"); // enable nftables

    Global *global = new Global(&app);
    Controller *controller = new Controller(&app);
    IpBlockController *ipBlockController = new IpBlockController(&app);
    qmlRegisterSingletonInstance("app.Global", 1, 0, "Global", global);
    qmlRegisterSingletonInstance("app.Controller", 1, 0, "Controller", controller);
    qmlRegisterSingletonInstance("app.IpBlockController", 1, 0, "IpBlockController", ipBlockController);


    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/NFTManager/Main.qml"));
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
