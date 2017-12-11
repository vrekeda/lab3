/************************************************************************
*file: DoublyLinkedList.h
*DoublyLinkedList class declaration
*author: Rekeda Volodymyr
*written: 25/11/2017
*last modified: 02/12/2017
*************************************************************************/

#pragma once

#include "ListNode.h"
#include <iostream>

class DoublyLinkedList {
	ListNode *head;
public:

	DoublyLinkedList(void);							//default constructor
	~DoublyLinkedList(void);						//destructor
													//member functions
	int size();										//Returns the number of elements in the list.
	bool empty();									//Returns true if empty, false otherwise.
	void clear();									//Removes all elements from the list.
	void push_back(const ListNode &nd);				// Adds node to the end of the list.
	void push_front(const ListNode &nd);			// Adds node to the front of the list.
	void pop_front();								// Removes the first element of the list.
	void pop_back();								// Removes the last element of the list.
	void insert_ord(const ListNode &nd);			//Inserts node preserving list ordering
	void sort();									//Sorts list in nondescending order
	bool insert_after(const char *dat, const ListNode &nd);// Inserts nd after the
													 //the node with dat. Returns 
													 //true on success	
	void operator=(const DoublyLinkedList &dl);		// Overloaded of the assignment 
													//operator
	void merge(DoublyLinkedList &lst);				//Removes the elements from the argument 
													//list, inserts them into the target list,  
													//and orders the new, combined set of 
													//elements in nondescending order
	void erase(const char *dat);							// Removes all nodes with dat 
	void unique();									//Removes adjacent duplicate elements or adjacent elements
	void assign(DoublyLinkedList &dl, int first, int last);		//deletes elements 
																//from argument list between first and last 
																//positions and adds them to the end of target list 
	void splice(int where, const DoublyLinkedList &dl);			//inserts elements of 
																//argument list in target list starting from  
																//where position
	void splice(int where, const DoublyLinkedList &dl, int first, int last);	// inserts elements of argument list from first to 
																				//last positions in target list starting from  
																				//where position

	void print();										//prints list
	void print_bkw();									//prints list backward

private:
	ListNode *tail;
	int length;
};
