#include<iostream>

using namespace std;

class X
{
    protected:
    int x,y;
    void setfunc(int i,int j){x=i,y=j;};
    public:
    virtual void func()=0;
    void print()
    {
        cout<<"the value of x is: "<<x<<" y is: "<<y;
    }
};

class Y:public X
{
    public:
    void func()override
    {
        cout<<"hello";
    }
    void getfunc(int a,int b)
    {
        setfunc(a,b);
    }
    void getm(Y &obj)
    {
        cout<<obj.x<<"\t"<<obj.y<<endl;
    }
};

int main()
{
    Y obj;
    obj.getfunc(5,10);
    obj.print();
    Y obj2;
    obj2.getm(obj);
    return 0;
}