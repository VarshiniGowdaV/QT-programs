#include "mainwindow.h"
#include <QFont>

MainWindow::MainWindow()
    : currentDate(QDate::currentDate())
{
    setupUI();
    updateCalendar();
}

MainWindow::~MainWindow() {}

void MainWindow::setupUI()
{
    this->setFixedSize(600, 450);

    prevMonthButton = new QPushButton("< Previous", this);
    prevMonthButton->setGeometry(10, 10, 120, 40);
    connect(prevMonthButton, &QPushButton::clicked, this, &MainWindow::showPreviousMonth);

    nextMonthButton = new QPushButton("Next >", this);
    nextMonthButton->setGeometry(460, 10, 120, 40);
    connect(nextMonthButton, &QPushButton::clicked, this, &MainWindow::showNextMonth);

    monthYearButton = new QPushButton("Month Year", this);
    monthYearButton->setGeometry(170, 10, 250, 40);
    monthYearButton->setFont(QFont("Arial", 14, QFont::Bold));
    monthYearButton->setStyleSheet("text-align: center;");

    const char* daysOfWeek[7] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
    QFont headerFont;
    headerFont.setBold(true);
    for (int i = 0; i < 7; ++i)
    {
        headerButtons[i] = new QPushButton(daysOfWeek[i], this);
        headerButtons[i]->setGeometry(40 + i * 75, 60, 75, 35);
        headerButtons[i]->setFont(headerFont);
        headerButtons[i]->setEnabled(false);
    }

    for (int row = 0; row < 6; ++row)
    {
        for (int col = 0; col < 7; ++col)
        {
            dayButtons[row][col] = new QPushButton(this);
            dayButtons[row][col]->setGeometry(40 + col * 75, 100 + row * 60, 75, 50);
            dayButtons[row][col]->setEnabled(false);
        }
    }
}

void MainWindow::updateCalendar()
{
    clearCalendar();

    QDate firstDay(currentDate.year(), currentDate.month(), 1);
    int startDay = firstDay.dayOfWeek() % 7;
    int daysInMonth = firstDay.daysInMonth();
    QDate today = QDate::currentDate();

    int day = 1;
    for (int i = 0; i < 6 && day <= daysInMonth; ++i)
    {
        for (int j = 0; j < 7; ++j)
        {
            if (i == 0 && j < startDay) continue;
            if (day > daysInMonth) break;

            QPushButton *btn = dayButtons[i][j];
            btn->setText(QString::number(day));
            btn->setEnabled(true);

            if (today.year() == currentDate.year() &&
                today.month() == currentDate.month() &&
                today.day() == day)
            {
                btn->setStyleSheet("background-color: Blue; font-weight: bold;");
            }
            else
            {
                btn->setStyleSheet("");
            }

            ++day;
        }
    }

    monthYearButton->setText(currentDate.toString("MMMM yyyy"));
}

void MainWindow::clearCalendar()
{
    for (int row = 0; row < 6; ++row)
    {
        for (int col = 0; col < 7; ++col)
        {
            dayButtons[row][col]->setText("");
            dayButtons[row][col]->setEnabled(false);
            dayButtons[row][col]->setStyleSheet("");
        }
    }
}

void MainWindow::showPreviousMonth()
{
    currentDate = currentDate.addMonths(-1);
    updateCalendar();
}

void MainWindow::showNextMonth()
{
    currentDate = currentDate.addMonths(1);
    updateCalendar();
}
