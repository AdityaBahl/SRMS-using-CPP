//*********************
//                   HEADER FILE USED
//**********************
/*
#include<fstream>
#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<string.h>
#include<iomanip>
*/
#include<conio.h>
#include<bits/stdc++.h>
#include<stdio.h>
//*********************
//                   CLASS USED IN PROJECT
//**********************

using namespace std;

class entry
{
	char cn[10];
	char dest[50];
	char ccode[20];
	char date[20];
	int wt;
  public:
	void create_entry()
	{
		cout<<"\nEntry Details...\n";
		cout<<"\nEnter the date";
		gets(date);
		cout<<"\n\nEnter Client Code";
		gets(ccode);
		cout<<"\n\nEnter Cong Number";
		gets(cn);
		cout<<"\n\nEnter Destination";
		gets(dest);
		cout<<"\n\nEnter Weight";
		cin>>wt;
		cout<<"\n\n\nEntry Completed..";
	}

	void show_entry()
	{
		cout<<"\nEnter Cong Number : ";
		gets(cn);
		cout<<"\nDate : ";
		puts(date);
		cout<<"\nClient Code : ";
		puts(ccode);
		cout<<"\nDestination : ";
		puts(dest);
		cout<<"\nWeight : "<<wt;

	}

	void modify_entry()
	{
		cout<<"\nEnter Cong Number : ";
		gets(cn);
		cout<<"\nModify Client Code : ";
		gets(ccode);
		cout<<"\nModify Destination : ";
		gets(dest);
		cout<<"Modify Date : ";
		gets(date);
		cout<<"\nModify Weight : ";
		cin>>wt;
	}

	char* retcn()
	{
		return cn;
	}

	void report()
	{cout<<"\t"<<cn<<setw(15)<<date<<setw(15)<<ccode<<setw(15)<<dest<<setw(10)<<wt<<endl;}
};         //class ends here


//*********************
//    	global declaration for stream object, object
//**********************

fstream fp,fp1;
entry dt ;


//*********************
//    	function to write in file
//**********************

void write_entry()
{
	char ch;
	fp.open("entry.dat",ios::out|ios::app);
	do
	{
		system("cls");
		dt.create_entry();
		fp.write((char*)&dt,sizeof(entry));
		cout<<"\n\nDo you want to add more record..(y/n?)";
		cin>>ch;
	}while(ch=='y'||ch=='Y');
	fp.close();
}


//*********************
//    	function to read specific record from file
//**********************


void display_spb(char n[])
{
	cout<<"\nEntry DETAILS\n";
	int flag=0;
	fp.open("entry.dat",ios::in);
	while(fp.read((char*)&dt,sizeof(entry)))
	{
		if(strcmpi(dt.retcn(),n)==0)
		{
			dt.show_entry();
			flag=1;
		}
	}

	fp.close();
	if(flag==0)
		cout<<"\n\nEntry does not exist";
	getch();
}


//*********************
//    	function to modify record of file
//**********************


void modify_entry()
{
	char n[6];
	int found=0;
	system("cls");
	cout<<"\n\n\tMODIFY Entry REOCORD.... ";
	cout<<"\n\n\tEnter The cong no. of The entry";
	cin>>n;
	fp.open("entry.dat",ios::in|ios::out);
	while(fp.read((char*)&dt,sizeof(entry)) && found==0)
	{
		if(strcmpi(dt.retcn(),n)==0)
		{
			dt.show_entry();
			cout<<"\nEnter The New Details of cong"<<endl;
			dt.modify_entry();
			int pos=-1*sizeof(dt);
			fp.seekp(pos,ios::cur);
			fp.write((char*)&dt,sizeof(entry));
			cout<<"\n\n\t Record Updated";
			found=1;
		}
	}

	fp.close();
	if(found==0)
		cout<<"\n\n Record Not Found ";
	getch();
}


//*********************
//    	function to delete record of file
//**********************


