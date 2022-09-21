#include <iostream>
#include<algorithm>
using namespace std;

void fWaitingTime(int processes[], int n, 
			int bt[], int wt[], int quantum) 
{ 
	
	int rem_bt[n]; 
	for (int i = 0 ; i < n ; i++) 
		rem_bt[i] = bt[i]; 

	int t = 0; 
	
	while (1) 
	{ 
		bool done = true; 

		for (int i = 0 ; i < n; i++) 
		{ 
			
			if (rem_bt[i] > 0) 
			{ 
				done = false; 

				if (rem_bt[i] > quantum) 
				{ 
					 
					t += quantum; 

					
					rem_bt[i] -= quantum; 
				} 
			 
				else
				{ 
					
					t = t + rem_bt[i];

					wt[i] = t - bt[i]; 

					
					rem_bt[i] = 0; 
				} 
			} 
		} 

		
		if (done == true) 
		break; 
	} 
}

void fTurnAroundTime(int processes[], int n, 
						int bt[], int wt[], int tat[]) 
{ 
	 
	for (int i = 0; i < n ; i++) 
		tat[i] = bt[i] + wt[i]; 
} 




void display(int process[],int n,int at[],int bt[],int tat[],int wt[])
{
    cout<<"Process ID     Arrival Time        Burst Time       TurnAround Time       Waiting Time"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<process[i]<<"                  "<<at[i]<<"                  "<<bt[i]<<"                 "<<tat[i]<<"                      "<<wt[i]<<endl;
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
   
    int process[n],wait[n],tat[n],burst_time[n],at[n]={0},bt[n];
   
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
    
    int quantum;
    cout<<"Enter time quantum:";
    cin>>quantum; 
   
    fWaitingTime(process,n,burst_time,wait,quantum);
    fTurnAroundTime(process,n,burst_time,wait,tat);
    display(process,n,at,burst_time,tat,wait);
    average(process,n,tat,wait);
    


    return 0;
}