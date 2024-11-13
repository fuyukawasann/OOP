//
// Created by 이한별 on 24. 10. 30.
//

#include <iostream>
#include "Number.h"
#include "Fraction.h"
#include "ComplexFraction.h"

using namespace std;

template<class T>
class Node
{
public:
    Node<T>();
    T getData();
    void setData(T newData);
    Node * getNext();
    void setNext(Node* next);

private:
    T data;
    Node *next;
};

template<class T>
Node<T>::Node()
{
    next = nullptr;
}

template<class T>
T Node<T>::getData()
{
    return data;
}

template <class T>
void Node<T>::setData(T newData)
{
    data = newData;
}

template <class T>
Node<T>* Node<T>::getNext()
{
    return next;
}

template <class T>
void Node<T>::setNext(Node* newNext)
{
    next = newNext;
}


template <class T>
class Stack
{
public:
    Stack();
    ~Stack();
    void push(T newData);
    T pop();

private:
    Node<T>* head;
};

template <class T>
Stack<T>::Stack()
{
    head = nullptr;
}

template <class T>
Stack<T>::~Stack(){};

template <class T>
void Stack<T>::push(T newData)
{
    Node<T>* newHead = new Node<T>;
    newHead->setNext(head);
    newHead->setData(newData);
    head = newHead;
}

template <class T>
T Stack<T>::pop()
{
    T result = head->getData();
    Node<T>* oldHead = head;
    head = head->getNext();
    delete oldHead;
    return result;
}

int main()
{
    Stack<int> s1;

    s1.push(5);
    s1.push(7);
    cout << s1.pop() << endl;
    cout << s1.pop() << endl;


    Stack<Fraction> s2;
    Fraction f1;
    f1.setDenominator(11).setNumerator(4);
    s2.push(f1);
    f1.setDenominator(3).setNumerator(7);
    s2.push(f1);
    s2.pop().print();
    cout << endl;
    s2.pop().print();
    cout << endl;

    Stack<Number *> s3;

    Fraction f2;
    ComplexFraction cf1;

    f2.setNumerator(7).setDenominator(5);
    cf1.setReal(f1).setImaginary(f2);
    s3.push(&cf1);
    s3.push(&f2);

    /* Test Part */
    // Fraction *f3 = dynamic_cast<Fraction*>(s3.pop());
    // if(!f3) cout << "f3 is a null ptr" << endl;
    // if(f3) {f3->print(); cout << endl;}
    // ComplexFraction* cf2 = dynamic_cast<ComplexFraction*>(s3.pop());
    // if(!cf2) cout << "cf1 is a null ptr" << endl;
    // if(cf2) {cf2->print(); cout << endl;}
    // Number* n1 = s3.pop();
    // if(!n1) cout << "n1 is a null ptr" << endl;
    // if(n1) {n1->print(); cout << endl;}


    /* Custom Test */
    // Make ComplexFracton Stack
    Stack<ComplexFraction *> s4;
    s4.push(&cf1);
    ComplexFraction cf3;
    cf3.setReal(f2).setImaginary(f1);
    s4.push(&cf3);

    // Comp -> Frac
    // Fraction *f4 = dynamic_cast<Fraction*>(s4.pop());
    // if(!f4) cout << "f4 is a null ptr" << endl;
    // if(f4) {f4->print(); cout << endl;}
    // ComplexFraction *cf4 = s4.pop();
    // if(!cf4) cout << "cf4 is a null ptr" << endl;
    // if(cf4) {cf4->print();cout << endl;}
    Number * n2 = dynamic_cast<Number*>(s4.pop());
    if(!n2) cout << "n2 is a null ptr" << endl;
    if(n2) {n2->print(); cout << endl;}



    cout << endl;

    return 0;
}


