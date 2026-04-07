#include<iostream>
using namespace std;
template <class T>
class ChainNode{
    friend Chain<T>;
    private:
    T data;
    ChainNode<T> * link;
};
template <class T>
class Chain{
    public:
    Chain(){}
    ~Chain();
    bool isempty() const{ return first == 0;}
    int Length() const;
    bool Find(int k ,T&x)const;
    int Search(const T& x) const;
    Chain<T> & Delete(int k,T&x);
    Chain<T> & Insert(int k,T&x);
    void Output(onstream& out) const;
    private:
    ChainNode<T> * first;
};
int main()
{
    
    return 0;
}