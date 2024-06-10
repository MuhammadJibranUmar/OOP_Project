#include<iostream>
#include<fstream>
#include<iomanip>
#include<windows.h>
using namespace std;

void start();// for loading bar

void menu();//main menu function prototype

class ManageMenu {
protected:
    string userName; //hide admin name

public:

    

    ManageMenu()
    {
        system("color 0B"); //change terminal color
        cout << "\n\n\n\n\n\n\n\n\n\t  Enter Your Name to Continue as an Admin: ";
        cin >> userName;
        system("CLS");
        
    }

    
};


class ContactInfo {
public:
    string address;
    string mobileNo;
};

class Package {
public:
    string name;
    float price;
};

class Customer
{
public:
    string name, gender;
    int age, menuBack;
    static int cusID;
    char all[999];
    ContactInfo contact;

    void getDetails()
    {
        ofstream out("old-customers.txt", ios::app); //open file using append mode to write customer details
        {
            cout << "\nEnter Customer ID: ";
            cin >> cusID;
            cin.ignore();
            cout << "Enter Name: ";
            getline(cin,name);//cin>>name;
            cout << "Enter Age: ";
            cin >> age;
            cout << "Enter Mobile Number: ";
            cin >> contact.mobileNo;
            cout << "Address: ";
            cin.ignore();
            getline(cin,contact.address);//cin >> contact.address;
            cout << "Gender: ";
            cin >> gender;
        }
        out << "\nCustomer ID: " << cusID << "\nName: " << name << "\nAge: " << age << "\nMobile Number: " << contact.mobileNo << "\nAddress: " << contact.address << "\nGender: " << gender << endl;
        out.close();
        cout << "\nSaved \nNOTE: We save your details record for future purposes.\n" << endl;
    }
    void showDetails() //function to show old customer records
    {
        ifstream in("old-customers.txt");
        {
            if(!in)
            {
                cout << "File Error!" << endl;
            }
            while(!(in.eof()))
            {
                in.getline(all, 999);
                cout << all << endl;
            }
            in.close();
        }
    }
};

int Customer::cusID;

class Cabs
{
public:
    int cabChoice;
    int kilometers;
    float cabCost;
    static float lastCabCost;

    void cabDetails()
    {
        cout << "We Provide Safest And Comfortable Journey " << endl;
        cout << "-----------SAT Cabs-----------\n" << endl;
        cout << "1. Rent a Standard Cab  (Including AC) - Rs.30  per 1KM" << endl;
        cout << "2. Rent a Luxury   Cab                 - Rs.100 per 1KM" << endl;

        cout << "\nEnter another key to back or," << endl;

        cout << "\nTo calculate the cost for your journey.." << endl;
        cout << "Enter which kind of cab you need: ";
        cin >> cabChoice;
        cout << "Enter Kilometers you have to travel: ";
        cin >> kilometers;

        int hireCab;

        if(cabChoice == 1){
            cabCost = kilometers * 30;
            cout << "\nYour Tour Will Cost " << cabCost << " Rupees For a Standard Cab" << endl;
            cout << "Press 1 to hire this cab: or ";
            cout << "Press 2 to select another cab: ";
            cin >> hireCab;
            system("CLS");
            if (hireCab == 1){
                lastCabCost = cabCost;
                cout << "\nYou have successfully hired standard cab" << endl;
                cout << "Goto Menu to take the receipt" << endl;
            }
            else if(hireCab == 2){
                cabDetails();
            }
            else{
                cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
                Sleep(1100);
                system("CLS");
                cabDetails();
            }
        }
        else if(cabChoice == 2){
            cabCost = kilometers * 100;
            cout << "\nYour Tour Will Cost " << cabCost << " Rupees For a Luxury Cab" << endl;
            cout << "Press 1 to hire this cab: or ";
            cout << "Press 2 to select another cab: ";
            cin >> hireCab;
            system("CLS");
            if (hireCab == 1){
                lastCabCost = cabCost;
                cout << "\nYou have successfully hired luxury cab" << endl;
                cout << "Goto Menu to take the receipt" << endl;
            }
            else if(hireCab == 2){
                cabDetails();
            }
            else{
                cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
                Sleep(1100);
                system("CLS");
                cabDetails();
            }
        }
        else{
            cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
            Sleep(1100);
            system("CLS");
            menu();
        }

        cout << "\nPress 1 to Redirect Main Menu: ";
        cin >> hireCab;
        system("CLS");
        if(hireCab == 1){
            menu();
        }
        else{
            menu();
        }
    }
};

