 #include <iostream>
using namespace std;

template <class T>
class LinearList {
private:
    int MaxSize;
    int length;
    T* element;

public:
    LinearList(int MaxListSize);
    bool Find(int k, T& x) const;
    int Search(const T& x) const;
    bool Insert(int k, const T& x);
    bool Delete(int k, T& x);
    void Display() const;
};

// Constructor
template <class T>
LinearList<T>::LinearList(int MaxListSize) {
    MaxSize = MaxListSize;
    element = new T[MaxSize];
    length = 0;
}

// Find
template <class T>
bool LinearList<T>::Find(int k, T& x) const {
    if (k < 1 || k > length)
        return false;

    x = element[k - 1];
    return true;
}

// Search
template <class T>
int LinearList<T>::Search(const T& x) const {
    for (int i = 0; i < length; i++) {
        if (element[i] == x)
            return i + 1;
    }
    return 0;
}

// Insert
template <class T>
bool LinearList<T>::Insert(int k, const T& x) {
    if (k < 1 || k > length + 1 || length == MaxSize)
        return false;

    for (int i = length - 1; i >= k - 1; i--) {
        element[i + 1] = element[i];
    }

    element[k - 1] = x;
    length++;
    return true;
}

// Delete
template <class T>
bool LinearList<T>::Delete(int k, T& x) {
    if (k < 1 || k > length)
        return false;

    x = element[k - 1];

    for (int i = k; i < length; i++) {
        element[i - 1] = element[i];
    }

    length--;
    return true;
}

// Display
template <class T>
void LinearList<T>::Display() const {
    cout << "List elements: ";
    for (int i = 0; i < length; i++) {
        cout << element[i] << " ";
    }
    cout << endl;
}

// Main
int main() {
    LinearList<int> list(5);

    list.Insert(1, 10);
    list.Insert(2, 20);
    list.Insert(3, 30);
    list.Insert(4, 40);

    cout << "Original list:" << endl;
    list.Display();

    int value;
    if (list.Find(3, value))
        cout << "Element at position 3: " << value << endl;
    else
        cout << "Invalid position!" << endl;

    int pos = list.Search(20);
    if (pos != 0)
        cout << "Element 20 found at position: " << pos << endl;
    else
        cout << "Element not found!" << endl;

    int deletedValue;
    if (list.Delete(2, deletedValue))
        cout << "Deleted element: " << deletedValue << endl;
    else
        cout << "Deletion failed!" << endl;

    cout << "List after deletion:" << endl;
    list.Display();

    return 0;
}