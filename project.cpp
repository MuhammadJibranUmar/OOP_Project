#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
using namespace std;

const int MAX = 100;

class Date
{
public:
    Date()
    {
        month = 0;
        day = 0;
        year = 0;
    }

    Date(int m, int d, int y)
    {
        month = m;
        day = d;
        year = y;
    }

    void setDOB(int m, int d, int y)
    {
        month = m;
        day = d;
        year = y;
    }

    void printDOB()
    {
        cout << month << "/" << day << "/" << year << endl;
    }

    void calculateAge()
    {
        time_t now = time(0);
        tm *ltm = localtime(&now);
        int currentYear = 1900 + ltm->tm_year;
        int currentMonth = 1 + ltm->tm_mon;
        int currentDay = ltm->tm_mday;

        int age = currentYear - year;
        if (currentMonth < month)
        {
            age--;
        }
        else if (currentMonth == month)
        {
            if (currentDay < day)
            {
                age--;
            }
        }

        cout << "Age: " << age << endl;
    }

private:
    int month;
    int day;
    int year;
};

// person class
class Person
{
public:
    Person()
    {
        firstName = "";
        lastName = "";
        address = "";
        phone = "";
        email = "";
    }

    void setPerson()
    {
        cout << "Enter first name: ";
        getline(cin, firstName);
        cout << "Enter last name: ";
        getline(cin, lastName);
        cout << "Enter DOB (mm/dd/yyyy): ";
        int m, d, y;
        cin >> m >> d >> y;
        dob.setDOB(m, d, y);
        cin.ignore();
        cout << "Enter address: ";
        getline(cin, address);
        cout << "Enter phone: ";
        getline(cin, phone);
        cout << "Enter email: ";
        getline(cin, email);
    }

    void printPerson()
    {
        cout << "Name: " << firstName << " " << lastName << endl;
        cout << "DOB: ";
        dob.printDOB();
        cout << "Address: " << address << endl;
        cout << "Phone: " << phone << endl;
        cout << "Email: " << email << endl;
    }

    void calculateAge()
    {
        dob.calculateAge();
    }

protected:
    string firstName;
    string lastName;
    Date dob;
    string address;
    string phone;
    string email;
};

class Student : public Person
{
public:
    Student()
    {
        gpa = 0.0;
    }
    void setData()
    {
        Person::setPerson();
        totalStudents++;
    }

    void printPerson()
    {
        cout << "Student ID: " << studentID << endl;
        Person::printPerson();
        cout << "Registration No: " << registrationNo << endl;
        cout << "GPA: " << gpa << endl;
    }



private:
    int studentID;
    static int totalStudents;
    int registrationNo;
    double gpa;
};

class Faculty : public Person
{
public:
    Faculty()
    {
        facultyID = 0;
    }

    void setData()
    {
        Person::setPerson();
        facultyID = totalFaculty + 1;
        totalFaculty++;
    }

    void printPerson()
    {
        cout << "Faculty ID: " << facultyID << endl;
        Person::printPerson();
    }

private:
    int facultyID;
    static int totalFaculty;
};
class Result
{
public:
    Result()
    {
        mids = 0;
        sessional = 0;
        quiz = 0;
        presentation = 0;
        assignment = 0;
        finals = 0;
        totalMarks = 0;
        grade = "";
    }

    void setMids(float m)
    {
        if (m > 25 || m < 0)
        {
            cout << "Invalid marks for mids" << endl;
            return;
        }
        mids = m;
    }

    void setSessional()
    {
        sessional = quiz + presentation + assignment;
    }

    void setQuiz(float q)
    {
        if (q > 5 || q < 0)
        {
            cout << "Invalid marks for quiz" << endl;
            return;
        }
        quiz = q;
    }

    void setPresentation(float p)
    {
        if (p > 10 || p < 0)
        {
            cout << "Invalid marks for presentation" << endl;
            return;
        }
        presentation = p;
    }

    void setAssignment(float a)
    {
        if (a > 10 || a < 0)
        {
            cout << "Invalid marks for assignment" << endl;
            return;
        }
        assignment = a;
    }

    void setFinals(float f)
    {
        if (f > 50 || f < 0)
        {
            cout << "Invalid marks for finals" << endl;
            return;
        }
        finals = f;
    }

    void calculateTotalMarks()
    {
        totalMarks = mids + sessional + finals;
    }

