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
		size = 0;
		capacity = 3;
		p = new T[capacity];
	}
	~myList()
	{
		delete[]p;
	}
	void push_back(T num)
	{
		if (size == capacity)
		{
			ChangeSize();
		}

		p[size++] = num;
	}
	void push_front(T num)
	{
		if (size == capacity)
		{
			ChangeSize();
		}

		T* tmp = new T[size + 1];
		tmp[0] = num;
		for (int i = 0; i < size; i++)
			tmp[i + 1] = p[i];
		size++;
		for (int i = 0; i < size; i++)
			p[i] = tmp[i];
	}

	void insert(int position, T num)
	{
		if (size == capacity)
		{
			ChangeSize();
		}

		if (size != 0)
		{
			T* tmp = new T[size + 1];
			for (int i = 0; i < position; i++)
				tmp[i] = p[i];
			tmp[position] = num;
			for (int i = position + 1; i <= size; i++)
				tmp[i] = p[i - 1];
			size++;
			for (int i = 0; i < size; i++)
				p[i] = tmp[i];
		}
		else
		{
			p = new T[1];
			p[0] = num;
			size++;
		}

	}
	void pop_back()
	{
		T* tmp = new T[size - 1];
		for (int i = 0; i < size - 1; i++)
			tmp[i] = p[i];
		size--;
		delete[]p;
		p = tmp;
	}

	void pop_front()
	{
		T* tmp = new T[size - 1];
		for (int i = 1; i < size; i++)
			tmp[i - 1] = p[i];
		size--;
		delete[]p;
		p = tmp;
	}
	void pop_index(int position)
	{
		T* tmp = new T[size - 1];
		for (int i = 0; i < position; i++)
			tmp[i] = p[i];
		for (int i = position; i < size; i++)
			tmp[i] = p[i + 1];
		size--;
		delete[]p;
		p = tmp;
	}
	void print()
	{
		for (int i = 0; i < size; i++)
			cout << p[i] << ' ';
		cout << endl;
	}
private:
	
	T* p;
	int size;
	int capacity;
	void ChangeSize()
	{
		capacity *= 2;
		T* tmp = new T[capacity];
		for (int i = 0; i < size; i++)
			tmp[i] = p[i];
		delete[]p;
		p = tmp;
	}
};