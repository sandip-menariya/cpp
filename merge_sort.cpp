#include<iostream>

using namespace std;

void merge(int arr[],int low,int mid,int high)
{
    int n=(high-low)+1,narr[n];
    int k=0,i=low,j=mid+1;
    while(i<=mid && j<=high)
    {
        if(arr[i]<=arr[j])
        {
            narr[k++]=arr[i++];
        }
        else
        {
            narr[k++]=arr[j++];
        }
    }
    while(i<=mid)
    {
        narr[k++]=arr[i++];
    }
    while(j<=high)
    {
        narr[k++]=arr[j++];
    }
    for(int i=0;i<n;i++)
    {
        arr[i+low]=narr[i];
    }
}

void merge_sort(int arr[],int low,int high)
{
    if(low<high)
    {
        int mid=(high+low)/2;
        merge_sort(arr,low,mid);
        merge_sort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}

int main()
{
    int arr[]={12,3,46,8,12,2,10,47,52,1,4,18,23,76,32,0};
    int high=sizeof(arr)/sizeof(arr[0]);
    merge_sort(arr,0,high-1);
    cout<<"sorted array: \n";
    for(int i=0;i<high;i++)
    {
        cout<<arr[i]<<"\t";
    }
    return 0;
}