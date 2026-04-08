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
    Chain<T> & Delete(int k);
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
        out<<current->data<<" ";
    }
}
template <class T>
ostream& operator<<(ostream& out, const Chain<T>& x){
    x.Output(out);
    return out;
}
  template <class T>
Chain<T>& Chain<T>::Insert(int k, T& x) {
    if (k < 0 || k > Length()) {
        cout << "Invalid position" << endl;
        return *this;
    }

    ChainNode<T>* newNode = new ChainNode<T>;
    newNode->data = x; 
    if (k == 0) {
        newNode->link = first;
        first = newNode;
    }
    else {
        ChainNode<T>* p = first;
 
        for (int i = 1; i < k; i++) {
            p = p->link;
        }

        newNode->link = p->link;
        p->link = newNode;
    }

    return *this;
}
template <class T>
Chain<T> & Chain<T>::Delete(int k){
   if(k<1 || !first){
    return *this;
   }
   ChainNode<T> * p = first;
   ChainNode<T> * q = first;
   if(k == 1){
    first = first->link;
    return *this;
   }
   else{
    for(int i = 1;i<k-1 && p;i++){
        p =p->link;
    }
    if(p== NULL ||p->link == NULL){
        return *this;
    }
    q = p->link;
    p->link = q->link;
    delete q;

   }
   return *this;
}
int main()
{
    Chain<int> c;

    cout << "Initially:" << endl;
    cout << "Is empty? " << c.isempty() << endl;
    cout << "Length = " << c.Length() << endl;

    int a = 10, b = 20, d = 30, e = 15;
 
    c.Insert(0, a);   
    c.Insert(1, b);   
    c.Insert(2, d);  
    c.Insert(1, e);   

    cout << "\nAfter insertion:" << endl;
    cout << "List: ";
    c.Output(cout);
    cout << endl;

    cout << "Length = " << c.Length() << endl;

    int x;
 
    if (c.Find(1, x))
        cout << "1st element = " << x << endl;
    else
        cout << "1st element not found" << endl;

    if (c.Find(2, x))
        cout << "2nd element = " << x << endl;
    else
        cout << "2nd element not found" << endl;

    if (c.Find(4, x))
        cout << "4th element = " << x << endl;
    else
        cout << "4th element not found" << endl;

    if (c.Find(5, x))
        cout << "5th element = " << x << endl;
    else
        cout << "5th element not found" << endl;


    cout<<c<<endl;
    c.Delete(2);
    cout<<c;
    return 0;
}