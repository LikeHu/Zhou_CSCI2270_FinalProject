#ifndef __MYLIST_H__
#define __MYLIST_H__

template<class T>
class MyList
{
public:
	struct Node
	{
		T value;
		Node* next;

		Node() : next(NULL){}
		Node(T& t) : value(t), next(NULL){}

		~Node()
		{
			if(next)
				delete next;
			next = NULL;
		}
	};

	MyList() : front(NULL), back(NULL)
	{

	}

	~MyList()
	{
		if(front)
			delete front;

		front = back = NULL;
	}

	void push_back(T& t)
	{
		if(back)
		{
			back->next = new Node(t);
			back = back->next;
		}
		else
			front = back = new Node(t);
	}

	bool empty()
	{
		return (front == NULL);
	}

public:
	Node* front; // front node
	Node* back; // end node
};

#endif
