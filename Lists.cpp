#include "Lists.h"
#include <iostream>
//fucntion definitons
//constructor
linkedList::linkedList():
	numnodes(0)
{
	//set current node to null
	currentnode = nullptr;
};
//destructor
linkedList::~linkedList() {
	node* tmpnode;
	std::string* myString;
	//go to end of list
	tmpnode = getlast();
	
	//while a node exists
	while (tmpnode) {
		//if prior node exists
		if (tmpnode->prior != nullptr) {
			//set current node to previous node
			currentnode = tmpnode->prior;
			//set current node next pointer to be null
			currentnode->next = nullptr;
		}
		//if last node in list (both next and previous node are null) set current node to be null
		if ((tmpnode->prior == nullptr) && (tmpnode->next == nullptr)){
			currentnode = nullptr;
		}
		//casting data to string for output
		myString = (std::string*)tmpnode->data; 
		//printing what data is being deleted
		std::cout <<"deleting:" << *myString << std::endl;
		//delete data of node
		delete tmpnode->data;
		//delete node
		delete tmpnode;
		//go to end of list
		tmpnode = getlast();
}

};
//if list is empty return true else return flase
bool linkedList::isempty(void) {
	if (currentnode == nullptr) {
		return true;
	}
	
	return false;
	
};
//function to append node at end of list
bool linkedList::addnode(datatypes p_datatype, void* p_ptr) {
	//create new node from data supplied
	node* newnode;
	newnode = new node;
	newnode->prior = nullptr;
	newnode->datatype = p_datatype;
	newnode->data = p_ptr;
	newnode->next = nullptr;
	//if list  is empty new node is current node
	if (isempty()){
		currentnode = newnode;
		numnodes++;
		return true;
	}
	//go to last node in list
	getlast();
	//make next node of current node equal to new node
	currentnode->next = newnode;
	//make prior node pointer of new node equal to current node 
	newnode->prior = currentnode;
	//make current node pointer equal to new node
	currentnode = newnode;
	numnodes++;
	return true;
};
//function to insert a new node prior to the current nodde
bool linkedList::insertnodeprior(datatypes p_datatype, void* p_ptr){
	node* newnode;
	//if list is empty simply call addnode function
	if (isempty()) {
		return addnode(p_datatype, p_ptr);
	}
	//creatign new node
	newnode = new node;
	newnode->prior = nullptr;
	newnode->datatype = p_datatype;
	newnode->data = p_ptr;
	newnode->next = nullptr;
	//checking if the current node is the first in the list if it is create the new node at the top of the list
	if (currentnode->prior == nullptr) {
		currentnode->prior = newnode;
		newnode->next = currentnode;
		currentnode = newnode;
		numnodes++;
		return true;
	}
	//else it inserts the new node prior to the current node and links the prior nodes pointer to the new node
	currentnode->prior->next = newnode;
	newnode->prior = currentnode->prior;
	currentnode->prior = newnode;
	newnode->next = currentnode;
	currentnode = newnode;
	numnodes++;
	return true;
};
//function to create a new node after the current node
bool linkedList::insertnodepost(datatypes p_datatype, void* p_ptr) {
	node* newnode;
	//if list is empty simply call addnode function
	if (isempty()) {
		return addnode(p_datatype, p_ptr);
	}
	//creating the new node
	newnode = new node;
	newnode->prior = nullptr;
	newnode->datatype = p_datatype;
	newnode->data = p_ptr;
	newnode->next = nullptr;
	//checking if the current node is the last in the list and appending on the new node to the bottom of the list
	if (currentnode->next == nullptr) {
		currentnode->next = newnode;
		newnode->prior = currentnode;
		currentnode = newnode;
		numnodes++;
		return true;
	}
	//else it inserts the new node after the current node and links the next nodes prior pointer to the new node
	currentnode->next->prior = newnode;
	newnode->next = currentnode->next;
	currentnode->next = newnode;
	newnode->prior = currentnode;
	currentnode = newnode;
	numnodes++;
	return true;
};

//function for deleting of the current node and updating the list
bool linkedList::deletecurrentnode(void) {
	node* tmpnode;
	//if the list is empty return false as no node can be deleted
	if (isempty()) {
		return false;
	}
	//if the current node is the only node in the list
	if ((!currentnode->prior) && (!currentnode->next)) {
		delete currentnode;
		currentnode = nullptr;
		numnodes--;
		return true;
	}
	//if the node is the first node in the list
	if (!currentnode->prior) {
		tmpnode = currentnode->next;
		currentnode->next->prior = nullptr;
		delete currentnode;
		currentnode = tmpnode;
		numnodes--;
		return true;
	}
	//if the current node is the last node in the list
	if (!currentnode->next) {
		tmpnode = currentnode->prior;
		currentnode->prior->next = nullptr;
		delete currentnode;
		currentnode = tmpnode;
		numnodes--;
		return true;
	}
	//code to delete current node and update prior node next and next node prior
	tmpnode = currentnode->prior;
	currentnode->next->prior = currentnode->prior;
	currentnode->prior->next = currentnode->next;
	delete currentnode;
	numnodes--;
	currentnode = tmpnode;
	return true;

};

//fucntion to get first node in list
node* linkedList::getfirst(void) {
	node* ptr;
	//if list is empty return null pointer else pointer equals current node
	if (isempty()) {
		return nullptr;
	}
	ptr = currentnode;
	//while prior  pointer of current node is not equal to null point to previous node in the list
	while (ptr->prior != nullptr) {
		ptr = ptr->prior;
	}
	//make current node equal to ptr as now at beginning of list
	currentnode = ptr;
	//return pointer to current node (top of list)
	return currentnode;
};

//fucntion to get last node in list
node* linkedList::getlast(void) {
	node* ptr;
	//if list is empty return null pointer else pointer equals current node
	if (isempty()) {
		return nullptr;
	}
	ptr = currentnode;
	//while the next pointer of current node is not equal to null point to next node in the list

	while (ptr->next !=  nullptr) {
		ptr = ptr->next;
	}
	//make current node equal to ptr as now at end of list
	currentnode = ptr;
	//return pointer to current node (bottom of list)
	return currentnode;
};

//move current pointer to previous node return true if successful else return false
bool linkedList::goprior(void) {
	//if previous node equals null pointer return false as at top of list
	if (currentnode->prior == nullptr) {
		return false;
	}
	//move current node to previous node
	currentnode = currentnode->prior;
	//return true
	return true;
};

//move current pointer to next node return true if successful else return false
bool linkedList::gonext(void) {
	//if next node equals null pointer return false as at bottom of list
	if (currentnode->next == nullptr) {
		return false;
	}
	//move current node to next node
	currentnode = currentnode->next;
	//return true
	return true;
};
//function to iterate through list and print the data **only works for strings currently**
void linkedList::printlist(void) {
	std::string* myString;
	//if getfirst returns null we know the list is empty and has nothing to print
	if (!getfirst()) {
		std::cout << "The list is empty" << std::endl;
		return;
	};
	
	//cast node data to string
	myString = (std::string*)currentnode->data;
	//print out  string
	std::cout << *myString << std::endl;
	//while not at the end of the list
	while (currentnode->next != nullptr) {
		//go to next node
		gonext();
		//cast node data to string
		myString = (std::string*)currentnode->data;
		//print out string
		std::cout << *myString << std::endl;

	}
};