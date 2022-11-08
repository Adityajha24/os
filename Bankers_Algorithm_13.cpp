#include<iostream>
using namespace std;
class Bankers{
public:
int alloc[50][50];

int maxi[50][50];

int need[50][50];

int avail[50];

int check_safety(int j,int nr)


{

       for(int i=0;i<nr;i++)

       {

              if(need[j][i]>avail[i])

              return 0;

       }

       return 1;

}

int check(bool a[],int n)

{

       for(int i=0;i<n;i++)

       {

              if(a[i]==false)

              return 0;

       }

       return 1;

}
};

int main()

{
Bankers b;
       int np=100;

       int nr=100;

     

       cout<<"\nEnter the no of processes : ";

       cin>>np;

       cout<<"\nEnter the no of resources : ";

       cin>>nr;  
 
 
       cout<<"\nEnter the allocation data : \n";

       for(int i=0;i<np;i++)

       for(int j=0;j<nr;j++)

       cin>>b.alloc[i][j];
       
       
       cout<<"\nEnter the requirement data : \n";

       for(int i=0;i<np;i++)

       for(int j=0;j<nr;j++)

       cin>>b.maxi[i][j];
       
       for(int i=0;i<np;i++)

       for(int j=0;j<nr;j++)

       b.need[i][j]=b.maxi[i][j]-b.alloc[i][j];

     

       cout<<"\nEnter the availability matrix : \n";

       for(int i=0;i<nr;i++)

       cin>>b.avail[i];


int ex_it=nr;

       int flg;

       bool completed[np];

       while(10)

       {

              for(int i=0;i<np;i++)

              {

                     if(!completed[i] && b.check_safety(i,nr))

                     {

                         

                           for(int j=0;j<nr;j++)

                           b.avail[j]+=b.alloc[i][j];

                     }

                     completed[i]=true;

              }
              flg=b.check(completed,np);

              ex_it--;

              if(flg==1 || ex_it==0)

              break;

       }
       
       cout<<"\nThe final availability matrix \n";

       for(int i=0;i<nr;i++)

       cout<<b.avail[i]<<"  ";

     

       cout<<"\n --------- Result ------------- \n";

       if(flg==1)

       cout<<"There is no deadlock";

       else

       cout<<"Sorry there is a possibility of deadlock";

     

       return 0;

}
