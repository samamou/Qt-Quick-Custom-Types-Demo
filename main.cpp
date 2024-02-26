#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "Header.hpp"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    // Register custom types for QML
    qmlRegisterType<MyObject>("com.myobject", 1, 1, "myObject"); // registers a custom class / type for QML 
    qmlRegisterType<DataModel>("com.myobject", 1, 1, "DataModel"); // registers a custom class / type for QML

    const QUrl url(u"qrc:/test/Main.qml"_qs);

    // Handle object creation failure
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);

    engine.load(url);

    return app.exec();
}
