#ifndef VECTOR_H
#define VECTOR_H


#include<iostream>
#include<string>
#include"exceptions.h"

template<class T>
class Vector{
    //! Class: Vector
    //! A vector which approximates the stl vector
private:


    //! The number of elements stored in the vector
    int size_v;

    //! A pointer to the array holding the elements
    T* elem;

    //! The maximum storage of the vector
    int space;

public:
    //! Vector()
    //! Default constructor
    //! Sets size = 0
    //! Sets elem to point to nullptr
    //! Sets Space = 0
    Vector(): size_v{0}, elem{nullptr}, space{0}{}

    //! Vector(int s)
    //! Alternate constructor
    //! Sets size = 0
    //! Creates a new array of T objects of size s, the parameter
    //! Sets space = s
    explicit Vector(int s): size_v{0}, elem{ new T[s]}, space{s}{

    }

    //! Vector(const Vector& src)
    //! Copy constructor
    Vector(const Vector& src): size_v{src.size()}, elem{ new T[src.capacity()]}, space{src.capacity()}{// copy constructor

        for (int i = 0; i < size_v; i++)
        {
            elem[i] = src.elem[i];
        }

    }

    //! Vector(Vector&& src)
    //! Move constructor
    Vector(Vector&& src){
        elem = src.elem;
        size_v = src.size_v;

        src.elem = nullptr;
        src.size_v = 0;
    }

    //! Vector& operator=(const Vector& src)
    //! Copy assignment
    Vector& operator=(const Vector& src){
        delete[] elem;// free the old space

        size_v = src.size();// copy value of size
        space = src.capacity();// copy value of space
        elem = new T[space];// create new space

        for (int i = 0; i < size_v; i++)
        {
            elem[i] = src.elem[i];
        }

        return *this;
    }

    //! Vector& operator=(Vector&& src)
    //! Move assignment
    Vector& operator=(Vector&& src)
    {
        if(this != &src)
        {
            delete[] elem;

            elem = src.elem;
            size_v = src.size();
            space = src.capacity();

            src.elem = nullptr;
            src.size_v = 0;
            src.space = 0;

        }

        return *this;
    }

    //! ~Vector()
    //! Destructor
    ~Vector()
    {
        delete[] elem;
    }


    //! T& operator[](int n)
    //! Access: returns reference
    T& operator[](int n)
    {

        if (n < size_v)
        {
            return elem[n];
        }
        throw outOfBounds();

    }

    //! T* getArrayFromVector()
    //! Returns the elem pointer
    T* getArrayFromVector()
    {
        return elem;
    }

    //! const T& operator[](int n)
    //! Access: returns reference
    const T& operator[](int n) const
    {
        if (n < size_v)
        {
            return elem[n];
        }
        throw outOfBounds();
    }

    //! int size() const
    //! Returns the current size
    int size() const
    {
        return size_v;
    }

    //! int capacity() const
    //! Returns current available space
    int capacity() const{
        return space;
    }

    //! void resize(int newsize)
    //! Grows the vector and give default values to the new elements
    void resize(int newsize){
        reserve(newsize);
        for (int i = size_v; i < newsize; i++)
        {
            elem[i] = T();
        }
        size_v = newsize;
    }

    //! void push_back(T val)
    //! Adds element
    void push_back(T val){
        if (size_v == 0)// vector is empty
        {
            reserve(10);
        }
        else if (size_v == space)// vector is full
        {
            reserve(2 * space);
        }
        elem[size_v] = val;
        size_v++;
    }

    //! void reserve(int newalloc)
    //! Get more space
    void reserve(int newalloc){
        if (newalloc > space)
        {
            space = newalloc;
            T* newElem = new T[space];
            for (int i = 0; i < size_v; i++)
            {
                newElem[i] = elem[i];
            }
            delete[] elem;

            elem = newElem;
        }
        else
        {
            throw invalidSize();
        }

    }

    //! using iterator = T*
    //! Establishes that iterator is pointer of T type
    using iterator = T*;

    //! using const_iterator = T*
    //! Establishes that const_iterator is const pointer of T type
    using const_iterator = const T*;

    //! iterator begin()
    //! Points to first element
    //! Returns null pointer if no elements
    //! Else return the address of first element
    iterator begin(){
        if (size_v == 0)
        {
            return nullptr;
        }
        return &elem[0];
    }


    //! const_iterator begin() const
    //! Points to first element
    //! Returns null pointer if no elements
    //! Else return the address of first element
    const_iterator begin() const{

        if (size_v == 0)
        {
            return nullptr;
        }
        return &elem[0];

    }

    //! iterator end()
    //! Points to one past last element
    //! Returns null pointer if no elements
    //! Else returns one past last element
    iterator end(){

        if (size_v == 0)
        {
            return nullptr;
        }
        return &elem[size_v];
    }

    //! const_iterator end() const
    //! Points to one past last element
    //! Returns null pointer if no elements
    //! Else returns one past last element
    const_iterator end() const{
        // returns null pointer if no elements
        if (size_v == 0)
        {
            return nullptr;
        }
        return &elem[size_v];// Size_v is always 1 more than element index


    }

    //! iterator insert(iterator p, const T& v)
    //! Insert a new element v before p
    iterator insert(iterator p, const T& v){
        if (p < begin())
        {
            throw iteratorOutOfBounds();
        }
        if (size_v + 1 > space)// make sure theres space
        {
            reserve(2 * space);// give it more slots if there isnt enough space
        }
        for (iterator pos = end(); pos != p; --pos)// shift all elements to the right of 1
        {
            *pos = *(pos - 1);
        }
        *p = v;// write in v at p
        size_v++;

        return p;

    }

    //! iterator erase(iterator p)
    //! Remove element pointed to by p
    iterator erase(iterator p){
        if (p > end())//
        {
            throw iteratorOutOfBounds();
        }
        else if (p == end())
        {
            return p;
        }
        for (iterator pos = p + 1; pos != end(); ++pos)// start at p + 1 because iterators are equality comparative
        {
            *(pos - 1) = *pos;// shift elements to the left of p left
        }
        *(end() - 1) = T();// Set element at the end to default value
        size_v--;// decrease size
        return p;
    }
};



#endif
