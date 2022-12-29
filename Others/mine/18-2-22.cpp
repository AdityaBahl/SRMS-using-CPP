#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <windows.h>
using namespace std;
//#define clear system("cls")
#define clear cout << "\n";
#define endl "\n"
void loadingbar();                             //loading animation
void addnew(char *, int, int, string, string); //to add a new entry(option 1)
void stulog(char *);                           //student login(option 2)
void faclog(int count_n, char *);              //faculty login(option 3)
void proc();                                   //proctor login(option 4)
void adminview();                              //admin view(option 5)
int main()                                     //MAIN FUNCTION
{
    clear;
    loadingbar();
    clear;
    char data[20];
    int n = 0, option = 0, count_n = 0;
    // This is the initial mark alloted to a subject.
    string empty = "00";
    string proctor = "";
    // Name of the file in which DB is stored.
    ifstream f("Example.txt");
    string line;
    // The following for loop counts the total number of lines in the file.
    for (int i = 0; std::getline(f, line); ++i)
        count_n++;
    // This prints out all the available options in the DB
    while (option != 6)
    {
        clear;
        cout << "\nAvailable operations: \n\n\n1. Add New Students\n2. Student Login\n3. Faculty Login\n4. Proctor Login\n5. Admin View\n6. Exit\nEnter option: ";
        cin >> option;
        switch (option)
        {
        case 1:
            clear;
            addnew(data, n, count_n, empty, proctor);
            cout << "DONT FORGET TO INSERT THE MARKS SCORED VIA PROCTORED LOGIN";
            cin.ignore();
            cin.get();
            continue;
        case 2:
            clear;
            stulog(data);
            cin.ignore();
            cin.get();
            continue;
        case 3:
            clear;
            faclog(count_n, data);
            cin.ignore();
            cin.get();
            continue;
        case 4:
            clear;
            proc();
            cin.ignore();
            cin.get();
            continue;
        case 5:
            clear;
            adminview();
            cin.ignore();
            cin.get();
            continue;
        case 6:
            clear;
            loadingbar();
            cin.ignore();
            cin.get();
            clear;
            return 0;
        default:
            cout << "\n";
        }
    }
    return 0;
}
void loadingbar()
{
    //clear;
    //cout << "OM NAMAH SHIVAY";
    system("color 8F");
    //char a = 177, b = 219;
    cout << "\n\t\t\t\t\tProject By Aditya Bahl, B, 20021038";
    cout << "\n\n\n\n\n\t\t\t\t\tSTUDENT's RECORD MAINTENANCE SYSTEM";
    cout << "\n\n\n\t\t\t\t\tLoading...\n\n\t\t\t\t\t";
    for (int i = 0; i < 26; i++)
        cout << char(177);
    cout << "\r";
    cout << "\t\t\t\t\t";
    for (int i = 0; i < 26; i++)
    {
        cout << char(219);
        Sleep(190);
    }
}
void addnew(char *data, int n, int count_n, string empty, string proctor)
{
    cout << "Enter the number of students: ";
    cin >> n;
    int marksinput = 0;
    count_n += n;
    for (int i = 0; i < n; i++)
    {
        ifstream f("Example.txt");
        ofstream outfile;
        outfile.open("Example.txt", ios::app);
        // The entire data of a single student is
        // stored line-by-line.
        cout << "Enter Your Unique Registration Number: ";
        cin >> data;
        outfile << data << "\t";
        cout << "Enter The First Name: ";
        cin >> data;
        outfile << data << "\t";
        // Inserting empty data initially into the file
        cout << "Enter Your Unique Subject 1: ";
        cin >> marksinput;
        outfile << marksinput << "\t";
        cout << "Enter Your Unique Subject 2: ";
        cin >> marksinput;
        outfile << marksinput << "\t";
        cout << "Enter Your Unique Subject 3: ";
        cin >> marksinput;
        outfile << marksinput << "\t";
        cout << "Enter Your Unique Proctor ID: ";
        cin >> proctor;
        outfile << proctor << endl;
    }
}
void stulog(char *data)
{
    char regno[9];
    cout << "Enter your registration number: ";
    cin >> regno;
    ifstream infile;
    int check = 0;
    infile.open("Example.txt", ios::in);
    // This loop prints out the data according to the registration number specified.
    while (infile >> data)
    {
        if (data == regno)
        {
            cout << "\nRegistration Number: " << data << endl;
            infile >> data;
            cout << "Name: " << data << endl;
            infile >> data;
            cout << "Subject1 mark: " << data << endl;
            infile >> data;
            cout << "Subject2 mark: " << data << endl;
            infile >> data;
            cout << "Subject3 mark:" << data << endl;
            infile >> data;
            cout << "Proctor ID: " << data << endl;
            infile.close();
            check = 1;
        }
    }
    if (check == 0)
        cout << "No such registration number found!" << endl;
}
void faclog(int count_n, char *data)
{
    string subcode;
    int option;
    cout << "Enter your subject code: ";
    cin >> subcode;
    string code1 = "10", code2 = "20", code3 = "30", mark = "";
    ifstream infile;
    int check = 0;
    cout << "\nAvailable operations: \n1. Add data about marks\n2. View data\nEnter option: ";
    cin >> option;
    if (option == 1)
    {
        cout << "Warning! You would need to add mark details for all the students!" << endl;
        for (int i = 0; i < count_n; i++)
        {
            fstream file("Example.txt");
            // The seek in file has been done according to the length of the data being inserted. It needs
            // to be adjusted accordingly for different lengths of data.
            if (subcode == code1)
            {
                file.seekp(26 + 37 * i, std::ios_base::beg);
                cout << "Enter the mark of student#" << (i + 1) << " : ";
                cin >> mark;
                file.write(mark.c_str(), 2);
            }
            if (subcode == code2)
            {
                file.seekp(29 + 37 * i, std::ios_base::beg);
                cout << "Enter the mark of student#" << (i + 1) << " : ";
                cin >> mark;
                file.write(mark.c_str(), 2);
            }
            if (subcode == code3)
            {
                file.seekp(32 + 37 * i, std::ios_base::beg);
                cout << "Enter the mark of student#" << (i + 1) << " : ";
                cin >> mark;
                file.write(mark.c_str(), 2);
            }
        }
    }
    // This loop is used to view marks of a student.The extra infile commands have been used to
    // get a specific mark only since the data has been seperated by a tabspace.
    else if (option == 2)
    {
        infile.open("Example.txt", ios::in);
        if (subcode == code1)
        {
            cout << "Registration number - Marks\n"
                 << endl;
            while (infile >> data)
            {
                //cout << "-->1 " << code1 << endl;
                cout << data;
                infile >> data;
                infile >> data;
                cout << " - " << data << endl;
                infile >> data;
                infile >> data;
                check = 1;
            }
        }
        infile.close();
        infile.open("Example.txt", ios::in);
        if (subcode == code2)
        {
            cout << "Registration number - Marks\n"
                 << endl;
            while (infile >> data)
            {
                //cout << "-->2 " << code2 << endl;
                cout << data;
                infile >> data;
                infile >> data;
                infile >> data;
                cout << " - " << data << endl;
                infile >> data;
                check = 1;
            }
        }
        infile.close();
        infile.open("Example.txt", ios::in);
        if (subcode == code3)
        {
            cout << "Registration number - Marks\n"
                 << endl;
            while (infile >> data)
            {
                //cout << "-->3 " << code3 << endl;
                cout << data;
                infile >> data;
                infile >> data;
                infile >> data;
                cout << " - " << data << endl;
                infile >> data;
                check = 1;
            }
        }
    }
    cout << subcode << " -3-->" << code1 << "-3--> " << code2 << endl;
    infile.close();
    if (check == 0)
        cout << "No such subject code found!" << endl;
}
// This loop displays all the details of students under the same proctor ID.
void proc()
{
    //char procid[10], a;
    string procid, a;
    cout << "Enter your proctor ID: ";
    cin >> procid;
    int check = 0;
    //char temp1[100], temp2[100], temp3[100], temp4[100], temp5[100], id[100];
    string temp1, temp2, temp3, temp4, temp5, id;
    ifstream infile;
    infile.open("Example.txt", ios::in);
    while (infile >> temp1)
    {
        infile >> temp2;
        infile >> temp3;
        infile >> temp4;
        infile >> temp5;
        infile >> id;
        //cout << temp1 << " " << temp2 << " " << temp3 << " " << temp4 << " " << temp5 << " " << id << " " << procid << endl;
        if (id == procid)
        {
            cout << "\nRegistration Number:     " << temp1 << endl;
            cout << "Name:                    " << temp2 << endl;
            cout << "Subject1 Marks:          " << temp3 << endl;
            cout << "Subject2 Marks:          " << temp4 << endl;
            cout << "Subject3 Marks:          " << temp5 << endl;
            check = 1;
            cout << "\n Press Any Key To Continue!\n";
            cin >> a;
        }
        //cout << "yo ";
        //Sleep(1000);
    }
    if (check == 0)
        cout << "No such proctor ID found!" << endl;
}
void adminview()
{
    char password[25];
    cout << "Enter the admin password: ";
    cin >> password;
    // This variable value can be changed according to your requirement of the administrator password.
    string admin_pass = "admin";
    if (password == admin_pass)
    {
        //cout << "Reg No.\t--> Name\t--> TCA\t--> TMA\t--> Proctor ID" << endl;
        ifstream infile;
        infile.open("Example.txt", ios::in);
        char data[25];
        int i = 1;
        while (infile >> data)
        {
            cout << i << "ST STUDENT's DETAILS:\n\n";
            cout << "Registration Number: " << data << endl;
            infile >> data;
            cout << "Name:                " << data << endl;
            infile >> data;
            cout << "Subject1 Marks:      " << data << endl;
            infile >> data;
            cout << "Subject2 Marks:      " << data << endl;
            infile >> data;
            cout << "Subject3 Marks:      " << data << endl;
            infile >> data;
            cout << "Proctor ID:          " << data << "\n\n\n";
            i++;
        }
    }
}