float Cabs::lastCabCost;

class Booking
{
public:
    int choiceHotel;
    int packChoice1;
    int gotoMenu;
    static float hotelCost;
    Package packages[3];

    void hotels()
    {
        packages[0] = {"Standard Pack" , 5000.00};
        packages[1] = {"Premium  Pack" , 10000.00};
        packages[2] = {"Luxury   Pack" , 15000.00};

        cout << "-------WELCOME TO HOTEL RIVER PLACE-------\n" << endl;

        cout << "Swimming Pool | Free WiFi | Family Rooms \n Fitness Center | Restaurant & Bar" << endl;

        cout << "These are Packages Offered by River Palace:\n" << endl;

        for(int i = 0; i < 3; ++i) {
            cout << i+1 << ". " << packages[i].name << "\tPrice: Rs." << packages[i].price << endl;
        }

        cout << "\nPress another key to back or\nEnter Package number you want to book: ";
        cin >> packChoice1;

        if (packChoice1 >= 1 && packChoice1 <= 3){
            hotelCost = packages[packChoice1-1].price;
            cout << "You have successfully booked " << packages[packChoice1-1].name << " at Hotel River Palace " << endl;
            cout << "Goto Menu and take the receipt" << endl;
        }
        else{
            cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
            Sleep(1100);
            system("CLS");
            hotels();
        }

        cout << "\nPress 1 to Redirect Main Menu: ";
        cin >> gotoMenu;
        system("CLS");
        if(gotoMenu == 1){
            menu();
        }
        else{
            menu();
        }
    }
};

float Booking::hotelCost;

class Charges : public Booking, Cabs, Customer //Multiple Inheritance of some other classes to Chargers
{

public:

    void printBill()
    {
        ofstream outf("receipt.txt"); //receipt for bought items
        {
            outf << "--------SAT Travel Agency--------" << endl;
            outf << "-------------Receipt-------------" << endl;
            outf << "___________" << endl;

            outf << "Customer ID: " << Customer::cusID << endl << endl;
            outf << "Description\t\t Total" << endl;
            outf << "Hotel cost:\t\t " << fixed << setprecision(2) << Booking::hotelCost << endl;
            outf << "Travel (cab) cost:\t " << fixed << setprecision(2) << Cabs::lastCabCost << endl;

            outf << "___________" << endl;
            outf << "Total Charge:\t\t " << fixed << setprecision(2) << Booking::hotelCost+Cabs::lastCabCost << endl;
            outf << "___________" << endl;
            outf << "------------THANK YOU------------" << endl;
        }
        outf.close();
        //cout << "Your receipt printed, please get it from the file saved path:D" << endl;
    }

    void showBill()
    {
        ifstream inf("receipt.txt");
        {
            if(!inf)
            {
                cout << "File Error!" << endl;
            }
            while(!(inf.eof()))
            {
                inf.getline(all, 999);
                cout << all << endl;
            }
        }
        inf.close();
    }
};
 void start()
{
    system("Color 0B");
    cout<<"\n\n\n\n\n\n\n\n\n";
    cout<<"\t\t\t\t\t\t----------------------------\n";
    cout<<"\t\t\t\t\t\t----------------------------\n";
    cout<<"\t\t\t\t\t\t\tWelcome To \n"; 
    cout<<"\t\t\t\t\t\tSialkot Adventure Tours \n";
    cout<<"\t\t\t\t\t\t----------------------------\n";
    cout<<"\t\t\t\t\t\tPlease wait for a while\n";
    cout<<"\t\t\t\t\tLoading ";
    char x = 219;
	for(int i=0; i<35; i++)
{
	cout<<x;
	if(i<10)
	Sleep(300);
	if(i>=1 && i<20)
	Sleep(150);
	if(i>=10)
	Sleep(25);
}
 
    system("cls");
    
}
 

