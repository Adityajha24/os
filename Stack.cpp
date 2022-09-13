#include <iostream>

using namespace std;

class St
{
    private : 
    int stck[100],top=-1;
    public:
    void push(int value)
    {
        if(isfull())
        cout<<"Stack overflow."<<endl;
        else
        {
            top++;
            stck[top]=value;
        }
    }
    
    bool isfull()
    {
        if(top==99)
        return true;
        else
        return false;
    }
    
};



int main()
{
   St obj1;
   int ch;
   
  
   do{
       cout<<"1. Push"<<endl;
       cout<<"2. Pop"<<endl;
       cout<<"3.Display"<<endl;
       cout<<"4. Exit"<<endl;
     
     cin>>ch;
       switch(ch)
       {
          case 1:
          {
              int val;
               cout<<"enter the value"<<endl;
             cin>>val;
           obj1.push(val);
           break;
           
       }
       default :
       {
           cout<<"Invalid choice"<<endl;
       }
   }
   }
   while(ch!=4);
   

    return 0;
}
