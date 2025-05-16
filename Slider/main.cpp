#include <QApplication>
#include "sliderapp.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    SliderApp window;
    window.show();

    return app.exec();
}

