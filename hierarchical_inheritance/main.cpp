// #include "student.h"
// #include "teacher.h"
// int main() {
//     Student s("varshi",22,"Computer Science");
//     Teacher t("Dr .Raju",44,"Maths");
//      s.showStudentdetails();
//      t.showteacherdetails();

//     return 0;
// }
#include "student.h"
#include "teacher.h"

int main()
{
    Student* s = new Student("Varshi", 22, "Computer Science");
    Teacher* t = new Teacher("Dr. Raju", 44, "Maths");

    s->showStudentdetails();
    t->showteacherdetails();
    delete s;
    delete t;

    return 0;
}
