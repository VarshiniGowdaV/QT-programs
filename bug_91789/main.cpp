#include <QApplication>
#include <QLabel>
#include <QHBoxLayout>
#include <QPalette>
#include <QWidget>

QLabel* createColorLabel(const QString& name, const QColor& color)
{
    QLabel* label = new QLabel(name);
    label->setAutoFillBackground(true);

    QPalette palette = label->palette();
    palette.setColor(QPalette::Window, color);
    palette.setColor(QPalette::WindowText, Qt::black);
    label->setPalette(palette);
    label->setAlignment(Qt::AlignCenter);
    label->setFixedSize(80, 100);
    label->setFrameStyle(QFrame::Panel | QFrame::Raised);
    label->setLineWidth(2);

    return label;
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QWidget window;
    window.setWindowTitle("MainWindow");

    QPalette p = app.palette();

    QHBoxLayout* layout = new QHBoxLayout;

    layout->addWidget(createColorLabel("Light", p.color(QPalette::Light)));
    layout->addWidget(createColorLabel("Midlight", p.color(QPalette::Midlight)));
    layout->addWidget(createColorLabel("Button", p.color(QPalette::Button)));
    layout->addWidget(createColorLabel("Dark", p.color(QPalette::Dark)));
    layout->addWidget(createColorLabel("Mid", p.color(QPalette::Mid)));
    layout->addWidget(createColorLabel("Shadow", p.color(QPalette::Shadow)));

    window.setLayout(layout);
    window.show();

    return app.exec();
}
