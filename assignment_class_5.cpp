/*My name: النيل ابو القاسم ابراهيم النور
    Class: الفرقة الثانية 
Department: الحاسوب
*/
#include <iostream>
#include <string>
using namespace std ;
const int maxSize = 12;

class linkedlist{
    struct Node
    {
        int item; 
        Node*next;
    };
    Node*first;
    Node*last;
    int length;
public:
    linkedlist(){
    
    first=last =NULL;
    length = 0;
    }
    bool isEmpty() // دالة إختبار السلسة اذا كانت فارغة
      {
         return length == 0;
      }
    void insertFirst(int element) // دالة إضافة عنصر إلي أول السلسلة
    {
        Node*newNode = new Node ;
        newNode->item = element;
        if (length == 0)
        {
            first = last = newNode;
            newNode->next = NULL;
        }
        else {
            newNode->next = first ;
            first = newNode;
        }
        length++;
    }

    void insertlast(int element) // دالة إضافة عنصر إلي أخر السلسلة
    {
        Node *newNode = new Node ;
        newNode->item = element;
        if (length == 0)
        {
            first = last = newNode;
            newNode->next = NULL;
        }
        else {
            last->next = newNode;
            newNode->next = NULL;
            last = newNode;
        }
        length ++;
    }

    void insertAtPos(int pos, int element) //
    { 
        if (pos < 0 || pos > length)
            cout << "out of Range\n";
        else 
        {
            Node*newNode = new Node;
            newNode->item = element;
            if(pos == 0)
                insertFirst(element);
            else if(pos == length)
                insertlast(element);
            else 
            {
                Node * cur = first;
                for (int i = 1; i < pos; i++)
                {
                    cur=cur->next;
                }
                newNode->next=cur->next;
                cur->next=newNode;
                length++;
            }
        }

    }
    void print()
    {
        cout << "<<<< THE LINKED LIST >>>>\n";
        Node*cur = first;
        cout << "[ ";
        while (cur != NULL)
        {
            cout << cur->item <<" ";
            cur=cur->next;
        }  
        cout << "]\n";      
    }

};
/*===============================THE STACK==================================*/
class stack
{
    private:
        int stackArray [maxSize];
        int Top;
    public:
        stack():Top(-1){}

        void push(int element) // دالة إضافة عنصر في المكدس
        {
            if (Top >= maxSize - 1)
            {
                cout << "Stack is Full!\n";
            }
            else 
            {
                Top++;
                stackArray[Top] = element;
            }
        }
        bool isEmpty()
        {
            return Top < 0;
        }
        void pop() // دالة حذف العناصر في المكدس
        {
            if (isEmpty())
            {
                cout << "Stack is Empty !\n";
            }
            else
            {
                Top--;
            }
        }
        void print()
        {
            cout<<"<<<<<<<<<<= STACK =>>>>>>>>>>"<<endl;
            cout <<"===\n";
            for (int i = Top; i >= 0; i--)
            {
                cout << stackArray[i] << endl;
            }
            cout << "===";
        }

};
/*===================QUEUE=======================*/
class Queue
{
int front, end, length, queueArray[maxSize];
public:
    Queue(){
        front = 0;
        end = maxSize - 1;
        length = 0;
    }
    bool isEmpty()
    {
        return length == 0;
    }
    bool isFull()
    {
        return length==maxSize;
    }
    void addQueue(int number) // دالة إضافة العناصر إلي الصف 
    {
        if (isFull()) // دالة إختبار اذا كان الصف ممتلء
        {
            cout << "Queue is Full can't add \n";
        }
        else
        {
            end = (end + 1)%maxSize;
            queueArray[end] = number;
            length++;
        }
        
    }
    void deleteQueue() // دالة حذف العناصر من الصف
    {
        if (isEmpty()) //دالة اختبار الصف اذا كان فارغ
        {
            cout << "Queue is Empty can't delate\n";
        }
        else
        {
            front = (front+1)%maxSize;
            length--;
        }
        
    }
    void printQueue() //دالة طباعة عناصر الصف
    {
        cout << "[ ";
        for (int i = front; i != end+1; (i+1)%maxSize)
        {
            cout << queueArray[i]<< " ";
        }
        cout << "]";
    
    }

};

int main ()
{

linkedlist l; stack s; Queue q; //   كائنات من الكلاسات الاب
int choose, pos, element, choice;
string Exit ;
cout << "Choose the number ";
cin >> choice;

    switch (choice)
{
case 1:
    cout << "Firstly add 4 Element to linked list :"<< endl;
    for (int i = 1; i < 5; i++)
    {
        cout<< "Enter the element number "<<i<<": ";
        cin >> element;
        l.insertlast(element);
    }
    l.print();

    do
    {
        cout<< "\n now to add more element|\npress 1 and the element will be the first one\n";
        cout<< "press 2 and the element will be the last one\n";
        cout<< "press 3 to add at position .. enter the poition and then enter the element \n";
        cout << "press 4 to remove element :";
        try 
        {
            cin >> choice;
            if (choice==1)
            {
                cout<< "The Element =";
                cin>> element;
                l.insertFirst(element);
            }
            else if (choice==2)
            {
                cout<< "The Element =";
                cin>> element;
                l.insertlast(element);
            }
            else if (choice == 3)
            {
                cout <<"The position =";
                cin >> pos;
                cout<< "The Element =";
                cin>> element;
                l.insertAtPos(pos, element);
            }
                    
            else 
            {
                throw "wrong!";
            }

        }
        catch(char const*e)
        {
            cout <<"ERROR : "<<e<<'\n';
        }
        l.print();
        cout<< "\nDo you want to Exit ";
        cin >> Exit;
    } while (Exit != "yes");

break;
        
case 2:
    cout << "Firstly Add 3 element to Stack: "<<"\n";
    for (int i=1; i < 4;i++)
    {
        cout << "Enter The Element number "<<i<< ":";
        cin>> element;
        s.push(element);
    }
    s.print();

    do
    {
        cout << "\npress 1 to Push Element on TOP || 2 to Pop element from Top:";
        try 
        {
            cin >> choice;
            if(choice == 1)
            {
                cout << "The Element = ";
                cin >> element;
                s.push(element);
            }
            else if (choice == 2)
            {
                s.pop();
            }
            else 
            {
                throw "Out of Range!\n";
            }
        }
        catch(char const*e)
        {
            cerr << "\nError : "<< e <<endl;
        }
        s.print();
    cout << "\nDo you want to Exit? || type (yes) to exit or (no) to continue :";
    cin >> Exit;
    } while (Exit != "yes");

break;

case 3:
    cout << "Firstly Add 3 element to Queue: "<<"\n";
    for (int i=1; i < 4;i++)
    {
        cout << "Enter The Element number "<<i<< ":";
        cin>> element;
        q.addQueue(element);
    }
    q.printQueue();

    do
    {
        cout << "\npress 1 to add Element on Queue || 2 to Queue element from Queue:";
        try 
        {
                cin >> choice;
            if(choice == 1)
            {
                cout << "The Element = ";
                cin >> element;
                q.addQueue(element);
            }
            else if (choice == 2)
            {
                q.deleteQueue();
            }
            else 
            {
                throw "Out of Range!\n";
            }
        }
        catch(char const*e)
            {
                cerr << "\nError : "<< e <<endl;
            }
            q.printQueue();
    cout << "\nDo you want to Exit? || type (yes) to exit or (no) to continue :";
    cin >> Exit;
    } while (Exit != "yes");

break;

default:
    cout << "Something went wrong!";
    break;  

}

return 0;
}
    