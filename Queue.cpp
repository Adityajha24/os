#include <iostream>
using namespace std;
class Q{
    private:
    int queue[100],f=-1,r=-1; 
    public:
      bool isfull()
        {
            if(r==99)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    void enque(int value)
    {
       
        if(isfull())
        {
            cout<<"over flow ";
            
        }
        else
        {
           if(f==-1)
           {f++;
               r++;
               queue[r]=value;
           }
           else
           {
                r++;
               queue[r]=value;
           }
        }
       
    }
    bool isempty()
    {
        if(f==r)
        {return true;}
        
        return false;
    }
   int deque()
   {
       int value;
       if(isempty())
       {
           return -1;
       }
       else
       {
           value=queue[r];
           if(f>=r)
           {f=0;
               r=0;
           }
           else
           {f++;}
           return value;
       }
   }
   void display()
   {
       for(int i=f;i<=r;i++)
       {cout<<queue[i]<<" ";}
       cout<<endl;
   }
};
int main()
{
    Q s;
    cout<<"1 for enque"<<endl;
    cout<<"2 for deque"<<endl;
    cout<<"3 for display"<<endl;
    cout<<"4 for exit"<<endl;
    int ch;
    do{
        
        cin>>ch;
        switch(ch)
        {
            case 1:
            {s.enque(10);
                break;
            }
            case 2:
            {s.deque();
                break;
            }
            case 3:
            {s.display();
                break;
            }
            case 4:
            {
                cout<<"you are out now"<<endl;
                break;
            }
            default:
            {cout<<"invalid choice "<<endl;}
        }
    }while(ch!=4);
    return 0;
}