#include <QApplication>
#include <QDialog>
#include <QPushButton>
#include <QVBoxLayout>
#include <QKeyEvent>
#include <QCloseEvent>
#include <QDebug>

class TestDialog : public QDialog {
public:
    bool closeEventCalled = false;

    TestDialog(QWidget *parent = nullptr) : QDialog(parent) {
        setWindowTitle("QTBUG-112763 Test");

        QPushButton *button = new QPushButton("Close Dialog");
        connect(button, &QPushButton::clicked, this, &QDialog::close);

        QVBoxLayout *layout = new QVBoxLayout(this);
        layout->addWidget(button);
    }

protected:
    void keyPressEvent(QKeyEvent *event) override {
        if (event->key() == Qt::Key_Escape) {
            qDebug() << "[KEY] Escape key pressed → calling QDialog::close()";
            QDialog::close();  // 🔁 CHANGED from reject() to close()
        } else {
            QDialog::keyPressEvent(event);
        }
    }

    void closeEvent(QCloseEvent *event) override {
        closeEventCalled = true;
        qDebug() << "[EVENT] closeEvent() triggered!";
        QDialog::closeEvent(event);
    }
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    TestDialog dialog;
    dialog.exec();

    qDebug() << "[RESULT] Dialog closed with result:" << dialog.result();
    qDebug() << "[CHECK] Was closeEvent() called?" << dialog.closeEventCalled;

    return 0;
}
