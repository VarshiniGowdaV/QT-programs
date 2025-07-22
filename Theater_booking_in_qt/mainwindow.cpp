#include "mainwindow.h"
#include <QInputDialog>
#include <QMessageBox>
#include <QLabel>
#include <QFont>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), currentDate(QDate::currentDate()), selectedDate(QDate())
{
    manager = new TheaterManager();
    setupUI();
    setupCalendar();
    updateCalendar();
}

MainWindow::~MainWindow()
{
    delete manager;
}

void MainWindow::setupUI()
{
    this->setFixedSize(500, 550);

    QStringList dayNames = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    for (int i = 0; i < 7; ++i)
    {
        QLabel* dayLabel = new QLabel(dayNames[i], this);
        dayLabel->setGeometry(50 + i * 60, 50, 50, 20);
        dayLabel->setAlignment(Qt::AlignCenter);
    }

    monthYearButton = new QPushButton(this);
    monthYearButton->setGeometry(150, 10, 200, 30);
    monthYearButton->setEnabled(false);
    monthYearButton->setStyleSheet("font-weight: bold; font-size: 16px; background-color: #f0f0f0;");

    prevMonthButton = new QPushButton("<", this);
    prevMonthButton->setGeometry(100, 10, 40, 30);
    connect(prevMonthButton, &QPushButton::clicked, this, &MainWindow::previousMonth);

    nextMonthButton = new QPushButton(">", this);
    nextMonthButton->setGeometry(360, 10, 40, 30);
    connect(nextMonthButton, &QPushButton::clicked, this, &MainWindow::nextMonth);

    bookButton = new QPushButton("Book Theatre", this);
    bookButton->setGeometry(120, 460, 120, 30);
    connect(bookButton, &QPushButton::clicked, this, &MainWindow::bookTheatre);

    checkBookingsButton = new QPushButton("Check Bookings", this);
    checkBookingsButton->setGeometry(260, 460, 120, 30);
    connect(checkBookingsButton, &QPushButton::clicked, this, &MainWindow::checkBookings);

    exitButton = new QPushButton("Exit", this);
    exitButton->setGeometry(190, 500, 120, 30);
    connect(exitButton, &QPushButton::clicked, this, &MainWindow::exitApplication);
}

void MainWindow::setupCalendar()
{
    dayButtons.resize(6);
    for (int i = 0; i < 6; ++i)
    {
        dayButtons[i].resize(7);
        for (int j = 0; j < 7; ++j)
        {
            dayButtons[i][j] = new QPushButton(this);
            dayButtons[i][j]->setGeometry(50 + j * 60, 80 + i * 60, 50, 50);
            dayButtons[i][j]->setEnabled(false);
            connect(dayButtons[i][j], &QPushButton::clicked, this, &MainWindow::handleDateSelection);
        }
    }
}

void MainWindow::clearCalendar()
{
    for (int i = 0; i < 6; ++i)
    {
        for (int j = 0; j < 7; ++j)
        {
            QPushButton* btn = dayButtons[i][j];
            btn->setText("");
            btn->setEnabled(false);
            btn->setStyleSheet("");
        }
    }
    selectedButton = nullptr;
}

void MainWindow::updateCalendar()
{
    clearCalendar();
    QDate firstDay(currentDate.year(), currentDate.month(), 1);
    int startDay = firstDay.dayOfWeek() % 7;
    int daysInMonth = firstDay.daysInMonth();

    int day = 1;
    for (int i = 0; i < 6 && day <= daysInMonth; ++i)
    {
        for (int j = 0; j < 7; ++j)
        {
            if (i == 0 && j < startDay) continue;
            if (day > daysInMonth) break;

            QPushButton* btn = dayButtons[i][j];
            btn->setText(QString::number(day));
            btn->setEnabled(true);

            QDate btnDate(currentDate.year(), currentDate.month(), day);

            if (btnDate == QDate::currentDate())
            {
                btn->setStyleSheet("background-color: green;");
            }
            else if (isDateFullyBooked(day))
            {
                btn->setStyleSheet("background-color: gray;");
            }

            ++day;
        }
    }

    monthYearButton->setText(currentDate.toString("< MMMM yyyy >"));
}

void MainWindow::nextMonth()
{
    currentDate = currentDate.addMonths(1);
    updateCalendar();
}

void MainWindow::previousMonth()
{
    currentDate = currentDate.addMonths(-1);
    updateCalendar();
}

void MainWindow::handleDateSelection()
{
    QPushButton* senderBtn = qobject_cast<QPushButton*>(sender());
    if (!senderBtn || senderBtn->text().isEmpty()) return;

    int day = senderBtn->text().toInt();
    selectedDate = QDate(currentDate.year(), currentDate.month(), day);

    if (selectedDate < QDate::currentDate()) {
        QMessageBox::warning(this, "Invalid Date", "Booking is only available for today or future dates.");
        selectedDate = QDate();
        return;
    }

    if (selectedButton)
    {
        int prevDay = selectedButton->text().toInt();
        QDate prevDate(currentDate.year(), currentDate.month(), prevDay);

        if (prevDate == QDate::currentDate())
            selectedButton->setStyleSheet("background-color: green;");
        else if (isDateFullyBooked(prevDay))
            selectedButton->setStyleSheet("background-color: gray;");
        else
            selectedButton->setStyleSheet("");
    }

    selectedButton = senderBtn;
    senderBtn->setStyleSheet("background-color: #9370DB;");
}

void MainWindow::bookTheatre()
{
    if (!selectedDate.isValid())
    {
        QMessageBox::warning(this, "Error", "Please select a valid date.");
        return;
    }

    bool ok;
    int theatreId = QInputDialog::getInt(this, "Book Theatre", "Enter Theatre ID (1-10):", 1, 1, 10, 1, &ok);
    if (ok)
    {
        QString dateStr = selectedDate.toString("dd-MM-yyyy");
        std::string dateStdStr = dateStr.toStdString();
        std::string theatreIdStr = std::to_string(theatreId);

        if (manager->isAvailable(dateStdStr, theatreIdStr))
        {
            manager->bookTheater(dateStdStr, theatreIdStr);
            QMessageBox::information(this, "Booking", "Theatre " + QString::number(theatreId) + " booked for " + dateStr);
            updateCalendar();
        }
        else
        {
            QMessageBox::warning(this, "Booking Failed", "Theatre " + QString::number(theatreId) + " is already booked on " + dateStr);
        }
    }
}

void MainWindow::checkBookings()
{
    if (!selectedDate.isValid())
    {
        QMessageBox::warning(this, "Error", "Please select a date first.");
        return;
    }

    QString dateStr = selectedDate.toString("dd-MM-yyyy");
    std::string dateStdStr = dateStr.toStdString();
    std::vector<std::string> booked = manager->getBookedTheatres(dateStdStr);

    if (booked.empty())
    {
        QMessageBox::information(this, "Bookings", "No theatres booked on " + dateStr);
    }
    else
    {
        QString bookedList;
        for (const auto& id : booked)
        {
            bookedList += QString::fromStdString(id) + " ";
        }
        QMessageBox::information(this, "Bookings", "Booked theatres on " + dateStr + ": " + bookedList);
    }
}

void MainWindow::exitApplication()
{
    close();
}

bool MainWindow::isDateFullyBooked(int day)
{
    QString dateStr = QDate(currentDate.year(), currentDate.month(), day).toString("dd-MM-yyyy");
    std::string dateStdStr = dateStr.toStdString();
    std::vector<std::string> booked = manager->getBookedTheatres(dateStdStr);
    return booked.size() >= 10;
}
