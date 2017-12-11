#include "ListNode.h"

ListNode::ListNode()
{
	data = nullptr;
	prev = nullptr;
	next = nullptr;
}

ListNode::ListNode(const char *_data)
{
	prev = nullptr;
	next = nullptr;
	if (_data == nullptr)
	{
		data = nullptr;
		return;
	}
	data = new char[strlen(_data)+1];
	strcpy(data, _data);
}

ListNode::~ListNode(void)
{
	delete[] data;
}