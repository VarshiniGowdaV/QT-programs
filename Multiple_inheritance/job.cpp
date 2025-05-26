#include "job.h"
#include <iostream>

Job::Job(std::string designation,double salary)
{
    m_designation = designation;
    m_salary = salary;
    std::cout<<"Job constructor called"<<std::endl;
}
Job::~Job()
{
    std::cout<<"job destructor called"<<std::endl;
}
std::string Job:: getdesignation()
{
    return m_designation;
}
double Job::getsalary()
{
    return m_salary;
}
void Job::setJobDetails(const std::string designation, double salary) {
    m_designation = designation;
    m_salary = salary;
}

void Job::showJobDetails() const {
    std::cout << "Designation: " << m_designation << ", Salary: $" << m_salary << std::endl;
}
