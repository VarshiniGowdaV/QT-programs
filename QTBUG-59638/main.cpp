// #include <QCoreApplication>
// #include <QMultiHash>
// #include <QDebug>

// int main(int argc, char *argv[])
// {
//     QCoreApplication a(argc, argv);
    // QMultiHash<int ,int>myhash;
    // myhash.insert(10,1);
    // myhash.insert(20,2);
    // myhash.insert(5,3);
    // myhash.insert(10,2);
    // myhash.insert(4,3);
    // myhash.insert(6,3);
    // myhash.insert(10,2);
    // myhash.insert(6,2);
    // myhash.insert(8,2);
    // myhash.insert(10,2);
    // myhash.insert(4,2);
    // myhash.insert(1,2);
    // myhash.insert(10,5);

    //qDebug() <<"Values of the numbers :" <<myhash;
//     return 0;
// }


// #include <QCoreApplication>
// #include <QHash>
// #include <QDebug>

// int main(int argc, char *argv[])
// {
//     QCoreApplication a(argc, argv);

//     QHash<int, int> myHash;
//     myHash.insert(10, 1);
//     myHash.insert(20, 2);
//     myHash.insert(5, 3);
//     myHash.insert(10, 2);  // Overwrites previous value for key 10
//     myHash.insert(4, 3);
//     myHash.insert(6, 3);
//     myHash.insert(10, 2);  // Overwrites again
//     myHash.insert(6, 2);   // Overwrites previous value for key 6
//     myHash.insert(8, 2);
//     myHash.insert(10, 2);  // Overwrites again
//     myHash.insert(4, 2);   // Overwrites previous value for key 4
//     myHash.insert(1, 2);
//     myHash.insert(10, 5);  // Final overwrite for key 10

//        qDebug() <<"Values of the numbers :" <<myHash;

//     return 0;
// }


// #include <QCoreApplication>
// #include <QMultiMap>
// #include <QDebug>
// int main(int argc, char *argv[])
// {
//     QCoreApplication a(argc, argv);
//     QMultiMap<int, int> mymap;
//      mymap.insert(10, 1);
//      mymap.insert(0, 2);
//      mymap.insert(10,2);
//      mymap.insert(2, 1);
//      mymap.insert(1, 5);
//      mymap.insert(10, 3);
//      mymap.insert(5, 4);
//      mymap.insert(1, 2);
//      mymap.insert(4, 1);
//      mymap.insert(10, 4);
//      mymap.insert(10, 10);

//      qDebug() <<"value of the number :"<<mymap;
//      return 0;
// }

#include <QCoreApplication>
#include <QMap>
#include <QDebug>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QMap<int, int> mymap;
     mymap.insert(10, 1);
     mymap.insert(0, 2);
     mymap.insert(10,2);
     mymap.insert(2, 1);
     mymap.insert(1, 5);
     mymap.insert(10, 3);
     mymap.insert(5, 4);
     mymap.insert(1, 2);
     mymap.insert(4, 1);
     mymap.insert(10, 4);
     mymap.insert(10, 10);

     qDebug() <<"value of the number :"<<mymap;
     return 0;
}

