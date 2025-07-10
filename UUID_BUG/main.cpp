// #include <QCoreApplication>
// #include <QDebug>
// #include <QString>
// #include <QUuid>
// #include <QHash>

// int main(int argc, char *argv[])
// {
//     QCoreApplication app(argc, argv);

//     QHash<QString, QString> userTable;

//     // Create 1st user
//     QString user1Id = QUuid::createUuid().toString();
//     userTable.insert(user1Id, "Alice");

//     // Simulate a UUID collision (forcefully reusing the same ID)
//     QString user2Id = user1Id; // ❌ Collision
//     userTable.insert(user2Id, "Bob");

//     // Display user table
//     qDebug() << "User table contents:";
//     for (auto it = userTable.begin(); it != userTable.end(); ++it) {
//         qDebug() << it.key() << "->" << it.value();
//     }

//     return 0;
// }

#include <QCoreApplication>
#include <QDebug>
#include <QUuid>
#include <QHash>

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    QHash<QString, QString> userTable;

    // Create 1st user with safe check
    QString user1Id;
    do {
        user1Id = QUuid::createUuid().toString();
    } while (userTable.contains(user1Id));
    userTable.insert(user1Id, "Alice");

    // Create 2nd user with same safe check
    QString user2Id;
    do {
        user2Id = QUuid::createUuid().toString();
    } while (userTable.contains(user2Id));
    userTable.insert(user2Id, "Bob");

    // Display user table
    qDebug() << "User table contents:";
    for (auto it = userTable.begin(); it != userTable.end(); ++it) {
        qDebug() << it.key() << "->" << it.value();
    }

    return 0;
}
