#include <QCoreApplication>
#include <QJSEngine>
#include <QJSValue>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    QJSEngine engine;

    // -------- Example 1: Object property --------
    QJSValue person = engine.newObject();  // create JS object
    person.setProperty("name", QJSValue("Alice"));
    person.setProperty("age", QJSValue(30));

    qDebug() << "Name:" << person.property("name").toString();  // Output: "Alice"
    qDebug() << "Age:" << person.property("age").toInt();       // Output: 30

    // -------- Example 2: Array property --------
    QJSValue array = engine.newArray(3);  // create JS array
    array.setProperty(0, QJSValue("Red"));
    array.setProperty(1, QJSValue("Green"));
    array.setProperty(2, QJSValue("Blue"));

    for (int i = 0; i < 3; ++i) {
        qDebug() << "Array[" << i << "] =" << array.property(i).toString();
    }

    return 0;
}
