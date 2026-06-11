#include<iostream>
#include <cstdlib>
#include <ctime> 
using namespace std;
int main(){
    int planszabomb[4][4]={{0,0,0,0},
                       {0,0,0,0},
                       {0,0,0,0},
                       {0,0,0,0}};
                       int planszaodkryta[4][4]={{0,0,0,0},
                       {0,0,0,0},
                       {0,0,0,0},
                       {0,0,0,0}};
                       int planszazakryta[4][4]={{0,0,0,0},
                       {0,0,0,0},
                       {0,0,0,0},
                       {0,0,0,0}};
    int wybor;
    int wybor2;
cout<<"saper 4x4"<<endl;
cout<<"1. Nowa gra"<<endl;
cout<<"2. tutorial"<<endl;
cout<<"inne. Wyjscie"<<endl;
cin>>wybor;
if (wybor==1)
{
    //losowanie bomb
    srand(time(0));
    for (int i = 0; i < 4; i++)
    {
        int x=rand()%4;
        int y=rand()%4;
        if (planszabomb[x][y]==0)
        {
            planszabomb[x][y]=1;
        }
        else
        {
            i--;
        }
        
    }
    for(int i=0;i<4;i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if(planszabomb[i][j]==1)
            {
                planszaodkryta[i][j]=9;
            }
          else if (planszabomb[i][j]==0)
            {
                int licznik=0;
                if (i-1>=0 && j-1>=0 && planszabomb[i-1][j-1]==1)
                {
                    licznik++;
                }
                if (i-1>=0 && planszabomb[i-1][j]==1)
                {
                    licznik++;
                }
                if (i-1>=0 && j+1<4 && planszabomb[i-1][j+1]==1)
                {
                    licznik++;
                }
                if (j-1>=0 && planszabomb[i][j-1]==1)
                {
                    licznik++;
                }
                if (j+1<4 && planszabomb[i][j+1]==1)
                {
                    licznik++;
                }
                if (i+1<4 && j-1>=0 && planszabomb[i+1][j-1]==1)
                {
                    licznik++;
                }
                if (i+1<4 && planszabomb[i+1][j]==1)
                {
                    licznik++;
                }
                if (i+1<4 && j+1<4 && planszabomb[i+1][j+1]==1)
                {
                    licznik++;
                }
                
               planszaodkryta[i][j]=licznik;
            }
            if(planszaodkryta[i][j]==0)
            {
                planszazakryta[i][j]=0;
            }
            else if(planszaodkryta[i][j]==9)
            {
                planszazakryta[i][j]=1;
            }
            cout<<planszazakryta[i][j]<<" ";
        }
        cout<<endl;
    }
}
if (wybor==2)
{
    cout<<"ustawienia yo"<<endl<<"1. graj"<<endl<<"inne. wyjscie"<<endl;
    cin>>wybor2;
    if (wybor2==1)
    {
        wybor=1;
    }
    else
    {
        return 0;
    }
}
else
{
  return 0;
}




}