// #include <QCoreApplication>
// #include <QMultiMap>
// #include <QDebug>
// int main(int argc, char *argv[])
// {
//     QCoreApplication a(argc, argv);

//     QMultiMap<QString, int> map;
//     map.insert("apple", 1);
//     map.insert("apple", 6);
//     map.insert("pple", 2);
//     map.insert("e", 0);
//     map.insert("banana",4);
//     map.insert("pineapple",5);
//     map.insert("gova",9);
//     map.insert("mango",9);
//     map.insert("orange",8);
//     map.insert("kiwi",3);
//     map.insert("grapes",7);
    // QMultiMap<QString, int> tmap;
    // tmap.insert("apple", 8);
    // tmap.insert("bapple", 9);
    // tmap.insert("zapple", 10);
    // QMultiMap<int, int> mymap;
    // mymap.insert(10, 1);
    // mymap.insert(0, 2);
    // mymap.insert(10, 10);
    // QMultiMap<float ,int>qmap;
    // qmap.insert(10.8,1);
    // qmap.insert(10.6,2);    // QMultiMap<QString, int> tmap;
    // tmap.insert("apple", 8);
    // tmap.insert("bapple", 9);
    // tmap.insert("zapple", 10);
    // QMultiMap<int, int> mymap;
    // mymap.insert(10, 1);
    // mymap.insert(0, 2);
    // mymap.insert(10, 10);
    // QMultiMap<float ,int>qmap;
    // qmap.insert(10.8,1);
    // qmap.insert(10.6,2);
    // qmap.insert(10.9,3);

    // qDebug() <<"Valued number : "<<tmap;

    // qDebug() <<"Valued number : "<<map;
    // qDebug() << "Values for key 'apple':" << mymap;
    // qmap.insert(10.9,3);

    // qDebug() <<"Valued number : "<<tmap;

    // qDebug() <<"Valued number : "<<map;
    // qDebug() << "Values for key 'apple':" << mymap;
//     qDebug() <<"Valued number : "<<map;

//     return 0;
// }


#include <QCoreApplication>
#include <QMultiHash>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QMultiHash<QString, int>hash;
    hash.insert("apple", 1);
    hash.insert("apple", 1);
    hash.insert("pple", 2);
    hash.insert("e", 0);
    QMultiHash<int ,int>myhash;
    myhash.insert(10,1);
    myhash.insert(20,2);
    myhash.insert(5,3);

    QMultiHash<float ,int>qhash;
    qhash.insert(10.8,2);
    qhash.insert(10.6,1);
    qhash.insert(10.9,3);

    qDebug() << "Values for key 'apple':" << hash;
    qDebug() <<"Values of the numbers :" <<myhash;
    qDebug() <<"Valued number : "<<qhash;
    return 0;
}
