#pragma once
#include <iostream>
#include <algorithm>
using namespace std;

template<class T>
class myList
{
public:
	myList()
	{
		first = NULL;
	}

	~myList()
	{
		free(first);
	}

	void push_back(T num)
	{
		Node* p = (Node*)malloc(sizeof(Node));
		p->data = num;
		p->next = NULL;

		if (first == NULL)
		{
			first = p;
			return;
		}

		Node* tmp = first;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = p;
	}

	void push_front(T num)
	{
		Node* tmp = (Node*)(malloc(sizeof(Node)));
		tmp->data = num;
		tmp->next = first;
		first = tmp;
	}

	void insert(int position, T num)
	{
		Node* p = (Node*)malloc(sizeof(Node));
		p->data = num;

		if (first == NULL)
		{
			p->next = NULL;
			first = p;
			return;
		}

		if (position == 0)
		{
			push_front(num);
			return;
		}

		Node* tmp = first;
		for (int i = 2; i <= position; i++)
		{
			if (tmp->next != NULL)
			{
				tmp = tmp->next;
			}
		}

		p->next = tmp->next;
		tmp->next = p;
	}

	void pop_back()
	{
		if (first != NULL)
		{
			if (first->next == NULL)
				first = NULL;
			else
			{
				Node* tmp = first;
				while (tmp->next->next != NULL)
					tmp = tmp->next;
				tmp->next = NULL;
			}
		}
	}

	void pop_front()
	{
		first = first->next;
	}

	void pop_index(int position)
	{
		if (position == 0)
		{
			pop_front();
			return;
		}

		if (first->next == NULL)
		{
			first = first->next;
			return;
		}

		Node* tmp = first;
		for (int i = 2; i <= position; i++)
		{
			if (tmp->next != NULL)
				tmp = tmp->next;
		}
		tmp->next = tmp->next->next;
	}

	void print()
	{
		Node* ptr = first;
		while (ptr)
		{
			cout << ptr->data;
			if (ptr->next)
				cout << ' ';
			ptr = ptr->next;
		}

		cout << endl;
		free(ptr);
	}
private:
	struct Node
	{
		T data;
		Node* next;

	}*first;
};
