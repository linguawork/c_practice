/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BinarySearchTreeUdemy.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 11:03:20 by areggie           #+#    #+#             */
/*   Updated: 2022/05/26 13:14:22 by areggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
from Udemy course 
Advanced C Programming COurse
https://www.udemy.com/course/advanced-c-programming-course/learn/lecture/17962368#overview

the prog is written on CodeBlocks

it inserts the value via rand and prints 3 types of traversal

The code sucks, it does not print all the nodes

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*slef-referential structure*/
struct treeNode
{
	int data; /*node value*/ 
	struct treeNode *leftPtr; /* pointer to left subtree*/
	struct treeNode *rightPtr; /*pointer ti right subtree*/	
};

typedef struct treeNode TreeNode;  // we turned our struct treeNode into *TreeNodePtr;
typedef TreeNode *TreeNodePtr; 

void insertNode (TreeNodePtr *treePtr, int value );
void inOrder(TreeNodePtr treePtr); // for traversal
void preOrder(TreeNodePtr treePtr);
void postOrder(TreeNodePtr treePtr); 
 

int main()
{
	int		loopcounter; 
	int		randomValue;


/*init stage*/
	loopcounter = 0; 
	randomValue = 0; 
	TreeNodePtr rootPtr = NULL;  /* init tree which is empty*/ 

	srand(time(NULL));
	printf("The numbers being placed in the tree are:\n");

/*insert random value from 0 to 14 into the tree*/
	for (loopcounter = 1; loopcounter <= 10; loopcounter++)
	{
		randomValue = rand() % 15;
		printf("%d ", randomValue);
		insertNode(&rootPtr, randomValue);
	}
	
	printf("\n\nThe preOrder traversal is:\n");
	preOrder(rootPtr);
	
	printf("\n\nThe inOrder traversal is:\n");
	inOrder(rootPtr);

	printf("\n\nThe postOrder traversal is:\n");
	postOrder(rootPtr);

	return 0; /*indicates successful termination*/
} 

void insertNode (TreeNodePtr *treePtr, int value )
{
	/* if the structure has nothing */
	if (*treePtr == NULL) 
	{
		*treePtr = malloc(sizeof(TreeNode)); // we init the memory for the struct
	}
	/*if memory was allocated then assign data*/
	if (*treePtr != NULL)
	{
		(*treePtr)->data = value;
		(*treePtr)->leftPtr = NULL;
		(*treePtr)->rightPtr = NULL;
	}
	else /*tree is not empty, the node has a number*/
	{
		/*if val less than number in the node we insert to left*/
		if (value < (*treePtr)->data) 
			insertNode(&((*treePtr)->leftPtr), value);//recursion
		
		if (value > (*treePtr)->data) 
			insertNode(&((*treePtr)->rightPtr), value);
		if (value == (*treePtr)->data) 
			printf("the duplicate value\n");
		
	}
	
}

// Inorder traversal
void inOrder(TreeNodePtr treePtr) 
{
  	if (treePtr != NULL) // checking if it is not empty
	{
		inOrder(treePtr->leftPtr);//recursion
		printf("%3d", treePtr->data);
		inOrder(treePtr->rightPtr);
	}
}

// PreOrder traversal
void preOrder(TreeNodePtr treePtr) 
{
  	if (treePtr != NULL) // checking if it is not empty
	{
		printf("%3d", treePtr->data);
		preOrder(treePtr->leftPtr);//recursion
		preOrder(treePtr->rightPtr);
	}
}

// PreOrder traversal
void postOrder(TreeNodePtr treePtr) 
{
  	if (treePtr != NULL) // checking if it is not empty
	{
		postOrder(treePtr->leftPtr);//recursion
		postOrder(treePtr->rightPtr);
		printf("%d", treePtr->data);
	}
}

