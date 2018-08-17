/**
 * @brief 	Abstract Data Structures : Linked List
 * @date	07/14/2018
 * 
 * @section 	DESCRIPTION
 * Insert a node at any position
 * 
 * @return 
 */

#include <iostream>
#include <cstdlib>		// required for rand()
#include <ctime>		// required for time()
#include "Node.h"


// Function Prototypes
void removeSecondNode();				// Removes Node @ second position
void addEnd340(int data);				// Insertsthe new node at the end of the Linkedlist
int getCurrentSize340Iterative();		// Counts the number of node in the LinkedList iteratively

int getCurrentSize340RecursiveHelper(Node *temp);	// helper
int getCurrentSize340Recursive();		// Recursively counts the number of node int the LinkedList

//int getFrequencyOf340RecursiveHelper(Node<ItemType>*, const ItemType&) const; // helper
int getFrequencyOf340Recursive(const int& data);		// Recursively counts the number of times an entry appears in the LinkedList
Node removeRandom340();					// removes a random entry from the LinkedList.


void Print();
void Insert(int data, int position);	// Node to be inserted @ position
void Delete(int poition);				// Node to be delted @ position 
Node *Reverse(Node *head);				// Reverses the Linked list


struct Node *head;	// global variable

// Begin Main 
int main() {
	
	head = NULL; 	// empty list
	int iterative_count{};
	int recursive_count{};
	int frequency{};	
	
	// Function Insert()
	std::cout << "\n-------------------Call to INSERT()------------------------------\n" <<std::endl;
	Insert(2,1);	// List : 2
	Insert(3,2);	// List : 2,3
	Insert(4,1);	// List : 4,2,3
	Insert(5,2);	// List : 4,5,2,3
	Insert(7,3);	// List : 4,5,7,2,3
	Insert(0,4);	// List : 4,5,7,0,2,3
	Insert(9,5);	// List : 4,5,7,0,9,2,3	
	Insert(4,5);	// List : 4,5,7,0,4,9,2,3
	Insert(0,8);	// List : 4,5,7,0,4,9,2,0,3
	Insert(9,10);	// List : 4,5,7,0,4,9,2,0,3,9
	Insert(0,3);	// List : 4,5,0,7,0,4,9,2,0,3,9
	Insert(7,12);	// List : 4,5,0,7,0,4,9,2,0,3,9,7
	Print();
	
	iterative_count = getCurrentSize340Iterative();
	std::cout << "\nIterative count of Nodes: " << iterative_count << std::endl;
	
	frequency = getFrequencyOf340Recursive(0);
	std::cout << "\nFrequency of data(0) recursively: " << frequency << std::endl;
	
	recursive_count = getCurrentSize340Recursive();
	std::cout << "\nRecursive count of Nodes: " << recursive_count << std::endl;
	
	//iterative_count = getCurrentSize340Iterative();
	//std::cout << "\nIterative count of Nodes: " << iterative_count << std::endl;
	
	
	//#1
	// Function removeSecondNode()
	std::cout << "\n-------------------Call to removeSecondNode()--------------------\n" <<std::endl;
	// From #35 & 36:: list is: 4,5,7,0,9,2,3
	removeSecondNode();		// 4,7,0,9,2,3   -->[5] should be deleted from second position
	std::cout<<"AFTER call to removeSecondNode() for the FIRST time: \n\n";
	Print();
	std::cout << std::endl;
	
	removeSecondNode();		// 4,0,9,2,3     -->[7] should be deleted from second position
	std::cout<<"AFTER call to removeSecondNode() for the SECOND time: \n\n";
	Print();
	std::cout << std::endl;
	
	iterative_count = getCurrentSize340Iterative();
	std::cout << "\nIterative count of Nodes: " << iterative_count << std::endl;
	
	recursive_count = getCurrentSize340Recursive();
	std::cout << "\nRecursive count of Nodes: " << recursive_count << std::endl;
	
	frequency = getFrequencyOf340Recursive(0);
	std::cout << "\nFrequency of data(0) recursively: " << frequency << std::endl;
	
	
	//#2
	// Function addEnd340()
	std::cout << "\n-------------------Call to addEnd340()--------------------------\n" <<std::endl;
	addEnd340(1000);
	addEnd340(9999);
	Print();
	
	iterative_count = getCurrentSize340Iterative();
	std::cout << "\nIterative count of Nodes: " << iterative_count << std::endl;
	
	recursive_count = getCurrentSize340Recursive();
	std::cout << "\nRecursive count of Nodes: " << recursive_count << std::endl;
	
	frequency = getFrequencyOf340Recursive(0);
	std::cout << "\nFrequency of data(0) recursively: " << frequency << std::endl;
	
	
	//#3
	// Function removeRandom340()
	std::cout << "\n-------------------Call to removeRandom340()--------------------\n" <<std::endl;
	std::cout<<"First call: \n";
	Node temp = removeRandom340();
	Print();
	std::cout << std::endl;
	std::cout<<"Second call: \n";
	temp = removeRandom340();
	Print();
	std::cout << std::endl;
	
	iterative_count = getCurrentSize340Iterative();
	std::cout << "\nIterative count of Nodes: " << iterative_count << std::endl;
	
	recursive_count = getCurrentSize340Recursive();
	std::cout << "\nRecursive count of Nodes: " << recursive_count << std::endl;
	
	frequency = getFrequencyOf340Recursive(0);
	std::cout << "\nFrequency of data(0) recursively: " << frequency << std::endl;	
	
	
	// Function Delete()
	std::cout << "\n-------------------Call to DELETE()-----------------------------\n" <<std::endl;
	Delete(4);
	Delete(1);
	Print();		// List: 5,7,9,2,3
	iterative_count = getCurrentSize340Iterative();
	std::cout << "\nIterative count of Nodes: " << iterative_count << std::endl;
	
	recursive_count = getCurrentSize340Recursive();
	std::cout << "\nRecursive count of Nodes: " << recursive_count << std::endl;
	
	frequency = getFrequencyOf340Recursive(0);
	std::cout << "\nFrequency of data(0) recursively: " << frequency << std::endl;
	std::cout << std::endl;
	
	
	// Function Reverse()
	std::cout << "\n-------------------Call to REVERSE()----------------------------\n" <<std::endl;
	head = Reverse(head);
	Print();
	iterative_count = getCurrentSize340Iterative();
	std::cout << "\nIterative count of Nodes: " << iterative_count << std::endl;
	std::cout << std::endl;
	
//	recursive_count = getCurrentSize340Recursive(head);
//	std::cout << "\nRecursive count of Nodes: " << recursive_count << std::endl;
	
	std::cout << "----------------------------------------------------------------\n" <<std::endl;
	
	return 0;
} // end Main


