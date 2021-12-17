#include "SearchTree.h"
#include "Stack.h"
#include <iostream>

void initTree(TTree& root)
{
	root = nullptr;
}

void initTree(TTree& root, TData elem)
{
	root = new Node;
	root->data = elem;
	root->left = nullptr;
	root->right = nullptr;
}

void destroyTree(TTree& root)
{
	if (root != nullptr)
	{
		destroyTree(root->left);
		destroyTree(root->right);
		delete root;
		root = nullptr;
	}
}

bool isEmpty(TTree root)
{
	return root == nullptr;
}


void insertElement(TTree& root, TData elem)
{
	if (root == nullptr)
		initTree(root, elem);
	else
		if (elem < root->data)
		{
			insertElement(root->left, elem);
		}
		else
		{
			insertElement(root->right, elem);
		}
}

void deleteElement(TTree& root, TData elem)
{
	if (root == nullptr)
		std::cout << "Ёлемент не найден" << '\n';
	else
		if (elem == root->data)
			deleteNode(root);
		else
			if (elem < root->data)
				deleteElement(root->left, elem);
			else
				deleteElement(root->right, elem);

}

void deleteNode(TTree& pNode)
{
	if (pNode->left == 0 && pNode->right == nullptr)
	{
		delete pNode;
		pNode = nullptr;
	}
	else
	{
		TTree delNode;
		if (pNode->left == nullptr || pNode->right == nullptr)
		{
			delNode = pNode;
			if (pNode->left == nullptr)
				pNode = pNode->right;
			else
				pNode = pNode->left;
			delete delNode;
			delNode = nullptr;
		}
		else pNode->data = findSuccessor(pNode->right);
	}
}

int findSuccessor(TTree& pNode)
{
	if (pNode->left == nullptr)
	{
		int elem = pNode->data;
		TTree delNode = pNode;
		pNode = pNode->right;
		delete delNode;
		return elem;
	}
	else 
		return findSuccessor(pNode->left);
}

TTree search(TTree root, TData key)
{
	if (root == nullptr) 
		return nullptr;
	else
		if (key == root->data)
			return root;
		else
			if (key < root->data)
				return search(root->left, key);
			else
				return search(root->right, key);
}



void preorder(TTree root, FunctionType visit)
{
	if (root != nullptr) {
		visit(root->data);
		preorder(root->left, visit);
		preorder(root->right, visit);
	}
}

void inorder(TTree root, FunctionType visit)
{
	if (root != nullptr) {
		inorder(root->left, visit);
		visit(root->data);
		inorder(root->right, visit);
	}
}

void postorder(TTree root, FunctionType visit)
{
	if (root != nullptr) {
		postorder(root->left, visit);
		postorder(root->right, visit);
		visit(root->data);
	}
}

void preorderIterative(TTree root, FunctionType visit)
{
	TStack stack;
	init(stack);

	push(stack, root);

	while (!isEmpty(stack))
	{		
		StackData cur = peek(stack);
		pop(stack);

		visit(cur->data);

		if (cur->right != nullptr) {
			push(stack, cur->right);
		}

		if (cur->left != nullptr) {
			push(stack, cur->left);
		}
	}
}

void breadthTraverse(TTree root, FunctionType visit)
{
	
}