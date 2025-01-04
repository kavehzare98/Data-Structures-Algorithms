#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

#include "RuntimeError.h"

template <typename E>
class ArrayStack {

enum { DEF_CAPACITY = 100 };			// default capacity

private:
	E* S;
	int capacity;
	int t;

public:
	ArrayStack(int cap = DEF_CAPACITY) : S(new E[cap]), capacity(cap), t(-1) {}

	int size() const		{ return (t + 1); }

	bool empty() const		{ return (t < 0); }

	const E& top() const				// throws StackEmpty exception
	{ 
		if (empty()) throw StackEmpty("Top of empty stack");
		return S[t];
	}

	void push(const E& e)				// throws StackFull exception
	{
		if (size() == capacity) throw StackFull("Push to full stack");
		t = t + 1;
		S[t] = e;
	}

	void pop()							// throws StackEmpty exception
	{
		if (empty()) throw StackEmpty("Pop from emtpy stack");
		t = t - 1;
	}
};

#endif
