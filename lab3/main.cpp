#include "DoublyLinkedList.h"
#include "ListNode.h"
#include <stdlib.h>

int main()
{
	DoublyLinkedList *node = new DoublyLinkedList(), *node2 = new DoublyLinkedList(), *node3 = new DoublyLinkedList();
	node->push_back(*(new ListNode("Billy")));
	node->push_back(*(new ListNode("Bob")));
	node->push_back(*(new ListNode("Bobby")));
	node->push_back(*(new ListNode("Max")));
	node->push_back(*(new ListNode("Antony")));
	std::cout << "list1 \n";
	node->print();

	node2->push_back(*(new ListNode("Mark")));
	node2->push_back(*(new ListNode("Peter")));
	node2->push_back(*(new ListNode("Vlad")));
	std::cout << "\n\nlist2 \n";
	node2->print();

	node->insert_after("Max", *(new ListNode("Bob")));
	std::cout << "\n\n\"Bob\" was inserted after \"Max\" in list1\n";
	node->print();

	node->sort();
	std::cout << "\n\nlist1 was sorted\n";
	node->print();

	node->unique();
	std::cout << "\n\nlist1 unique\n";
	node->print();

	node->erase("Antony");
	std::cout << "\n\n\"Antony\" was erased from list1\n";
	node->print();

	node->insert_ord(*(new ListNode("Den")));
	std::cout << "\n\nlist1 insert_ord\n";
	node->print();

	node->merge(*node2);
	std::cout << "\n\nMerge";
	std::cout << "\nlist1 \n";
	node->print();
	std::cout << "\nlist2 \n";
	node2->print();

	node2->push_back(*(new ListNode("2")));
	node2->push_back(*(new ListNode("3")));
	node2->push_back(*(new ListNode("4")));
	node2->push_back(*(new ListNode("1")));
	std::cout << "\n\nlist2 \n";
	node2->print();

	node->assign(*node2, 0, 2);
	std::cout << "\n\nAssign first=0 last=2";
	std::cout << "\nlist1 \n";
	node->print();
	std::cout << "\nlist2 \n";
	node2->print();


	node2->push_back(*(new ListNode("5")));
	node2->push_back(*(new ListNode("4")));
	node2->push_back(*(new ListNode("7")));
	std::cout << "\n\nlist2 \n";
	node2->print();

	node->splice(6, *node2, 1, 3);
	std::cout << "\n\nSplice where=6 first=1 last=3";
	std::cout << "\nlist1 \n";
	node->print();
	std::cout << "\nlist2 \n";
	node2->print();

	node3->operator=(*node);
	std::cout << "\n\nlist3=list1\n";
	node3->print();
	std::cout << "\n\nlist3 was sorted and printed backward\n";
	node3->sort();
	node3->print_bkw();

	std::cout << "\n\n";

	system("pause");
	return 0;
}