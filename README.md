# Qt Quick Custom Types Demo

This is a Qt Quick application that demonstrates the use of custom C++ types in QML.

## Overview

The application uses `QGuiApplication` and `QQmlApplicationEngine` to handle GUI-specific aspects and load/run QML files.

Two custom C++ types, `MyObject` and `DataModel`, are registered with the QML type system using `qmlRegisterType`. `MyObject` has properties `foo` and `bar`, and a default three-way comparison operator. `DataModel` has a `data` property of type `MyObject` and a `toJson` function.

In `Main.qml`, a `Window` is created with a `DataModel` object and a `TextArea`. The `DataModel` object's `data` property is logged, updated, and logged again. The `TextArea` displays the initial and updated values of `data`.

The application is built and run in Qt Creator using the appropriate kit.

