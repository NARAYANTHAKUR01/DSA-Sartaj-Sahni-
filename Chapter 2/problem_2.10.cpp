#include<iostream>
using namespace std;

template <class T>
void insertion_in_sortedarray(T a[], int n, T key){
    int i = n - 1; 
    while(i >= 0 && a[i] > key){
        a[i+1] = a[i];
        i--;
    }
 
    a[i+1] = key;
}

int main()
{
    int a[6] = {1,2,3,6,7}; 
    insertion_in_sortedarray(a, 5, 4);

    for (int i = 0; i < 6; i++)
    {
       cout << a[i] << " ";
    }

    return 0;
}
/*#include<iostream>
#include<vector>
using namespace std;

template <class T>
void insert_sorted(vector<T>& v, T key){
    int i = v.size() - 1;
 
    v.push_back(key);
  
    while(i >= 0 && v[i] > key){
        v[i+1] = v[i];
        i--;
    } 
    v[i+1] = key;
}

int main(){
    vector<int> v = {1,2,3,6,7};

    insert_sorted(v, 4);

    for(auto x : v){
        cout << x << " ";
    }

    return 0;
}*/