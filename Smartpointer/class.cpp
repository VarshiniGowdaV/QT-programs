#include "class.h"
#include "button.h"
#include<iostream>
using namespace std;

template <typename T>
Class<T>::Class(T *ptr1)
{
    cout<<"MyClass Constructor"<<endl;
    m_ptr = ptr1;
}

template <typename T>
Class<T>::~Class()
{
    delete m_ptr;
    cout<<"Deleted memory"<<endl;
}

template<typename T>
T *Class<T>::getPtr()
{
    return m_ptr;
}

template<typename T>
T *Class<T>::operator->()
{
    return m_ptr;
}

template class Class<Button>;
template class Class<int>;
template class Class<double>;

