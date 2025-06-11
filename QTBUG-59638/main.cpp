#include <QCoreApplication>
#include <QMultiMap>
#include <QDebug>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QMultiMap<QString, int> map;
    map.insert("apple", 1);
    map.insert("bpple", 2);
    map.insert("ze", 0);
    QMultiMap<int, int> mymap;
    mymap.insert(10, 1);
    mymap.insert(0, 2);
    mymap.insert(10, 10);

    //  QList<int> values = map.values("apple");
    qDebug() << "Values for key 'apple':" << mymap;

    return 0;
}
