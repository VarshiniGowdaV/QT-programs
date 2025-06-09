#include <QApplication>
#include "mywidget.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MyWidget widget(200, 150, 200, 100);
    widget.resize(700, 500);
    widget.setWindowTitle("Shape Drawer");
    widget.show();

    return app.exec();
}
