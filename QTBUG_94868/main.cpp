// #include <QApplication>
// #include <QQuickWidget>
// #include <QQuickWindow>
// #include <QDebug>

// int main(int argc, char *argv[])
// {
//     QApplication app(argc, argv);

//     QQuickWidget *quickWidget = new QQuickWidget;
//     quickWidget->setSource(QUrl("qrc:/Main.qml"));
//     quickWidget->resize(400, 300);
//     quickWidget->show();

//     // ❌ Incorrect assumption: trying to cast the window to QQuickWindow
//     QQuickWindow *qw = qobject_cast<QQuickWindow*>(quickWidget->window());
//     if (qw) {
//         qDebug() << "Got QQuickWindow from QQuickWidget!";  // Dev thinks this will happen
//     } else {
//         qDebug() << "No QQuickWindow — this is NOT a wrapper.";  // This is the actual output
//     }

//     return app.exec();
// }


#include <QApplication>
#include <QQuickWidget>
#include <QVBoxLayout>
#include <QWidget>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("Correct QQuickWidget Usage");

    // Correct: QQuickWidget renders QML using QQuickRenderControl
    QQuickWidget *quickWidget = new QQuickWidget;
    quickWidget->setResizeMode(QQuickWidget::SizeRootObjectToView);
    quickWidget->setSource(QUrl("qrc:/MainView.qml"));

    QVBoxLayout *layout = new QVBoxLayout(&window);
    layout->addWidget(quickWidget);
    window.setLayout(layout);

    window.resize(400, 300);
    window.show();

    return app.exec();
}
