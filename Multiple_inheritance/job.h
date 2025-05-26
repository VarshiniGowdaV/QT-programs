#ifndef JOB_H
#define JOB_H

#include <string>

class Job {
private:
    std::string m_designation;
    double m_salary;

public:
    Job(std::string designation, double salary);
    ~Job();

    std::string getdesignation();
    double getsalary();

    void setJobDetails(const std::string designation, double salary);
    void showJobDetails() const;
};

#endif
