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
        current = current->next;
    }
    return len;
}
int main()
{
    
    return 0;
}