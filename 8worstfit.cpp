//worst fit
#include <iostream>
using namespace std;
int main()
{
    int nb,nf,b[10],f[10],frag[10],temp,highest=0;
    int bf[10],ff[10];
    cout<<"Enter the no of blocks"<<endl;
    cin>>nb;
    cout<<"Enter no of files"<<endl;
    cin>>nf;
    cout<<"Enter the size of each block";
    for(int i=1;i<=nb;i++)
    {
        cin>>b[i];
    }
    cout<<"Enter the size of each file";
    for(int i=1;i<=nf;i++)
    {
        cin>>f[i];
    }
    
    for(int i=1;i<=nf;i++)
    {
        for(int j=1;j<=nb;j++)
        {
            if(bf[j]!=1)
            {
                temp=b[j]-f[i];
                if(temp>=0 && highest<temp)
                {
                    ff[i]=j; //konsa block accomodate hogya
                    highest=temp;
                }
            }
        }
        frag[i]=highest;
        bf[ff[i]] = 1;
        highest=0;
    }
    cout<<"File_no,File_size,Block_no,Block_size,Fragment";
    for (int i =1; i <= nf; i++)
    {
      cout<<i<<" "<<f[i]<< " "<< ff[i] <<" " << b[ff[i]] <<" " << frag[i];  
    }
    
}


