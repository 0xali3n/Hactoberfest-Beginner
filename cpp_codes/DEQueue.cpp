//Queue is a linear Data structure which follows FIFO(First In First Out) order.
//Double Ended Queue
//Dequeue is a linear data structure in which the insertion and deletion operations are performed from both ends, with restrictions applied to it, by using pointers in my case.
//Here Dequeue is implemented using Array

#include <iostream>

using namespace std;

class DEQueue{
private:
    int front;
    int rear;
    int size;
    int* Q;

public:
    DEQueue(int size);
    ~DEQueue();
    void display();
    void enqueueFront(int x);
    void enqueueRear(int x);
    int dequeueFront();
    int dequeueRear();
    bool isEmpty();
    bool isFull();
};

//Constructor
DEQueue::DEQueue(int size) {
    this->size = size;
    front = -1;
    rear = -1;
    Q = new int [size];
}

//Destructor
DEQueue::~DEQueue() {
    delete [] Q;
}

//Condition for Empty Queue
bool DEQueue::isEmpty() {
    if (front == rear){
        return true;
    }
    return false;
}

//Condition for Full Queue
bool DEQueue::isFull() {
    if (rear == size - 1){
        return true;
    }
    return false;
}

//Enqueue Operation(Insertion) using Front Pointer
void DEQueue::enqueueFront(int x) {
    if (front == -1){
        cout << "\nDEQueue Overflow" << endl;
    } else {
        Q[front] = x;
        front--;
    }
}

//Enqueue Operation(Insertion) using Rear Pointer
void DEQueue::enqueueRear(int x) {
    if (isFull()){
        cout << "\nDEQueue Overflow" << endl;
    } else {
        rear++;
        Q[rear] = x;
    }
}

//Dequeue Operation(Deletion) using Front Pointer
int DEQueue::dequeueFront() {
    int x = -1;
    if (isEmpty()){
        cout << "\nDEQueue Underflow" << endl;
    } else {
        x = Q[front];
        front++;
    }
    return x;
}

//Dequeue Operation(Deletion) using Rear Pointer
int DEQueue::dequeueRear() {
    int x = -1;
    if (rear == -1){
        cout << "\nDEQueue Underflow" << endl;
    } else {
        x = Q[rear];
        rear--;
    }
    return x;
}

//Displaying the Queue
void DEQueue::display() {
    for (int i=front+1; i<=rear; i++) {
        cout << Q[i] << flush;
        if (i < rear){
            cout << " <- " << flush;
        }
    }
    cout << endl;
}

int main() {

    int n,x,ch;
    cout<<"Enter the size of the queue: ";
    cin>>n;
    DEQueue deq(n);
    do
    {
        cout<<"---------Menu---------"<<endl<<endl;
        cout<<"1. Enqueue Using Rear Pointer"<<endl;
        cout<<"2. Enqueue Using Front Pointer"<<endl;
        cout<<"3. Dequeue Using Rear Pointer"<<endl;
        cout<<"4. Dequeue Using Front Pointer"<<endl;
        cout<<"5. Display"<<endl;
        cout<<"6. Exit"<<endl;

        cout<<"\nEnter your choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1: cout<<"\nEnter the element: ";
                    cin>>x;
                    deq.enqueueRear(x);
                    break;
            case 2: cout<<"\nEnter the element: ";
                    cin>>x;
                    deq.enqueueFront(x);
                    break;
            case 3: deq.dequeueRear();
                    break;
            case 4: deq.dequeueFront();
                    break;
            case 5: deq.display();
                    break;
            case 6: exit(0);
                    break;
            default:cout<<"\nInvalid Choice"<<endl;
                    ch=0;
        }
     }while(ch<=6);
    return 0;
}
