#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "Header.hpp"

/**
 * @brief The main function of the application.
 *
 * This function initializes the application, registers custom types, loads the QML file,
 * and starts the event loop.
 *
 * @param argc The number of command line arguments.
 * @param argv The command line arguments.
 * @return The exit code of the application.
 */

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    // qmlRegisterType<Mmpose_params>("com.myobject", 1, 1, "mmpose_params"); // registers a custom class / type for QML 
    qmlRegisterType<DataModel>("com.myobject", 1, 1, "DataModel"); // registers a custom class / type for QML

    
    const QUrl url(u"qrc:/test/Main.qml"_qs);

    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
