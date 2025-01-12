#include<iostream>

using namespace std;



int main()
{
    int a,b,arr[5];
    cout<<"enter value of a :\n";
    cin>>a;
    cout<<"enter value of b :\n";
    cin>>b;
    try
    {
        if(b==0){
            throw runtime_error("cannot divide a value by zero\n");
        }
        else
        {
            a=a/b;
            cout<<a<<"\t";
        }
        try
        {
            cout<<"enter 5 values in array \n";
            for(int i=0;i<6;i++)
            {
                cin>>arr[i];
            }
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}