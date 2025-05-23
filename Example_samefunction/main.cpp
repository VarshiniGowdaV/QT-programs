#include <iostream>
#include "school.h"
#include "student.h"
using namespace std;

int main()
{
    School school;
    Student s1("s1",&school);
    Student s2("s2",&school);
    Student s3("s3",&school);
    Student s4("s4",&school);
    Student s5("s5",&school);
    Student s6("s6",&school);
    Student s7("s7",&school);
    Student s8("s8",&school);
    Student s9("s9",&school);
    Student s10("s10",&school);
    Student s11("s11",&school);
    Student s12("s12",&school);
    school.printme();

    return 0;

}