void delete_entry()
{
	char n[6];
	system("cls");
	cout<<"\n\n\n\tDELETE Entry ...";
	cout<<"\n\nEnter The cong no. of the Entry You Want To Delete : ";
	cin>>n;
	fp.open("entry.dat",ios::in|ios::out);
	fstream fp2;
	fp2.open("Temp.dat",ios::out);
	fp.seekg(0,ios::beg);
	while(fp.read((char*)&dt,sizeof(entry)))
	{
		if(strcmpi(dt.retcn(),n)!=0)
		{
			fp2.write((char*)&dt,sizeof(entry));
		}
	}

	fp2.close();
	fp.close();
	remove("entry.dat");
	rename("Temp.dat","entry.dat");
	cout<<"\n\n\tRecord Deleted ..";
	getch();
}


//*********************
//    	function to display Entry list
//**********************

void display_allb()
{
	system("cls");
	fp.open("entry.dat",ios::in);
	if(!fp)
	{
		cout<<"ERROR!!! FILE COULD NOT BE OPEN ";
		getch();
		return;
	}

	cout<<"\n\n\t\tEntry LIST\n\n";
	cout<<"=========================================================================\n";
	cout<<"\tCong Number"<<setw(10)<<"Date"<<setw(20)<<"Client Code"<<setw(15)<<"Destination"<<setw(10)<<"Weight"<<"\n";
	cout<<"=========================================================================\n";

	while(fp.read((char*)&dt,sizeof(entry)))
	{
		dt.report();
	}
	fp.close();
	getch();
}


//*********************
//    	INTRODUCTION FUNCTION
//**********************
/*
void intro()
{
	system("cls");
	//gotoxy(36,11);
	cout<<"COURIER";
	//gotoxy(35,14);
	cout<<"MANAGEMENT";
	//gotoxy(36,17);
	cout<<"SYSTEM";
	getch();
}
*/


//*********************
//    	ADMINISTRATOR MENU FUNCTION
//**********************

void admin_menu()
{
	system("cls");
	int ch2;
	cout<<"\n\n\n\tADMINISTRATOR MENU";
	cout<<"\n\n\t1.Enter Data ";
	cout<<"\n\n\t2.DISPLAY ALL Entries ";
	cout<<"\n\n\t3.DISPLAY SPECIFIC Entry ";
	cout<<"\n\n\t4.MODIFY Entry ";
	cout<<"\n\n\t5.DELETE Entry ";
	cout<<"\n\n\t6.BACK TO MAIN MENU";
	cout<<"\n\n\tPlease Enter Your Choice (1-6) ";
	cin>>ch2;
	switch(ch2)
	{
		case 1: system("cls");
			write_entry();break;
		case 2: display_allb();break;
		case 3: {
			char num[6];
			system("cls");
			cout<<"\n\n\tPlease Enter The Cong No. ";
			cin>>num;
			display_spb(num);
			break;
			}
		case 4: modify_entry();break;
		case 5: delete_entry	();break;
		case 6: return;
		default:cout<<"\a";
	}
	admin_menu();
}


//*********************
//    	THE MAIN FUNCTION OF PROGRAM
//**********************


int main()
{
	char ch;
	//intro();
	do
	{
	    system("cls");
		//clrscr();
		cout<<"\n\n\n\tMAIN MENU";
		cout<<"\n\n\t01. Billing Entry ";
		cout<<"\n\n\t02. Sorting Entry";
		cout<<"\n\n\t03. ADMINISTRATOR MENU";
		cout<<"\n\n\t04. EXIT";
		cout<<"\n\n\tPlease Select Your Option (1-4) ";
		ch=getche();
		switch(ch)
		{
			case '1':system("cls");
				 break;
			case '2':break;
			case '3':admin_menu();
				 break;
			case '4':exit(0);
			default :cout<<"\nWrong Choice try Again!";
			getch();
			cout<<"\a";
		}
	}while(ch!='4');
}

//*********************
//    			END OF PROJECT
//*********************
