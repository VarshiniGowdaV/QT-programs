#include "mainwindow.h"

MainWindow::MainWindow() : currentDate(QDate::currentDate())
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
    // Initialize the 2D array for calendar buttons (6 rows, 7 columns)
    dayButtons.resize(6);
    for (int i = 0; i < 6; ++i)
    {
        dayButtons[i].resize(7);
        for (int j = 0; j < 7; ++j)
        {
            dayButtons[i][j] = new QPushButton(this);
            dayButtons[i][j]->setGeometry(50 + j * 60, 50 + i * 60, 50, 50);
            dayButtons[i][j]->setEnabled(false);
        }
    }
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

            QPushButton *btn = dayButtons[i][j];
            btn->setText(QString::number(day));
            btn->setEnabled(true);

            if (isDateFullyBooked(day))
            {
                btn->setStyleSheet("background-color:gray;");
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

void MainWindow::bookTheatre()
{
    bool ok;
    int theatreId = QInputDialog::getInt(this, "Book Theatre", "Enter Theatre ID (1-10):", 1, 1, 10, 1, &ok);
    if (ok)
    {
        QString dateStr = currentDate.toString("dd-MM-yyyy");
        QMessageBox::information(this, "Booking", "Theatre " + QString::number(theatreId) + " booked for " + dateStr);
    }
}

void MainWindow::checkBookings()
{
    QString dateStr = currentDate.toString("dd-MM-yyyy");
    int availableTheatres = 10; // Placeholder logic for available theatres
    QMessageBox::information(this, "Bookings", QString::number(availableTheatres) + " theatres available on " + dateStr);
}

bool MainWindow::isDateFullyBooked(int day)
{
    // Placeholder logic to check if a date is fully booked
    return false;
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


// #include "mainwindow.h"
// #include <QPushButton>
// #include <QVBoxLayout>
// #include <QHBoxLayout>
// #include <QComboBox>
// #include <QTextEdit>
// #include <QCalendarWidget>
// #include <QLabel>
// #include <QDate>
// #include <QMessageBox>
// #include <QApplication>

// MainWindow::MainWindow(QWidget *parent)
//     : QMainWindow(parent)
// {
//     setWindowTitle("Theatre Booking System");

//     calendar = new QCalendarWidget(this);
//     prevMonthButton = new QPushButton("< Previous Month", this);
//     nextMonthButton = new QPushButton("Next Month >", this);
//     bookTheatreButton = new QPushButton("Book Theatre", this);
//     checkBookingsButton = new QPushButton("Check Bookings", this);
//     exitButton = new QPushButton("Exit", this);
//     theatreComboBox = new QComboBox(this);
//     statusTextEdit = new QTextEdit(this);
//     monthLabel = new QLabel("April 2025", this);

//     for (int i = 1; i <= 10; ++i) {
//         theatreComboBox->addItem(QString::number(i));
//     }
//     QVBoxLayout *mainLayout = new QVBoxLayout;
//     QHBoxLayout *topLayout = new QHBoxLayout;

//     topLayout->addWidget(prevMonthButton);
//     topLayout->addWidget(monthLabel);
//     topLayout->addWidget(nextMonthButton);

//     mainLayout->addLayout(topLayout);
//     mainLayout->addWidget(calendar);
//     mainLayout->addWidget(new QLabel("Select Theatre ID:"));
//     mainLayout->addWidget(theatreComboBox);
//     mainLayout->addWidget(bookTheatreButton);
//     mainLayout->addWidget(checkBookingsButton);
//     mainLayout->addWidget(exitButton);
//     mainLayout->addWidget(new QLabel("Status:"));
//     mainLayout->addWidget(statusTextEdit);

//     QWidget *centralWidget = new QWidget(this);
//     centralWidget->setLayout(mainLayout);
//     setCentralWidget(centralWidget);

//     connect(prevMonthButton, &QPushButton::clicked, this, &MainWindow::onPreviousMonthClicked);
//     connect(nextMonthButton, &QPushButton::clicked, this, &MainWindow::onNextMonthClicked);
//     connect(bookTheatreButton, &QPushButton::clicked, this, &MainWindow::onBookTheatreClicked);
//     connect(checkBookingsButton, &QPushButton::clicked, this, &MainWindow::onCheckBookingsClicked);
//     connect(exitButton, &QPushButton::clicked, this, &MainWindow::onExitClicked);
// }

// MainWindow::~MainWindow() {}

// void MainWindow::onPreviousMonthClicked()
// {
//     QDate currentMonth = calendar->selectedDate();
//     calendar->setSelectedDate(currentMonth.addMonths(-1));
//     monthLabel->setText(calendar->selectedDate().toString("MMMM yyyy"));
// }

// void MainWindow::onNextMonthClicked()
// {
//     QDate currentMonth = calendar->selectedDate();
//     calendar->setSelectedDate(currentMonth.addMonths(1));
//     monthLabel->setText(calendar->selectedDate().toString("MMMM yyyy"));
// }

// void MainWindow::onBookTheatreClicked()
// {
//     QDate selectedDate = calendar->selectedDate();
//     int theatreId = theatreComboBox->currentText().toInt();

//     bookedTheatres[selectedDate].append(theatreId);

//     QString status = QString("Theatre %1 booked successfully for %2").arg(theatreId).arg(selectedDate.toString("dd-MM-yyyy"));
//     updateStatus(status);
// }

// void MainWindow::onCheckBookingsClicked()
// {
//     QDate selectedDate = calendar->selectedDate();
//     if (bookedTheatres.contains(selectedDate)) {
//         QList<int> bookedList = bookedTheatres[selectedDate];
//         if (bookedList.isEmpty()) {
//             updateStatus("No theatres booked for this date.");
//         } else {
//             QStringList bookings;
//             for (int theatreId : bookedList) {
//                 bookings.append(QString::number(theatreId));
//             }
//             QString status = QString("Theatres booked for %1: %2").arg(selectedDate.toString("dd-MM-yyyy")).arg(bookings.join(", "));
//             updateStatus(status);
//         }
//     } else {
//         updateStatus("No theatres booked for this date.");
//     }
// }

// void MainWindow::onExitClicked()
// {
//     QApplication::quit();
// }

// void MainWindow::updateStatus(const QString &status)
// {
//     statusTextEdit->setText(status);
// }
