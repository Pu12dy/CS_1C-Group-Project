#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H


#include<string>
#include<exception>
using namespace std;

class outOfBounds: public exception
{
public:
    const char* what() const throw()
    {
        return "Index out of Bounds!\n";
    }
};

class invalidSize: public exception
{
public:
    const char* what() const throw()
    {
        return "Invalid resize/reserve!\n";
    }
};

class iteratorOutOfBounds: public exception
{
public:
    const char* what() const throw()
    {
        return "Iterator out of bounds!\n";
    }
};

class fileNotFound : public exception
{
public:
    const char* what() const throw()
    {
        return "Error opening file!\n";
    }
};

#endif
