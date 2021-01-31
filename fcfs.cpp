#include<iostream>
using namespace std;
void avgtime(int processes[],int,int bt[]);
void waitingtimes(int processes[],int bt[],int,int wt[]);
void turnaroundtime(int processes[],int wt[],int,int bt[],int tat[]);
int main()
{
    int processes[]={1,2,3};
    int n=3;
    int burstime[]={10,20,30};
    avgtime(processes,n,burstime);
    return 0;
}
void avgtime(int processes[],int n,int bt[])
{
    int wt[n],tat[n],ttat=0,twat=0;
    waitingtimes(processes,bt,n,wt);
    turnaroundtime(processes,wt,n,bt,tat);
    cout<<"Process Name "<< " "<<"Burst time "<<" "<<"Waiting time"<<" "<<"turnaround "<<endl;
    for(int i=0;i<n;i++)
    {
        ttat=ttat+tat[i];
        twat=twat+wt[i];
        cout<<i+1<<" "<<bt[i]<<" "<<wt[i]<<" "<<tat[i]<<endl;
    }
    //cout<<"Avg waiting time is:"<<twat/n;
    //cout<<"Avg turnaroundtime is:"<<tatime/n;
}
void waitingtimes(int processes[],int bt[],int n,int wt[])
{
    wt[0]=0;
    for(int i=1;i<n;i++)
    {
        wt[i]=bt[i-1]+wt[i-1];
    }
    
}
void turnaroundtime(int processes[],int wt[],int n,int bt[],int tat[])
{
    for(int i=0;i<n;i++)
    {
        tat[i]=wt[i]+bt[i];
    }
}
