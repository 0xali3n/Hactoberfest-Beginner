//this is program for circular-queue in C++ languauge

#include<iostream>
using namespace std;
int q[4];
int f=-1;
int r=-1;
void insert_element()
{

    if(f==0 and r==3 or f==r+1)
    {

        cout<<"Queue overflow....!!"<<endl;
    }
    else
    {
        int ele;
        cout<<"Enter the element : "<<endl;
        cin>>ele;
        r=(r+1)%4;
        q[r]=ele;
        cout<<"Element inserted in Queue sucessfully...."<<endl;
        if(f==-1)
        {
            f=0;
        }
    }



}
void remove_element()
{
    if(f==0 and r==-1)
    {
        cout<<"Queue underflow...."<<endl;
    }
    else
    {
        cout<<"Element "<<q[f]<<" removed sucessfuly..."<<endl;
        f=(f+1)%4;
    }
}
void display()
{
    if(f==0 and r==-1)
    {
        cout<<"Queue is EMPTY..."<<endl;
    }
    else
    {
        if(f<=r)
        {
            int i=f;
            while(i<=r)
            {
                cout<<q[i]<<"  ";
                i++;

            }
        }
        else
        {
             for(int i=0;i<=r;i++)
            {
                cout<<q[i]<<endl;
            }
            for(int i=f;i<=3;i++)
            {
                cout<<q[i]<<endl;
            }

        }

    }


}

int main()
{
     int i;
    do{
            printf("\n\t\tCIRCULAR QUEUE OPERATIONS\n");
            printf("\n****************MENU**********************\n");

            printf("\n1-INSERT elements in queue:\n");
            printf("2- REmOVE elements in queue:\n");
            printf("3-DISPLAY elements in queue:\n");
            printf("4-EXIT\n");
            printf("Provide your choice :");
            cin>>i;
            switch(i)
            {
            case 1:
                insert_element();
                break;
            case 2:
                remove_element();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            }
}while(true);




}
