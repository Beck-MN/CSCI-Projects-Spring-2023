/*
@problem FrontList ADT
@author Beck Christensen
@starID rg6291gh
@duedate 3.26.2023
@instructor Jie Meichsner 
*/
#ifndef FRONT_LIST
#define FRONT_LIST

template<class ItemType>
class FrontList {
public:
    virtual bool insert(const ItemType& newEntry) = 0;
    virtual bool remove() = 0;
    virtual ItemType retrieve() const = 0;
	virtual void clear() = 0;
    virtual ~FrontList() {}
};

#endif