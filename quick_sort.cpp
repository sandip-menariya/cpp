#include<iostream>

using namespace std;

int partition(int arr[],int low,int high)
{
    int pivot=arr[low];
    int i=low+1,j=high;
    do
    {
        while (arr[i]<=pivot)
        {
            i++;
        }
        while (arr[j]>=pivot)
        {
            j--;
        }
        if(i<j)
        {
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    } while (i<j);
    arr[low]=arr[j];
    arr[j]=pivot;
    return j;    
}

void quick_sort(int arr[],int low,int high)
{
    if(low<high)
    {
        int partitionn=partition(arr,low,high);
        quick_sort(arr,low,partitionn-1);
        quick_sort(arr,partitionn+1,high);
    }
}

int main()
{
    int arr[]={12,3,46,8,12,2,10,47,52,1,4,18,23,76,32,0};
    cout<<sizeof(arr)<<endl;
    cout<<sizeof(arr[0])<<endl;
    int high=sizeof(arr)/sizeof(arr[0]);
    quick_sort(arr,0,high-1);
    cout<<"sorted array: \n";
    for(int i=0;i<high;i++)
    {
        cout<<arr[i]<<"\t";
    }
}