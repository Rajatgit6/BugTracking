#include<iostream>
#include<conio.h>
#include"../../headerfiles/conio2.h"
using namespace std;

void formmaker(int a,int b,int n,string elements[]);
string getdata(int a,int b,int i);
void formmaker(int a,int b,int n,string elements[])
{
    //arguments to change the position and number of options----a ,b,n + arguments of strings from main file
    int i;
    gotoxy(a,b);//goto initial postion

    for(i=0;i<n;i++)                    // print titles
        {
         gotoxy(a-1,b+2*i);
         cout<<elements[i];
        }
    for(i=0;i<n;i++)                  //print boxex
        {
         gotoxy(a+15,b+i*2);
         textbackground(0);textcolor(10);
         cout<<"                  ";
        }
}

string getdata(int a,int b,int i)                  //get usre input in the boxes
    {
     string formdata;
     gotoxy(a+15,b+i*2);
     getline(cin,formdata);
     textbackground(0);textcolor(10);
     return formdata;
    }
