/************************************************************************
*file: ListNode.h
*ListNode class declaration
*author: Rekeda Volodymyr
*written: 25/11/2017
*last modified: 02/12/2017
*************************************************************************/


#pragma once

#include <cstring>
#pragma  warning (disable: 4996)

class ListNode {
	char *data;
	ListNode *prev;
	ListNode *next;
public:
	friend class DoublyLinkedList;
	ListNode();//default constructor
	ListNode(const char *_data);
	~ListNode(void);
};