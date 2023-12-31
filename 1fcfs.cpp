//fcfs


#include<iostream>
using namespace std;

//PID,AT,BT will be given

struct process
{
    int pid;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
};
void findct(process proc[],int n)
{
    //CT of fist process is equal to burst time of first
    proc[0].ct=proc[0].bt;
    for(int i=1;i<n;i++)
    {
        proc[i].ct=proc[i-1].ct+proc[i].bt;

    }
}
void findtat(process proc[],int n)
{
    for(int i=0;i<n;i++)
    {
        proc[i].tat=proc[i].ct-proc[i].at;
    }
}

//next page 1 fcfs

void findwt(process proc[],int n)
{   
    //wt of first process is always zero
    proc[0].wt=0;
    for(int i=1;i<n;i++)
    {
        proc[i].wt=proc[i].tat-proc[i].bt;
    }
}

void findfcfs(process proc[],int n)
{
    findct(proc,n);
    findtat(proc,n);
    findwt(proc,n);

}

void printfcfs(process proc[],int n)
{
    cout<<"FCFS SCHEDULING : "<<endl;
    cout<<"PID\t AT\t BT\t CT\t TAT\t WT"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<proc[i].pid<<"\t"<<proc[i].at<<"\t"<<proc[i].bt<<"\t"<<proc[i].ct<<"\t"<<proc[i].tat<<"\t"<<proc[i].wt<<endl;
    }
}

int main()
{
    int n=5; //no of processes
    process proc[5]={{1,0,5},{2,1,3},{3,2,2},{4,3,4},{5,4,1}};
    findfcfs(proc,n);
    printfcfs(proc,n);
    return 0;
}

