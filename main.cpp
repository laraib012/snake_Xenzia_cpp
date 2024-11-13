






#include <windows.h>
#include <conio.h>
#include <math.h>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include<string>
using namespace std;

int gotoRowCol(int rpos, int cpos)
{
    int xpos = cpos, ypos = rpos;
    COORD scrn;
    HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
    scrn.X = cpos;
    scrn.Y = rpos;
    int r = SetConsoleCursorPosition(hOuput, scrn);
    return r;
}
void sleep(int m)
{
    for (int j = 0; j < m * 21000; j++)
    {
    }
}

void init_array_1(char A[])
{
    for (int i = 0; i < 3; i++)
    {
        A[i] = '*';
    }
    for (int i = 3; i < 1000; i++)
    {
        A[i] = ' ';
    }
}

void snake_move(int pos_row[], int pos_col[], int num, char ch1, int &r, int &c)
{
    for (int i = 1; i < num; i++)
    {
        pos_row[i - 1] = pos_row[i];
        pos_col[i - 1] = pos_col[i];
    }
    if (ch1 == 'd' || ch1 == 'D')
    {
        r++;
        pos_row[num - 1] = r;
        pos_col[num - 1] = c;
    }
    if (ch1 == 'u' || ch1 == 'U')
    {
        r--;
        pos_row[num - 1] = r;
        pos_col[num - 1] = c;
    }
    if (ch1 == 'l' || ch1 == 'L')
    {
        c--;
        pos_row[num - 1] = r;
        pos_col[num - 1] = c;
    }
    if (ch1 == 'r' || ch1 == 'R')
    {
        c++;
        pos_row[num - 1] = r;
        pos_col[num - 1] = c;
    }
}

void print_snake(int pos_row[], int pos_col[], int num)
{
    char ch = '*';
    for (int i = num-1; i >= 0; i--)
    {
        if(i==num-1){ch='*';}
        else{ch='-';}
        gotoRowCol(pos_row[i], pos_col[i]);
        sleep(1000);
        cout << ch;
    }
}

bool dead_on_strike(int pos_row[], int pos_col[], int num){
    //if((pos_row[num - 1] == 40) || (pos_col[num - 1] == 130) || (pos_row[num - 1] == 0) || (pos_col[num - 1]) == 0){
      //     return true;
    //}
    if((pos_row[num - 1] == 40) || (pos_col[num - 1] == 130) || (pos_col[num - 1] == 0)){
          return true;
    }
    if(pos_row[num-1]==1){
        return true;
    }
    for (int i = num-2; i > 0; i--)
    {
        if((pos_row[num - 1] == pos_row[i]) && (pos_col[num - 1] == pos_col[i])){
            return true;
        }
    return false;
}}
void upper_line(char ch )
{
    for(int i=1;i<=130;i++)
    {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
           // Setting the text color to blue
           SetConsoleTextAttribute(hConsole, 1);
           gotoRowCol(0,i);
        cout<<ch<<endl;
           SetConsoleTextAttribute(hConsole, 7);
    }
}
void left_line(char ch )
{
    for(int i=0;i<=40;i++)
    {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
           // Setting the text color to blue
           SetConsoleTextAttribute(hConsole, 1);
           gotoRowCol(i,0);
        cout<<ch<<endl;
           SetConsoleTextAttribute(hConsole, 7);
    }
}
void right_line(char ch )
{
    for(int i=0;i<=40;i++)
    {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
           // Setting the text color to blue
           SetConsoleTextAttribute(hConsole, 1);
           gotoRowCol(i,130);
        cout<<ch<<endl;
           SetConsoleTextAttribute(hConsole, 7);
    }
}
void lower_line(char ch )
{
    for(int i=0;i<=130;i++)
    {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
           // Setting the text color to blue
           SetConsoleTextAttribute(hConsole, 1);
           gotoRowCol(40,i);
        cout<<ch<<endl;
           SetConsoleTextAttribute(hConsole, 7);
    }
}
void box(char ch)
{
    upper_line(ch);
    left_line(ch);
    lower_line(ch);
    right_line(ch);
}
void food(int & r1,int & c1)
{
      r1=(rand() % 40)+1;
      c1=(rand() % 130)+1;
      gotoRowCol(r1,c1);
      HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    // Setting the text color to blue
      SetConsoleTextAttribute(hConsole, 2);
      cout<<'#';
      SetConsoleTextAttribute(hConsole, 2);
}
void watch(int & SS,int & MM,int & HH)
{
  SS++;
  sleep(1000);
  if(SS>59)
  {
   MM++;
   SS=0;
  }
  if(MM>59)
  {
    HH++;
    MM=0;
  }
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
      SetConsoleTextAttribute(hConsole, 2);
  gotoRowCol(42,150);
  cout<<"\n\t\t stopwatch";
    SetConsoleTextAttribute(hConsole, 7);
  gotoRowCol(43,150);
  cout<<"\n\t\t HH : MM : SS";
  gotoRowCol(44,150);
    SetConsoleTextAttribute(hConsole, 4);
  cout<<"\n\t\t "<<HH<<" : "<<MM<<" : "<<SS;
  gotoRowCol(45,150);
  SetConsoleTextAttribute(hConsole, 7);

 }

 void rules()

