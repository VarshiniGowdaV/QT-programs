#include <QCoreApplication>
#include <QTimerEvent>
#include <QDebug>

class MyObject : public QObject {
public:
    MyObject() {
        startTimer(1000); // 1 second
    }

protected:
    void timerEvent(QTimerEvent *event) override {
        qDebug() << "Timer triggered:" << event->timerId();
        //QObject::timerEvent(event); // Uncommenting this changes nothing
    }
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    MyObject obj;
    return a.exec();
}