// Function Insert inserts data @position
void Insert(int data, int position){
	Node *temp1 = new Node();		// Instantiation
	temp1->data = data;				// assign data
	temp1->next = NULL;				// assign next node connection
	
	if (position == 1) {
		temp1->next = head;
		head = temp1;
		return;
	}
	Node *temp2 = head;		// Start at the head
	for (int i=0; i<position-2; i++) {
		temp2 = temp2->next;
	}
	temp1->next = temp2->next;		// link temp2 node to temp1
	temp2->next = temp1;
	
} // end Insert


//#1
// Function removeSecondNode 
// removes node @ second position
void removeSecondNode() {
	Node *temp = head;	// start with the head node 
	
	
	if (head == NULL) {	// if the list is empty there is no second node to delete
		std::cout <<"Sorry! the list is empty." << std::endl;
		
	} else if(head->next == NULL) {			// there is a single node in the list
		//head->next = temp->next		
		temp = head->next;		// fetch the second node which the head points to next
		std::cout <<"Sorry! there is a single node in the list." << std::endl;
		
	} else {					// more than two nodes in the list
		temp = head->next;
		head->next = head->next->next;		// head now points to the node that the second node pointed (i.e, the third node)
	}
	delete temp;
} // end removeSecondNode()



// #2 
// Function addEnd340()
// inserts the new node a the end of the list
void addEnd340(int data) {
	Node *temp = head;		// start from the head
	
	while (temp->next != NULL) {	// Traverse the list until the last node is found
		temp = temp->next;
	}
	
	Node *newNode = new Node();
	newNode->data = data;
	temp->next = newNode;
} // end addEnd340()


