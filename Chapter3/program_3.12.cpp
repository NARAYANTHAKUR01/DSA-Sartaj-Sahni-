#include<iostream>
using namespace std;
template <class T>
class Chain;

template <class T>
class ChainNode{
    friend class Chain<T>;
    private:
    T data;
    ChainNode<T> * link;
};
template <class T>
class Chain{
    public:
    Chain() { first = NULL; }
    ~Chain();
    bool isempty() const{ return first == 0;}
    int Length() const;
    bool Find(int k ,T&x)const;
    int Search(const T& x) const;
    Chain<T> & Delete(int k,T&x);
    Chain<T> & Insert(int k,T&x);
    void Output(ostream& out) const;
    private:
    ChainNode<T> * first;
};
template <class T>
Chain<T>::~Chain(){
    ChainNode<T> * next;
    while(first){
        next = first->link;
        delete first;
        first = next;
    }
}

template <class T>
int Chain<T>::Length() const{
    ChainNode<T> * current = first;
    int len = 0;
    while(current){
        len++;
        current = current->link;
    }
    return len;
}
template <class T>
bool Chain<T>::Find(int k,T&x) const{
    if(k<1) return false;
    ChainNode<T> * next = first;
    int index = 1;
    while(next && index<k){
        next = next->link;
        index++;
    }
    if(next){
        x = next->data;
        return true;
    }
    return false;
}
template <class T>
void Chain<T>::Output(ostream&out) const{
    ChainNode<T> * current;
    for(current = first;current;current = current->link){
        cout<<current->data<<" ";
    }
}
template <class T>
ostream operator<<(ostream& out,const Chain<T> &x){
    x.Output(out);
    return out;
}
int main()
{
    Chain<int> c;

    cout << "Is empty? " << c.isempty() << endl;
    cout << "Length = " << c.Length() << endl;

    int x;
    if (c.Find(1, x))
        cout << "Found: " << x << endl;
    else
        cout << "Element not found" << endl;
    
    return 0;
}