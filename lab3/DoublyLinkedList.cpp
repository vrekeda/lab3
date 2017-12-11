#include "DoublyLinkedList.h"

DoublyLinkedList::DoublyLinkedList(void)
{
	head = nullptr;
	tail = nullptr;
	length = 0;
}

DoublyLinkedList::~DoublyLinkedList(void)
{
	clear();
}

int DoublyLinkedList::size()
{
	return length;
}

bool DoublyLinkedList::empty()
{
	if (head == nullptr)
		return true;
	else return false;
}

void DoublyLinkedList::clear()
{
	while (head != nullptr)
		pop_front();
}

void DoublyLinkedList::push_front(const ListNode &nd)
{
	ListNode *node;
	if (nd.data == nullptr)
		return;
	length++;
	if (head == nullptr)
	{
		head = new ListNode(nd.data);
		tail = head;
		return;
	}
	node = new ListNode(nd.data);
	head->prev = node;
	node->next = head;
	head = node;
}

void DoublyLinkedList::push_back(const ListNode &nd)
{
	ListNode *node;
	if (nd.data == nullptr)
		return;
	length++;
	if (head == nullptr)
	{
		head = new ListNode(nd.data);
		tail = head;
		return;
	}
	node = new ListNode(nd.data); 
	tail->next = node;
	node->prev = tail;
	tail = node;
}

void DoublyLinkedList::pop_front()
{
	ListNode *tmp;
	if (empty())
		return;
	tmp = head->next;
	delete head;
	head = tmp;
	length--;
	if (head != nullptr)
		head->prev = nullptr;
	else
		tail = nullptr;
}

void DoublyLinkedList::pop_back()
{
	ListNode *tmp;
	if (empty())
		return;
	tmp = tail->prev;
	delete tail;
	tail = tmp;
	length--;
	if (tail != nullptr)
		tmp->next = nullptr;
	else
		head = nullptr;
}

void DoublyLinkedList::erase(const char *dat)
{
	ListNode *cur=head, *tmp;
	if (head == nullptr || dat==nullptr)
		return;
	while (cur != nullptr)
	{
		if ((strcmp(cur->data, dat)) == 0)
		{
			if (cur == head)
			{
				cur = cur->next;
				pop_front();
			}
			else if (cur == tail)
			{
				cur = cur->next;
				pop_back();
			}
			else {
				cur->prev->next = cur->next;
				tmp = cur->next;
				cur->next->prev = cur->prev;
				delete cur;
				cur = tmp;
				length--;
			}
		}
		else cur = cur->next;
	}
}

bool DoublyLinkedList::insert_after(const char *dat, const ListNode &nd)
{
	ListNode *cur=head, *node; 
	if (nd.data == nullptr)
		return false;
	if (head == nullptr)
		return false;
	node = new ListNode(nd.data);
	while (cur != nullptr)
	{
		if ((strcmp(dat, cur->data)) == 0)
		{
			if (cur!= tail) {
				node->next = cur->next;
				node->prev = cur;
				cur->next->prev = node;
				cur->next = node;
				length++;
			}
			else push_back(nd);
			return true;
		}
		cur = cur->next;
	}
	return false;
}

void DoublyLinkedList::assign(DoublyLinkedList &dl, int first, int last)
{
	ListNode *cur = dl.head, *tmp;
	if (first < 0 || first >= dl.length || last < 0 || last >= dl.length ||dl.head==nullptr)
		return;
	int count=0;
	while (cur != nullptr)
	{
		if (count >= first && count <= last)
		{
			this->push_back(*(new ListNode(cur->data)));
			if (cur == dl.head)
			{
				cur = cur->next;
				dl.pop_front();
			}
			else if (cur == dl.tail)
			{
				dl.pop_back();
				cur = nullptr;
			}
			else {
				cur->next->prev = cur->prev;
				cur->prev->next = cur->next;
				tmp = cur->next;
				delete cur;
				cur = tmp;
				dl.length--;
			}
		}
		else cur = cur->next;
		count++;
	}
}

