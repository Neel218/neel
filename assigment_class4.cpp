/*
Name : النيل ابو القاسم ابراهيم النور
Department : الحاسوب
Class : الفرقة الثانية
*/
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class Shape // كلاس أب مجرد 
{
protected:  // تعمل تغليف
    float pi = 3.14; 
    int radius;
    int  width;
    int height;
public:
    void set_Width() //دالة ادخال قيمة القاعدة
    {
        cout << "Width =";
        cin >> width;
    }
    void set_Height() //دالة ادخال قيمة الطول 
    {
        cout << "Height =";
        cin >> height;
    }
    void set_Radius() //دالة ادخال قيمة القطر
    {
        cout << "Radius =";
        cin >> radius;
    }
    virtual int area(void)=0;

    void printArea(void) //دالة تعويض دوال المساحة لكل الكلاسات الوارثة ثم طباعتها
    {
        cout << "The Area =\n";
        cout<< this->area()<<"\n";
    }
    virtual int Ocean(void)=0; 

    void printOcean(void) //دالة تعويض دوال المحيطات لكل الكلاسات الوارثة ثم طباعته
    {
        cout<< "The Ocean =\n";
        cout<< this->Ocean() <<"\n";
    }
};
class Polygon : public Shape
{
 public:
    int area() //دالة حساب مساحة المضلع 
    {
        return (radius * width * height);
    }
    int Ocean() //دالة حساب محيط المضلع
    {
        return (width * height);
    }
};
class Triangle : public Polygon //كلاس المثلث يرث من كلاس المضلع وراثة عامة 
{
public : 
    int area() //دالة حساب مساحة المثلث
    {
        return (0.5*width*height);
    }
    int Ocean() //دالة حساب محيط المثلث 
    {
       return (width + height*2);
    }
  };  
class Rectangl : public Polygon //كلاس المستطيل يرث من كلاس المضلع وراثة عامة
{
public : 
    int area() //دالة حساب مساحة المستطيل 
    {
        return (width*height);
    }
    int Ocean() //دالة حساب محيط المستطيل
    {
        return (2*width+2*height);
    }
};
class Square : public Polygon //كلاس المربع يرث من كلاس المضلع وراثة عامة
{
public : 
    int area() //دالة حساب مساحة المربع
    {
        return (height * height);
    }
    int Ocean () // دالة حساب محيط المربع
    {
        return (4*height);
    }
};
class Ellipse : public Shape // كلاس الشكل البيضاوي يرث من الكلاس الأب وراثة عامة
{
public : 
    int area() //دالة حساب مساحة الشكل البيضاوي 
    {
        return (pi * width * height);
    }
    int Ocean() //دالة حساب محيط الشكل البيضاوي
    {
        return (pi*(radius*radius));
    }
};
class Circle : public Ellipse //كلاس الدائرة يرث كلاس الشكل البيضاوي وراثة عامة
{
    public :
    int area () //دالة حساب مساحة الدائرة
    {
        return (pi/4*(radius*radius));
    }
    int Ocean () //دالة حساب محيط الدائرة
    {
        return (pi*radius);
    }
};

int main() 
{
    Polygon pol ;
    Triangle tria ; 
    Rectangl rect ;
    Square squ ;
    Ellipse ell ;
    Circle cir ;

    Shape *pointer1 = &pol;     //تعريف المؤشر الاول من الكلاس الاب وربطة بكائن عنوان كلاس المضلع
    Shape *pointer2 = &ell;     //تعريف المؤشر الثانى ل من الكلاس الاب وربطة بكائن عنوان كلاس  الشكل البيضاوي
    Polygon *pointer3 = &tria;  //تعريف المؤشر الثالث من كلاس المضلع وربطة بكائن عنوان كلاس المثلث
    Polygon *pointer4 = &rect;  //تعريف المؤشر الرابع من كلاس المضلع وربطة بكائن عنوان كلاس المستطيل
    Polygon *pointer5 = &squ;   //تعريف المؤشر الخامس من كلاس المضلع وربطة بكائن عنوان كلاس المربع
    Ellipse *pointer6 = &cir;   //تعريف المؤشر السادس من كلاس المضلع وربطة بكائن عنوان كلاس الدائرة

    cout << "------Find Area and Ocean of Shapes------\n";

    cout << "\n enter the value of polypon's width , height and Radius :\n";
    pointer1->set_Width();
    pointer1->set_Height();
    pointer1->set_Radius();

    cout << "\n enter the value of Ellipse's width , height and Radius :\n";
    pointer2->set_Width();
    pointer2->set_Height();
    pointer2->set_Radius();

    cout << "\n enter the value of Triangle's width , height and Radius :\n";
    pointer3->set_Width();
    pointer3->set_Height();

    cout << "\n enter the value of Rectangle's width , height  :\n";
    pointer4->set_Width();
    pointer4->set_Height();

    cout << "\n enter the value of Square's height :\n";
    pointer5->set_Height();

    cout << "\n enter the value of Circle's Radius :\n";
    pointer6->set_Radius();

    cout<< "\n >>> THE FINL RESULT <<< \n";

    cout << "\nTHE POLYGON :\n"; //نتيجة المضلع
    pointer1->printArea();
    pointer1->printOcean();
    
    cout<< "\nTHE ELLIPSE :\n"; //نتيجة الشكل البيضاوي
    pointer2->printArea();
    pointer2->printOcean();

    cout << "\nTHE TRIANGLE :"; // نتيجة المثلث
    pointer3->printArea();
    pointer3->printOcean();

    cout << "\nTHE RECTANGL :\n"; //نتيجة المستطيل
    pointer4->printArea();
    pointer4->printOcean();

    cout << "\nTHE SQUARE :\n"; //نتيجة المربع
    pointer5->printArea();
    pointer5->printOcean();

    cout << "\nCIRCLE :\n"; //نتيجة الدائرة
    pointer6->printArea();
    pointer6->printOcean();

}