// #3
// Function getCurrentSize340Iterative()
// counts the number of node in the Linked list iteratively
int getCurrentSize340Iterative() {
	Node *temp = head;		// start from the head
	int count{};
	
	while (temp != NULL) {
		count++;
		temp = temp->next;		
	}
	return count;
	
} // end getCurrentSize340Iterative()



// Helper
int getCurrentSize340RecursiveHelper(Node *temp) {
	int count{0};
	
	if (temp == NULL) {		// Base condition or Exit Case : if (temp == NULL)
		return count;
	} else {
		return 1 + getCurrentSize340RecursiveHelper(temp->next);
	}
}

// #4
// getCurrentSize340Recursive()
// counts the number of node in the LinkedList recursively
int getCurrentSize340Recursive() {
	Node *temp = head;	// start from the head
	return getCurrentSize340RecursiveHelper(temp);	
		
} // end getCurrentSize340Recursive()



//int getFrequencyOf340RecursiveHelper(Node<ItemType>*, const ItemType&) {
//	
//} // helper

//#5
// Function getFrequencyOf340Recursive()
// Recursively counts the number of times an entry appers in the LinkedList.
int getFrequencyOf340Recursive(const int& data) {
	Node *temp = head;		// start from the head node
	int frequency{0};
	//int counter{0};
	
	if (temp != NULL && temp->data == data) {
		frequency++;
		temp = temp->next;
		getFrequencyOf340Recursive(temp->data = data);
		
	} else {
		frequency = 0;
	}
	
	return frequency;
	
} // end getFrequencyOf340Recursive()


// #6 
// Function removeRandom340()
// removes a random entry from the LinkedList
Node removeRandom340() {
	// Random Number generation
	// Seed the random number generator
	// else the generator will get the same sequence of random numbers every run

	int random_num{};
	int size = getCurrentSize340Iterative();	// number of random numbers to generate
	int min{ 1 };								// lower bound (inclusive)
	int max = size;								// upper bound (inclusive)
	
	std::cout << std::endl;
	//std::cout << "RAND_MAX on the system is: " << RAND_MAX << std::endl;
	srand(time(nullptr));						// seed the random number

	for (int i{ 1 }; i <= max; i++) {
		random_num = rand() % max + min;		// generate a random number [min, max]
												//std::cout << random_num << std::endl;
	}

	//std::cout << "size is : " << size << std::endl;
	std::cout << "random number is: " << random_num << std::endl;
	std::cout << std::endl;

	Node *temp1 = head;
	int position = random_num;

	if (position == 1) { 	// if there is a single node to delete then
		head = temp1->next;	// head now points to second node.
		//delete temp1;		// free memeory
		return *temp1;				// exit

	} else {
		for (int i=0; i < (position - 2); i++) {
			temp1 = temp1->next;			// temp1 points to (n-1)th Node
		}
		Node *temp2 = temp1->next;	//nth Node
		temp1->next = temp2->next;	// (n+1)th Node
		return *temp2;
	}
	
} // end removeRandom340()




// Fucntion Delete deletes Node @ position i
void Delete(int position) {
	Node *temp1 = head;
	
	if (position == 1) { 	// if there is a single node to delete then
		head = temp1->next;	// head now points to second node.
		delete temp1;		// free memeory
		return;				// exit
	}
	
	for (int i=0; i<position-2; i++) {
		temp1 = temp1->next;			// temp1 points to (n-1)th Node
	}
	Node *temp2 = temp1->next;	//nth Node
	temp1->next = temp2->next;	// (n+1)th Node
	delete temp2;	
} // end Delete


// Function Reverse reverses the Linked List
Node *Reverse(Node *head) {
	Node *current, *prev, *next;	// next is a local variable to the Reverse Function
	current = head;					// current->next = *(current).next
	prev = NULL;
	
	while (current != NULL) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	head = prev;
	return head;
	
} // end Reverse



// Print Function displays content
void Print() {
	Node *temp = head;	// start from head node
	//std::cout << "[";
	while (temp != NULL) {	// check to see if there are more than a single node
		std::cout << "[" << temp->data << "|]" <<"--->";
		temp = temp->next;
	}
	std::cout << "NULL" << std::endl;
	
} // ennd Print()