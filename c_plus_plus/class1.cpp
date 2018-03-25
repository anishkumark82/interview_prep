#include<iostream>
using namespace std;

class DateClass
{
    int date;
    int month;
    int year;

    public:
    DateClass():
        date(1),
        month(1),
        year(1970)
    {
    }
    DateClass(int dd, int mm, int yy):
        date(dd),
        month(mm),
        year(yy)
    {
    }
    DateClass(const DateClass &d):
        date(d.date),
        month(d.month),
        year(d.year)
    {
        cout<<"Copy Constructor : "<<__func__<<endl;
    }
    void print()
    {
        cout<<date<<"-"<<month<<"-"<<year<<endl;
    }
    // Can use a copy constructor for this
    void copyFrom(const DateClass &d)
    {
        // Can access private data of all objects
        date = d.date;
        month = d.month;
        year = d.year;
    }
};

int main()
{
    DateClass x(15,3,2018);
    x.print();
    DateClass y;
    y.copyFrom(x);
    y.print();
    DateClass z(y);
    z.print();

    return 0;
}
