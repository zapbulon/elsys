#include <exception>
#include <iostream>

using namespace std;

template <class T> class stack {
    static const unsigned size_ = 16;
    T data_[size_];
    int top_ ;
public :
    stack();
    T top () const ;
    void pop();
    void push(T val);
    bool empty() const;

    void print();
};

template <class T> stack<T>::stack() : top_(-1) {};

template <class T> T stack<T>::top() const {
    if (top_ < 0) {
        throw exception();
    }

    return data_[top_];
}

template <class T> void stack <T>::pop(void) {
    if (top_ < 0) {
        throw exception();        
    }

    top_--;
}

template <class T> void stack<T>::push(T val) {
    if (size_ <= top_+1) {
        throw std::exception();
    }

    data_[++top_] = val;
}

template <class T> bool stack<T>::empty(void) const {
    return top_ < 0;
}

template <class T> void stack<T>::print() {
    cout << "The current stack content is:" << endl;
    
    for (T value: data_) {
        cout << value << " ";
    }

    cout << endl;
}