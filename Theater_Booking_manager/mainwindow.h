#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QDate>
#include <QMessageBox>
#include <QInputDialog>
#include <QVector>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();
    ~MainWindow();

private:
    QPushButton *prevMonthButton;
    QPushButton *nextMonthButton;
    QPushButton *monthYearButton;
    QPushButton *bookTheatreButton;
    QPushButton *checkBookingsButton;
    QPushButton *exitButton;
    QVector<QVector<QPushButton*>> dayButtons;
    QDate currentDate;

    void setupUI();
    void setupCalendar();
    void updateCalendar();
    void clearCalendar();
    bool isDateFullyBooked(int day);

private slots:
    void showPreviousMonth();
    void showNextMonth();
    void bookTheatre();
    void checkBookings();
};

#endif // MAINWINDOW_H


// #ifndef MAINWINDOW_H
// #define MAINWINDOW_H
// #include <QMainWindow>
// #include <QPushButton>
// #include <QComboBox>
// #include <QTextEdit>
// #include <QCalendarWidget>
// #include <QLabel>
// #include <QDate>
// #include <QMap>

// class MainWindow : public QMainWindow
// {
//     Q_OBJECT
// public:
//     explicit MainWindow(QWidget *parent = nullptr);
//     ~MainWindow();
// private slots:
//     void onPreviousMonthClicked();
//     void onNextMonthClicked();
//     void onBookTheatreClicked();
//     void onCheckBookingsClicked();
//     void onExitClicked();
// private:
//     void updateStatus(const QString &status);

//     QCalendarWidget *calendar;
//     QPushButton *prevMonthButton;
//     QPushButton *nextMonthButton;
//     QPushButton *bookTheatreButton;
//     QPushButton *checkBookingsButton;
//     QPushButton *exitButton;
//     QComboBox *theatreComboBox;
//     QTextEdit *statusTextEdit;
//     QLabel *monthLabel;
//     QMap<QDate, QList<int>> bookedTheatres;  // Store bookings with dates
// };

// #endif
