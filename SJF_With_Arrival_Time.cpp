#include <iostream>
#include <stdlib.h>

using namespace std;

void input_burst_arrival_time(int burst_time[],int process[],int n,int arrival_time[])
{
  for(int i=0;i<n;i++)
    {
        cin>>process[i];
    }


   cout<<"Enter the arrival time";
    for(int i=0;i<n;i++)
    {
        cin>>arrival_time[i];
        
    }
    cout<<"Enter the burst time";
    for(int i=0;i<n;i++)
    {
        cin>>burst_time[i];
        
    }
}

void sort_arrival_time(int arrival_time[],int process[],int n,int burst_time[])
{
  for(int i=0;i<n;i++)
  {
    for(int j=i+1;j<n;j++)
    {
      if(arrival_time[i]>arrival_time[j])
      {
        swap(process[i],process[j]);
        swap(arrival_time[i],arrival_time[j]);
        swap(burst_time[i],burst_time[j]);
       
      }
    }
  }
}

void sort_burst_time(int arrival_time[],int process[],int n,int burst_time[])
{
  for(int i=0;i<n;i++)
  {
    for(int j=i+1;j<n;j++)
    {
      if(arrival_time[i]==arrival_time[j])
      
      {
        if(burst_time[i]>burst_time[j])
        
        {
          swap(process[i],process[j]);
          swap(arrival_time[i],arrival_time[j]);
          swap(burst_time[i],burst_time[j]);
        }
      }
    }
  }
}

void sjf(int process[],int n,int arrival_time[],int waiting_time[],int burst_time[],int turn_around_time[],int completion_time[])
{
  int temp;
  int value;

  completion_time[0] = arrival_time[0] + burst_time[0];
  turn_around_time[0] = completion_time[0] - arrival_time[0];
  waiting_time[0] = turn_around_time[0] - burst_time[0];
  

  for(int i=1;i<4;i++)

  {
    temp = completion_time[i-1];
    int low = burst_time[i];
    for(int j=i;j<n;j++)
    {
      if(temp >= arrival_time[j] && low >=burst_time[j])
      
      {
        low = burst_time[j];
        value = j;
      }
    }
    completion_time[value] = temp + burst_time[value];
    turn_around_time[value] = completion_time[value] - arrival_time[value];
    waiting_time[value] = turn_around_time[value] - burst_time[value];
 
  }
}

void display(int process[],int n,int burst_time[],int waiting_time[],int turn_around_time[],int arrival_time[])

{
  cout<<endl<<endl;

  cout<<"Process"<<" \t"<<"Arrival Time"<<" \t"<<"Burst Time"<<" \t"<<"Waiting Time"<<" \t"<<"Turn Around Time"<<endl;
  for(int i=0;i<n;i++)
  {
    cout<<process[i]<<"\t\t"<<arrival_time[i]<<"\t\t"<<burst_time[i]<<"\t\t"<<waiting_time[i]<<"\t\t"<<turn_around_time[i]<<endl;
  }

  cout<<endl<<endl;
}

int main()
{
    int n;
    cout<<"Enter the number of process";
    cin>>n;
  int process[n];
  int burst_time[n];
  int waiting_time[n];
  int completion_time[n];
  int turn_around_time[n];
  int arrival_time[n];

  input_burst_arrival_time(burst_time,process,n,arrival_time);

  sort_arrival_time(arrival_time,process,n,burst_time);

  sort_burst_time(arrival_time,process,n,burst_time);

  sjf(process,n,arrival_time,waiting_time,burst_time,turn_around_time,completion_time);

  display(process,n,burst_time,waiting_time,turn_around_time,arrival_time);

  return 0;
}
// #include <iostream>
// #include <stdlib.h>

// using namespace std;

// void input_burst_arrival_time(int burst_time[],int process[],int n,int arrival_time[])
// {
//   cout<<"Enter burst time and arrival time (in pairs) for four processes : "<<endl;
//   for(int i=0;i<n;i++)
//   // The user is asked to enter burst time and arrival time of 4 processes.
//   {
//     process[i]=i;
//     cin>>burst_time[i];
//     cin>>arrival_time[i];
//     // Input is taken for the butst time and arrival time.
//   }
// }

