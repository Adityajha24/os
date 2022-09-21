#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;

    void findCompletionTime(int process[],int n,int arrival_time[],int burst_time[],int ct[])
    {   
       
        //ct[0]=burst_time[0];
       
        for(int i=0;i<n;i++)
        {   
            if(i==0)
            {
                ct[0]=burst_time[0];
            }
            else
            ct[i]=ct[i-1]+burst_time[i];
           
           
        }
  
    }

    void findTurnAroundTime(int process[],int n,int ct[],int at[],int tat[])
    {
       
        for(int i=0;i<n;i++)
        {
            tat[i]=ct[i]-at[i];
            
        }
                               
    }

 void findWaitingTime(int process[],int n,int tat[],int bt[],int wt[])
    {
        
        for(int i=0;i<n;i++)
        {
            wt[i]=tat[i]-bt[i];
            
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


void sortAccordingArrivalTime(int process[],int n,int at[], int bt[])
    {
        bool swapped;
        int temp;
        int stemp;
        for (int i = 0; i < n; i++) 
        {
            swapped = false;
            for (int j = 0; j < n - i - 1; j++) 
            {
                if (at[j] > at[j + 1]) 
                {
                    
                    temp = at[j];
                    at[j] = at[j + 1];
                    at[j + 1] = temp;

                   
                    temp = bt[j];
                    bt[j] = bt[j + 1];
                    bt[j + 1] = temp;


                    temp = process[j];
                    process[j] = process[j + 1];
                    process[j + 1] = temp;

                    
                    swapped = true;
                }
            }
            if (swapped == false) 
            {
                break;
            }
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
   
    cout<<"Enter no. of processes:"<<endl;
    cin>>n;
    int process[n];
    for(int i=0;i<n;i++)
    {
        cin>>process[i];
    }

    cout<<"Enter arrival time:"<<endl;
    int arrival_time[n];
    for(int i=0;i<n;i++)
    {
        cin>>arrival_time[i];
        
    }

    cout<<"Enter burst time:"<<endl;
    int burst_time[n];
    for(int i=0;i<n;i++)
    {
        cin>>burst_time[i];
    }

    sortAccordingArrivalTime(process,n,arrival_time,burst_time);
     

int ct[n],tat[n],wt[n];
    

     
    findCompletionTime(process,n,arrival_time,burst_time,ct);
    findTurnAroundTime(process,n,ct,arrival_time,tat);
    findWaitingTime(process,n,tat,burst_time,wt);
    display(process,n,arrival_time,burst_time,ct,tat,wt);
    average(process,n,tat,wt);
    return 0;
}

