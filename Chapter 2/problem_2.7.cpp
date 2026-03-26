/*selection sort*/
#include<iostream>
using namespace std;
template <class T>
void selectionsort(T arr[],int n){
    for (int i = 0; i < n; i++)
    {
     int min = i;
        for (int j= i+1; j < n; j++)
        {
            if(arr[i]>arr[j]){
                min = j;
            }
        }
        if(min !=i){
            swap(arr[min],arr[i]);
        }
        
    }
    
}
int main()
{
    float arr[] = {2.1,6.20,8.6,7,4};
    selectionsort(arr,5);
    for(int i = 0;i<5;i++){
        cout<<arr[i];
    }
    return 0;
}