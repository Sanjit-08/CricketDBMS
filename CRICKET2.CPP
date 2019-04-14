#include<fstream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
/**************************************************************************************
			      CLASS DECLARATION
***************************************************************************************/
class cricketer
{
	int runs,wicket,overs,balls,innings,hsc,bbowl,plcode;
	public:
	int matches;
	char name[10],country[10];

	void input()
	{
		cout<<"\n\t\t Enter The Details: \n";
		cout<<"\n\t Player Code: ";
		cin>>plcode;
		cout<<"\n\t Name Of The Player: ";
		cin>>name;
		cout<<"\n\t Country: ";
		cin>>country;
		cout<<"\n\t Matches Played: ";
		cin>>matches;
		cout<<"\n\t Innings: ";
		cin>>innings;
		cout<<"\n\t Runs: ";
		cin>>runs;
		cout<<"\n\t Balls Played: ";
		cin>>balls;
		cout<<"\n\t Overs Bowled: ";
		cin>>overs;
		cout<<"\n\t Wickets: ";
		cin>>wicket;
	}

/**************************************************************************************
				 FUNCTIONS USED
***************************************************************************************/

	void display()
	{
		cout<<"\n"<<plcode<<"\t"<<name<<"\t"<<country<<"\t"<<matches<<"\t"<<innings<<"\t"<<runs<<"\t"<<balls<<"\t"<<overs<<"\t"<<wicket;
	}

	int get_plcode()
	{
		return plcode;
	}
	int get_wickets()
	{
		return wicket;
	}
	char* get_country()
	{
		return country;
	}
	int get_matches()
	{
		return matches;
	}
	int get_runs()
	{
		return runs;
	}
};

/**************************************************************************************
				VOID MAIN
***************************************************************************************/

