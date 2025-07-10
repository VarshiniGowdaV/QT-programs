// #include <QCoreApplication>
// #include <QImage>
// #include <QDebug>

// int main(int argc, char *argv[])
// {
//     QCoreApplication a(argc, argv);

//     QImage original(100, 100, QImage::Format_RGB888);
//     qDebug() << "Original format:" << original.format();  // Format_RGB888

//     QImage scaled = original.scaled(50, 50, Qt::KeepAspectRatio, Qt::SmoothTransformation);
//     qDebug() << "Scaled format:" << scaled.format();      // ⚠️ Format_RGB32 — unexpected!

//     // This may cause issues if you rely on Format_RGB888
//     return 0;
// }


//main_fixed.cpp – scales and then converts back to RGB888
#include <QCoreApplication>
#include <QImage>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    QImage original(100, 100, QImage::Format_RGB888);
    qDebug() << "Original format:" << original.format();   //  QImage::Format_RGB888

    QImage scaled = original.scaled(50, 50,
                                    Qt::KeepAspectRatio,
                                    Qt::SmoothTransformation)
                        .convertToFormat(QImage::Format_RGB888); // restore format
    qDebug() << "Scaled format :" << scaled.format();      //  QImage::Format_RGB888
    return 0;
}




