#include<stdio.h>
#include<string.h>

struct Course
{
    /* data */
    int course_code;
    char course_name[30];
};

struct Student
{
    /* data */
    char name[20];
    int age;
    char address[30];
    double cgpa;
    char id[20];
    int num_of_courses;
    struct Course courses[6];
    void (*addCourse)(struct Course course, struct Student*);
    void (*printCourses)(struct Student*);
    void (*printStudent)(struct Student*);
};

void addCourseForStudent(struct Course course, struct Student*this) {
    int i = this->num_of_courses;
    if (this->cgpa > 2.5) {
        if (this->num_of_courses == 6) {
            printf("\nYou are not allowed to take more than 6 courses\n\n");
            return;
        }
    }
    else {
        if (this->num_of_courses == 4) {
            printf("\nYou are not allowed to take more than 4 courses\n\n");
            return;
        }
    }
    this->courses[i] = course;
    this->num_of_courses++;
}

void printCoursesForStudent(struct Student*this) {
    int i = 0;
    while(i < this->num_of_courses) {
        printf("course name: %s\n", this->courses[i].course_name);
        printf("course code: %d\n", this->courses[i].course_code);
        i++;
    }
}

void printStudent(struct Student*this) {
    printf("name: %s\n", this->name);
    printf("age: %d\n", this->age);
    printf("address: %s\n", this->address);
    printf("cgpa: %0.2lf\n", this->cgpa);
    printf("id: %s\n\n", this->id);
}

struct Teacher
{
    /* data */
    char name[20];
    int age;
    int isPermanent;
    int isVisiting;
    char address[20];
    int num_of_courses;
    struct Course courses[7];
    double basic_salary;
    double load_salary;
    void (*addCourse)(struct Course course, struct Teacher*);
    void (*printCourses)(struct Teacher*);
    int (*getSalary)(struct Teacher*);
    void (*printTeacher)(struct Teacher*);
};

void addCourseForTeacher(struct Course course, struct Teacher* this) {
    int i = this->num_of_courses;
    if (this->isPermanent == 1) {
        if (i == 7) {
            printf("\nYou are not allowed to take more than 7 courses\n\n");
            return;
        }
    }
    if (this->isVisiting == 1) {
        if (i == 3) {
            printf("\nYou are not allowed to take more than 3 courses\n\n");
            return;
        }
    }
    this->basic_salary += 2000.0;
    this->courses[i] = course;
    this->num_of_courses++;
}

void printCoursesForTeacher(struct Teacher* this) {
    int i = 0;
    while(i < this->num_of_courses) {
        printf("course name: %s\n", this->courses[i].course_name);
        printf("course code: %d\n", this->courses[i].course_code);
        i++;
    }
}

int getSalary(struct Teacher* this) {
    return (this->basic_salary + this->load_salary);
}

void printTeacher(struct Teacher* this) {
    printf("\n\nname: %s\n", this->name);
    printf("age: %d\n", this->age);
    printf("address: %s\n", this->address);
    printf("numberOfCourses: %d\n", this->num_of_courses);
    printf("salary: %0.2lf\n", this->basic_salary);
}

int main() {
    struct Student student = {
        .name = "jimmy page", 
        .age = 23, 
        .address = "mirpur, dhaka-1216", 
        .cgpa = 3.1, 
        .id = "16112839234", 
        .num_of_courses = 0, 
        .addCourse = addCourseForStudent, 
        .printCourses = printCoursesForStudent,
        .printStudent = printStudent
        };

    struct Course course1 = {215, "Programming Language 2"};
    struct Course course2 = {115, "Programming Language 1"};
    struct Course course3 = {225, "Data Structures and Algorithms"};
    struct Course course4 = {331, "Microprocessors"};
    struct Course course5 = {311, "Database Management"};

    student.addCourse(course1, &student);
    student.addCourse(course2, &student);
    student.addCourse(course3, &student);
    student.addCourse(course4, &student);
    student.addCourse(course5, &student);
    
    student.printStudent(&student);

    student.printCourses(&student);

    struct Course course6 = {323, "Operating Systems"};
    struct Course course7 = {324, "Computer Network"};

    student.addCourse(course6, &student);
    student.addCourse(course7, &student);

    student.printStudent(&student);

    student.printCourses(&student);

    struct Student student2 = {
        .name = "dimebag", 
        .age = 24, 
        .address = "Dhanmondi, dhaka-1216", 
        .cgpa = 2.4, 
        .id = "1712184642", 
        .num_of_courses = 0, 
        .addCourse = addCourseForStudent, 
        .printCourses = printCoursesForStudent,
        .printStudent = printStudent
    };

    student2.addCourse(course1, &student2);
    student2.addCourse(course2, &student2);
    student2.addCourse(course3, &student2);
    student2.addCourse(course4, &student2);
    student2.addCourse(course5, &student2);

    student2.printStudent(&student2);

    student2.printCourses(&student2);

    struct Teacher permanentFaculty = {
        .name = "slash",
        .age = 30,
        .address = "Mirpur",
        .num_of_courses = 0,
        .isPermanent = 1,
        .isVisiting = 0,
        .basic_salary = 10000.0,
        .addCourse = addCourseForTeacher,
        .printCourses = printCoursesForTeacher,
        .getSalary = getSalary,
        .printTeacher = printTeacher
    };
    
    permanentFaculty.addCourse(course1, &permanentFaculty);
    permanentFaculty.addCourse(course2, &permanentFaculty);
    permanentFaculty.addCourse(course3, &permanentFaculty);
    permanentFaculty.addCourse(course4, &permanentFaculty);

    permanentFaculty.printTeacher(&permanentFaculty);
    permanentFaculty.printCourses(&permanentFaculty);
    
    struct Teacher visitingFaculty = {
        .name = "ozzy",
        .age = 28,
        .address = "RA",
        .num_of_courses = 0,
        .isPermanent = 0,
        .isVisiting = 1,
        .basic_salary = 6000.0,
        .addCourse = addCourseForTeacher,
        .printCourses = printCoursesForTeacher,
        .getSalary = getSalary,
        .printTeacher = printTeacher
    };
    
    visitingFaculty.addCourse(course4, &visitingFaculty);
    visitingFaculty.addCourse(course5, &visitingFaculty);
    visitingFaculty.addCourse(course1, &visitingFaculty);

    visitingFaculty.printTeacher(&visitingFaculty);
    visitingFaculty.printCourses(&visitingFaculty);

    return 0;
}