#ifndef EXTRACREDIT_H
#define EXTRACREDIT_H
#include "vector.h"
#include "shape.h"
#include <QDebug>

struct Cmp_by_id {
    bool operator()(const shape* s1, const shape* s2) const
    {
        return s1->getShapeID() < s2->getShapeID();
    }
};

struct Cmp_by_perimeter
{
    bool operator()(const shape* s1, const shape* s2) const
    {
        return s1->perimeter() < s2->perimeter();
    }
};

struct Cmp_by_area
{
    bool operator()(const shape* s1, const shape* s2) const
    {
        return s1->area() < s2->area();
    }
};

template<typename Iterator, typename Predicate>
void selection_sort(Iterator first, Iterator last, Predicate pred)
{
    Iterator lead = first;
    Iterator follow = first;
    Iterator temp = new shape*;

    while(lead != last - 1)
   {
       ++lead;
       if(pred(*lead, *follow))
       {
           *temp = *lead;
           *lead = *follow;
           *follow = *temp;

           lead = first;
           follow = first;
       }
       else
       {
           ++follow;
       }
   }
    delete temp;
}


#endif // EXTRACREDIT_H
