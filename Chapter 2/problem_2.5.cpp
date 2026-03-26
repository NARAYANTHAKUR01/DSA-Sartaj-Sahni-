/*calculating rank*/
#include <bits/stdc++.h>
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
int main(){
   int arr[] = {4,3,9,3,7};
   int r[] = {0,0,0,0,0};
   ranking(arr,5,r);
   for(int i = 0;i<5;i++)
   cout<<r[i]<<",";
    return 0;
}