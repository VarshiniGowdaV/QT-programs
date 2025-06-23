#ifndef MYCLASS_H
#define MYCLASS_H
template <typename T>

class Class
{
public:
    Class(T* ptr);
    ~Class();
    T* getPtr();
    T* operator->();

private:
    T* m_ptr;
};

#endif // MYCLASS_H
