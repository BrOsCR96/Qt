#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "./src/Battery.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    qmlRegisterType<Battery>("CustomComponents", 1, 0, "Battery");

    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("Brian", "Main");

    return app.exec();
}
