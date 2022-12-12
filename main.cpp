#include <iostream>
#include <Windows.h>
using namespace std;
string pswrdchk = "password"; // password
void changepass();
void adminacc();
void studacc();
void menu()
{
    string pswrd;
    int a;
retry:
    cout << "\n\n\n\n\t\t\t\t Welcome To Aditya's Student Record Database Management system\n";
    cout << "\n\n\n\t\t\t\t\t\t\n\n Enter Password : ";
    cin >> pswrd;
    if (pswrd == pswrdchk)
    {
        system("cls");
        cout << "\n\n\n\n\t\t\t\t Welcome To Aditya's Student Record Database Management system\n";
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
            adminacc();
            goto retry;
            break;
        case 2:
            system("cls");
            studacc();
            goto retry;
            break;
        case 3:
            system("cls");
            cout << "\t\t\n\n\n\n\n\n\n\t\t\t\t\tQuitting The Program ";
            for (int i = 0; i < 4; i++)
            {
                Sleep(1000);
                cout << ". ";
            }
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
            cout << "\t\t\n\n\n\n\n\n\n\t\t\t\t\tQuitting The Program";
            for (int i = 0; i < 4; i++)
            {
                Sleep(1000);
                cout << ".";
            }
            exit(0);
        }
    }
}
void changepass()
{
redopass:
    string newpass, passver;
    cout << "Enter Old Password\n";
    cin >> passver;
    if (passver == pswrdchk)
    {
        cout << "Enter New Password\n";
        cin >> newpass;
        pswrdchk = newpass;
    }
    else
    {
        char ch;
        cout << "\t\t\n\n\n\n\n\n\n\t\t\t\t\tWrong Password! Try again?(y/n)";
        cin >> ch;
        if (ch == 'y')
        {
            system("cls");
            goto redopass;
        }
        else if (ch == 'n')
        {
            system("cls");
            cout << "\t\t\n\n\n\n\n\n\n\t\t\t\t\tQuitting The Program";
            for (int i = 0; i < 4; i++)
            {
                Sleep(1000);
                cout << ".";
            }
            exit(0);
        }
    }
}
void adminacc()
{
adminredo:
    int a;
    cout << "\n\n\n\n\t\t\t\t Welcome To Aditya's Student Record Database Management system\n";
    cout << "\n\n\n\n\t\t\t\t          |ADMINISTRATIVE ACCESS|\n";
    cout << "\n\n\n\t\t\t\t\t 1.)Enter Details\n";
    cout << "\n\n\t\t\t\t\t 2.)View Details\n";
    cout << "\n\n\t\t\t\t\t 3.)Delete Details\n";
    cout << "\n\n\t\t\t\t\t 4.)Change password For Adminstrators \n";
    cout << "\n\n\t\t\t\t\t 5.)Change password For Students \n";
    cout << "\n\n\t\t\t\t\t 6.)Exit";
    cout << "\n\n\t\t\t\t\t ENTER YOUR CHOICE :";
    cin >> a;
    switch (a)
    {
    case 1:
        cout << "adddata()";
        system("cls");
        break;
    case 2:
        cout << "viewdata()";
        system("cls");
        break;
    case 3:
        cout << " deletedata()";
        system("cls");
        break;
    case 4:
        changepass();
        system("cls");
        goto adminredo;
        exit(0);
        break;
    case 5:
        changepass();
        system("cls");
        goto adminredo;
        exit(0);
        break;
    case 6:
        cout << "\t\t\n\n\n\n\n\n\n\t\t\t\t\tQuitting The Program ";
        for (int i = 0; i < 4; i++)
        {
            Sleep(1000);
            cout << ". ";
        }
        exit(0);
        break;
    }
}
void studacc()
{
    cout << "\n\n\n\n\t\t\t\t Welcome To Aditya's Student Record Database Management system\n";
    cout << "\n\n\n\n\t\t\t\t          |STUDENT ACCESS|\n";
    cout << "\n\n\t\t\t\t\t 1.)View Details For All\n";
    cout << "\n\n\t\t\t\t\t 2.)View Details For a Single Student\n";
    cout << "\n\n\t\t\t\t\t 3.)Change password For Students \n";
    cout << "\n\n\t\t\t\t\t 4.)Exit";
    cout << "\n\n\t\t\t\t\t ENTER YOUR CHOICE :";
}
int main()
{
    menu();
    return 0;
}
v
