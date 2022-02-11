#include<iostream>
#include<conio.h>
#include<stdio.h>
#include"../../headerfiles/conio2.h"
#include<stdlib.h>
#include<windows.h>
using namespace std;

void menu(int ch,string m[],int options,int a,int b)
    {
        int i=0;
        while(i<options)
            {
             gotoxy(a,b+i);              //replace a by a+i*strlength and b+i by b  for horixontal menu
             if(ch==i+1)
                {
                textcolor(LIGHTGREEN);
                textbackground(BLACK);
                cout<<m[i];// if next choic then highlight
                textcolor(LIGHTBLUE);
                textbackground(WHITE);
                }
        else
            {
            cout<<m[i];               //print without color
            }
    i++;
            }
    }
int makemenu(int options, string m[],int a=40,int b=15)                      //replace by other name to used in other file
{
    int l=0;
    int i=1;
    menu(1,m,options,a,b);                   //calling menu functions
    int ch;
    bool running=TRUE;
    while(running)
      {
        ch=getch();
        switch(ch)
          {
            case 72:                // relace by 75 for horizontal menu
                if( i!=1)
                  {
                   i--;
                    menu(i,m,options,a,b);
                    break;
            case 80:                // replace by 77 for horizontal menu
            if(i!=options)
                {
                    i++;
                    menu(i,m,options,a,b);
                    break;

            case 13:
                return i;                  //replace bv return i t return to the main function
                running=FALSE;
                break;
            case 27:
                exit(1);
            default:
                break;
    }
}
_getch();
}
    }
}