    void calculateGrade()
    {
        if (totalMarks >= 84.5 && totalMarks <= 100)
        {
            grade = "A+";
        }
        else if (totalMarks >= 79.5 && totalMarks < 84.5)
        {
            grade = "A";
        }
        else if (totalMarks >= 75.5 && totalMarks < 79.5)
        {
            grade = "B+";
        }
        else if (totalMarks >= 69.5 && totalMarks < 75.5)
        {
            grade = "B";
        }
        else if (totalMarks >= 64.5 && totalMarks < 69.5)
        {
            grade = "B-";
        }
        else if (totalMarks >= 59.5 && totalMarks < 64.5)
        {
            grade = "C+";
        }
        else if (totalMarks >= 54.5 && totalMarks < 59.5)
        {
            grade = "C";
        }
        else if (totalMarks >= 49.5 && totalMarks < 54.5)
        {
            grade = "D";
        }
        else
        {
            grade = "F";
        }
    }

    string getGrade()
    {
        return grade;
    }

    float getTotalMarks()
    {
        return totalMarks;
    }

private:
    float mids;
    float sessional;
    float quiz;
    float presentation;
    float assignment;
    float finals;
    float totalMarks;
    string grade;
};

class Course
{
public:
    Course()
    {
        courseTitle = "";
        creditHours = 0;
        totalMarks = 100;
    }

    void setData()
    {
        cout << "Enter Course Title: ";
        getline(cin, courseTitle);
        cout << "Enter Credit Hours: ";
        cin >> creditHours;
        cin.ignore();
    }

    void getData()
    {
        cout << "Course Title: " << courseTitle << endl;
        cout << "Course ID: " << courseID << endl;
        cout << "Credit Hours: " << creditHours << endl;
        cout << "Total Marks: " << totalMarks << endl;
    }

    void setMarks()
    {
        while (true)
        {
            cout << "Which marks do you want to enter?" << endl;
            cout << "1. Mids" << endl;
            cout << "2. Quiz" << endl;
            cout << "3. Presentation" << endl;
            cout << "4. Assignment" << endl;
            cout << "5. Finals" << endl;
            cout << "Enter your choice: ";
            int choice;
            cin >> choice;
            cin.ignore();
            if (choice < 1 || choice > 5)
            {
                cout << "Invalid choice" << endl;
                continue;
            }
            switch (choice)
            {
            case 1:
                cout << "Enter mids marks: ";
                float m;
                cin >> m;
                result.setMids(m);
                break;
            case 2:
                cout << "Enter quiz marks: ";
                float q;
                cin >> q;
                result.setQuiz(q);
                break;
            case 3:
                cout << "Enter presentation marks: ";
                float p;
                cin >> p;
                result.setPresentation(p);
                break;
            case 4:
                cout << "Enter assignment marks: ";
                float a;
                cin >> a;
                result.setAssignment(a);
                break;
            case 5:
                cout << "Enter finals marks: ";
                float f;
                cin >> f;
                result.setFinals(f);
                break;
            default:
                cout << "Invalid choice" << endl;
                break;
            }
            cout << "Do you want to enter more marks? (y/n): ";
            char ch;
            cin >> ch;
            cin.ignore();
            if (ch == 'n' || ch == 'N')
            {
                break;
            }
        }
    }

    void displayResult()
    {
        result.calculateTotalMarks();
        result.calculateGrade();
        cout << "Total Marks: " << result.getTotalMarks() << endl;
        cout << "Grade: " << result.getGrade() << endl;
    }


private:
    int courseID;
    static int totalCourses;
    string courseTitle;
    int creditHours;
    int totalMarks;
    Result result;
};

class Department
{
public:
    Department()
    {
        departmentName = "";
        totalFaculty = 0;
        totalStudents = 0;
        totalCourses = 0;
    }

    void setDepartment()
    {
        cout << "Enter Department Name: ";
        getline(cin, departmentName);
        departmentID = totalDepartments + 1;
        totalDepartments++;
    }

    void setData(){
        cout << "Department ID: " << departmentID << endl;
        cout << "Department Name: " << departmentName << endl;

        while(true){
            cout << "1. Add Faculty" << endl;
            cout << "2. Add Student" << endl;
            cout << "3. Add Course" << endl;
            cout << "4. Exit" << endl;
            cout << "Enter your choice: ";
            int choice;
            cin >> choice;
            cin.ignore();
            if(choice == 1){
                addFaculty();
            }
            else if(choice == 2){
                addStudent();
            }
            else if(choice == 3){
                addCourse();
            }
            else if(choice == 4){
                break;
            }
            else{
                cout << "Invalid choice" << endl;
            }
        }
    }

    int getDepartmentID()
    {
        return departmentID;
    }

