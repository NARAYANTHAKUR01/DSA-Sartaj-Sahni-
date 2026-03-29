/* Insertion sort*/
#include<iostream>
using namespace std;

template <class T>
void insertion_sort(T arr[],int n){

    for(int i = 0;i<n;i++){
        int key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}
int main()
{
    int arr[] = {5,11,2,65,1,25,8};
    insertion_sort(arr,7);
    for (int i = 0; i < 7; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}
 /*
 #include<iostream>
using namespace std;

template <class T>
void insertion_sort(T arr[], int n){

    for(int i = 1; i < n; i++){
        T key = arr[i];
        int j;

        for(j = i - 1; j >= 0; j--){
            if(arr[j] > key){
                arr[j + 1] = arr[j];   
            }
            else{
                break;  
            }
        }

        arr[j + 1] = key;
    }
}

int main(){
    int arr[] = {5,11,2,65,1,25,8};
    insertion_sort(arr,7);

    for(int i = 0; i < 7; i++){
        cout << arr[i] << " ";
    }

    return 0;
}*/