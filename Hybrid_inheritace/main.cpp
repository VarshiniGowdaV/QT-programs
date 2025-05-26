#include "intern.h"

int main() {
    Intern intern;

    intern.Student::setPersonDetails("varshi", 21);
    intern.setStudentID(1001);
    intern.setInternDetails("Software Development");

    intern.displayIntern();

    return 0;
}
