#include <iostream>
using namespace std;
template <class T>
int sequential_search(T a[],int n,T k){
   for (int i = 0; i < n; i++){
         if(a[i] == k ){
            return i+1;
         }
   } 
   return -1;
   
}
int main(){
    int arr[] = {1,2,4,68,9,1,33};
    int s = 1;
    int n = 7;
    cout<<sequential_search(arr,n,s);

    return 0;
}