void menu() //menu function contain main menu
{

    int mainChoice;
    int inChoice;
    int gotoMenu;
    cout << "\n\t\t\t\t\t     * SIALKOT ADVENTURE TOURS*" << endl;
    cout<<  "\t\t\t\t\t       (Let's Go ^ To Heavens)"  <<endl;
    cout << "\t\t\t     -------------------------MAIN MENU--------------------------" << endl;
    cout<<"\n\n\n\n";
    cout << "\t\t\t\t\t _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ " << endl;
    cout << "\t\t\t\t\t|\t\t\t\t\t|" << endl;
    
    cout << "\t\t\t\t\t|\tCustomer Management -> 1\t|" << endl;
    cout << "\t\t\t\t\t|\tCabs Management     -> 2\t|" << endl;
    cout << "\t\t\t\t\t|\tHotel Booking       -> 3\t|" << endl;
    cout << "\t\t\t\t\t|\tCharges & Bill      -> 4\t|" << endl;
    cout << "\t\t\t\t\t|\tExit                -> 5\t|" << endl;
    cout << "\t\t\t\t\t|\t\t\t\t\t|" << endl;
    cout << "\t\t\t\t\t|_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _|" << endl;
    cout<<"\n";
    cout << "\t\t\t\t\tEnter Choice: ";
    cin >> mainChoice;

    system("CLS");

    Customer a2; //creating objects
    Cabs a3;
    Booking a4;
    Charges a5;

    /*if(mainChoice == 0){

    }*/
    if(mainChoice == 1){
        cout << "------Customers------\n" << endl;
        cout << "1. Enter New Customer"<< endl;
        cout << "2. See Old Customers"<< endl;

        cout << "\nEnter choice: ";
        cin >> inChoice;

        system("CLS");
        if(inChoice == 1){
            a2.getDetails();
        }
        else if(inChoice == 2){
            a2.showDetails();
        }
        else{
            cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
            Sleep(1100);
            system("CLS");
            menu();
        }
        cout << "Press 1 to Redirect Main Menu: ";
        cin >> gotoMenu;
        system("CLS");
        if(gotoMenu == 1){
            menu();
        }
        else{
            menu();
        }
    }
    else if(mainChoice == 2){
        a3.cabDetails();
    }
    else if(mainChoice == 3){
        cout << "-->You Can Book a Luxury Hotel Using The System <--\n" << endl;
        a4.hotels();
    }
    else if(mainChoice == 4){
        cout << "-->Get your receipt<--\n" << endl;
        a5.printBill();
        cout << "Your receipt is already printed you can get it from file path\n" << endl;
        cout << "To display the your receipt in the screen, Enter 1:\n Or enter another key to back main menu: ";
        cin >> gotoMenu;
        if(gotoMenu == 1){
            system("CLS");
            a5.showBill();
            cout << "Press 1 to Redirect Main Menu: ";
            cin >> gotoMenu;
            system("CLS");
            if(gotoMenu == 1){
                menu();
            }
            else{
                menu();
            }
        }
        else{
            system("CLS");
            menu();
        }
    }
    else if(mainChoice == 5){
        cout << "\n\n\t--GOOD-BYE!--" << endl;
        Sleep(1100);
        system("CLS");
        ManageMenu();
    }
    else{
        cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
        Sleep(1100);
        system("CLS");
        menu();
    }
}

int main()
{   start();
    ManageMenu startObj;
    menu();
    return 0;}
