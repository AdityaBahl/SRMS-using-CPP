#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
//string pswrdcheck="password";
void studentacc();
void quitting()
{
    cout << "\t\t\n\n\n\n\n\n\n\t\t\t\t\tQuitting The Program ";
    for (int i = 0; i < 4; i++)
    {
        Sleep(750);
        cout << ". ";
    }
}
//void adminacc();
class student //STUDENT CLASS
{
    int student_id;
    string name;
    char gender;
    string course;
    int sem;
    float marks;
    float percentage;

public:
    void get_data();
    void show_data();
    int get_student_id() { return student_id; }
} s;
class admin
{
};

void student::get_data()
{
    cout << "\nEnter the student details....\n";
    cout << "Enter student ID         ";
    cin >> student_id;
    cout << "Enter full name          ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter gender  M/F        ";
    cin >> gender;
    cout << "Enter course             ";
    cin.ignore();
    getline(cin, course);
    cout << "Enter semester           ";
    cin >> sem;
    cout << "Enter marks (out of 500) ";
    cin >> marks;
    cout << endl;
    percentage = marks / 5;
}
void student::show_data()
{
    cout << "\n\n\n..... Student Details ....\n";
    cout << "Student ID         : " << student_id << endl;
    cout << "Full name          : " << name << endl;
    cout << "Gender             : " << gender << endl;
    cout << "Course             : " << course << endl;
    cout << "Marks              : " << marks << endl;
    cout << "Semester           : " << sem << endl;
    cout << "Percentage         : " << percentage << endl;
    cout << endl;
}

void add_data()
{
    char ch;
    ofstream fout;
    fout.open("Students.txt", ios::binary | ios::out | ios::app);
    s.get_data();
    fout.write((char *)&s, sizeof(s));
    fout.close();
    cout << "\n\nData successfully saved to file....\n";
}

void display_data()
{
    ifstream fin;
    fin.open("Student.txt", ios::binary | ios::in);
    while (!fin.eof())
    {
        fin.read((char *)&s, sizeof(s));
        s.show_data();
    }
    fin.close();
    system("cls");
    cout << "\n\nData reading from successfully done....\n";
}

void searchdata()
{
    int n;
    bool b = false;
    ifstream fin;
    fin.open("students.txt", ios::binary | ios::in);
    cout << "Enter student id you want to serach : ";
    cin >> n;
    while (fin.read((char *)&s, sizeof(s)))
    {
        if (n == s.get_student_id())
        {
            cout << "The details of student " << n << " shown herewith :\n";
            s.show_data();
            b = true;
        }
    }
    fin.close();
    if (!b)
        cout << "The student with ID " << n << " not found!!!...\n";
    cout << "Data reading from file sucessfully done....\n";
}

void delete_data()
{
    int n;
    bool b = false;
    ifstream fin;
    ofstream fout, tout;
    fin.open("students.txt", ios::binary | ios::in);
    fout.open("tempstudents.txt", ios::binary | ios::out);
    fin.open("trashstudents.txt", ios::binary | ios::out);

    cout << "Enter student ID you want to move to trash:\n";
    cin >> n;
    while (fin.read((char *)&s, sizeof(s)))
    {
        if (n == s.get_student_id())
        {
            cout << "The details of the following student has been moved to trash :\n";
            s.show_data();
            tout.write((char *)&s, sizeof(s));
            b = true;
        }
        else
            fout.write((char *)&s, sizeof(s));

        fout.close();
        tout.close();
        fin.close();
        if (!b)
            cout << "The student with ID " << n << " not found!!!...\n";
        remove("students.txt");
        rename("tempstudents.txt", "students.txtx");
    }
}

void get_trash()
{
    ifstream fin;
    fin.open("trashstduents.txt", ios::binary | ios::in);
    while (fin.read((char *)&s, sizeof(s)))
    {
        s.show_data();
    }
    fin.close();
    cout << "\n\nData reading from file sucessfully done\n";
}

void modify_data()
{
    int n, pos;
    bool b = false;
    fstream f;
    f.open("students.txt", ios::in | ios::out | ios::binary);
    cout << "Enter ID of student whose details you want to modify\n";
    cin >> n;

    while (f.read((char *)&s, sizeof(s)))
    {
        pos = f.tellg();
        if (n == s.get_student_id())
        {
            cout << "The following student details will be modified with new data\n";
            s.show_data();
            f.seekg(pos - sizeof(s));
            f.write((char *)&s, sizeof(s));
            b = true;
        }
    }
    f.close();

    if (!b)
        cout << "The student with ID " << n << " not found!!!...\n";
    cout << "Data reading from file sucessfully done....\n";
}

