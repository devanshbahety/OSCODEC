
//priorityscheduling

//PRIORITY
#include<iostream>
#include<algorithm>
using namespace std;

void prioritys(int process[],int at[],int bt[],int priority[],int n){
int time = 0;
cout<<"PROCESS\t ARRIVAL TIME\t BURST TIME\t PRIORITY"<<endl;
for(int i=0;i<n;i++){
	cout<<process[i]<<"\t\t"<<at[i]<<"\t\t"<<bt[i]<<"\t\t"<<priority[i]<<"\t\t"<<endl;
}
	
	for(int i=0;i<n-1;++i)
	   {
	   for(int j=0;j<n-i-1;++j){
	   	if(priority[j]>priority[j+1]){
	   		swap(process[j],process[j+1]);
	   		swap(at[j],at[j+1]);
	   		swap(bt[j],bt[j+1]);
	   		swap(priority[j],priority[j+1]);
		   }
	   }
}

//next page priority scheduling
 
cout<<"PROCESS\t ARRIVAL TIME\t BURST TIME\t PRIORITY"<<endl;
for(int i=0;i<n;i++){
	cout<<process[i]<<"\t\t"<<at[i]<<"\t\t"<<bt[i]<<"\t\t"<<priority[i]<<"\t\t"<<endl;
}
for(int i=0;i<n;i++){
	time = time + bt[i];
	cout<<"time "<<time<<" process "<<process[i]<<"completed"<<endl;
}

}
int main(){
	int process[] = {1,2,3,4,5,6,7};
	int at[]={0,2,1,4,6,5,7};
	int bt[]={3,5,4,2,9,4,10};
	int priority[] = {2,6,3,5,7,4,10};
	int n = sizeof(process)/sizeof(process[0]);
	prioritys(process,at,bt,priority,n);
}