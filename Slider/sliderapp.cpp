#include "sliderapp.h"
#include <QVBoxLayout>
#include <QDebug>

SliderApp::SliderApp(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);

    slider = new QSlider(Qt::Horizontal, this);
    slider->setRange(0, 100);

    valueLabel = new QLabel("Value: 0", this);

    layout->addWidget(slider);
    layout->addWidget(valueLabel);

    connect(slider, &QSlider::valueChanged, this, &SliderApp::updateValue);

    setLayout(layout);
    setWindowTitle("Slider Value Display");
    resize(300, 100);
}

void SliderApp::updateValue(int value) {
    valueLabel->setText("Value: " + QString::number(value));
    static bool firstDisplay = true;
    if (firstDisplay) {
        qDebug() << "Current Slider Value:" << value;
        firstDisplay = false;
    } else {
        qInfo().noquote() << "\rCurrent Slider Value: " << value << " ";
    }
}
