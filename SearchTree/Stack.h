#pragma once
#include "SearchTree.h"

typedef TTree StackData;

struct StackNode {
	StackData data;
	StackNode* next;
};

typedef StackNode* TStack;

void init(TStack& top);
bool isEmpty(TStack top);
void push(TStack& top, StackData elem);
void pop(TStack& top);
StackData peek(TStack top);
void clear(TStack & top);
