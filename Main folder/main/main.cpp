#include<stdio.h>
#include<conio.h>
#include<iostream>
#include<windows.h>
#include"../../headerfiles/conio2.h"
#include"../../headerfiles/menu.h"
#include"../../headerfiles/login.h"
#include"../../headerfiles/form.h"
#include<fstream>
#include<ctime>
using namespace std;
int registerpage();
void dashboard();
void create_bug();
void Bug_report();
void bug_status();
void loading();
void rect();
void welocomeDetails();
void addbug(string filename);
int openbugsdetails(string filename);
void tokenize(string s, string del = " ");
HANDLE wHnd; // Handle to write to the console.
HANDLE rHnd;
void MoveWindowSize(int posx, int posy, int x, int y)
{
    RECT rectClient, rectWindow;
    HWND hWnd = GetConsoleWindow();
    GetClientRect(hWnd, &rectClient);
    GetWindowRect(hWnd, &rectWindow);
    MoveWindow(hWnd, posx, posy, rectClient.right - rectClient.left, rectClient.bottom - rectClient.top, TRUE);
    HWND console = GetConsoleWindow();
    RECT ConsoleRect;
    GetWindowRect(console, &ConsoleRect);
    MoveWindow(console, ConsoleRect.left, ConsoleRect.top, x, y, TRUE);
    HWND consoleWindow = GetConsoleWindow();
    SetWindowLong(consoleWindow, GWL_STYLE, GetWindowLong(consoleWindow, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);
}
int main(int argc, char* argv[])
{   textbackground(15); clrscr();
    int width=1400;
    int hight=1000;
    MoveWindowSize(-10,-5,width,hight);
    int auth_user;
    wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
    rHnd = GetStdHandle(STD_INPUT_HANDLE);

    while(1){

            SetConsoleTitle("BUG TRACKER--DEVELOPED BY RAJAT,ANIK,EELINA,TRIYASHA,SOUMYABRATA");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_BLUE| BACKGROUND_GREEN|BACKGROUND_RED|BACKGROUND_INTENSITY);
            system("CLS");
            int f;
            rect();
            welocomeDetails();
            int options=3;
            string m[]={"Login","Register","Exit"};                    // options to show in menu
            f=makemenu(options,m,32,18);                               // sendings options to show in menu
            switch(f){                                                 // defined work of each options

                    case 1:
                        system("CLS");
                        rect();
                        auth_user=loginpage();
                        if(auth_user==5){                             // if user is autharised then send him to dashboard
                        loading();
                        dashboard();}
                        break;
                    case 2:
                        system("CLS");
                        registerpage();
                        break;
                    case 3:
                        exit(1);
                        break;

                    }
            }
    return 0;
    }
/*----------------------------Open Register Page---------------------------------*/
int registerpage()
 {
    rect();
    int a,b;
    a=20;b=15;
    gotoxy(a+10,5);
    cout<<"REGISTER PAGE";
    gotoxy(a+8,6);
    cout<<"_________________";
    gotoxy(30,23);
    textbackground(12);
    cout<<"        ";
    gotoxy(30,24);
    textcolor(0);
    cout<<" SUBMIT ";
    textcolor(9);
    textbackground(15);
    string mydata[3];
    string elements[]={"UserName:","CreatePassword:","Organisation:"};
    formmaker(a,b,3,elements);                  //call formmaker
    mydata[0]=getdata(a,b,0);             // get userinput
    mydata[1]=getdata(a,b,1);
    mydata[2]=getdata(a,b,2);
    gotoxy(25,23);
          if(getch()==27)
                    {
                    return 0;
                    }
    ofstream myfile;
    myfile.open("UserDetails.csv",ios::ate | ios::app);
    myfile<<mydata[0]<<","<<mydata[1]<<","<<mydata[2]<<"\n";
    myfile.close();
    return 0;
    }
    /*-----------------------------------close--------------------------------*/
