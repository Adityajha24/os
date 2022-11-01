#include <iostream>

using namespace std;

int main()
{
   int bt[55],ts,n,i,x=0,tt=0;
   char pn[10];
   cout<<"Enter the Number of Processes:\t";
   cin>>n;
   for(i=0;i<n;i++)
   {
       cout<<"Enter Process Name and Estimate Time:\t";
       cin>>pn[i];
       cin>>bt[i];
    }
    cout<<"The Processes are:\t";
for(i=0;i<n;i++)
{
    cout<<"processes:"<<i+1<<pn[i];
for(i=0;i<n;i++){
    tt=tt+pn[i];
    }
    while(x!=tt)
    {
        for(i=0;i<n;i++)
        {
        if(bt[i]>ts)
        {
            x=x-ts;
            cout<<"\n"<<pn[i]<<"->"<<ts;
            bt[i]=bt[i]-ts;
            
        }
            else if((bt[i]<=ts)&&bt[i]!=0)
            {
                x=x+bt[i];
                cout<<" "<<pn[i]<<"->"<<bt[i];
                bt[i]=0;
            }
        }
        
    }
}

}
