#include <QCoreApplication>
#include <QDebug>
#include <QTimer>
#include <QThread>

// Define custom type
struct MyType {
    int value;
};
Q_DECLARE_METATYPE(MyType)

// Producer class
class Producer : public QObject {
    Q_OBJECT
public:
    using QObject::QObject;
signals:
    void sendValue(MyType val);
};

// Consumer class
class Consumer : public QObject {
    Q_OBJECT
public slots:
    void receiveValue(MyType val) {
        qDebug() << "Received value:" << val.value;
    }
};

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);

    qRegisterMetaType<MyType>("MyType");

    Producer producer;
    Consumer consumer;
    QThread thread;

    consumer.moveToThread(&thread);

    QObject::connect(&producer, &Producer::sendValue,
                     &consumer, &Consumer::receiveValue,
                     Qt::QueuedConnection);

    thread.start();

    QTimer::singleShot(100, [&]() {
        emit producer.sendValue({123});
    });

    QTimer::singleShot(500, &app, &QCoreApplication::quit);

    int result = app.exec();
    thread.quit();
    thread.wait();
    return result;
}

#include "main.moc"  // <------ Required for moc to generate code when all is in one file





// #include <QCoreApplication>
// #include <QDebug>
// #include <QTimer>
// #include <QThread>

// struct MyType {
//     int value;
// };
// Q_DECLARE_METATYPE(MyType)

// class Producer : public QObject {
//     Q_OBJECT
// public:
//     using QObject::QObject;
// signals:
//     void sendValue(MyType val);
// };

// class Consumer : public QObject {
//     Q_OBJECT
// public:
//     using QObject::QObject;
// public slots:
//     void receiveValue(MyType val) {
//         qDebug() << "Received value:" << val.value;
//     }
// };

// int main(int argc, char *argv[]) {
//     QCoreApplication app(argc, argv);
//     qRegisterMetaType<MyType>("MyType");

//     Producer producer;
//     Consumer consumer;
//     QThread thread;

//     consumer.moveToThread(&thread);

//     QObject::connect(&producer, &Producer::sendValue,
//                      &consumer, &Consumer::receiveValue,
//                      Qt::QueuedConnection);

//     thread.start();
//     QTimer::singleShot(100, [&]() {
//         emit producer.sendValue({456});
//     });

//     QTimer::singleShot(500, &app, &QCoreApplication::quit);
//     return app.exec();
// }

// // ✅ Correct moc include
// #include "main.moc"