/*--------------------------------dashboard opening----------------------------------*/
void dashboard(){
  wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
  rHnd = GetStdHandle(STD_INPUT_HANDLE);
  while(1){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_BLUE| BACKGROUND_GREEN|BACKGROUND_RED|BACKGROUND_INTENSITY);
        system("CLS");
        rect();
        gotoxy(18,8);
        cout<<"[............WELCOME............]";
        int f;
        int options=4;
        string m[]={"Enter_New_BUG","Change_Bug_Status","Bug_Report","Exit"};        // options to show in menu
        f=makemenu(options,m,25);                                                    //sendings options to show in menu
        switch(f){                                                                   //defined work of each options
                case 1:
                    create_bug();
                    break;
                case 2:
                    bug_status();
                    break;
                case 3:
                    Bug_report();
                    break;
                case 4:
                    exit(1);
                    break;
                }
            }
    }


/*-------------------------------------------Create New bug-------------------------------------*/
void create_bug()
{
    system("CLS");
    rect();
    string mydata[4];
    int a,b;
    a=20;b=15;
    gotoxy(a+2,b-5);
    time_t now=time(0);
    tm* ltm=localtime(&now);
    cout<<"[-----Add New Bugs-----]";
    string elements[]={"Bug_Title","Bug_Assigned_To"};
    formmaker(a,b,2,elements);                                     //call form maker
    mydata[0]=getdata(a,b,0);                                      // get user input
    mydata[1]=getdata(a,b,1);
    mydata[2]="Progressed";
    int options=1;
    string m[]={" ADD Details "};                                  // options to show in menu
    int f=makemenu(options,m,25,21);                               //sending options to show in menu
    switch(f){                                                     //defined work of each options
            case 1:
                addbug(mydata[0]);
                break;
            }
    //bug saving
   ofstream mybug;
   mybug.open("bug_details.csv",ios::ate | ios::app);
   mybug<<mydata[0]<<","<<ltm->tm_mday<<"-"<<1+ltm->tm_mon<<"-"<<1900+ltm->tm_year<<","<<mydata[1]<<","<<mydata[2]<<"\n";
   mybug.close();
}
void addbug( string filename)
    {
    system("CLS");
    ofstream myfile;
    string content,data,fname;
    int i;
    rect();
    gotoxy(25,4);
    cout<<"ADD details to bug"<<endl;
    fname=filename+".txt";
    myfile.open(fname,ios::ate | ios::app);
    myfile<<filename<<endl;
    while(getch()!=27)
                {
                    gotoxy(10,8+i);
                    getline(cin,data);
                    myfile<<data<<endl;
                    i++;
                }
    gotoxy(14,28);cout<<"Thanks! Your Data is saving........";
    loading();
    myfile.close();
    }
/*-------------------------------------BUG REPORT--------------------------------------*/

void Bug_report()
  {
    system("CLS");
    loading();
    system("CLS");
    while(1){
            rect();
            string myname[4];
            int i=0,c=0,x;
            ifstream myfilerr;
            myfilerr.open("Bug_details.csv");
            gotoxy(26,4);
            textbackground(0);
            textcolor(14);
            cout<<"            ";
            gotoxy(26,5);
            cout<<" Bug Report ";
            gotoxy(26,6);
            cout<<"            ";
            textbackground(15);
            textcolor(0);
            while(myfilerr.good())
                    {
                     gotoxy(6,9+i);
                     getline(myfilerr,myname[0],',');
                     getline(myfilerr,myname[1],',');
                     getline(myfilerr,myname[2],',');
                     getline(myfilerr,myname[3]);
                     if(myname[0].size()!=0)
                        {
                            for(c=0;c<4;c++)
                                {
                                 cout<<myname[c];
                                 x=15-myname[c].size();
                                 while(x!=0)               // to print space equal to fixed space - string size
                                      {
                                        cout<<" ";
                                        x--;
                                       }
                                 }
                          }
                        i=i+2;
                      }
            int a=6,
            b=9+i;
            string mydata1;
            string elements[]={"Open Details"};
            formmaker(a,b,1,elements);                     //call form maker
               // get userinput


            myfilerr.close();
            if(getch()==27)
                break;
            else{
                mydata1=getdata(a,b,0);
                openbugsdetails(mydata1);
                }
            }
  }
