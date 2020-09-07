/*
########################################################################
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
				PROGRAM CODE
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
########################################################################
*/
/*
########################################################################
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
			SUBMITTED BY:- ASHISH KUMAR
			  
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
########################################################################
*/
/*
########################################################################
				  HEADER FILES USED
########################################################################
*/
#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<Process.h>
#include<dos.h>
#include<stdlib.h>
/*
########################################################################
		FUNCTIONS USED FOR MAKING THE PROGRAM ATTRACTIVE
########################################################################
*/
void conviction(int h, int hh, char goh[],int c=0,int del=21)
{
char ch;
int i,j=0;
randomize();
while(goh[j]!='\0')
{
for(i=0;i<random(25);i++)
{gotoxy(h,hh);
 delay(del);
ch=65+random(40);
cout<<ch;}
gotoxy(h,hh);
if(c!=0){textcolor(YELLOW);cprintf("%c",goh[j]);}
else
printf("%c",goh[j]);
j++;h++;
if(h==81)
{h=1;hh++;}
}
}
/*
########################################################################
			     FRONG PAGE - TOPIC
########################################################################
*/
				 void intr()
{
clrscr();
textbackground(BLUE);
textcolor(YELLOW);
conviction(33,5,"   PROJECT ON \0",1);
gotoxy(33,6);cout<<"   ~~~~~~~~~~ ";
conviction(32,8,"HOSPITAL MANAGEMENT \0",1);
gotoxy(32,9);cout<<"~~~~~~~~~~~~~~~~~~~";
delay(500);
cout<<"\n-------------------------------------------------------------------------------";
conviction(2,13,"   PLEASE WAIT WHILE THE PROGRAM IS LOADING \0",1);
for(int kx=0;kx<=6;kx++)
{
cout<<" . ";
delay(100);
}
delay(600);
for(int xa=0;xa<1;xa++)
{
conviction(30,16,"  PROGRAM LOADED  \0",1);
conviction(30,17,"~~~~~~~~~~~~~~~~~~~~ \0",1);
delay(800);
}

cout<<"\n\n-------------------------------------------------------------------------------";
conviction(4,22," SUBMITTED BY :- \0",1);
delay(2000);
conviction(22,22,"ASHISH KUMAR \0",1);
cout<<"\n\n-------------------------------------------------------------------------------";
delay(1500);
cout<<"\n Don't press any key!!"; delay(500);
for(int a=0;a<7;a++)
{
cout<<" . ";
delay(300);
}
conviction(28,31,"   PROGRAM LOADED   \0",1);delay(500);
conviction(28,32,"~~~~~~~~~~~~~~~~~~~~~~ \0",1);delay(500);
}
/*
########################################################################
	    CLASS FOR CONTROLLING ALL FUNCTIONS RELATED TO DOCTOR
########################################################################
*/
			       class doctor
{
char n[20],q[20],s[20],a[50],p[12],dob[20],doj[20];
public:
			       void input()
{
cout<<"\n NAME OF DOCTOR:- ";
gets(n);
cout<<"\n ENTER DATE OF BIRTH (DATE/MONTH/YEAR):- ";
gets(dob);
cout<<"\n ENTER THE PHONE NUMBER:- ";
gets(p);
cout<<"\n ENTER THE ADDRESS:- ";
gets(a);
cout<<"\n ENTER THE QUALIFICATION:- ";
gets(q);
cout<<"\n ENTER THE SPECIALISATION:- ";
gets(s);
cout<<"\n ENTER THE DATE OF JOINING THE HOSPITAL(DATE/MONTH/YEAR) :- ";
gets(doj);
}
			       void output()
{
cout<<"\n\t\t\t DOCTOR DETAILS"<<"\n";
cout<<"\n NAME OF DOCTOR :-"<<n;
cout<<"\n DATE OF BIRTH:- "<<dob;
cout<<"\n PHONE NUMBER:- "<<p;
cout<<"\n ADDRESS:- "<<a;
cout<<"\n QUALIFICATION:- "<<q;
cout<<"\n SPECIALISATION:- "<<s;
cout<<"\n DATE OF JOINING THE HOSPITAL:- "<<doj;
}
char *retph()
{
return p;
}
char *retn()
{
return n;
}
};
/*
########################################################################
			FUNCTION FOR ADDING RECORDS OF DOCTOR
########################################################################
*/
			      void drwrite()
{
clrscr();
cout<<"\n\t\t\t\t DOCTOR ADD MENU:-";
doctor d;
ofstream fout("d.dat",ios::app|ios::binary);
d.input();
fout.write((char*)&d,sizeof(doctor));
fout.close();
cout<<"\n\n-------------------------------------------------------------------------------";
cout<<"\n press enter to return back";
getch();
}
/*
########################################################################
			FUNCTION FOR DISPLAYING RECORDS OF DOCTOR
########################################################################
*/
			      void drdisplay()
{
clrscr();
int jk=0;
doctor d;
ifstream fin("d.dat",ios::binary);
while(fin.read((char*)&d,sizeof(d)))
{
jk++;
d.output();
cout<<"\n\n-------------------------------------------------------------------------------";
}
fin.close();
if(jk==0)
{
cout<<"\n you may have just installed this software so";
cout<<"\n\n\t\t\t !!!! there are no records !!!! ";
cout<<"\n\t\t\t please enter some to have an output ";
}
cout<<"\n press enter to return back";
getch ();
}
/*
########################################################################
			FUNCTION FOR DELETING RECORDS OF DOCTOR
########################################################################
*/
			      void drdel()
{
clrscr();
char k;
doctor d;
int ml=0;
ifstream fin("d.dat",ios::app|ios::binary);
ofstream fout("t.dat",ios::app|ios::binary);
char m[40];
int flag=0;
gotoxy(30,5);cout<<"DOCTOR DELETE MENU";
gotoxy(30,6);cout<<"~~~~~~~~~~~~~~~~~~";
gotoxy(20,7);
cout<<"ENTER NAME OF THE DOCTOR WHOSE0 RECORD IS TO BE DELETED:- "<<"\n\n\t";
gets(m);
while(fin.read((char*)&d,sizeof(d)))
{
if(strcmpi(d.retn(),m)==0 )
{
cout<<"\n\t\t !!! RECORD FOUND !!!"<<"\n";delay(500);
flag=1;
d.output();
cout<<"\n\n\t\t WANT TO DELETE THIS RECORD "<<"\n";
cout<<"\n\t\t WARNING: THIS CANT BE UNDONE ";
cout<<"\n\n\t PLEASE PROVIDE INPUT (Y OR N) ";
cin>>k;
if(k=='y' || k=='Y')
{
cout<<"\n\n\t DELETING...";
delay(3000);
cout<<"\n\n\t DELETED :D";
cout<<"\n\n\t PRESS ENTER TO RETURN TO PREVOIUS MENU";
getch();
}
else
{
fout.write((char*)&d,sizeof(d));
ml++;
}
}
else
fout.write((char*)&d,sizeof(d));
}
fin.close();
fout.close();
if(flag==0)
{
gotoxy(30,15);cout<<"THERE IS NO DOCTOR WITH THIS NAME";
gotoxy(30,25);cout<<"PRESS ENTER TO RETURN TO MENU";
getch();
}
if (ml==1)
{
cout<<"\n\n\t\t !!!! NO CHANGES HAVE BEEN MADE !!!!";
getch ();
}
remove("d.dat");
rename("t.dat","d.dat");
}
/*
########################################################################
			FUNCTION FOR UPDATING RECORDS OF DOCTOR
########################################################################
*/
				void drupdate()
{
clrscr();
fstream f("d.dat",ios::in|ios::ate|ios::app|ios::binary);
ofstream fout("k.dat",ios::ate|ios::binary);
doctor d;
char s[40],flag=0;
gotoxy(30,5);cout<<"DOCTOR UPDATE MENU";
gotoxy(30,6);cout<<"~~~~~~~~~~~~~~~~~~";
gotoxy(17,10);cout<<"Enter The Name OfDoctor Whose Record Is To Be Updated:- ";
cout<<"\n\t";
gets(s);
f.seekp(0,ios::beg);
while(f.read((char*)&d,sizeof (d)))
{
if(strcmpi(d.retn(),s)==0)
{
flag=1;
gotoxy(34,13);cout<<"!!RECORD FOUND!!";
delay(500);
d.output();
cout<<"\n\n\t Press Enter To Add New Informaion";
getch();
cout<<"\n NEW INFOMATION";
cout<<"\n --------------"<<"\n";
d.input();
cout<<"\n\n\t\t Updating....";
delay(2000);
cout<<"\n\n\t\t UPDATED!!";
}
fout.write((char*)&d,sizeof(d));
}
if(flag==0)
{
gotoxy(43,13);cout<<"There Is No Doctor With This Name";
}
f.close();
fout.close();
remove("d.dat");
rename("k.dat","d.dat");
cout<<"\n\n\t\t press enter to return to menu";
getch();
}
/*
########################################################################
			FUNCTION FOR SEARCHING RECORDS OF DOCTOR
########################################################################
*/
			      void drsearch()
{
clrscr();
char p[40],phone[12];
doctor d;
ifstream fin;
int ch,flag=0;
do
{
clrscr();
gotoxy(27,5);cout<<"DOCTOR SEARCH MENU";
gotoxy(27,6);cout<<"~~~~~~~~~~~~~~~~~~";
gotoxy(23,8);cout<<"1. SEARCH BY NAME";
gotoxy(23,9);cout<<"2. SEARCH BY PHONE NUMBER";
gotoxy(23,10);cout<<"3. RETURN TO MAIN MENU";
cout<<"\n\n-------------------------------------------------------------------------------";
gotoxy(23,20);cout<<"* ENTER YOUR CHOICE:- ";
cin>>ch;
switch(ch)
{
case 1:clrscr();
	gotoxy(31,6);cout<<"ENTER THE NAME:- ";
	gets(p);
	gotoxy(33,10);cout<<"SEARCHING....";
	delay(2000);
	fin.open("d.dat",ios::binary);
	while(fin.read((char*)&d,sizeof (d)))
	{
	if(strcmpi(d.retn(),p)==0)
	{
	flag=1;
	gotoxy(49,10);cout<<"FOUND!!";
	gotoxy(29,16);cout<<"Press Enter To See Record";
	getch();
	d.output();
	getch();
	}
	}
	if(flag==0)
	{
	gotoxy(26,14);cout<<"There Is No Doctor With This Name";
	gotoxy(28,24);cout<<"press enter to return to menu";
	getch();
	}
	fin.close();
	break;
case 2:clrscr();
	gotoxy(31,6);cout<<"ENTER THE PHONE NUMBER:-";
	gets(phone);
	gotoxy(33,10);cout<<"SEARCHING....";
	delay(2000);
	fin.open("d.dat",ios::binary);
	while(fin.read((char*)&d,sizeof (d)))
	{
	if(strcmpi(d.retph(),phone)==0)
	{
	flag=1;
	gotoxy(49,10);cout<<"\n !!FOUND!!";
	gotoxy(29,16);cout<<"\n Press Enter To See Record"<<"\n\t\n";
	getch();
	d.output();
	getch();
	}
	}
	if(flag==0)
	{
	gotoxy(26,14);cout<<"There Is No Doctor With This Phone Number";
	gotoxy(28,24);cout<<"press enter to return to menu";
	getch();
	}
	fin.close();
	break;
}
}while(ch!=3);
}
/*
########################################################################
	   FUNCTION FOR CONTROLING ALL FUNCTIONS RELATED TO DOCTOR
########################################################################
*/
			      void drmenu()
{
int c;
doctor d;
do
{
clrscr();
gotoxy(27,5);cout<<"DOCTORS MENU";
gotoxy(27,6);cout<<"~~~~~~~~~~~~~";
gotoxy(23,8);cout<<"1. ADD DOCTOR INFOMATION";
gotoxy(23,9);cout<<"2. DISPLAY DOCTORS INFOMATION";
gotoxy(23,10);cout<<"3. DELETE DOCTOR INFOMATION";
gotoxy(23,11);cout<<"4. UPDATE DOCTOR INFOMATION ";
gotoxy(23,12);cout<<"5. SEARCH DOCTOR INFOMATION";
gotoxy(23,13);cout<<"6. EXIT";
cout<<"\n\n-------------------------------------------------------------------------------";
gotoxy(23,18);cout<<"* ENTER YOUR CHOICE:- ";
cin>>c;
switch(c)
{
case 1:drwrite();break;
case 2:drdisplay();break;
case 3:drdel();break;
case 4:drupdate();break;
case 5:drsearch();break;
case 6:break;
}
}while(c!=6);
}
/*
########################################################################
			FUNCTION FOR PASSWORD FOR THE PROGRAM
########################################################################
*/
			   char Password()
{
clrscr ();
int  i=0;
char pass[]="thisisit",h[15];

gotoxy(30,16);cout<<"Enter The Password  : ";
while(1)
{
char ch;
int x=random(40)+random(-10);
h[i]=getch();
if(h[i]!=8)
{
ch=h[i]+x;
if(h[i]==13 || h[i]==27)
break;
i++;
cout<<ch;
}
else
{
i--;
cout<<" ";
}
}
h [i]='\0';
if(strcmpi(pass,h)==0)
{
cout<<"\n\n\n-------------------------------------------------------------------------------";
gotoxy(28,84);cout<<"\n \n \t \t \t      CORRECT ! Entry Allowed!!";
delay(2000);
return 'X';
}
else
{
cout<<"\n\n\n-------------------------------------------------------------------------------";
gotoxy(32,92); cout<<"\n \n \t \t \t WRONG PASSWORD!! ENTRY REJECTED";
gotoxy(32,92); cout<<" \n \n \t \t \t   Press enter and try again ";
getch();
return 'Y';
}
}
/*
########################################################################
		  FUNCTION FOR THOUGHT OF EXECUTION OF PROGRAM
########################################################################
*/

