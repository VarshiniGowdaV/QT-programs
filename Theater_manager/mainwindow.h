#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QDate>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();
    ~MainWindow();

private slots:
    void showPreviousMonth();
    void showNextMonth();

private:
    QPushButton *dayButtons[6][7];
    QPushButton *headerButtons[7];
    QPushButton *prevMonthButton;
    QPushButton *nextMonthButton;
    QPushButton *monthYearButton;

    QDate currentDate;

    void setupUI();
    void updateCalendar();
    void clearCalendar();
};

#endif