// void sort_arrival_time(int arrival_time[],int process[],int n,int burst_time[])
// // Function is used to sort the processes on the basis of their arrival time.
// // In case, two processes have same arrival time they will be placed next to each other.
// {
//   for(int i=0;i<n;i++)
//   {
//     for(int j=i+1;j<n;j++)
//     {
//       if(arrival_time[i]>arrival_time[j])
//       {
//         swap(process[i],process[j]);
//         swap(arrival_time[i],arrival_time[j]);
//         swap(burst_time[i],burst_time[j]);
//         // Process id, arrival time as well as burst time of the processes are sorted inaccordance with arrival time.
//       }
//     }
//   }
// }

// void sort_burst_time(int arrival_time[],int process[],int n,int burst_time[])
// // Function is used to sort the processes with same burst time according to their arrival time.
// {
//   for(int i=0;i<n;i++)
//   {
//     for(int j=i+1;j<n;j++)
//     {
//       if(arrival_time[i]==arrival_time[j])
//       // Condition is checked if two processes have same arrival time.
//       {
//         if(burst_time[i]>burst_time[j])
//         // In case the arrival time is same, the processes are compared according to their burst time and further sorted.
//         {
//           swap(process[i],process[j]);
//           swap(arrival_time[i],arrival_time[j]);
//           swap(burst_time[i],burst_time[j]);
//         }
//       }
//     }
//   }
// }

// void sjf_operations(int process[],int n,int arrival_time[],int waiting_time[],int burst_time[],int turn_around_time[],int completion_time[])
// // This function is used to calcuate waiting time and turn around time fot the processes.
// {
//   int temp;
//   int value;

//   completion_time[0] = arrival_time[0] + burst_time[0];
//   turn_around_time[0] = completion_time[0] - arrival_time[0];
//   waiting_time[0] = turn_around_time[0] - burst_time[0];
//   // For the first process the completion time, waiting time an turn around time are initialised.

//   for(int i=1;i<n;i++)
//   // Process from the seconf are iterated to till the last process in reached.
//   {
//     temp = completion_time[i-1];
//     int low = burst_time[i];
//     for(int j=i;j<n;j++)
//     {
//       if(temp >= arrival_time[j] && low >=burst_time[j])
//       // Completion time of previous process is compare with the arrival time of current process as well the burst time is compared.
//       {
//         low = burst_time[j];
//         value = j;
//       }
//     }
//     completion_time[value] = temp + burst_time[value];
//     turn_around_time[value] = completion_time[value] - arrival_time[value];
//     waiting_time[value] = turn_around_time[value] - burst_time[value];
//     // Value of completion time, waiting time and turn around time is calculated using formulae.
//   }
// }

// void display(int process[],int n,int burst_time[],int waiting_time[],int turn_around_time[],int arrival_time[])
// // Table is printed which prints the calculated value as the output.
// {
//   cout<<endl<<endl;

//   cout<<"Process"<<" \t"<<"Arrival Time"<<" \t"<<"Burst Time"<<" \t"<<"Waiting Time"<<" \t"<<"Turn Around Time"<<endl;
//   for(int i=0;i<n;i++)
//   {
//     cout<<process[i]<<"\t\t"<<arrival_time[i]<<"\t\t"<<burst_time[i]<<"\t\t"<<waiting_time[i]<<"\t\t"<<turn_around_time[i]<<endl;
//   }

//   cout<<endl<<endl;
// }

// int main()
// {
  


//    int n;
//     cout<<"Enter the number of process";
//     cin>>n;

//     int process[n],wait[n],tat[n],burst_time[n],comp[n],at[n];
//     for(int i=0;i<n;i++)
//     {
//         cin>>process[i];
//     }


//    cout<<"Enter the arrival time";
//     for(int i=0;i<n;i++)
//     {
//         cin>>at[i];
        
//     }
//     cout<<"Enter the burst time";
//     for(int i=0;i<n;i++)
//     {
//         cin>>burst_time[i];
        
//     }
  
//   sort_arrival_time(at,process,n,burst_time);

//   sort_burst_time(at,process,n,burst_time);

//   sjf_operations(process,n,at,wait,burst_time,tat,comp);

//   display(process,n,burst_time,wait,tat,at);

//   return 0;
// }