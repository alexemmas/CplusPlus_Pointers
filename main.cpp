#include <iostream>
#include "Lists.h"

//a handful of examples of pointer values /  pointer data along with Linked list example
int main(void){

	linkedList* myList;
	std::string* myString;
	int num = 100;
	int* numptr = &num;

	//memory address of variable value
	std::cout << "int variable stored at:" << numptr << std::endl;
	
	//memory address of pointer
	std::cout << "int pointer stored at:" << &numptr << std::endl;
	
	//print out value of variable using the pointer 
	std::cout << "int value:" << *numptr << std::endl;

	//create new linked list
	myList = new linkedList;
	
	//add new node and print list
	myString = new std::string("Hello");
	myList->addnode(datatypes::string, myString);
	myList->printlist();
	std::cout << std::endl;

	//add new node and print list
	myString = new std::string("World");
	myList->addnode(datatypes::string, myString);
	myList->printlist();
	std::cout << std::endl;
	
	//add new node and print list
	myString = new std::string("This is a List");
	myList->addnode(datatypes::string, myString);
	myList->printlist();
	std::cout << std::endl;
	
	//inserting data after the first node
	myList->getfirst();
	myString = new std::string("New data");
	myList->insertnodepost(datatypes::string, myString);
	myList->printlist();

	std::cout << "total number of nodes is:" << myList->getnumnodes() << std::endl;
	std::cout << std::endl;
	
	//deleting the last node in the list
	myList->getlast();
	myList->deletecurrentnode();
	myList->printlist();
	std::cout << std::endl;
	//deleting data from the middle of the list
	myList->goprior();
	myList->deletecurrentnode();
	//deleting data from the top of the list
	myList->getfirst();
	myList->deletecurrentnode();
	//deleting the final entry in the list
	myList->deletecurrentnode();
	//trying to delete data from an empty list
	myList->deletecurrentnode();
	//trying to print the empty list
	myList->printlist();
	std::cout<<std::endl;
	std::cout << "total number of nodes is:" << myList->getnumnodes() << std::endl;
	std::cout << std::endl;

	delete myList;

};