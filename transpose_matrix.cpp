#include<iostream>

using namespace std;

int main()
{
    int arr[][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    int row=sizeof(arr)/sizeof(arr[0]);
    int col=sizeof(arr[0])/sizeof(arr[0][0]),k=0;
    cout<<row<<" "<<col<<endl;
    int new_arr[col][row];
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            new_arr[j][i]=arr[i][j];
        }
    }
    cout<<"Transpose:"<<endl;
    for(int i=0;i<col;i++)
    {
        for(int j=0;j<row;j++)
        {
            cout<<new_arr[i][j]<<"\t";
        }
        cout<<endl;
    }
    return 0;
}