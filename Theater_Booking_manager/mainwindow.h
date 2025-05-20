#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QDate>
#include <QMessageBox>
#include <QInputDialog>
#include <QVector>
#include <QMap>
#include <QSet>

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
    QDate selectedDate;

    QMap<QString, QSet<int>> bookings;

    void setupUI();
    void setupCalendar();
    void updateCalendar();
    void clearCalendar();
    bool isDateFullyBooked(int day);
    bool isToday(int day);

private slots:
    void showPreviousMonth();
    void showNextMonth();
    void bookTheatre();
    void checkBookings();
    void selectDate();
};

#endif // MAINWINDOW_H

