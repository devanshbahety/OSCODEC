//sjf

#include<iostream>
using namespace std;

struct process
{
    int pid;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
};

void findsjf(process proc[],int n)
{
    int rt[n];
    for(int i=0;i<n;i++)
    {
        rt[i]=proc[i].bt;
    }
    //variables
    int currenttime=0;
    int complete=0;//how many process completed
    int shortest=0;//index of min bt
    int minburst=9999;//store min bt within current time
    while(complete<n)
    {
        minburst=9999;//reset it to  big value
        for(int i=0;i<n;i++)
        {
            if(proc[i].at<=currenttime && rt[i]<minburst && rt[i]>0)
            {
                minburst=rt[i];
                shortest=i;
            }

        }
        rt[shortest]--;

	//next page sjf

        if(rt[shortest]==0)
        {
            complete++;
            proc[shortest].ct=currenttime+1;
            proc[shortest].tat=proc[shortest].ct-proc[shortest].at;
            proc[shortest].wt=proc[shortest].tat-proc[shortest].bt;
        }
        currenttime++;
    }

}

void printsjf(process proc[],int n)
{
    cout<<"SJF SCHEDULING : "<<endl;
    cout<<"PID\t AT\t BT\t CT\t TAT\t WT"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<proc[i].pid<<"\t"<<proc[i].at<<"\t"<<proc[i].bt<<"\t"<<proc[i].ct<<"\t"<<proc[i].tat<<"\t"<<proc[i].wt<<endl;
    }
}


int main()
{
    int n=5;
    process proc[5]={{1,0,5},{2,2,3},{3,1,8},{4,4,2},{5,3,4}};
    // cout<<"enter process details(ID,AT,BT)"<<endl;
    // for(int i=0;i<n;i++)
    // {
    //     cout<<"enter process "<<i+1<<endl;
    //     cin>>proc[i].pid>>proc[i].at>>proc[i].bt;

    // }
    findsjf(proc,n);
    printsjf(proc,n);

    return 0;
}

