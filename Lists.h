//code to ensure header file is only used once
#ifndef LIST
#define LIST
///////////////////////////////////////////////////////////////////////////////////////////////////////////
// I am aware c++ has its own linked lists i created this as an exercise for my understanding of pointers//
///////////////////////////////////////////////////////////////////////////////////////////////////////////

//defining datatypes that can be used
enum datatypes {
	number, 
	string,

};

//defining structure of nodes within the list
struct node {
	//pointer to previous node in list
	node* prior;
	//type of data in node
	datatypes datatype;
	//data
	void* data;
	//pointer to next node in list
	node* next;
};
//class definiton for linked list
class linkedList {
private:
	//pointer to current node
	node* currentnode;
	long numnodes;
public:
	//constructor and destructor 
	linkedList();
	~linkedList();
	//fucntion to check if list is empty
	bool isempty(void);
	//function to add node to list
	bool addnode(datatypes p_datatype, void* p_ptr);
	bool insertnodeprior(datatypes p_datatype, void* p_ptr);
	bool insertnodepost(datatypes p_datatype, void* p_ptr);
	bool deletecurrentnode(void);
	//functions for finding first and last nodes in list
	node* getfirst(void);
	node* getlast(void);
	//functions for going to the previous or next node in the list
	bool goprior(void);
	bool gonext(void);
	//function to print contents of the list
	void printlist(void);
	long getnumnodes(void) { return numnodes; };

};
#endif // !LIST