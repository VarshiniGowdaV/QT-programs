#include "mainwindow.h"
#include <QApplication>
#include <QInputDialog>
#include <QMessageBox>

MainWindow::MainWindow() : currentDate(QDate::currentDate()), selectedDate(QDate::currentDate())
{
    setupUI();
    updateCalendar();
}

MainWindow::~MainWindow() {}

void MainWindow::setupUI()
{
    this->setFixedSize(500, 500);

    prevMonthButton = new QPushButton("< Previous", this);
    prevMonthButton->setGeometry(10, 10, 100, 30);
    connect(prevMonthButton, &QPushButton::clicked, this, &MainWindow::showPreviousMonth);

    nextMonthButton = new QPushButton("Next >", this);
    nextMonthButton->setGeometry(380, 10, 100, 30);
    connect(nextMonthButton, &QPushButton::clicked, this, &MainWindow::showNextMonth);

    monthYearButton = new QPushButton(this);
    monthYearButton->setGeometry(150, 10, 200, 30);
    monthYearButton->setEnabled(false);

    QFont boldFont = monthYearButton->font();
    boldFont.setBold(true);
    boldFont.setPointSize(12);
    monthYearButton->setFont(boldFont);
    monthYearButton->setStyleSheet("color: white; text-align: center;font-weight: bold");

    bookTheatreButton = new QPushButton("Book Theatre", this);
    bookTheatreButton->setGeometry(10, 450, 100, 30);
    connect(bookTheatreButton, &QPushButton::clicked, this, &MainWindow::bookTheatre);

    checkBookingsButton = new QPushButton("Check Bookings", this);
    checkBookingsButton->setGeometry(130, 450, 120, 30);
    connect(checkBookingsButton, &QPushButton::clicked, this, &MainWindow::checkBookings);

    exitButton = new QPushButton("Exit", this);
    exitButton->setGeometry(380, 450, 100, 30);
    connect(exitButton, &QPushButton::clicked, this, &MainWindow::close);

    setupCalendar();
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
            dayButtons[i][j]->setGeometry(50 + j * 60, 50 + i * 60, 50, 50);
            dayButtons[i][j]->setEnabled(false);
            connect(dayButtons[i][j], &QPushButton::clicked, this, &MainWindow::selectDate);
        }
    }
}