void main()
{
	fstream file,file1;
	char ch;
	int choice,choice1,pcode,flag,choice2,loc,n;
	cricketer ob;
/**************************************************************************************
				MAIN MENU
***************************************************************************************/

	do
	{
		clrscr();
		cout<<"********************************************************************************";
		cout<<"********************************************************************************";
		cout<<"\n\t\t\t CRICKET DATABASE MANAGEMENT";
		cout<<"\n\n********************************************************************************";
		cout<<"********************************************************************************\n";
		cout<<"\n********************************************************************************";
		cout<<"\n\t\t\t\t MAIN MENU\n";
		cout<<"\n********************************************************************************";
		cout<<"\n\tPress 1 For Data Entry";
		cout<<"\n\tPress 2 For Reports";
		cout<<"\n\tPress 3 For Quitting";
		cout<<"\n\nEnter Choice: ";
		cin>>choice;
		switch(choice)
		{
		case 1:
		do
		{
/**************************************************************************************
			      MENU FOR DATA ENTRY
***************************************************************************************/

			clrscr();
			cout<<"________________________________________________________________________________";
			cout<<"\n\t\t\t\tDATA ENTRY MENU\n";
			cout<<"________________________________________________________________________________";
			cout<<"\nPress 1 For Fresh Entry Of Records";
			cout<<"\nPress 2 For Adding Records";
			cout<<"\nPress 3 To  Display All Records";
			cout<<"\nPress 4 For Deleting A Record";
			cout<<"\nPress 5 For Modification";
			cout<<"\nPress 6 For Exit To Main Menu";
			cout<<"\nEnter Your Choice: ";
			cin>>choice1;
			switch(choice1)
			{
/**************************************************************************************
			      CODING FOR ENTRY OF FRESH RECORDS
***************************************************************************************/

				case 1:
				clrscr();
				file.open("crick.dat",ios::out|ios::binary);
				do
				{
					ob.input();
					file.write((char*)&ob,sizeof(ob));
					cout<<"\nDo You Want To Enter More Records(Y/N)";
					cin>>ch;
				}
				while(ch=='Y' || ch=='y');
				file.close();
				cout<<"\n!!Record Added!!";
				break;

/**************************************************************************************
			      CODING FOR ADDING A NEW RECORD
***************************************************************************************/

				case 2:
				file.open("crick.dat",ios::app|ios::binary);
				do
				{
					ob.input();
					file.write((char*)&ob,sizeof(ob));
					cout<<"\nDo You Want To Enter More Records(Y/N)";
					cin>>ch;
				}
				while(ch=='Y' || ch=='y');
				file.close();
				cout<<"\n!!Record Added!!";
				break;

/**************************************************************************************
			      CODING FOR DISPLAYING ALL RECORDS
***************************************************************************************/

				case 3:
				file.open("crick.dat",ios::in|ios::binary);
				cout<<"\n"<<"Plyr Cd\t"<<"Name\t"<<"Country\t"<<"Matches\t"<<"Innings\t"<<"Runs\t"<<"Balls\t"<<"Overs\t"<<"Wicket\t";
				while(file.read((char*)&ob,sizeof(ob)))
				{
					ob.display();
				}
				file.close();
				cout<<"\n\nPress Any Key To Continue";
				break;

/**************************************************************************************
			      CODING FOR DELETING A RRECORD
***************************************************************************************/

				case 4:
				file.open("crick.dat",ios::in|ios::binary);
				file1.open("crick1.dat",ios::out|ios::binary);
				flag=0;
				cout<<"\n Enter The Player Code Of Player Whose Record Is To Be Deleted ";
				cin>>pcode;
				while(file.read((char*)&ob,sizeof(ob)))
				{
					if(ob.get_plcode()!=pcode)
					{
						file1.write((char*)&ob,sizeof(ob));
					}

					else
					{
						flag=1;
					}
				}
				file.close();
				file1.close();
				if(flag==0)
				{
					cout<<"\n Record Not Found";
					remove("crick1.dat");
				}
				else
				{
					remove("crick.dat");
					rename("crick1.dat","crick.dat");
				}
				cout<<"\n!!Record Deleted!!";
				break;

/**************************************************************************************
			      CODING FOR MODIFYING A RECORD
***************************************************************************************/

				case 5:
				file.open("crick.dat",ios::in|ios::out|ios::ate|ios::binary);
				file.seekg(0);
				flag=0;
				cout<<"Enter The Player Code Of Record To Be Edited: ";
				cin>>pcode;
				while(file.read((char*)&ob,sizeof(ob)))
				{
				if(ob.get_plcode()==pcode)
				{
					flag=1;
					loc=file.tellg();

					break;
				}

				}
				if(flag==1)
				{
					cout<<"\n Old Record\n";
					cout<<"\n"<<"Plyr Cd\t"<<"Name\t"<<"Country\t"<<"Matches\t"<<"Innings\t"<<"Runs\t"<<"Balls\t"<<"Overs\t"<<"Wicket\t";
					ob.display();
					cout<<"\nEnter Modifications";
					ob.input();
					file.seekg(loc-sizeof(ob));
					file.write((char*)&ob,sizeof(ob));
					cout<<"\n!!Record Modified!!";
				}
				else
				{
					cout<<"\nRecord Not Found!!";
				}
				file.close();
				break;

/**************************************************************************************
			      CODING FOR EXITING DATA ENTRY MENU
***************************************************************************************/

				case 6:
				cout<<"\nQuit From Data Entry Menu";
				break;

				default:
				cout<<"\n Wrong Choice For Data Entry Menu";
				break;

				cout<<"\nPress Any Key To Continue";
			}
		getch();
	}
	while(choice1!=6);

	break;

/**************************************************************************************
			      MENU FOR REPORTS
***************************************************************************************/

	case 2:
	do
	{
		clrscr();
		cout<<"\n________________________________________________________________________________";
		cout<<"\n\t\t\t\tREPORT MENU";
		cout<<"\n________________________________________________________________________________";
		cout<<"\nPress 1 For Displaying Information Wicket Wise ";
		cout<<"\nPress 2 For Displaying Information Country Wise ";
		cout<<"\nPress 3 For Displaying Information On The Basis Of Number Of Matches Played ";
		cout<<"\nPress 4 For Displaying Information On The Basis Of Runs ";
		cout<<"\nPress 5 To Quit ";
		cout<<"\nEnter Choice: ";
		cin>>choice2;
		switch(choice2)
		{
/**************************************************************************************
			      CODING FOR WICKET WISE INFORMATION
***************************************************************************************/

			case 1:
			cout<<"Enter Minimum Number Of Wickets: ";
			cin>>n;
			file.open("crick.dat",ios::in|ios::binary);
			cout<<"\n"<<"Plyr Cd\t"<<"Name\t"<<"Country\t"<<"Matches\t"<<"Innings\t"<<"Runs\t"<<"Balls\t"<<"Overs\t"<<"Wicket\t";
			while(file.read((char*)&ob,sizeof(ob)))
			{
				if(ob.get_wickets()>n)
				{
					ob.display();
				}
			}
			file.close();
			cout<<"\n\nPress Any Key To Continue";
			break;

/**************************************************************************************
			      CODING FOR COUNTRY WISE INFORMATION
***************************************************************************************/

			case 2:
			char country[10];
			cout<<"\nEnter Name Of Country: ";
			cin>>country;
			file.open("crick.dat",ios::in|ios::binary);
			cout<<"\n"<<"Plyr Cd\t"<<"Name\t"<<"Country\t"<<"Matches\t"<<"Innings\t"<<"Runs\t"<<"Balls\t"<<"Overs\t"<<"Wicket\t";
			while(file.read((char*)&ob,sizeof(ob)))
			{
				if(strcmpi(ob.get_country(),country)==0)
					{
						ob.display();
					}
			}
			file.close();
			cout<<"\n\nPress Any Key To Continue";
			break ;

/**************************************************************************************
	       CODING FOR INFORMATION BASED ON NUMBER OF MATCHES PLAYED
***************************************************************************************/

			case 3:
			cout<<"Enter Minimum Number Of Matches: ";
			cin>>n;
			file.open("crick.dat",ios::in|ios::binary);
			cout<<"\n"<<"Plyr Cd\t"<<"Name\t"<<"Country\t"<<"Matches\t"<<"Innings\t"<<"Runs\t"<<"Balls\t"<<"Overs\t"<<"Wicket\t";
			while(file.read((char*)&ob,sizeof(ob)))
			{
				if(ob.get_matches()>n)
				{
					ob.display();
				}
			}
			file.close();
			cout<<"\n\nPress Any Key To Continue";
			break  ;

/**************************************************************************************
			  CODING FOR INFORMATION BASED ON RUNS SCORED
***************************************************************************************/

			case 4:
			cout<<"Enter Minimum Runs: ";
			cin>>n;
			file.open("crick.dat",ios::in|ios::binary);
			cout<<"\n"<<"Plyr Cd\t"<<"Name\t"<<"Country\t"<<"Matches\t"<<"Innings\t"<<"Runs\t"<<"Balls\t"<<"Overs\t"<<"Wicket\t";
			while(file.read((char*)&ob,sizeof(ob)))
			{
				if(ob.get_runs()>n)
				{
					ob.display();
				}
			}
			file.close();
			cout<<"\n\nPress Any Key To Continue";
			break;

/**************************************************************************************
			      CODING FOR EXITING REPORT MENU
***************************************************************************************/

			case 5:
			cout<<"\nQuit To Main Menu";
			break;

			default:
			cout<<"\nWrong Choice ....";
			break;

			cout<<"\n Press Any Key To Continue";
		}
		getch();
	}
	while(choice2!=5);

	break;

/**************************************************************************************
			      CODING QUITTING FROM MAIN MENU
***************************************************************************************/

	case 3:
	cout<<"\nBye!!";
	break;

	default:
	cout<<"\n Wrong Choice For Main Menu";
	}
cout<<"\nPress Any Key To Continue";
getch();
}
while(choice!=3);
}
