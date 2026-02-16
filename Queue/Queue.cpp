//////////////////////////////////////////////////////
// Queue using generic approach
/////////////////////////////////////////////////////

#include<iostream>
using namespace std;

#pragma pack(1)

template <class T>
class Queuenode
{
    public:
       T data;
       Queuenode<T> *next;
       
        Queuenode(T no)
       {
           this->data = no;
           this->next = NULL;
       }
}; 

template <class T>
class Queue
{
    private:
       Queuenode<T> *first;
       Queuenode<T> *last;
       int iCount;
    
    public:
       Queue();
       void Enqueue(T);            
       T Dequeue();                
       void Display();
       int Count();
};

template <class T>
Queue<T> :: Queue()
{
    cout<<"Queue gets created successfully\n";
    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}


////////////////////////////////////////////////////////////////////////////////////////////////// 
//  
//    Function Name :   Enqueue
//    Input         :   Data of node
//    Output        :   Nothing
//    Description   :   Used to insert node at last position
//    Author        :   Anuja Santosh Dhanwate
//    Date          :   06/11/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////// 

template <class T>
void Queue<T>::Enqueue(T no)
{
    Queuenode<T> *newn = NULL;
    newn = new  Queuenode<T>(no);

    if(this->first == NULL && this->last == NULL)
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        this->last->next = newn;
        this->last = this->last->next;
    }
    this->iCount++;
}   

////////////////////////////////////////////////////////////////////////////////////////////////// 
//  
//    Function Name :   Dequeue
//    Input         :   Nothing
//    Output        :   Nothing
//    Description   :   Used to delete node at first position
//    Author        :   Anuja Santosh Dhanwate
//    Date          :   06/11/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////// 

template <class T>
T Queue<T>:: Dequeue()
{
    T Value = 0;

    Queuenode<T> *temp = this->first;

    if(this->first == NULL && this->last == NULL)
    {
        cout<<"Queue is empty\n";
        return -1;
    }

    else if (this->first == this->last)
    {
        this->first = NULL;
        this->last = NULL;
    }
    
    else
    {
        Value = this->first->data;
        
        this->first = this->first->next;
        delete temp;

        this->iCount--;

        return Value;
    }
}     


////////////////////////////////////////////////////////////////////////////////////////////////// 
//  
//    Function Name :   Display
//    Input         :   Nothing
//    Output        :   Nothing
//    Description   :   Used to display all nodes 
//    Author        :   Anuja Santosh Dhanwate
//    Date          :   06/11/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////// 

template <class T>
void Queue<T>:: Display()
{
    Queuenode<T> *temp =this->first;

    if(this->first == NULL && this->last == NULL)
    {
        cout<<"Queue is empty\n";
        return;
    }

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |-";
        temp = temp->next;
    }
    cout<<"\n";
}

////////////////////////////////////////////////////////////////////////////////////////////////// 
//  
//    Function Name :   Count
//    Input         :   Nothing
//    Output        :   Nothing
//    Description   :   Used to count total nodes in queue
//    Author        :   Anuja Santosh Dhanwate
//    Date          :   06/11/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////// 

template <class T>
int Queue<T>:: Count()
{
    return this->iCount;
}


