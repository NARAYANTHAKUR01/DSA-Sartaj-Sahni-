#include<iostream>
using namespace std;
template <class T>
void ranking(T arr[],int n,int r[]){
 
for(int i = 1 ;i<n;i++){
    for(int j = 0;j<i;j++){
       if(arr[j]<=arr[i]){
         r[i]++;}
       else{
        r[j]++;
       }
    }
}  
}
template <class T>
void ranksort(T a[],int n,int b[]){
    int i = 0;
    while(i !=n){
      if(i!=b[i]){
        swap(a[i],a[b[i]]);
        swap(b[i],b[b[i]]);
      }
      else{
        i++;
      }
    }
}


int main()
{   int arr[] = {8,2,1,11,5};
    int rank[] = {0,0,0,0,0};

    ranking(arr,5,rank);
    ranksort(arr,5,rank);
    for (int i = 0; i < 5; i++)
    { 
        cout<<arr[i]<<" ";
    }
    
    return 0;
}