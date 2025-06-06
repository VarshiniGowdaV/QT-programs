#include <QApplication>
#include "mywidget.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    int x = 50;
    int y = 60;
    int width = 200;
    int height = 100;

    MyWidget widget(x, y, width, height);
    widget.show();

    return app.exec();
}
