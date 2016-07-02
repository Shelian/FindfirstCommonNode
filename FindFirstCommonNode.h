#ifndef __FINDFIRSTCOMMONNODE_H__
#define __FINDFIRSTCOMMONNODE_H__

struct ListNode
{
	int _value;
	ListNode* _next;

	ListNode(int x)
		:_value(x)
		, _next(NULL)
	{}
};

typedef ListNode Node;
Node* FindFirstCommonNode(Node* pHead1, Node* pHead2)
{
	Node* cur1 = pHead1;
	Node* cur2 = pHead2;
	int count1 = 0;
	int count2 = 0;
	while (cur1)
	{
		++count1;
		cur1 = cur1->_next;
	}

	while (cur2)
	{
		++count2;
		cur2 = cur2->_next;
	}
	int count = count1 - count2;
	Node* pListNodeLong = pHead1;
	Node* pListNodeShort = pHead2;
	if (count2 > count1)
	{
		pListNodeLong = pHead2;
		pListNodeShort = pHead1;
		count = count2 - count1;
	}

	while (count)
	{
		--count;
		pListNodeLong = pListNodeLong->_next;
	}

	while (pListNodeLong && pListNodeShort &&pListNodeLong != pListNodeShort)
	{
		pListNodeLong = pListNodeLong->_next;
		pListNodeShort = pListNodeShort->_next;
	}

	if (pListNodeLong == pListNodeShort != NULL)
	{
		return pListNodeLong;
	}
}

void TestFind()
{
	Node* p1 = new Node(1);
	Node* p2 = new Node(2);
	Node* p3 = new Node(3);
	Node* p6 = new Node(6);
	Node* p7 = new Node(7);
	Node* p4 = new Node(4);
	Node* p5 = new Node(5);

	p1->_next = p2;
	p2->_next = p3;
	p3->_next = p6;
	p6->_next = p7;

	p4->_next = p5;
	p5->_next = p6;
	p6->_next = p7;
	cout << FindFirstCommonNode(p1, p4)->_value << endl;
}


#endif //__FINDFIRSTCOMMONNODE_H__