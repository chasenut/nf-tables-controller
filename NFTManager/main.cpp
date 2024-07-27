#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "Global.h"

/// enable nftables
// sudo systemctl enable nftables
// sudo systemctl start nftables

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    Global global(&app);
    qmlRegisterSingletonInstance("app.Global", 1, 0, "Global", &global);

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
