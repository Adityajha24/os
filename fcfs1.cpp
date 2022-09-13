#include<iostream>
using namespace std;
class FCFS
{
    public:
    
    void findCompletionTime(int process[],int n,int burst_time[],int comp_time[])
    {
       
        comp_time[0]=burst_time[0];
        cout<<"Completion Time:"<<endl;
        cout<<comp_time[0]<<endl;
        for(int i=1;i<n;i++)
        {
            comp_time[i]=comp_time[i-1]+burst_time[i];
            cout<<comp_time[i]<<endl;
        }
    }
    void findTurnAroundTime(int process[],int n,int ct[])
    {   
        int tat[n],average;
        cout<<"Turn around time:"<<endl;
        for(int i=0;i<n;i++)
        {
            tat[i]=ct[i];
            cout<<tat[i]<<endl;
            average=average+tat[i];
        }
        cout<<"Average Turn around time:"<<average/n<<endl;
    }
    void findWaitingTime(int process[],int n,int ct[],int bt[],int wt[])
    {   
        int tat[n],average=0;
        cout<<"Waiting Time:"<<endl;
        for(int i=0;i<n;i++)
        {
             tat[i]=ct[i];
            wt[i]=tat[i]-bt[i];
            average=average+wt[i];
            cout<<wt[i]<<endl;
        }
        average=average/n;
        cout<<"Average waiting time:"<<average;
    }
};
int main()
{
    FCFS f;
    int n;
    cout<<"Enter no of processes:";
    cin>>n;
    int process[n];
    for(int i=1;i<=n;i++)
    {
        cin>>process[i];
    } 
    // cout<<"Process No.:"<<endl;
    // for(int i=0;i<n;i++)
    // {
    //     cout<<process[i]<<endl;
    // }
    int burst_time[]={2,3,4,5};
    int comp_time[n],waiting_time[n],tat[n];
    f.findCompletionTime(process,n,burst_time,comp_time);
    f.findTurnAroundTime(process,n,comp_time);
    f.findWaitingTime(process,n,comp_time,burst_time,waiting_time);
    


}