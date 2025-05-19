#include "mainwindow1.h"
#include <QFont>
#include <iostream>
Mainwindow1::Mainwindow1()
    :currentDate(QDate::currentDate())
{
    setupUI();
    updateCalendar();
    std::cout<<"Mainwindow constructor called"<<std::endl;
}
Mainwindow1::~Mainwindow1()
{
    std::cout<<"Mainwindow destructor called"<<std::endl;
}
void Mainwindow1::setupUI()
{
    this->setFixedSize(600,430);

    PrevMonthButton = new QPushButton("< Previous",this);
    PrevMonthButton->setGeometry(10,10,120,40);
    connect(PrevMonthButton, &QPushButton::clicked, this, &Mainwindow1::showPreviousMonth);

    nextMonthButton=new QPushButton("Next >",this);
    nextMonthButton->setGeometry(460,10,120,40);
    connect(nextMonthButton,&QPushButton::clicked,this,&Mainwindow1::showNextMonth);

    monthYearButton = new QPushButton("Month Year",this);
    monthYearButton->setGeometry(170,10,250,40);
    monthYearButton->setFont(QFont("Arial",14,QFont::Bold));
    monthYearButton->setStyleSheet("Text-align:center;");

    const char* daysofWeek[7] = {"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};
    QFont headerFont;
    headerFont.setBold(true);
    for(int i=0;i<7;++i)
    {
        headerButtons[i] = new QPushButton(daysofWeek[i], this);
        headerButtons[i]->setGeometry(40 + i * 75, 60, 75, 35);
        headerButtons[i]->setFont(headerFont);
        headerButtons[i]->setEnabled(false);
    }
    for(int row = 0 ;row<6;++row)
    {
        for(int col = 0;col < 7;++col)
        {
            dayButtons[row][col]=new QPushButton(this);
            dayButtons[row][col]->setGeometry(40 + col * 75, 100 + row * 60, 75, 50);
            dayButtons[row][col]->setEnabled(false);
        }
    }
}
void Mainwindow1::updateCalendar()
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
void Mainwindow1::clearCalendar()
{
    for(int row=0;row<6;++row)
    {
        for(int col = 0 ;col < 7;++col)
        {
            dayButtons[row][col]->setText("");
            dayButtons[row][col]->setEnabled(false);
            dayButtons[row][col]->setStyleSheet("");
        }
    }
}
void Mainwindow1::showPreviousMonth()
{
    currentDate=currentDate.addMonths(-1);
    updateCalendar();
}
void Mainwindow1::showNextMonth()
{
    currentDate =currentDate.addMonths(1);
    updateCalendar();
}
