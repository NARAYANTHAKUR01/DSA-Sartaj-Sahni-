/*Bubble sort*/
#include<iostream>
using namespace std;
template <class T>
void bubblesort(T arr[],int n){
     for(int i =0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
     }
}
int main()
{
    int ar[] = {5,6,8,15,31,9,5};
    bubblesort(ar,7);
    for (int i = 0; i < 7; i++)
    {
        cout<<ar[i]<<" ";
    }
    
    return 0;
}