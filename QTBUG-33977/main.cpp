#include <QCoreApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    QStringList args = app.arguments();

    for (int i = 0; i < args.size(); ++i) {
        qDebug() << "Argument" << i << ":" << args.at(i);
    }

    return 0;
}
