#include <QApplication>
#include "mywidget.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MyWidget w;
    w.show();  // ✅ Only w.show() here

    return app.exec();
}
