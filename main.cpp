#include <iostream>
#include <string>
#include <stack>
using namespace std;

template<class type>

class Queue
{
private:
    struct node
    {
        type item;  //To store the value of the element
        node *next;  //Pointer to indicate the location of the last item in the queue
    };
    node *front;  //To store the value of the first element
    node *rear;  //To store the value of the last element
    int counter;  //Count the items in the queue

public:
    Queue()
    {
        front = NULL;
        rear = NULL;
        counter = 0;
    }

    //Return true if the Queue is empty, otherwise return false.
    bool empty()
    {
        return front == NULL && rear == NULL;
    }

    //To add an item to the queue
    void append(type newItem)
    {
        if (empty())
        {
            front = new node;
            front->item = newItem;
            front->next = NULL;
            rear = front;
            counter++;
        }
        else
        {
            node *newItemPtr = new node;
            newItemPtr->item = newItem;
            newItemPtr->next = NULL;
            rear->next = newItemPtr;
            rear = newItemPtr;
            counter++;
        }
    }

    //To delete the first item in the queue
    void serve()
    {
        if(empty())
        {
            cout<<"the Queue is Underflow"<<endl;
        }
        else if(front == rear)
        {
            rear = NULL;
            front = NULL;
            counter--;
        }
        else
        {
            node *temp = front;
            front = front->next;
            temp->next = NULL;
            delete temp;
            counter--;
        }
    }

    //Delete all queue items
    void clear()
    {
        if(empty())
            cout<<"the Queue is underflow"<<endl;
        else
        {
            node *temp = front;
            while(front != NULL)
            {
                front = front->next;
                temp->next = NULL;
                delete temp;
                counter--;
            }
            rear = NULL;
            cout<<"the clear is successfully"<<endl<<endl;
        }
    }

    //get first item in queue
    type getFront()
    {
        if(empty())
            cout<<"the Queue is Underflow"<<endl;
        else
            return front->item;
    }

    //get last item in queue
    type getRear()
    {
        if(empty())
            cout<<"the Queue is Underflow"<<endl;
        else
            return rear->item;
    }

    //To display all queue items
    void display()
    {
        if(empty())
            cout<<"the Queue is Underflow"<<endl<<endl;
        else
        {
            node *current = front;
            cout<<"The Queue Element is: [ ";
            while(current != NULL)
            {
                cout<<current->item<<" ";
                current = current->next;
            }
            cout<<"]"<<endl;
        }
    }

    //get queue size
    int size()
    {
        return counter;
    }

    //To reverse the order of the queue elements
    void reverseQueue()
    {
        if(empty())
            cout<<"the queue is underflow"<<endl;
        else
        {
            stack <type> stac;
            while(size() != 0)
            {
                stac.push(getFront());
                serve();
            }
            while(stac.size() != 0)
            {
                append(stac.top());
                stac.pop();
            }
        }
    }

};

int main()
{
    Queue <int> queue;
    int option, value;
    cout<<"\t\t<<{Welcome to the Queue program}>>"<<endl;
    while(true)
    {
        cout<<"Option:"<<endl;
        cout<<"\t1- Append."<<endl
            <<"\t2- Serve."<<endl
            <<"\t3- Clear."<<endl
            <<"\t4- Display."<<endl
            <<"\t5- Size."<<endl
            <<"\t6- Reverse the Queue."<<endl
            <<"\t7- is it Empty?."<<endl
            <<"\t8- Exit"<<endl;
        cout<<"Choose the desired option number(1, 2, 3, 4, 5, 6, 7 or 8):"<<endl<<">>";
        cin>>option;
        switch(option)
        {
        case 1:
            system("cls");
            cout<<"Enter the number: ";
            cin>>value;
            queue.append(value);
            cout<<endl<<endl;
            break;
        case 2:
            system("cls");
            queue.serve();
            cout<<endl<<endl;
            break;
        case 3:
            system("cls");
            queue.clear();
            cout<<endl<<endl;
            break;
        case 4:
            system("cls");
            queue.display();
            cout<<endl<<endl;
            break;
        case 5:
            system("cls");
            cout<<"Queue size is: "<<queue.size()<<endl;
            cout<<endl<<endl;
            break;
        case 6:
            system("cls");
            if(!queue.empty())
            {
                queue.reverseQueue();
                cout<<"Reverse the Queue completed successfully."<<endl;
            }
            else
            {
                cout<<"The queue is underflow."<<endl;
            }
            cout<<endl<<endl;
            break;
        case 7:
            system("cls");
            if(queue.empty())
                cout<<"the stack is empty";
            else
                cout<<"the stack is not empty";
            cout<<endl<<endl;
            break;
        case 8:
            return 0;
            break;
        default:
            system("cls");
            system("color 7");
            cout<<"the option is not fount.. try again."<<endl;
            cout<<endl<<endl;
            break;
        }
    }

    return 0;
}
