package com.company;

import java.util.ArrayList;

class Course {
    int course_code;
    String course_name;
    
    public Course(int course_code, String course_name) {
        this.course_code = course_code;
        this.course_name = course_name;
    }
    
    public int getCourse_code() {
        return course_code;
    }
    
    public void setCourse_code(int course_code) {
        this.course_code = course_code;
    }
    
    public String getCourse_name() {
        return course_name;
    }
    
    public void setCourse_name(String course_name) {
        this.course_name = course_name;
    }
    
    @Override
    public String toString() {
        return "name: " + course_name + "\ncourse code: " + course_code;
    }
}

class Student {
    String name;
    int age;
    String address;
    double cgpa;
    String id;
    ArrayList<Course>courses;
    
    public Student(String name, int age, String address, double cgpa, String id) {
        this.name = name;
        this.age = age;
        this.address = address;
        this.cgpa = cgpa;
        this.id = id;
        this.courses = new ArrayList<>();
    }
    
    public String getName() {
        return name;
    }
    
    public void setName(String name) {
        this.name = name;
    }
    
    public int getAge() {
        return age;
    }
    
    public void setAge(int age) {
        this.age = age;
    }
    
    public String getAddress() {
        return address;
    }
    
    public void setAddress(String address) {
        this.address = address;
    }
    
    public double getCgpa() {
        return cgpa;
    }
    
    public void setCgpa(double cgpa) {
        this.cgpa = cgpa;
    }
    
    public String getId() {
        return id;
    }
    
    public void setId(String id) {
        this.id = id;
    }
    
    public void addCourse(Course course) {
        if (this.cgpa >= 2.5) {
            if (courses.size() == 6) {
                System.out.println("You are not allowed to take more than 6 courses");
                return;
            }
        } else {
            if (courses.size() == 4) {
                System.out.println("You are not allowed to take more than 4 courses");
                return;
            }
        }
        this.courses.add(course);
    }
    
    public void printCourses() {
        System.out.println();
        for(int i=0; i< courses.size(); i++) {
            System.out.println(courses.get(i));
        }
        System.out.println();
    }
    
    @Override
    public String toString() {
        return  "name: " + name + "\n" +
                "age: " + age + "\n" +
                "address: " + address + "\n" +
                "cgpa: " + cgpa + "\n" +
                "id: " + id + "\n";
    }
}

abstract class Teacher {
    String name;
    int age;
    String address;
    double basic_salary;
    double load_salary;
    ArrayList<Course> courses;
    
    public Teacher(String name, int age, String address, double basic_salary) {
        this.name = name;
        this.age = age;
        this.address = address;
        this.basic_salary = basic_salary;
        this.load_salary = 0;
        this.courses = new ArrayList<>();
    }
    
    public String getName() {
        return name;
    }
    
    public void setName(String name) {
        this.name = name;
    }
    
    public int getAge() {
        return age;
    }
    
    public void setAge(int age) {
        this.age = age;
    }
    
    public String getAddress() {
        return address;
    }
    
    public void setAddress(String address) {
        this.address = address;
    }
    
    abstract void addCourse(Course course);
    
    void printCourses() {
        System.out.println();
        for(int i=0; i<courses.size(); i++) {
            System.out.println(courses.get(i));
        }
        System.out.println();
    }
    
    double getSalary() {
        return (this.basic_salary + this.load_salary);
    }
    
    @Override
    public String toString() {
        return "name: " + name + "\n" +
                "age: " + age + "\n" +
                "address: " + address + "\n" +
                "numberOfCourses: " + courses.size() + "\n" +
                "salary: " + basic_salary + "\n";
    }
}

class PermanentFaculty extends Teacher {
    
    public PermanentFaculty(String name, int age, String address, double basic_salary) {
        super(name, age, address, basic_salary);
    }
    
    @Override
    void addCourse(Course course) {
        if (super.courses.size() == 7) {
            return;
        }
        super.courses.add(course);
        super.load_salary += 2000.0;
    }
}

class VisitingFaculty extends Teacher {
    
    public VisitingFaculty(String name, int age, String address, double basic_salary) {
        super(name, age, address, basic_salary);
    }
    
    @Override
    void addCourse(Course course) {
        if (super.courses.size() == 3) {
            return;
        }
        super.courses.add(course);
        super.load_salary += 2000.0;
    }
}


public class Main {

    public static void main(String[] args) {
        Student student1 = new Student("jimmy page", 23, "mirpur, dhaka-1216", 3.1, "16112839234");
        
        Course course1 = new Course(215, "Programming Language 2");
        Course course2 = new Course(115, "Programming Language 1");
        Course course3 = new Course(225, "Data Structures & Algorithms");
        Course course4 = new Course(331, "Microprocessors");
        Course course5 = new Course(311, "Database Management");
        
        student1.addCourse(course1);
        student1.addCourse(course2);
        student1.addCourse(course3);
        student1.addCourse(course4);
        student1.addCourse(course5);
        
        System.out.println(student1);
        student1.printCourses();
    
        Course course6 = new Course(323, "Operating Systems");
        Course course7 = new Course(324, "Machine Learning");
        
        student1.addCourse(course6);
        student1.addCourse(course7);
        
        System.out.println(student1);
        student1.printCourses();
        
        Student student2 = new Student("dimebag", 24, "Dhanmondi, Dhaka-1216", 2.4, "1712184642");
    
        student2.addCourse(course1);
        student2.addCourse(course2);
        student2.addCourse(course3);
        student2.addCourse(course4);
        student2.addCourse(course5);
    
        System.out.println(student2);
        student2.printCourses();
        
        PermanentFaculty permanentFaculty = new PermanentFaculty("slash", 30, "Mirpur", 10000.0);
        
        permanentFaculty.addCourse(course1);
        permanentFaculty.addCourse(course2);
        permanentFaculty.addCourse(course3);
        permanentFaculty.addCourse(course4);
    
        System.out.println(permanentFaculty);
        permanentFaculty.printCourses();
        
        VisitingFaculty visitingFaculty = new VisitingFaculty("ozzy", 28, "RA", 6000);
        
        visitingFaculty.addCourse(course4);
        visitingFaculty.addCourse(course5);
        visitingFaculty.addCourse(course1);
    
        System.out.println(visitingFaculty);
        visitingFaculty.printCourses();
    }
}
