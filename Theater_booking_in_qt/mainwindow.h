#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QVector>
#include <QDate>
#include "theatermanager.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void updateCalendar();
    void nextMonth();
    void previousMonth();
    void handleDateSelection();
    void bookTheatre();
    void checkBookings();
    void exitApplication();

private:
    void setupUI();
    void setupCalendar();
    void clearCalendar();
    bool isDateFullyBooked(int day);
    void highlightSelectedDate(int day);

    QPushButton *monthYearButton;
    QPushButton *prevMonthButton;
    QPushButton *nextMonthButton;
    QPushButton *bookButton;
    QPushButton *checkBookingsButton;
    QPushButton *exitButton;
    QVector<QVector<QPushButton*>> dayButtons;
    QDate currentDate;
    QDate selectedDate;
    QPushButton* selectedButton = nullptr;
    TheaterManager* manager;
};

#endif
