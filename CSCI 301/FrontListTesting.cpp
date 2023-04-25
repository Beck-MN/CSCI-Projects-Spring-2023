/*
@problem Testing program for FrontList Programs (Project6)
@author Beck Christensen
@starID rg6291gh
@duedate 3.26.2023
@instructor Jie Meichsner 
*/
#include <iostream>
#pragma once
#include "FrontListInheritedPublic.h"
#include "FrontListInheritedPrivate.h"
#include "FrontListLinkedList.h"

void testFrontList(FrontList<int>* listPtr) {
    std::cout << "Testing FrontList implementation...\n";
	
    listPtr->insert(5);
    listPtr->insert(7);
    listPtr->insert(3);
    listPtr->insert(6);

    std::cout << "Retrieving first element: " << listPtr->retrieve() << std::endl;

    listPtr->remove();

    std::cout << "Retrieving first element after remove: " << listPtr->retrieve() << std::endl;

    listPtr->clear();
}

void testLinkedList(LinkedList<int>* listPtr) {
    std::cout << "Testing LinkedList implementation...\n";

    listPtr->insert(1,5);
    listPtr->insert(2,7);
    listPtr->insert(3,3);
	listPtr->insert(4,6);

    std::cout << "Retrieving first element: " << listPtr->getEntry(1) << std::endl;
    std::cout << "Retrieving third element: " << listPtr->getEntry(3) << std::endl;
    
	listPtr->remove(1);

    std::cout << "Retrieving first element after remove: " << listPtr->getEntry(1) << std::endl;
    std::cout << "Retrieving third element after remove: " << listPtr->getEntry(3) << std::endl;
    listPtr->clear();
}

int main() {
    // Test FrontList implemented using LinkedList
    FrontList<int>* list1Ptr = new FrontListLinkedList<int>();
    testFrontList(list1Ptr);
    delete list1Ptr;

    // Test FrontList derived from LinkedList using public inheritance
    FrontList<int>* list2Ptr = new FrontListInheritedPublic<int>();
    testFrontList(list2Ptr);
    delete list2Ptr;

    // Test FrontList derived from LinkedList using private inheritance
    FrontList<int>* list3Ptr = new FrontListInheritedPrivate<int>();
    testFrontList(list3Ptr);
    delete list3Ptr;

    // Test LinkedList
    LinkedList<int>* list4Ptr = new LinkedList<int>();
    testLinkedList(list4Ptr);
    delete list4Ptr;

    return 0;
}