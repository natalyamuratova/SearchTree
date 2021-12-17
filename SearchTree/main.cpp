#include "SearchTree.h"
#include <iostream>
#include <Windows.h>

void printNode(int& elem);
void deleteLists(TTree& pNode);
int high(TTree root);
void absolute(int& elem);
int countLevelRecursive(TTree root, const int level, int currentLevel);
void minAndMaxLevel(TTree root, int currentLevel, int min[], int max[]);
void initMinAndMax(TTree root, int currentLevel, int min[], int max[]);

int main()
{
    SetConsoleOutputCP(1251);

    TTree root;
    initTree(root);

    std::cout << "Сколько элементов в вашем дереве?" << std::endl;
    int n;
    std::cin >> n;

    std::cout << "Введите элементы дерева" << std::endl;
    int elem;

    for (int i = 0; i < n; i++)
    {
        std::cin >> elem;
        insertElement(root, elem);
    }

    int h = high(root);

    int* max = new int[h];
    int* min = new int[h];

    initMinAndMax(root, 0, min, max);
    minAndMaxLevel(root, 0, min, max);

    for (int i = 0; i < h; i++) {
        std::cout << "Минимальный на уровне " << i << " = " << min[i];
        std::cout << "Mаксимальный на уровне " << i << " = " << max[i];
    }

    delete[] min;
    delete[] max;

    /*std::cout << countLevelRecursive(root, 3, 1) << std::endl;*/

    /*preorder(root, printNode);
    std::cout << std::endl;

    inorder(root, printNode);
    std::cout << std::endl;

    postorder(root, printNode);
    std::cout << std::endl;*/

    /*deleteLists(root);
    preorder(root, printNode);*/

    /*std::cout<<"h="<<high(root);*/

    /*postorder(root, absolute);
    postorder(root, printNode);*/

    /*preorderIterative(root, printNode);*/
}

void printNode(int& elem)
{
    std::cout << elem << " ";
}

void deleteLists(TTree& pNode)
{
    if (pNode != nullptr)
    {
        if (pNode->left == nullptr && pNode->right == nullptr)
        {
            delete pNode;
            pNode = nullptr;
        }
        else
        {
            deleteLists(pNode->left);
            deleteLists(pNode->right);
        }
    }
}

int high(TTree root)
{
    if (root == nullptr)
        return 0;
    else
    {
        int hLeft = high(root->left);
        int hRight = high(root->right);
        return (hLeft > hRight ? hLeft : hRight) + 1;
    }
}

void absolute(int& elem)
{
    if (elem < 0)
        elem = -elem;
}

int countLevelRecursive(TTree root, const int level, int currentLevel) {
    if (root == nullptr)
        return 0;
    if (currentLevel == level)
        return 1;
    return countLevelRecursive(root->left, level, currentLevel + 1) + countLevelRecursive(root->right, level, currentLevel + 1);
}

void initMinAndMax(TTree root, int currentLevel, int min[], int max[]) {
    if (root != nullptr) {
        min[currentLevel] = root->data;
        max[currentLevel] = root->data;
        initMinAndMax(root->left, currentLevel + 1, min, max);
        initMinAndMax(root->right, currentLevel + 1, min, max);
    }
}

void minAndMaxLevel(TTree root, int currentLevel, int min[], int max[]) {
    if (root != nullptr) {
        if (root->data < min[currentLevel])
            min[currentLevel] = root->data;
        else if (root->data > max[currentLevel])
            max[currentLevel] = root->data;
        minAndMaxLevel(root->left, currentLevel + 1, min, max);
        minAndMaxLevel(root->right, currentLevel + 1, min, max);
    }
}