void menu()
{
    string pswrd;
    int a;
retry:
    cout << "\n\n\n\n\t\t\t ......_____STUDENT RECORD MANAGEMENT SYSTEM____......\n";
    cout << "\n\n\n\t\t\t\t\t\t\n\n Enter Password : ";
    cin >> pswrd;
    fstream f;
    f.open("password.txt", ios::in);
    string psw;
    f >> psw;
    //if (pswrd == psw)
    if (pswrd == "psw")
    {
        system("cls");
        cout << "\n\n\n\n\t\t\t\t ......_____STUDENT RECORD MANAGEMENT SYSTEM____......\n";
        cout << "\n\n\n\t\t\t\t\t 1.)Admininstrative Access\n";
        cout << "\n\n\t\t\t\t\t 2.)Students Access\n";
        cout << "\n\n\t\t\t\t\t 3.)Exit \n";
        cout << "\n\n\t\t\t\t\t ENTER YOUR CHOICE: ";
        cin >> a;
        cout << endl;
        switch (a)
        {
        case 1:
            system("cls");
            // adminacc();
            goto retry;
            break;
        case 2:
            system("cls");
            studentacc();
            goto retry;
            break;
        case 3:
            system("cls");
            quitting();
            exit(0);
            break;
        }
        return;
    }
    else
    {
        system("cls");
        char ch;
        cout << "\t\t\n\n\n\n\n\n\n\t\t\t\t\tWrong Password! Try again?(y/n)";
        cin >> ch;
        if (ch == 'y')
        {
            system("cls");
            goto retry;
        }
        else if (ch == 'n')
        {
            system("cls");
            quitting();
            exit(0);
        }
    }
}
void studentacc()
{
    int ch;
    cout << "\t\t\t\tStudent Accesss\n";
    cout << "1.)To add a student\n";
    cout << "2.)To display details of all students\n";
    cout << "3.)To search a student and get his details\n";
    cout << "4.)To delete a student's details\n";
    cout << "5.)To get deleted records from trash a student\n";
    cout << "6.)To modify student's details\n";
    cout << "Enter the choice : ";
    cin >> ch;
    system("cls");
    switch (ch)
    {
    case 1:
        add_data();
        break;
    case 2:
        display_data();
        break;
    case 3:
        searchdata();
        break;

    case 4:
        delete_data();
        break;
    case 5:
        get_trash();
        break;
    case 6:
        modify_data();
        break;
    }
}
/*void changepass()
{
    redopass:
    string newpass,passver;
    cout<<"Enter Old Password\n";
    cin>>passver;
    if(passver==pswrdcheck)
    {
    cout<<"Enter New Password\n";
    cin>>newpass;
    pswrdcheck=newpass;
    }
    else
    {
       char ch;
        cout<<"\t\t\n\n\n\n\n\n\n\t\t\t\t\tWrong Password! Try again?(y/n)";
        cin>>ch;
        if(ch=='y')
        {
            system("cls");
            goto redopass;
        }
        else if(ch=='n')
        {
            system("cls");
            cout<<"\t\t\n\n\n\n\n\n\n\t\t\t\t\tQuitting The Program";
            for (int i = 0; i < 4; i++)
            {   Sleep(1000);
                cout << ".";
            }
            exit(0);
        }
    }
}*/
/*void adminacc()
{
    adminredo:
    int a;
    cout<<"\n\n\n\n\t\t\t\t Welcome To Aditya's Student Record Database Management system\n";
    cout<<"\n\n\n\n\t\t\t\t          |ADMINISTRATIVE ACCESS|\n";
    cout<<"\n\n\n\t\t\t\t\t 1.)Enter Details\n";
    cout<<"\n\n\t\t\t\t\t 2.)View Details\n";
    cout<<"\n\n\t\t\t\t\t 3.)Delete Details\n";
    cout<<"\n\n\t\t\t\t\t 4.)Change password For Adminstrators \n";
    cout<<"\n\n\t\t\t\t\t 5.)Change password For Students \n";
    cout<<"\n\n\t\t\t\t\t 6.)Exit";
    cout<<"\n\n\t\t\t\t\t ENTER YOUR CHOICE :";
    cin>>a;
    switch(a)
    {
    case 1:
        cout<<"adddata()";
         system("cls");
        break;
    case 2:
        cout<<"viewdata()";
        system("cls");
        break;
    case 3:
       cout<<" deletedata()";
       system("cls");
        break;
    case 4:
      changepass();
      system("cls");
      goto adminredo;
      exit (0);
        break;
    case 5:
      changepass();
      system("cls");
      goto adminredo;
      exit (0);
        break;
    case 6:
        cout << "\t\t\n\n\n\n\n\n\n\t\t\t\t\tQuitting The Program ";
        for (int i = 0; i < 4; i++)
        {   Sleep(1000);
            cout << ". ";
        }
        exit(0);
        break;
    }
}
*/
int main()
{
    menu();
    return 0;
}