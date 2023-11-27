//Bankers Algorithm

#include<iostream>
using namespace std;

int main()
{
    int n=5;
    int r=3;
    int alloc[5][3]={{0,0,1},//P0
                     {3,0,0},//P1
                     {1,0,0},//P2
                     {2,3,2},//P3
                     {0,0,3}};//P4
    int max[5][3]={{7,6,3},//P0 //MAX MATRIX
                     {3,2,2},//P1
                     {8,0,2},//P2
                     {2,1,2},//P3
                     {5,2,3}};//P4

    int avail[3]={2,3,2};
    int need[n][r];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<r;j++)
        {
            need[i][j]=max[i][j]-alloc[i][j];
        }
    }

    //f ->resource allocated ko control karegi
    //ans ->safe sequence ka jo value hai isme jayega
    //ind ->store index of safe sequence

    int f[n],ans[n],ind=0;
    for(int k=0;k<n;k++)
    {
        f[k]=0;//taki isme garbage value na aaye
    }

      //next page bankers 3 algo

    //abh calculate karunga available ki
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            if(f[i]==0)
            {
                int flag=0;
                for(int j=0;j<r;j++)
                {
                    if(need[i][j]>avail[j])
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag==0)//matlab available hai need se jyada hai
                {
                    ans[ind++]=i;//index stor hojayega safe sequence ka jaise 1 agar p1 pehle chala toh
                    for(int y=0;y<r;y++)
                    {
                        avail[y]=avail[y]+alloc[i][y];
                    }
                    f[i]=1;
                }
            }
        }
    }

    if(ind < n)
    {
        cout << "Unsafe State: No safe sequence found." << endl;
    }
    else
    {
        cout<<"The safe sequence is"<<endl;
        for(int i=0;i<n;i++)
        {
            cout<<"P"<<ans[i]<<"->";
        }
    }

    return 0;
}


