// #include <QCoreApplication>
// #include <QList>
// #include <QString>
// #include <QDebug>

// int main(int argc, char *argv[])
// {
//     QCoreApplication a(argc, argv);

//     QList<QString> names;
//     names << "Alice" << "Bob" << "Charlie";

//     qDebug() << "Names:";
//     for (const QString &name : names) {
//         qDebug() << name;
//     }

//     return a.exec();
// }
#include <QCoreApplication>
#include <QList>
#include <QByteArray>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList<QByteArray> dataPackets;

    dataPackets << QByteArray("GET / HTTP/1.1")
                << QByteArray::fromHex("48656c6c6f")  // "Hello" in hex
                << QByteArray::fromBase64("U29tZSBCYXNlNjQ=");  // "Some Base64"

    qDebug() << "Raw Data Packets:";
    for (const QByteArray &packet : dataPackets) {
        qDebug() << packet;
    }

    return a.exec();
}
