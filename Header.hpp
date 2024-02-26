#pragma once

#include <QtQml>
#include <compare>

struct MyObject
{
    Q_GADGET // Macro to enable Qt's meta-object system for this struct

    Q_PROPERTY(QString foo MEMBER foo) // Declares a QString property named "foo" with a member variable "foo"
    Q_PROPERTY(int bar MEMBER bar) // Declares an int property named "bar" with a member variable "bar"
public:
    QString foo = "heleeeeeelo"; // Default value for the "foo" property
    int bar = 123; // Default value for the "bar" property

    std::strong_ordering operator<=>(const MyObject &) const = default; // Provides a strong ordering comparison operator (<=>) for comparing two MyObject instances
};

struct DataModel : public QObject
{
    Q_OBJECT // Macro to enable Qt's meta-object system for this class

    Q_PROPERTY(MyObject data MEMBER data) // Declares a property named "data" with a member variable "data" of type MyObject
public:
    MyObject data; // Instance of MyObject

    Q_INVOKABLE QString toJson() // Declares a invokable method named "toJson" that returns a QString
    {
        /// magic
        return {}; // Placeholder return statement
    }
};
