#pragma once
#include "node.h"
#include <iostream>

template<typename T>
class Queue
{
	node<T>* first;
	node<T>* last;

public:
	Queue(): first(nullptr), last(nullptr)
	{
		first = nullptr;
		last = nullptr;
	}

	Queue(const Queue& other) : first(nullptr), last(nullptr)
	{
		node<T>* curr = other.first;
		while (curr)
		{
			enqueue(curr->data);
			curr = curr->next;
		}
	}

	~Queue()
	{
		while (!empty())
		{
			dequeue();
		}
	}

	void enqueue(const T& value)
	{
		if (!last)
		{
			last = new node<T>(value);
			first = last;
		}
		else
		{
			last->next = new node<T>(value);
			last->next->prev = last;
			last = last->next;
		}
	}

	void dequeue()
	{
		if (!empty())
		{
			node<T>* temp = first;
			first = first->next;
			if (first)
			{
				first->prev = nullptr;
			}
			else
			{
				last = nullptr;
			}
			delete temp;
		}
	}

	bool empty() const
	{
		return first == nullptr;
	}

	const T& front() const
	{
		if (!empty())
		{
			return first->data;
		}
		else
		{
			throw std::out_of_range("Пустая очередь");
		}
	}

	T& front()
	{
		if (!empty())
		{
			return first->data;
		}
		else
		{
			throw std::out_of_range("Пустая очередь");
		}
	}

	friend std::ostream& operator <<(std::ostream& os, const Queue& q)
	{
		node<T>* cur = q.first;
		while (cur)
		{
			os << cur->data << " ";
			cur = cur->next;
		}
		return os;
	}

	friend std::istream& operator >> (std::istream& is, const Queue& q)
	{
		T value;
		is >> value;
		q.enqueue(value);
		return is;
	}

	Queue& operator =(const Queue& other)
	{
		if (this != &other)
		{
			while (!empty())
			{
				dequeue();
			}
			node<T>* cur = other.first;
			while(cur)
			{
				enqueue(cur->data);
				cur = cur->next;
			}
		}
		return *this;
	}
};