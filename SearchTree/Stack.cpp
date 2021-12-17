#include "Stack.h";

void init(TStack& top)
{
	top = nullptr;
}

bool isEmpty(TStack top)
{
	return top == nullptr;
}

void push(TStack& top, StackData elem)
{
	TStack p = new StackNode;
	p->data = elem;
	p->next = top;
	top = p;
}

void pop(TStack& top)
{
	TStack p = top;
	top = top->next;
	p->next = nullptr;
	delete p;
	p = nullptr;
}

StackData peek(TStack top)
{
	return top->data;
}

void clear(TStack& top)
{
	while (!isEmpty(top)) {
		pop(top);
	}
}