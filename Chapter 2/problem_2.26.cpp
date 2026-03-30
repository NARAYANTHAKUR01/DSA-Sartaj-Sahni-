/* max_min*/
#include<iostream>
using namespace std;
template <class T>
void min_max(T arr[],int n){
int min = -1;
int max = -1;
for(int i = 0;i<n;i++){
    if(arr[i]>max)  max = arr[i];
    if(arr[i]<min) min = arr[i];
}
cout<<"max "<<max;
cout<<"min "<<min; 
}    
int main()
{
    int arr[] = {1,2,3,4,5};
    min_max(arr,5);

    return 0;
}