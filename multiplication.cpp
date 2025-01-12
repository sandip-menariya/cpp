#include<iostream>

using namespace std;

int main()
{
    int arr1[][2]={{0,1},{2,3},{4,5}};
    int arr2[][3]={{6,7,8},{9,10,11}};
    int resm[3][3]={0};
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            for(int k=0;k<2;k++)
            {
                resm[i][j]+=arr1[i][k]*arr2[k][j];
            }
        }
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
           
               cout<<resm[i][j]<<"\t";

        }
        cout<<endl;
    }
    return 0;
}