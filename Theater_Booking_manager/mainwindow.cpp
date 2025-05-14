#include "mainwindow.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QComboBox>
#include <QTextEdit>
#include <QCalendarWidget>
#include <QLabel>
#include <QDate>
#include <QMessageBox>
#include <QApplication>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("Theatre Booking System");

    calendar = new QCalendarWidget(this);
    prevMonthButton = new QPushButton("< Previous Month", this);
    nextMonthButton = new QPushButton("Next Month >", this);
    bookTheatreButton = new QPushButton("Book Theatre", this);
    checkBookingsButton = new QPushButton("Check Bookings", this);
    exitButton = new QPushButton("Exit", this);
    theatreComboBox = new QComboBox(this);
    statusTextEdit = new QTextEdit(this);
    monthLabel = new QLabel("April 2025", this);

    for (int i = 1; i <= 10; ++i) {
        theatreComboBox->addItem(QString::number(i));
    }
    QVBoxLayout *mainLayout = new QVBoxLayout;
    QHBoxLayout *topLayout = new QHBoxLayout;

    topLayout->addWidget(prevMonthButton);
    topLayout->addWidget(monthLabel);
    topLayout->addWidget(nextMonthButton);

    mainLayout->addLayout(topLayout);
    mainLayout->addWidget(calendar);
    mainLayout->addWidget(new QLabel("Select Theatre ID:"));
    mainLayout->addWidget(theatreComboBox);
    mainLayout->addWidget(bookTheatreButton);
    mainLayout->addWidget(checkBookingsButton);
    mainLayout->addWidget(exitButton);
    mainLayout->addWidget(new QLabel("Status:"));
    mainLayout->addWidget(statusTextEdit);

    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);

    connect(prevMonthButton, &QPushButton::clicked, this, &MainWindow::onPreviousMonthClicked);
    connect(nextMonthButton, &QPushButton::clicked, this, &MainWindow::onNextMonthClicked);
    connect(bookTheatreButton, &QPushButton::clicked, this, &MainWindow::onBookTheatreClicked);
    connect(checkBookingsButton, &QPushButton::clicked, this, &MainWindow::onCheckBookingsClicked);
    connect(exitButton, &QPushButton::clicked, this, &MainWindow::onExitClicked);
}

MainWindow::~MainWindow() {}

void MainWindow::onPreviousMonthClicked()
{
    QDate currentMonth = calendar->selectedDate();
    calendar->setSelectedDate(currentMonth.addMonths(-1));
    monthLabel->setText(calendar->selectedDate().toString("MMMM yyyy"));
}

void MainWindow::onNextMonthClicked()
{
    QDate currentMonth = calendar->selectedDate();
    calendar->setSelectedDate(currentMonth.addMonths(1));
    monthLabel->setText(calendar->selectedDate().toString("MMMM yyyy"));
}

void MainWindow::onBookTheatreClicked()
{
    QDate selectedDate = calendar->selectedDate();
    int theatreId = theatreComboBox->currentText().toInt();

    bookedTheatres[selectedDate].append(theatreId);

    QString status = QString("Theatre %1 booked successfully for %2").arg(theatreId).arg(selectedDate.toString("dd-MM-yyyy"));
    updateStatus(status);
}

void MainWindow::onCheckBookingsClicked()
{
    QDate selectedDate = calendar->selectedDate();
    if (bookedTheatres.contains(selectedDate)) {
        QList<int> bookedList = bookedTheatres[selectedDate];
        if (bookedList.isEmpty()) {
            updateStatus("No theatres booked for this date.");
        } else {
            QStringList bookings;
            for (int theatreId : bookedList) {
                bookings.append(QString::number(theatreId));
            }
            QString status = QString("Theatres booked for %1: %2").arg(selectedDate.toString("dd-MM-yyyy")).arg(bookings.join(", "));
            updateStatus(status);
        }
    } else {
        updateStatus("No theatres booked for this date.");
    }
}

void MainWindow::onExitClicked()
{
    QApplication::quit();
}

void MainWindow::updateStatus(const QString &status)
{
    statusTextEdit->setText(status);
}