void EXE()
{
clrscr();
cout<< "\n\t\t\tTHOUGHT OF THE EXECUTION";
cout<< "\n\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~\n\n\n";
randomize();
int i = random(7);
delay(80);

if(i==0)
conviction(1,5," You can do anything, but not everything.   -David Allen \0");
if(i==1)
conviction(1,5," Education is not filling of a pail, but the lightning of a fire.   -W.B.Yeats\0");
if(i==2)
conviction(1,5," The roots of EDUCATION are bitter but the fruit is sweet.   -Aristotle\0");
if(i==3)
conviction(1,5," The only soursce of knowledge is experience.   -Albert Einstein\0");
if(i==4)
conviction(1,5," The best thing about future is that it comes one day at a time.-Abraham Lincoin\0");
if(i==5)
conviction(1,5," Time is Money.   -Benjamin Franklin\0");
if(i==6)
conviction(1,5," \The difference between stupidity and genius is that genius has its limit.      -Albert Einstein\0");
delay(1500);
conviction(3,10," The Program will exit now  ");
delay(500);
for(int D=0;D<4;D++)
{cout<<". "; delay(444);}
delay(2000);
exit(1);
}
/*
########################################################################
	    CLASS FOR CONTROLLING ALL FUNCTIONS RELATED TO PATIENTS
########################################################################
*/
				   class patient
{
char n[20],g[20],a[20],i[50],r[42],d[50],pdob[20],pdov[20];
public:
void pinput()
{
cout<<"\n NAME OF PATIENT:- ";
gets(n);
cout<<"\n ENTER THE GENDER:- ";
gets(g);
cout<<"\n ENTER THE AGE:- ";
gets(a);
cout<<"\n ENTER DATE OF BIRTH (DATE/MONTH/YEAR):-  ";
gets(pdob);
cout<<"\n ENTER THE DISEASE:- ";
gets(d);
cout<<"\n ENTER THE DATE OF VISIT TO THE HOSPITAL(DATE/MONTH/YEAR):- ";
gets(pdov);
cout<<"\n ENTER THE PHONE NUMBER :- ";
gets(i);
cout<<"\n ENTER THE NAME OF DOCTOR IN-CHARGE:- ";
gets(r);
}
				void poutput()
{
cout<<"\n\t\t\t\t PATIENT DETAILS \n";
cout<<"\n NAME OF PATIENT:- "<<n;
cout<<"\n GENDER:- "<<g;
cout<<"\n AGE:- "<<a;
cout<<"\n DATE OF BIRTH (DATE/MONTH/YEAR):- "<<pdob;
cout<<"\n DISEASE:- "<<d;
cout<<"\n DATE OF VISIT TO THE HOSPITAL(DATE/MONTH/YEAR):- "<<pdov;
cout<<"\n PHONE NUMBER:- "<<i;
cout<<"\n DOCTOR IN-CHARGE:- "<<r;
}
char *retpho()
{
return i;
}
char *retna(){
return n;
}
};
/*
########################################################################
			FUNCTION FOR ADDING RECORDS OF PATIENT
########################################################################
*/
			     void pwrite()
{
clrscr();
cout<<"\n\n\t\t\t\t  PATIENT ADD MENU:-"<<"\n";
patient p;
ofstream fout("p.dat",ios::app|ios::binary);
p.pinput();
fout.write((char*)&p,sizeof(p));
cout<<"\n\n-------------------------------------------------------------------------------";
cout<<"\n press enter to return back";
fout.close();
getch ();
}
/*
########################################################################
			FUNCTION FOR DISPLAYING RECORDS OF PATIENT
########################################################################
*/
				  void pdisplay()
{
clrscr ();
int c=0;
cout<<"\n\n\t\t\t\t !!!! DISPLAY !!!!"<<"\n\n";
patient p;
ifstream fin("p.dat",ios::binary);
while(fin.read((char*)&p,sizeof(p)))
{
c++;
p.poutput();
cout<<"\n\n-------------------------------------------------------------------------------";
}
fin.close();
if (c==0)
{
cout<<"\n\t you may have installed new software"<<"\n\t so you should first add some data to have a display";
}
cout<<"\n Press Enter To Continue..";
getch ();
}
/*
########################################################################
			FUNCTION FOR DELETING RECORDS OF PATIENT
########################################################################
*/
				  void pdel()
{
clrscr();
char kx;
patient p;
ifstream fin("p.dat",ios::binary);
ofstream fout("s.dat",ios::app|ios::binary);
char m[40];
int flag=0,kshaz=0;
gotoxy(30,5);cout<<"PATIENT DELETE MENU";
gotoxy(30,6);cout<<"~~~~~~~~~~~~~~~~~~";
gotoxy(20,7);cout<<"ENTER NAME OF PATIENT WHOSE RECORD IS TO BE DELETED "<<"\n\n\t\t";
gets(m);
while(fin.read((char*)&p,sizeof(p)))
{
if(strcmpi(p.retna(),m)==0 )
{
flag=1;
cout<<"\n\t\t\t !!! RECORD FOUND !!! "<<"\n";delay(500);
p.poutput();
cout<<"\n\n\t\t WANT TO DELETE THIS RECORD ";
cout<<"\n\n\t\t WARNING : ONCE DELETED CANNOT BE RETRIEVED !!!";
cout<<"\n\n PLEASE PROVIDE INPUT (Y OR N)";
cout<<"\n\n\t\t\t\t";
cin>>kx;
if(kx=='y' || kx=='Y')
{
cout<<"\n\n\t DELETING . .";
delay(2000);
cout<<"\n\n\t\t !!! DELETED  !!!";
cout<<"\n\n\t PRESS ENTER TO RETURN TO PREVIOUS MENU ";
getch ();
}
else
{
fout.write((char*)&p,sizeof(p));
kshaz++;
}
}
else
{
fout.write((char*)&p,sizeof(p));
}
}
fin.close();
fout.close();
if(flag==0)
{
gotoxy(30,15);cout<<"THERE IS NO DOCTOR WITH THIS NAME";
gotoxy(30,25);cout<<"PRESS ENTER TO RETURN TO MENU";
getch();
}
if(kshaz==1)
{
cout<<"\n\t\t\t\t !!! NO CHANGES HAVE BEEN MADE";
getch ();
}
remove("p.dat");
rename("s.dat","p.dat");
}
/*
########################################################################
			FUNCTION FOR UPDATING RECORDS OF PATIENT
########################################################################
*/
				void pupdate()
{
clrscr();
fstream f("p.dat",ios::in|ios::ate|ios::app|ios::binary);
ofstream fout("t.dat",ios::binary);
patient p;
char s[40],flag=0;
gotoxy(30,5);cout<<"PATIENT UPDATE MENU";
gotoxy(30,6);cout<<"~~~~~~~~~~~~~~~~~~";
gotoxy(17,10);cout<<"Enter The Name Of Patient Whose Record Is To Be Updated ";
cout<<"\n\t";
gets(s);
f.seekp(0,ios::beg);
while(f.read((char*)&p,sizeof (p)))
{
if(strcmpi(p.retna(),s)==0)
{
flag=1;
cout<<"\n RECORD FOUND!!";
delay(500);
p.poutput();
cout<<"\n\n\t Press Enter To Add New Informaion";
getch();
cout<<"\n\t\t\t\t NEW INFOMATION";
cout<<"\n\t\t\t\t --------------";
cout<<"\n";
p.pinput();
cout<<"\n\t\t Updating....";
delay(2000);
cout<<"\n\n\t\t !!UPDATED!!";
cout<<"\n\n press enter to return to menu";
getch();
}
fout.write((char*)&p,sizeof(p));
}
if(flag==0)
{
cout<<"\n\n\t\t\t\t There Is No Patient With This Name";
gotoxy(25,17);cout<<"press enter to return to menu";
getch();
}
f.close();
fout.close();
remove("p.dat");
rename("t.dat","p.dat");
}
/*
########################################################################
			FUNCTION FOR SEARCHING RECORDS OF PATIENT
########################################################################
*/
			    void psearch()
{
clrscr();
char w[40],phone[12];
patient p;
ifstream fin;
int ch,flag=0;
do
{
clrscr();
gotoxy(27,5);cout<<"PATIENT SEARCH MENU";
gotoxy(27,6);cout<<"~~~~~~~~~~~~~~~~~~";
gotoxy(23,8);cout<<"1. SEARCH BY NAME";
gotoxy(23,9);cout<<"2. SEARCH BY PHONE NUMBER";
gotoxy(23,10);cout<<"3. RETURN TO MAIN MENU";
cout<<"\n\n-------------------------------------------------------------------------------";
gotoxy(23,20);cout<<"* ENTER YOUR CHOICE:- ";
cin>>ch;
switch(ch)
{
case 1:clrscr();
	gotoxy(31,6);cout<<"ENTER THE NAME";
	gets(w);
	gotoxy(33,10);cout<<"SEARCHING";
	for(int kl=0;kl<=7;kl++)
	{
	cout<<" . " ;
	delay(100);
	}
	fin.open("p.dat",ios::binary);
	while(fin.read((char*)&p,sizeof (p)))
	{
	if(strcmpi(p.retna(),w)==0)
	{
	flag=1;
	gotoxy(49,10);cout<<" !!FOUND!!";
	gotoxy(29,16);cout<<"Press Enter To See Record";
	getch();
	p.poutput();
	getch();
	}
	}
	if(flag==0)
	{
	gotoxy(26,14);cout<<"There Is No Doctor With This Name";
	gotoxy(28,24);cout<<"press enter to return to menu";
	getch();
	}
	fin.close();
	break;
case 2:clrscr();
	gotoxy(31,6);cout<<"ENTER THE PHONE NUMBER";
	cin>>phone;
	gotoxy(33,10);cout<<"SEARCHING....";
	delay(2000);
	fin.open("p.dat",ios::binary);
	while(fin.read((char*)&p,sizeof (p)))
	{
	if(strcmpi(p.retpho(),phone)==0)
	{
	flag=1;
	gotoxy(49,10);cout<<"FOUND!!";
	gotoxy(29,16);cout<<"Press Enter To See Record";
	getch();
	p.poutput();
	getch();
	}
	}
	if(flag==0)
	{
	gotoxy(26,14);cout<<"There Is No Doctor With This Phone Number";
	gotoxy(28,24);cout<<"press enter to return to menu";
	getch();
	}
	fin.close();
	break;
}
}while(ch!=3);
}
/*
########################################################################
	   FUNCTION FOR CONTROLING ALL FUNCTIONS RELATED TO PATIENTS
########################################################################
*/
				void pmenu()
{
int c;
patient p;
do
{
clrscr();
gotoxy(27,5);cout<<"PATIENTS MENU";
gotoxy(27,6);cout<<"~~~~~~~~~~~~~";
gotoxy(23,8);cout<<"1. ADD PATIENT INFOMATION";
gotoxy(23,9);cout<<"2. DISPLAY PATIENT INFOMATION";
gotoxy(23,10);cout<<"3. DELETE PATIENT INFOMATION";
gotoxy(23,11);cout<<"4. UPDATE PATIENT INFOMATION ";
gotoxy(23,12);cout<<"5. SEARCH PATIENT INFOMATION";
gotoxy(23,13);cout<<"6. EXIT";
cout<<"\n\n-------------------------------------------------------------------------------";
gotoxy(23,18);cout<<"* ENTER YOUR CHOICE:- ";
cin>>c;
switch(c)
{
case 1:pwrite();break;
case 2:pdisplay();break;
case 3:pdel();break;
case 4:pupdate();break;
case 5:psearch();break;
case 6:break;
}
}while(c!=6);

}
/*
########################################################################
	   FUNCTION FOR GIVING THE INTRODUCTION OF HOSPITAL
########################################################################
*/
				void intro()
{
clrscr();
cout<<"\n-------------------------------------------------------------------------------";
gotoxy(16,5);cout<<"The SANDHU LIFECARE HOSPITAL was setup in year 1996"<<endl;delay(1500);
gotoxy(10,7);cout<<"by Mrs. Santosh Devi in association with the Red Cross Society."<<endl;delay(800);
gotoxy(13,9);cout<<"There are various branches in different parts of the country"<<endl;delay(800);
gotoxy(1,11);cout<<"the very first branch was setup at Janak Puri, Delhi by the founder Chairperson."<<endl;delay(800);
gotoxy(6,13);cout<<"All branches are approved by the Home Ministry of the respective"<<endl;delay(800);
gotoxy(3,15);cout<<"state and the head branch is recognised by the Home Ministry, Central Govt."<<endl;delay(800);
gotoxy(15,17);cout<<"The hospital provides internship of 4 years also."<<endl;delay(800);
cout<<"\n-------------------------------------------------------------------------------";
cout<<" * press enter to return back";
getch();
}
/*
########################################################################
		   FUNCTION FOR THE MENU OF THE HOSPITAL
########################################################################
*/
			  void menu()
{
char ch;
do
{
delay(1000);
clrscr();
int ks=0;
cout<<" \n \n \n \n";
gotoxy(20,5);cout<<"           SANDHU LIFECARE HOSPITAL \0";
gotoxy(20,6);cout<<"          ~~~~~~~~~~~~~~~~~~~~~~~~~~ \0";
gotoxy(20,7);cout<<"                 WELCOMES YOU \0";
gotoxy(20,8);cout<<"                ~~~~~~~~~~~~~~ \0";
gotoxy(31,9);cout<<"1. ABOUT THE HOSPITAL \0";
gotoxy(31,10);cout<<"2. ABOUT THE PATIENTS";
gotoxy(31,11);cout<<"3. ABOUT THE DOCTORS \0";
gotoxy(31,12);cout<<"4. EXIT \0";
cout<<"\n\n-------------------------------------------------------------------------------";
gotoxy(31,16);cout<<"* ENTER YOUR CHOICE:- \0";
ch=getche();
switch(ch)
{
case '1':intro();break;
case '2':pmenu();break;
case '3':drmenu();break;
case '4':EXE();break;
}
}while(ch!=4);
}
/*
########################################################################
		       MAIN OF THE PROGRAM
########################################################################
*/
			void main ()
{
clrscr ();
textbackground(BLUE);
textcolor(YELLOW);
intr();
int i;
char k;

for(i=1;i<=3;i++)
{
k=Password();
if(k=='X')
{
menu();
break;
}

if(i==3)
{
cout<<"\n ";
cout<<"\n                        you are not an authorised user ";
cout<<"\n \n                         the program will now exit";
getch ();
EXE ();
}
}
}
/*
########################################################################
				THE END
########################################################################
*/