int openbugsdetails(string filename)
    {
     textbackground(15);
     int i=0;
     while(1)
        {
        system("CLS");
        rect();
        ifstream readfile1;
        string content;
        string fname= filename+".txt";
        readfile1.open(fname);
        if(!readfile1)
            {
            gotoxy(15,10);cout<<"--Oops! No Details Found|Type the correct Bug Name---";
            gotoxy(15,10);cout<<"Press any key to go back";
            getch();
            system("CLS");
            return 0;
            }
        else
            {
            while(readfile1.eof()==0)
                {
                getline(readfile1,content);
                gotoxy(10,6+i);
                textcolor(BLACK);
                cout<<content<<"\n";i++;
                }
            if(getch()!=80)
            system("CLS");
            return 0;
            }
        }
    }
/*-------------------------------------CHANGE STATUS-----------------------------------------------*/
void bug_status()
{
    system("CLS");
    rect();
    string mydata[2];
    int a,b;
    a=20;b=15;
    gotoxy(a+2,b-5);
    cout<<"[----Change Bug Status-----]";
    string elements[]={"Bug Title","Bug Status"};
    formmaker(a,b,2,elements);                  //call formmaker
    mydata[0]=getdata(a,b,0);             // get userinput
    mydata[1]=getdata(a,b,1);
    //-------------------------bug searching

    ifstream readfile1;
    ofstream writefile;
    writefile.open("temp.csv",ios::ate);                  //creating temp file
    readfile1.open("Bug_details.csv");
    string content[4];

    while(readfile1.eof()==0)
        { getline(readfile1,content[0],',');          //get coloumn 1st
          getline(readfile1,content[1],',');
          getline(readfile1,content[2],',');
          getline(readfile1,content[3]);

           if(content[0].compare(mydata[0])==0)                         // string to be deleted are  searching
                {
                    content[3]=mydata[1];
                    gotoxy(14,28);textbackground(WHITE);cout<<"----Your Data is Updating----";
                }
            else
                {
                gotoxy(14,25);textbackground(WHITE);
                cout<<"No Data found";
                }

            if(content[0].size()!=0)                                         // condition to check whether the 1st column is empty or not, if empty then do not copy the next coloumn to temp file
                {
                    writefile<<content[0]<<","<<content[1]<<","<<content[2]<<","<<content[3]<<endl;}                   //copying the content of 1st file to temp file except that which is  to be deleted
                }
            readfile1.close();
            writefile.close();                                                                                          // close both file after that remove and rename function works
            remove("Bug_details.csv");                                                                                  // delete main file
            rename("temp.csv","bug_details.csv");                                                                       //  rename temp file as main file
            loading();
    }
void rect()
    {
    int j,n=68,y=38;
    for(int i=1;i<=n;i++)
        {
        for(j=1;j<=y;j++)
            {
             if(i==1||i==n||j==1||j==y)
                {
                 gotoxy(1+i,1+j);
                 textbackground(12);
                 printf("  ");
                }
             else{
                textbackground(15);
                printf("  ");
                }
            }
        printf("\n");
         }
    textbackground(15);
    }
void loading()
{   int l=0;
    gotoxy(18,30);
    cout<<"LOADING--";
    while(l!=15)
        {
        textcolor(1);textbackground(12);
        cout<<" ";
        l++;
        Sleep(50);
        }
    textcolor(1);textbackground(15);
}

void welocomeDetails()
{
    time_t now=time(0);
    tm* ltm=localtime(&now);
    gotoxy(55,5);
    textcolor(BLUE);
    cout<<"Date:"<<ltm->tm_mday<<"-"<<1+ltm->tm_mon<<"-"<<1900+ltm->tm_year;
    gotoxy(55,7);
    cout << "Time:"<< ltm->tm_hour << ":";
    cout << ltm->tm_min << ":";
    cout << ltm->tm_sec;
    gotoxy(24,5);
    cout<<"-----Welcome-----";
    gotoxy(20,7);
    cout<<"Narula Institute Of Technology";
}
