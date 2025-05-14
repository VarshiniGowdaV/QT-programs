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
    this->setFixedSize(500, 400);

    prevMonthButton = new QPushButton("< Previous", this);
    prevMonthButton->setGeometry(10, 10, 100, 30);
    connect(prevMonthButton, &QPushButton::clicked, this, &MainWindow::showPreviousMonth);

    nextMonthButton = new QPushButton("Next >", this);
    nextMonthButton->setGeometry(380, 10, 100, 30);
    connect(nextMonthButton, &QPushButton::clicked, this, &MainWindow::showNextMonth);

    monthYearLabel = new QLabel(this);
    monthYearLabel->setGeometry(150, 10, 200, 30);
    monthYearLabel->setAlignment(Qt::AlignCenter);
    monthYearLabel->setFont(QFont("Arial", 14, QFont::Bold));

    QStringList weekDays = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    QFont headerFont;
    headerFont.setBold(true);
    for (int i = 0; i < 7; ++i)
    {
        headerButtons[i] = new QPushButton(weekDays[i], this);
        headerButtons[i]->setGeometry(20 + i * 60, 50, 60, 30);
        headerButtons[i]->setFont(headerFont);
        headerButtons[i]->setEnabled(false);
    }

    for (int row = 0; row < 6; ++row)
    {
        for (int col = 0; col < 7; ++col)
        {
            dayButtons[row][col] = new QPushButton(this);
            dayButtons[row][col]->setGeometry(20 + col * 60, 90 + row * 50, 60, 40);
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
                btn->setStyleSheet("background-color: lightblue; font-weight: bold;");
            }
            else
            {
                btn->setStyleSheet("");
            }

            ++day;
        }
    }

    monthYearLabel->setText(currentDate.toString("MMMM yyyy"));
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

