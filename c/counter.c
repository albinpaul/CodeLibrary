#include <stdio.h>
using namespace std;

 void quickSort(int a[], int first, int last)
{
    int start=first,end=last;
    int mid= (first+last)/2;
    int temp;
    while(start<=end)
    {
        while(a[start]<a[mid])
        {
            start=start+1;
        }
        while(a[end]>a[mid])
        {
            end=end-1;
        }
        if(start<=end)
        {
            temp=a[start];
            a[start]=a[end];
            a[end]=temp;
            start++;
            end--;
        }
    }
    if(first<end)
    {
        quickSort(a,first,end);
    }
    if(start<last)
    {
        quickSort(a,start,last);
    }
}
int main(){
  int a[]={0,3,2};
  quickSort(a,0,4);
  for(int i =0;i<3;i++){
    cout<<a[i]<<" "<<endl;
  }
}