/*
источник:
https://www.educba.com/binary-tree-program-in-c/
Вообще, хороший сайт для изучения С (много маленьких программ)
Example #1: C program for insertion in a Binary tree


A program to print binary tree in 2D 
source : https://www.geeksforgeeks.org/print-binary-tree-2-dimensions/
video to the code: https://www.youtube.com/watch?v=eY3SZLGCK2E

Doesnt work with the cycle, so I commented

The function insert implies ORDERED binary tree, so it is Binary Search Tree

*/

#include<stdio.h>
#include<stdlib.h> // malloc



struct BTnode
{
	int keyVal;
	struct BTnode *leftNode;
	struct BTnode *rightNode;
};
struct BTnode *getNode(int value)
{
	struct BTnode *newNode = malloc(sizeof(struct BTnode));
	newNode->keyVal = value;
	newNode->leftNode = NULL;
	newNode->rightNode = NULL;
	return newNode;
}
//insert is written with ordering
struct BTnode *insert(struct BTnode *rootNode, int value)
{
	if(rootNode == NULL)
		return getNode(value);
	if(rootNode->keyVal < value)
		rootNode->rightNode = insert(rootNode->rightNode,value);
	else if(rootNode->keyVal > value)
		rootNode->leftNode = insert(rootNode->leftNode,value);
	return rootNode;
}


void inOrder(struct BTnode *rootNode)
{
	//printing in triangle: left Root right
	if(rootNode == NULL)
		return;
	inOrder(rootNode->leftNode);
	printf("%d ",rootNode->keyVal);
	inOrder(rootNode->rightNode);
}



void preOrder(struct BTnode *rootNode)
{
	//printing in triangle:  Root left right
	if(rootNode == NULL)
		return;
	printf("%d ",rootNode->keyVal);		
	preOrder(rootNode->leftNode);
	preOrder(rootNode->rightNode);
}



void postOrder(struct BTnode *rootNode) // from South_west
{
	if(rootNode == NULL)
		return;	
	postOrder(rootNode->leftNode);
	postOrder(rootNode->rightNode);
	printf("%d ",rootNode->keyVal);	
}


/***************************print function*************/


#define COUNT 10
// Function to print binary tree in 2D
// It does reverse inorder traversal
void print2DUtil(struct BTnode *root, int space)
{
	// Base case
	if (root == NULL)
		return;

	// Increase distance between levels
	space += COUNT;

	// Process right child first
	print2DUtil(root->rightNode, space);

	// Print current node after space
	// count
	printf("\n");
	for (int i = COUNT; i < space; i++)
		printf(" ");
	printf("%d\n", root->keyVal);

	// Process left child
	print2DUtil(root->leftNode, space);
}

// Wrapper over print2DUtil()
void print2D(struct BTnode *root)
{
// Pass initial space count as 0
print2DUtil(root, 0);
}





int main()
{
	struct BTnode *rootNode = NULL;
	rootNode = insert(rootNode,7);
	rootNode = insert(rootNode,4);
	rootNode = insert(rootNode,8);
	rootNode = insert(rootNode,1);
	rootNode = insert(rootNode,5);
	rootNode = insert(rootNode,2);
	rootNode = insert(rootNode,9);
	rootNode = insert(rootNode,3);
	
	// int loopcounter;
	// int randomValue;

	// for (loopcounter = 1; loopcounter <= 10; loopcounter++)
	// {
	// 	randomValue = rand() % 15;
	// 	printf("%d ", randomValue);
	// 	insert(rootNode, randomValue);
	// }

	print2D(rootNode);
	
	printf("\n\nThe inOrder traversal is:\n");
	inOrder(rootNode);

	printf("\n\nThe preOrder traversal is:\n");
	preOrder(rootNode);

	printf("\n\nThe postOrder traversal is:\n");
	postOrder(rootNode);
return 0;
}