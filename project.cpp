#include <iostream>
#include <string>
#include <ctime>
using namespace std;


//comment

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

//person class
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

    Person(string fn, string ln, Date d, string a, string p, string e)
    {
        firstName = fn;
        lastName = ln;
        dob = d;
        address = a;
        phone = p;
        email = e;
    }

    void setPerson(){
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

private:
    int studentID;
    int registrationNo;
};

class Faculty : public Person
{
public:
private:
};

class Course
{
public:
private:
};

int main()
{
    Person p1;
    p1.setPerson();
    p1.printPerson();
    p1.calculateAge();

    return 0;
}
