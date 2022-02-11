#include<stdio.h>
#include<conio.h>
#include<iostream>
#include<windows.h>
#include"../../headerfiles/conio2.h"
#include"../../headerfiles/menu.h"
#include"../../headerfiles/form.h"
#include<fstream>
using namespace std;
/*-------------------------------------------login Page -------------------------------------------------*/
int loginpage()
{
    int a,b;
    a=20;b=15;
    gotoxy(a+7,b-5);
    cout<<"LOGIN PAGE\n";
    gotoxy(a+5,b-4);
    cout<<"________________";
    string mydata1,mydata2;
    string elements[]={"Username:","Password:"};
    formmaker(a,b,2,elements);//call formmaker
    mydata1=getdata(a,b,0);// get userinput
    mydata2=getdata(a,b,1);
    int f;
    int options=1;
    string m[]={"SUBMIT"};// options to show in menu
    f=makemenu(options,m,a-1,b+4);//sendings options to show in menu
    switch(f){

            case 1:
            break;
            case 2:
            loginpage();
            break;
            break;
            case 3:
            exit(1);
            break;
            }
    ifstream readfile;
    readfile.open("UserDetails.csv");
    string content,content2,content3;
    while(readfile.good())
            {
                getline(readfile,content,',');//get coloumn 1st
                getline(readfile,content2,',');//get coloumn 2nd
                getline(readfile,content3);
                if(content.compare(mydata1)==0&&content2.compare(mydata2)==0)// string to be searched
                    {
                        return 5;//dashboard function with content 3 as arguments
                        cout<<"match"<<content2;// if match then print its next coloumn
                        break;// if match the exit to the loop
                    }
            }
            readfile.close();
            }