void MainWindow::updateCalendar()
{
    clearCalendar();
    QDate firstDay(currentDate.year(), currentDate.month(), 1);
    int startDay = firstDay.dayOfWeek() % 7; // Sunday=0
    int daysInMonth = firstDay.daysInMonth();

    int day = 1;
    QDate today = QDate::currentDate();

    for (int i = 0; i < 6 && day <= daysInMonth; ++i)
    {
        for (int j = 0; j < 7; ++j)
        {
            if (i == 0 && j < startDay) continue;
            if (day > daysInMonth) break;

            QPushButton *btn = dayButtons[i][j];
            btn->setText(QString::number(day));
            btn->setEnabled(true);

            QDate thisDay(currentDate.year(), currentDate.month(), day);
            QString dateStr = thisDay.toString("dd-MM-yyyy");

            if (isDateFullyBooked(day)) {
                btn->setStyleSheet("background-color: gray;");
            } else if (thisDay == selectedDate) {
                btn->setStyleSheet("background-color: grey; font-weight: bold;");
            } else if (thisDay == today) {
                btn->setStyleSheet("background-color: lightblue; font-weight: bold;");
            } else {
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
            QPushButton *btn = dayButtons[row][col];
            btn->setText("");
            btn->setEnabled(false);
            btn->setStyleSheet("");
        }
    }
}

void MainWindow::selectDate()
{
    QPushButton* senderBtn = qobject_cast<QPushButton*>(sender());
    if (!senderBtn) return;

    bool ok;
    int day = senderBtn->text().toInt(&ok);
    if (!ok) return;

    selectedDate = QDate(currentDate.year(), currentDate.month(), day);

    updateCalendar();

    QMessageBox::information(this, "Date Selected", "You selected " + selectedDate.toString("dd-MM-yyyy"));
}

void MainWindow::bookTheatre()
{
    if (!selectedDate.isValid()) {
        QMessageBox::warning(this, "No Date Selected", "Please select a date first.");
        return;
    }

    QDate today = QDate::currentDate();
    if (selectedDate < today) {
        QMessageBox::warning(this, "Invalid Date", "Booking only allowed for today or future dates.");
        return;
    }

    bool ok;
    int theatreId = QInputDialog::getInt(this, "Book Theatre", "Enter Theatre ID (1-10):", 1, 1, 10, 1, &ok);
    if (ok)
    {
        QString dateStr = selectedDate.toString("dd-MM-yyyy");
        QSet<int> &booked = bookings[dateStr];

        if (booked.contains(theatreId)) {
            QMessageBox::warning(this, "Already Booked", "Theatre " + QString::number(theatreId) + " is already booked on " + dateStr);
        } else {
            booked.insert(theatreId);
            QMessageBox::information(this, "Booking", "Theatre " + QString::number(theatreId) + " booked for " + dateStr);
            updateCalendar();
        }
    }
}

void MainWindow::checkBookings()
{
    QString dateStr = selectedDate.isValid() ? selectedDate.toString("dd-MM-yyyy") : currentDate.toString("dd-MM-yyyy");
    int bookedCount = bookings[dateStr].size();
    int availableTheatres = 10 - bookedCount;
    QMessageBox::information(this, "Bookings", QString::number(availableTheatres) + " theatres available on " + dateStr);
}

bool MainWindow::isDateFullyBooked(int day)
{
    QDate thisDay(currentDate.year(), currentDate.month(), day);
    QString dateStr = thisDay.toString("dd-MM-yyyy");
    return bookings[dateStr].size() >= 10;
}

void MainWindow::showPreviousMonth()
{
    currentDate = currentDate.addMonths(-1);
    selectedDate = QDate();
    updateCalendar();
}

void MainWindow::showNextMonth()
{
    currentDate = currentDate.addMonths(1);
    selectedDate = QDate();
    updateCalendar();
}

// #include "mainwindow.h"
// #include <QApplication>
// #include <QInputDialog>
// #include <QMessageBox>

// MainWindow::MainWindow() : currentDate(QDate::currentDate())
// {
//     setupUI();
//     updateCalendar();
// }

// MainWindow::~MainWindow() {}

// void MainWindow::setupUI()
// {
//     this->setFixedSize(500, 500);

//     prevMonthButton = new QPushButton("< Previous", this);
//     prevMonthButton->setGeometry(10, 10, 100, 30);
//     connect(prevMonthButton, &QPushButton::clicked, this, &MainWindow::showPreviousMonth);

//     nextMonthButton = new QPushButton("Next >", this);
//     nextMonthButton->setGeometry(380, 10, 100, 30);
//     connect(nextMonthButton, &QPushButton::clicked, this, &MainWindow::showNextMonth);

//     monthYearButton = new QPushButton(this);
//     monthYearButton->setGeometry(150, 10, 200, 30);
//     monthYearButton->setEnabled(false);

//     QFont boldFont = monthYearButton->font();
//     boldFont.setBold(true);
//     boldFont.setPointSize(12);
//     monthYearButton->setFont(boldFont);
//     monthYearButton->setStyleSheet("color: white; text-align: center;font-weight: bold");


//     bookTheatreButton = new QPushButton("Book Theatre", this);
//     bookTheatreButton->setGeometry(10, 450, 100, 30);
//     connect(bookTheatreButton, &QPushButton::clicked, this, &MainWindow::bookTheatre);

//     checkBookingsButton = new QPushButton("Check Bookings", this);
//     checkBookingsButton->setGeometry(130, 450, 120, 30);
//     connect(checkBookingsButton, &QPushButton::clicked, this, &MainWindow::checkBookings);

//     exitButton = new QPushButton("Exit", this);
//     exitButton->setGeometry(380, 450, 100, 30);
//     connect(exitButton, &QPushButton::clicked, this, &MainWindow::close);

//     setupCalendar();
// }

// void MainWindow::setupCalendar()
// {
//     dayButtons.resize(6);
//     for (int i = 0; i < 6; ++i)
//     {
//         dayButtons[i].resize(7);
//         for (int j = 0; j < 7; ++j)
//         {
//             dayButtons[i][j] = new QPushButton(this);
//             dayButtons[i][j]->setGeometry(50 + j * 60, 50 + i * 60, 50, 50);
//             dayButtons[i][j]->setEnabled(false);
//         }
//     }
// }

// void MainWindow::updateCalendar()
// {
//     clearCalendar();
//     QDate firstDay(currentDate.year(), currentDate.month(), 1);
//     int startDay = firstDay.dayOfWeek() % 7;
//     int daysInMonth = firstDay.daysInMonth();

//     int day = 1;
//     QDate today = QDate::currentDate();

//     for (int i = 0; i < 6 && day <= daysInMonth; ++i)
//     {
//         for (int j = 0; j < 7; ++j)
//         {
//             if (i == 0 && j < startDay) continue;
//             if (day > daysInMonth) break;

//             QPushButton *btn = dayButtons[i][j];
//             btn->setText(QString::number(day));
//             btn->setEnabled(true);

//             QDate thisDay(currentDate.year(), currentDate.month(), day);
//             QString dateStr = thisDay.toString("dd-MM-yyyy");

//             if (isDateFullyBooked(day)) {
//                 btn->setStyleSheet("background-color: gray;");
//             } else if (thisDay == today) {
//                 btn->setStyleSheet("background-color: lightblue; font-weight: bold;");
//             } else {
//                 btn->setStyleSheet("");
//             }

//             ++day;
//         }
//     }

//     monthYearButton->setText(currentDate.toString("MMMM yyyy"));
// }

// void MainWindow::clearCalendar()
// {
//     for (int row = 0; row < 6; ++row)
//     {
//         for (int col = 0; col < 7; ++col)
//         {
//             QPushButton *btn = dayButtons[row][col];
//             btn->setText("");
//             btn->setEnabled(false);
//             btn->setStyleSheet("");
//         }
//     }
// }

// void MainWindow::bookTheatre()
// {
//     bool ok;
//     int theatreId = QInputDialog::getInt(this, "Book Theatre", "Enter Theatre ID (1-10):", 1, 1, 10, 1, &ok);
//     if (ok)
//     {
//         QString dateStr = currentDate.toString("dd-MM-yyyy");
//         QSet<int> &booked = bookings[dateStr];

//         if (booked.contains(theatreId)) {
//             QMessageBox::warning(this, "Already Booked", "Theatre " + QString::number(theatreId) + " is already booked on " + dateStr);
//         } else {
//             booked.insert(theatreId);
//             QMessageBox::information(this, "Booking", "Theatre " + QString::number(theatreId) + " booked for " + dateStr);
//             updateCalendar();
//         }
//     }
// }

// void MainWindow::checkBookings()
// {
//     QString dateStr = currentDate.toString("dd-MM-yyyy");
//     int bookedCount = bookings[dateStr].size();
//     int availableTheatres = 10 - bookedCount;
//     QMessageBox::information(this, "Bookings", QString::number(availableTheatres) + " theatres available on " + dateStr);
// }

// bool MainWindow::isDateFullyBooked(int day)
// {
//     QDate thisDay(currentDate.year(), currentDate.month(), day);
//     QString dateStr = thisDay.toString("dd-MM-yyyy");
//     return bookings[dateStr].size() >= 10;
// }

// void MainWindow::showPreviousMonth()
// {
//     currentDate = currentDate.addMonths(-1);
//     updateCalendar();
// }

// void MainWindow::showNextMonth()
// {
//     currentDate = currentDate.addMonths(1);
//     updateCalendar();
// }

