#include <iostream>

using namespace std;

int main()
{
    int a,i;
    char o,p,Z,X ;
    cout<<o<<"Name: ";  //اخرج أسم الطالب
    cin>>o;             //ادخل أسم الطالب
    cout<<i<<"number: /n"; //يخرج رقم الطالب
    cin>>i;               //أدخل رقم الطالب
    cout<<p<<"Department: comuter /n"; //يخرج قسم الطالب
    cin>>p;                             //أدخل قسم الطالب
    if(p==Z)                            //اذ كانت p تساوي z

        cout<<"control";                 //يخرج قسم التحكم
    else
        cout<<"communications";           //يخرج قسم الإتصالات

    cout<<a<<"Appreciation: ";            //يخرج تقدير الطالب في مادة
    cin>>a;                               //ادخل درجة الطالب
    if((a>=90)&&(a)<=100)       //إذا كانت الدرجة أكبر من أو تساوى 90 و وأقل من او تساوى 100
        cout<<'A';               //أخرج A 
    else if((a>=80)&&(a)<90)
        cout<<'B';
    else if((a>=70)&&(a)<80)
        cout<<'C';
    else if((a>=60)&&(a)<70)
        cout<<'D';
    else if((a>=50)&&(a)<60)
        cout<<'F';
    else
        cout<<'F-';
    return 0;
}
