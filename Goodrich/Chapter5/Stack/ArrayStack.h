#include "RuntimeError.h"

template <typename E>
class ArrayStack {

enum { DEF_CAPACITY = 100 };			// default capacity

public:
	ArrayStack(int cap = DEF_CAPACITY); 
	int size() const;
	bool empty() const;
	const E& top() const throw(StackEmpty);
	void push(const E& e) throw(StackFull);
	void pop() throw(StackEmpty);

private:
	E* S;
	int capacity;
	int t;
};
