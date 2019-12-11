#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H


#include<string>
#include<exception>
using namespace std;

//! Out of Bounds Exception
//! Returns the message:
//! Index out of Bounds!
class outOfBounds: public exception
{
public:
    const char* what() const throw()
    {
        return "Index out of Bounds!\n";
    }
};

//! Invalid Size Exception
//! Returns the message:
//! Invalid resize/reserve!
class invalidSize: public exception
{
public:
    const char* what() const throw()
    {
        return "Invalid resize/reserve!\n";
    }
};

//! Iterator Out of Bounds Exception
//! Returns the message:
//! Iterator out of bounds!
class iteratorOutOfBounds: public exception
{
public:
    const char* what() const throw()
    {
        return "Iterator out of bounds!\n";
    }
};

//! File Not Found Exception
//! Returns the message:
//! Error opening file!
class fileNotFound : public exception
{
public:
    const char* what() const throw()
    {
        return "Error opening file!\n";
    }
};

#endif