void DoublyLinkedList::sort()
{
	ListNode *cur = head, *tmp;
	if (head == nullptr)
		return;
	int i = 0, j = 0;
	for (i=0; i<length; i++)
	{
		for (j = 0; j < length- 1 - i; j++)
		{
			if (strcmp(cur->data, cur->next->data) > 0)
			{
				if (cur != head)
					cur->prev->next = cur->next;
				if (cur == head)
					head = cur->next;
				if (cur->next != tail)
					cur->next->next->prev = cur;
				if (cur->next == tail)
					tail = cur;
				tmp = cur->next->next;
				cur->next->next = cur->next->prev;
				cur->next->prev = cur->prev;
				cur->prev = cur->next;
				cur->next = tmp;
			}
			else
				cur = cur->next;
		}
		cur = head;
	}
}

void DoublyLinkedList::insert_ord(const ListNode &nd)
{
	ListNode *cur = head, *node;
	if (nd.data == nullptr)
		return;
	if (head == nullptr)
		return;
	node = new ListNode(nd.data);
	while (cur != nullptr)
	{
		if (cur == head && strcmp(cur->next->data, node->data) > 0)
		{
			push_front(nd);
			break;
		}
		if (cur == tail)
		{
			push_back(nd);
			break;
		}
		if (strcmp(cur->data, node->data)<0 && strcmp(cur->next->data, node->data)>0)
		{
			node->prev = cur;
			node->next = cur->next;
			cur->next->prev = node;
			cur->next = node;
			length++;
			break;
		}
		cur = cur->next;
	}
}

void DoublyLinkedList::operator=(const DoublyLinkedList &dl)
{
	ListNode *tmp = dl.head;
	if (this == &dl)
		return;
	this->clear();
	while (tmp != nullptr)
	{
		this->push_back(*(new ListNode(tmp->data)));
		tmp = tmp->next;
	}
}

void DoublyLinkedList::merge(DoublyLinkedList &lst)
{
	ListNode *cur = lst.head;
	if (lst.head == nullptr)
		return;
	while (cur != nullptr)
	{
		this->push_back(*(new ListNode(cur->data)));
		cur = cur->next;
		lst.pop_front();
	}
	this->sort();
}

void DoublyLinkedList::unique()
{
	ListNode *cur = head, *tmp;
	if (head == nullptr)
		return;
	while (cur->next != nullptr)
	{
		if (strcmp(cur->data, cur->next->data) == 0)
			if (cur->next != tail)
			{
				cur->next->next->prev = cur;
				tmp = cur->next->next;
				delete cur->next;
				cur->next = tmp;
				length--;
			}
			else 
				pop_back();
		else
			cur = cur->next;
	}
}

void DoublyLinkedList::splice(int where, const DoublyLinkedList &dl)
{
	ListNode *cur = this->head, *cur_dl = dl.head, *tmp_tail = this->tail, *tmp;
	int count = 0;
	if (where >= this->length || where<0 ||dl.head==nullptr)
		return;
	for (count = 0; count < where; count++)
		cur = cur->next;
	tail = cur;
	tmp = cur->next;
	while (cur_dl != nullptr)
	{
		this->push_back(*(new ListNode(cur_dl->data)));
		cur_dl = cur_dl->next;
	}
	tail->next = tmp;
	if (tail->next!=nullptr)
		this->tail = tmp_tail;
}

void DoublyLinkedList::splice(int where, const DoublyLinkedList &dl, int first, int last)
{
	ListNode *cur = this->head, *cur_dl = dl.head, *tmp_tail = this->tail, *tmp;
	int count = 0;
	if (where >= this->length || first>dl.length || last>dl.length || where<0 || first<0 || last<0 || dl.head==nullptr)
		return;
	for (count = 0; count < where; count++)
		cur = cur->next;
	count = 0;
	tail = cur;
	tmp = cur->next;
	while (cur_dl != nullptr)
	{
		if(count >= first && count <= last)
			push_back(*(new ListNode(cur_dl->data)));
		cur_dl = cur_dl->next;
		count++;
	}
	tail->next = tmp;
	if (tail->next != nullptr)
		this->tail = tmp_tail;
}

void DoublyLinkedList::print()
{
	ListNode *cur = head;
	if (head == nullptr)
		std::cout << "List is empty";
	while (cur != nullptr)
	{
		std::cout << cur->data << " ";
		cur = cur->next;
	}
}

void DoublyLinkedList::print_bkw()
{
	ListNode *cur = tail;
	if (head == nullptr)
		std::cout << "List is empty";
	while (cur != nullptr)
	{
		std::cout << cur->data << " ";
		cur = cur->prev;
	}
}