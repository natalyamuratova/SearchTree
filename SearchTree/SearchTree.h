#pragma once

typedef int TData;

struct Node {
	TData data;
	Node* left;
	Node* right;
};

typedef Node* TTree;
typedef void(*FunctionType) (TData& node);

void initTree(TTree& root);
void initTree(TTree& root, TData elem);
void destroyTree(TTree& root);
bool isEmpty(TTree root);

void insertElement(TTree& root, TData elem);
void deleteElement(TTree& root, TData elem);
void deleteNode(TTree& pNode);
int findSuccessor(TTree& pNode);
TTree search(TTree root, TData key);

//печать деревьев
void preorder(TTree root, FunctionType visit);
void inorder(TTree root, FunctionType visit);
void postorder(TTree root, FunctionType visit);

void preorderIterative(TTree root, FunctionType visit);
void breadthTraverse(TTree root, FunctionType visit);