{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    // Setting the text color to blue
      SetConsoleTextAttribute(hConsole, 4);
    gotoRowCol(5,140);
    cout<<"WELL COME TO THE SNAKE GAME "<<endl;

    // Setting the text color to blue
      SetConsoleTextAttribute(hConsole, 7);
    gotoRowCol(20-10,133);
    cout<<"RIGHT--------->R OR r "<<endl;
    gotoRowCol(20-9,133);
   cout<<"LEFT--------->L OR l "<<endl;
    gotoRowCol(20-8,133);
   cout<<"UP--------->U OR u "<<endl;
    gotoRowCol(20-7,133);
   cout<<"DOWN--------->D OR d "<<endl;

}

big_food(int & r1,int & c1)
{
     r1=(rand() % 40)+1;
      c1=(rand() % 130)+1;
      gotoRowCol(r1,c1);
      HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    // Setting the text color to blue
      SetConsoleTextAttribute(hConsole, 6);
      cout<<'O';
      SetConsoleTextAttribute(hConsole, 2);

}
void PlaySound(string filename){
   system( (filename).c_str() );
}


int main()
{
    int pos_row[1000];
    int pos_col[1000];
    int m = 20, r = 30, c = 29,num = 3,food_counter=0,br1=0,bc1=0;
    char ch1, prev_ch;
    int r1=20,c1=20;
    ch1 = 'r';
    char ch=219;
    box(ch);
    food(r1,c1);
    food_counter++;
    int SS=0,MM=0,HH=0;
    int counter=0;

    watch(SS, MM,HH);

    gotoRowCol(20,145);
    cout<<"Your score is : "<<counter;
    rules();
    while (true)
    {
        snake_move(pos_row, pos_col, num, ch1, r, c);
        watch(SS,MM,HH);
        if(br1==pos_row[num-1]&&bc1==pos_col[num-1])
                {
                    counter=counter+5;
                    gotoRowCol(20,145);
            cout<<"Your score is : "<<counter;

                }
        if(r1==pos_row[num-1]&&c1==pos_col[num-1])
        {
            PlaySound("munching-food.mp3");
            if(food_counter%2==0)
            {
                big_food(r1,c1);
                 br1=r1,bc1=c1;


            }



            num++;
            food(r1,c1);
            counter++;
            food_counter++;
            gotoRowCol(20,145);
            cout<<"Your score is : "<<counter;
        }
        print_snake(pos_row, pos_col, num);
        gotoRowCol(pos_row[0], pos_col[0]);
        cout<<" ";
        if(dead_on_strike(pos_row, pos_col, num)){
            break;
        }
        if (kbhit())
        {
            prev_ch = ch1;
            ch1 = getch();
            if(prev_ch=='r' && ch1=='l'){ch1='r';}
            if(prev_ch=='l' && ch1=='r'){ch1='l';}
            if(prev_ch=='u' && ch1=='d'){ch1='u';}
            if(prev_ch=='d' && ch1=='u'){ch1='d';}
        }
    }
}
