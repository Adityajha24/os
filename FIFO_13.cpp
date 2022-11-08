#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int pageFault(int page[],int n,int no_frame)
{
    int pagefault=0;
   
    vector<int> v1;
    int i;
    for(i=0;i<n;i++)
    {
        auto it=find(v1.begin(),v1.end(),page[i]);
        if(it==v1.end())
        {
            if(v1.size()==no_frame)
            {
            v1.erase(v1.begin());
            }
            v1.push_back(page[i]);
            pagefault++;
        }
    }
    return pagefault;
}

int main()
{
    int page[]={7,0,1,2,0,3,0,4,2,3,0,3,2};    
   
    int n=13;
   
    int no_frame=4;
    cout<<pageFault(page,n,no_frame);
   

    return 0;
}
