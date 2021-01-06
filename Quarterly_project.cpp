/*My name: النيل ابو القاسم ابراهيم النور
    Class: الفرقة الثانية 
Department: الحاسوب
*/
#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
struct Node
{
    string firstName;
    string lastName;
    string phoneNumber;
    string contactEmail;
    string contactNumber;
    string item; 
    Node*next;
};
class linkedlist{
private:
    Node first;
    Node last;
    Node number;
    Node email;
public: 
    linkedlist(){
    
    first=last =NULL;

    }

    void insert_contact(string = &first, string = &last, string = &number, string = &email ) //دالة إنشاء عقدة إضافتها إلي  القائمة
    {
        Node *temp = new Node ;
        temp ->firstName = first;
        temp ->lastName = last;
        temp ->phoneNumber = number ;
        temp ->contactEmail = email ;
        temp ->next = NULL;
        if (first = NULL)
        {
            first = temp;
            last = temp;
            temp = NULL;
        }
        else {
            last->next = temp;
            last = temp;
        }
        
    }

    void display_all() // دالة طباعة 
    {
        int coutactNumber = 1;
        Node *temp = new Node;
        temp= first;
        while (temp != NULL) //تكرار القائمة عنما العقدة المؤقتة ليس فارقة
        {
            //cout << "\nContect Number : " << 'contactNumber' << endl;
            cout << "first Name : " << temp->firstName << endl;
            cout << "last Name : " << temp->lastName << endl;
            cout << "phone Number : " << temp->phoneNumber << endl;
            cout << "Contect Email : " << temp->contactEmail << endl;
          //  ++contactNumber;
            temp = temp->next;
        }
    }
    void delete_position(int pos)//حذف نقطة باستخدام الموضع في القائمة
    {
        Node *current = new Node;
        Node *previous = new Node;
        Node *next = new Node;
        current = first;
        for (int i = 1; i<pos;i++)//تكرار القائمة عندما العقدة ليست فارقة
        {
            if (current = NULL)
                return;
            previous = current;
            current = current->next;
        }
        next = current->next;
        previous->next = current->next;
        delete current;
    }
    void delete_first()//حذف عقدة الرأس
    {
        Node* temp = new Node;
        temp = first;
        first = first->next;
        delete temp;
    } 

};
int main(){
    linkedlist Contacts; //  دالة إنشاء كائن عنصر جهات الاتصال  
    int choice, position;
    string firstName;
    string lastName;
    string phoneNumber;
    string Email;

    while (1){
        cout << "\n<<<<<< Minu >>>>>> " << endl;
        cout << "1. Show All Contacts" << endl;
        cout << "2. Add New Contact" << endl;
        cout << "3. Remove Contact" << endl;
        cout << "4. Edit Contacts" << endl;
        cout << "5. Exit The program " << endl;
        cout << " Enter The Nuber of Opration" ;
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << endl;
                Contacts.display_all();//عرض كافة جهات الاتصال
                cout << endl;
                break;
            case 2:
                cout << "\nEnter First Name ";
                cin >> firstName;
                cout << "\nEnter Last Name ";
                cin >> lastName;
                cout << "\nEnter phone Number ";
                cin >> phoneNumber;
                cout << "\nEnter Email  ";
                cin >> Email ;
                Contacts.insert_contact(firstName, lastName, phoneNumber, Email);//قم بإنشاء جهة الاتصال في القائمة المرتبطة
                cout << endl;
                break;
            case 3:
                cout << "Enter The contact number of the contact you would likedlast to remove ";
                cin >> position ;
                if (position == 1)
                    Contacts.delete_first();
                else
                    Contacts.delete_position(position);//حذف جهات إتصال من القائمة
                break;
            case 4:
                exit(1);
                break;
            
        }

    }
    return 0;

}