int main()
{
   
    int datatype = 0;

    cout<<"Select data type :\n";
    cout<<"1. int\n";
    cout<<"2. float\n";
    cout<<"3. char\n";
    cout<<"4. double\n";
    cout<<"Enter choice:\n";
    cin>>datatype;

    if(datatype == 1)
    {
            Queue<int> *qobj = new Queue<int>();
                    
            int iChoice = 0;
            int iValue = 0;
            int iRet = 0;
           
            while(1)                      // Unconditional loop
            {
                cout<<"-----------------------------------------------------------\n";
                cout<<"----------------Please select the option-------------------\n";
                cout<<"1 : Insert new elements into the queue\n";
                cout<<"2 : Remove the elements from queue\n";
                cout<<"3 : Display the elements of queue\n";
                cout<<"4 : Count the number of elements from the queue\n";
                cout<<"0 : Exit the application\n";

                cin>>iChoice;

                switch(iChoice)
                {
                    case 1 : 
                        cout<<"Enter the elements that you want to insert :\n";
                        cin>>iValue;
                        qobj->Enqueue(iValue);
                        cout<<"Elements gets inserted successfully.\n";
                        break;

                    case 2 :
                        iRet = qobj->Dequeue();
                        if(iRet != -1)
                        {
                            cout<<"Elements removed from queue is : "<<iRet<<"\n";

                        }
                        break;
                        
                    case 3:
                        cout<<"Elements of the queue atre :\n";
                        qobj->Display();
                        break;
                    
                    case 4:
                        iRet =  qobj->Count();
                        cout<<"Number of elements in queue are are : "<<iRet<<"\n";
                        break;
                    
                    case 0:
                        cout<<"Thank you for using our application\n";
                        delete qobj;
                        return 0;
                    
                    default:
                        cout<<"Please enter valid option\n";

                }// End of switch

                cout<<"-----------------------------------------------------------\n";
            }// End of while
    }
    
    else if(datatype == 2)
    {
            Queue<float> *qobj = new Queue<float>();
                    
            int iChoice = 0;
            float fValue = 0.0f;
            int iRet = 0;
            float fRet = 0.0f;

            while(1)                      // Unconditional loop
            {
                cout<<"-----------------------------------------------------------\n";
                cout<<"----------------Please select the option-------------------\n";
                cout<<"1 : Insert new elements into the queue\n";
                cout<<"2 : Remove the elements from queue\n";
                cout<<"3 : Display the elements of queue\n";
                cout<<"4 : Count the number of elements from the queue\n";
                cout<<"0 : Exit the application\n";

                cin>>iChoice;

                switch(iChoice)
                {
                    case 1 : 
                        cout<<"Enter the elements that you want to insert :\n";
                        cin>>fValue;
                        qobj->Enqueue(fValue);
                        cout<<"Elements gets inserted successfully.\n";
                        break;

                    case 2 :
                        fRet = qobj->Dequeue();
                        if(fRet != -1)
                        {
                            cout<<"Elements removed from queue is : "<<fRet<<"\n";

                        }
                        break;
                        
                    case 3:
                        cout<<"Elements of the queue atre :\n";
                        qobj->Display();
                        break;
                    
                    case 4:
                        iRet =  qobj->Count();
                        cout<<"Number of elements in queue are are : "<<iRet<<"\n";
                        break;
                    
                    case 0:
                        cout<<"Thank you for using our application\n";
                        delete qobj;
                        return 0;
                    
                    default:
                        cout<<"Please enter valid option\n";

                }// End of switch

                cout<<"-----------------------------------------------------------\n";
            }// End of while
    } 

    
    else if(datatype == 3)
    {
            Queue<char> *qobj = new Queue<char>();
                    
            int iChoice = 0;
            char cValue = 0;
            int iRet = 0;
            char cRet = '\0';

            while(1)                      // Unconditional loop
            {
                cout<<"-----------------------------------------------------------\n";
                cout<<"----------------Please select the option-------------------\n";
                cout<<"1 : Insert new elements into the queue\n";
                cout<<"2 : Remove the elements from queue\n";
                cout<<"3 : Display the elements of queue\n";
                cout<<"4 : Count the number of elements from the queue\n";
                cout<<"0 : Exit the application\n";

                cin>>iChoice;

                switch(iChoice)
                {
                    case 1 : 
                        cout<<"Enter the elements that you want to insert :\n";
                        cin>>cValue;
                        qobj->Enqueue(cValue);
                        cout<<"Elements gets inserted successfully.\n";
                        break;

                    case 2 :
                        cRet = qobj->Dequeue();
                        if(cRet != -1)
                        {
                            cout<<"Elements removed from queue is : "<<cRet<<"\n";

                        }
                        break;
                        
                    case 3:
                        cout<<"Elements of the queue atre :\n";
                        qobj->Display();
                        break;
                    
                    case 4:
                        iRet =  qobj->Count();
                        cout<<"Number of elements in queue are are : "<<iRet<<"\n";
                        break;
                    
                    case 0:
                        cout<<"Thank you for using our application\n";
                        delete qobj;
                        return 0;
                    
                    default:
                        cout<<"Please enter valid option\n";

                }// End of switch

                cout<<"-----------------------------------------------------------\n";
            }// End of while
    }
 
    else if(datatype == 4)
    {
            Queue<double> *qobj = new Queue<double>();
                    
            int iChoice = 0;
            double dValue = 0;
            int iRet = 0;
            double dRet = 0.0;

            while(1)                      // Unconditional loop
            {
                cout<<"-----------------------------------------------------------\n";
                cout<<"----------------Please select the option-------------------\n";
                cout<<"1 : Insert new elements into the queue\n";
                cout<<"2 : Remove the elements from queue\n";
                cout<<"3 : Display the elements of queue\n";
                cout<<"4 : Count the number of elements from the queue\n";
                cout<<"0 : Exit the application\n";

                cin>>iChoice;

                switch(iChoice)
                {
                    case 1 : 
                        cout<<"Enter the elements that you want to insert :\n";
                        cin>>dValue;
                        qobj->Enqueue(dValue);
                        cout<<"Elements gets inserted successfully.\n";
                        break;

                    case 2 :
                        dRet = qobj->Dequeue();
                        if(dRet != -1)
                        {
                            cout<<"Elements removed from queue is : "<<dRet<<"\n";

                        }
                        break;
                        
                    case 3:
                        cout<<"Elements of the queue atre :\n";
                        qobj->Display();
                        break;
                    
                    case 4:
                        iRet =  qobj->Count();
                        cout<<"Number of elements in queue are are : "<<iRet<<"\n";
                        break;
                    
                    case 0:
                        cout<<"Thank you for using our application\n";
                        delete qobj;
                        return 0;
                    
                    default:
                        cout<<"Please enter valid option\n";

                }// End of switch

                cout<<"-----------------------------------------------------------\n";
            }// End of while
    }
    else
    {
        cout<<"Sorry..! You have entered invalid datatype.\n";
    }
        return 0;

}//End of main