    void getData()
    {
        cout << "Department Name: " << departmentName << endl;
        cout << "Department ID: " << departmentID << endl;
        cout << "Total Faculty: " << totalFaculty << endl;
        cout << "Total Students: " << totalStudents << endl;
        cout << "Total Courses: " << totalCourses << endl;
    }

    void addFaculty()
    {
        faculty[totalFaculty].setData();
        totalFaculty++;
    }

    void addStudent()
    {
        students[totalStudents].setData();
        totalStudents++;
    }

    void addCourse()
    {
        courses[totalCourses].setData();
        totalCourses++;
    }

    void displayStudents()
    {
        for (int i = 0; i < totalStudents; i++)
        {
            students[i].printPerson();
        }
    }

    void displayFaculty()
    {
        for (int i = 0; i < totalFaculty; i++)
        {
            faculty[i].printPerson();
        }
    }

    void displayCourses()
    {
        for (int i = 0; i < totalCourses; i++)
        {
            courses[i].getData();
        }
    }

private:
    string departmentName;
    static int totalDepartments;
    int departmentID;
    int totalFaculty;
    Faculty faculty[MAX];
    int totalStudents;
    Student students[MAX];
    int totalCourses;
    Course courses[MAX];
};

class University
{
public:
    University()
    {
        universityName = "Alpha";
        universityID = 110;
        totalDepartments = 0;
    }

    void addDepartment()
    {
        departments[totalDepartments].setDepartment();
        totalDepartments++;
    }

    void addDepartmentData()
    {
        cout << "Enter Department ID: ";
        int id;
        cin >> id;
        cin.ignore();
        for (int i = 0; i < totalDepartments; i++)
        {
            if (departments[i].getDepartmentID() == id)
            {
                departments[i].setData();
                break;
            }
        }
    }

    void displayDepartments()
    {
        for (int i = 0; i < totalDepartments; i++)
        {
            departments[i].getData();
        }
    }

    void displayStudents()
    {
        for (int i = 0; i < totalDepartments; i++)
        {
            departments[i].displayStudents();
        }
    }

    void displayFaculty()
    {
        for (int i = 0; i < totalDepartments; i++)
        {
            departments[i].displayFaculty();
        }
    }

    void displayCourses()
    {
        for (int i = 0; i < totalDepartments; i++)
        {
            departments[i].displayCourses();
        }
    }

private:
    string universityName;
    int universityID;
    int totalDepartments;
    Department departments[MAX];
};

int Student::totalStudents = 0;
int Faculty::totalFaculty = 0;
int Course::totalCourses = 0;
int Department::totalDepartments = 0;

bool login(){
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;
    ifstream file("login.txt");
    string u, p;
    bool found = false;
    while (file >> u >> p)
    {
        if (u == username && p == password)
        {
            found = true;
            break;
        }
    }
    if (found)
    {
        cout << "Login successful" << endl;
    }
    else
    {
        cout << "Login failed" << endl;
    }
    return found;
}

void registerUser(){
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;
    ofstream file("login.txt", ios::app);
    file << username << " " << password << endl;
    cout << "User registered successfully" << endl;
}

int main()
{
    cout << "Welcome to University Information System" << endl;
    while(true){
        cout << "1. Login" << endl;
        cout << "2. Register" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        int choice;
        bool flag;
        cin >> choice;
        cin.ignore();
        if(choice == 1){
            flag = login();
        }
        else if(choice == 2){
            registerUser();
        }
        else if(choice == 3){
            break;
        }
        else{
            cout << "Invalid choice" << endl;
        }
        if(flag){
            break;
        }
    }

    University Alpha;

    while (true)
    {
        cout << "1. Add Department" << endl;
        cout << "2. Add Department Data" << endl; // Add Faculty, Student, Course
        cout << "3. Display Information" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;
        cin.ignore();
        if (choice == 1)
        {
            Alpha.addDepartment();
        }
        else if (choice == 2)
        {
            Alpha.addDepartmentData();
        }
        else if (choice == 3)
        {
            cout << "1. Display Departments" << endl;
            cout << "2. Display Students" << endl;
            cout << "3. Display Faculty" << endl;
            cout << "4. Display Courses" << endl;
            cout << "Enter your choice: ";
            int ch;
            cin >> ch;
            cin.ignore();
            if (ch == 1)
            {
                Alpha.displayDepartments();
            }
            else if (ch == 2)
            {
                Alpha.displayStudents();
            }
            else if (ch == 3)
            {
                Alpha.displayFaculty();
            }
            else if (ch == 4)
            {
                Alpha.displayCourses();
            }
        }
        else if (choice == 4)
        {
            break;
        }
        else
        {
            cout << "Invalid choice" << endl;
        }
    }


    return 0;
}
