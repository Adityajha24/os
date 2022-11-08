#include <iostream>
#include<algorithm>
using namespace std;

void findCompletionTime(int process[],int n,int burst_time[],int ct[])
{
    ct[0]=burst_time[0];
    for(int i=1;i<n;i++)
    {
        ct[i]=ct[i-1]+burst_time[i];
    }
}
void findWaitingTime(int process[],int n,int at[],int burst_time[],int wait[])
{  
    wait[0]=0;
    for(int i=1;i<n;i++)
    {
        wait[i] = wait[i-1]+burst_time[i-1];
    }
}

void TurnaroundTime(int process[],int n,int at[],int burst_time[],int tat[],int wait[])
{
    tat[0]= burst_time[0];
    
    for(int i=1;i<n;i++)
    {
        tat[i] = tat[i-1]+burst_time[i];
    }
}

void display(int process[],int n,int at[],int bt[],int ct[],int tat[],int wt[])
{
    cout<<"Process ID     Arrival Time    Burst Time         Completion Time        TurnAround Time       Waiting Time"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<process[i]<<"                  "<<at[i]<<"                  "<<bt[i]<<"                 "<<ct[i]<<"                   "<<tat[i]<<"                      "<<wt[i]<<endl;
    }
   
}
void average(int process[],int n,int tat[],int wt[])
{
    float avgtat=0,avgwt=0;
    for(int i=0;i<n;i++)
    {
        avgtat=avgtat+tat[i];
        avgwt=avgwt+wt[i];
    }
    cout<<"Average TurnAround Time:"<<avgtat/float(n)<<endl;
    cout<<"Average Waiting Time:"<<avgwt/float(n)<<endl;
    
}
int main()
{
    int n;
    cout<<"Enter the number of process";
    cin>>n;
   
    int process[n],wait[n],tat[n],burst_time[n],comp[n],at[n]={0},bt[n];
   
    for(int i=0;i<n;i++)
    {
        cin>>process[i];
    }
    cout<<"Enter the burst time";
    for(int i=0;i<n;i++)
    {
        cin>>burst_time[i];
        bt[i]=burst_time[i];
    }
    sort(burst_time,burst_time+n);
   
    findWaitingTime(process,n,at,burst_time,wait);
    TurnaroundTime(process,n,at,burst_time,tat,wait);
    findCompletionTime(process,n,burst_time,comp);
    display(process,n,at,bt,comp,tat,wait);
    average(process,n,tat,wait);

    return 0;
}
