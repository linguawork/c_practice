/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   22_04_10_BinaryTreeTraverse.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 15:59:30 by areggie           #+#    #+#             */
/*   Updated: 2022/04/10 16:05:08 by areggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
программа на бинарном дереве с примером прохода по веткам дерева в трех порядках

источник: https://www.programiz.com/dsa/binary-tree

Описание такого же кода есть и в песочнице по плюсам. Там я описал более детально 
*/

// Tree traversal in C

#include <stdio.h>
#include <stdlib.h>

struct node 
{
  int item;
  struct node* left;
  struct node* right;
};

// Inorder traversal
void inorderTraversal(struct node* root) 
{
  if (root == NULL) // защита от нуля
  		return;
  inorderTraversal(root->left);
  printf("%d ->", root->item);
  inorderTraversal(root->right);
}

// Preorder traversal
void preorderTraversal(struct node* root) 
{
  if (root == NULL)
		return;
  printf("%d ->", root->item);
  preorderTraversal(root->left);
  preorderTraversal(root->right);
}

// Postorder traversal
void postorderTraversal(struct node* root) 
{
  if (root == NULL)
  		return;
  postorderTraversal(root->left);
  postorderTraversal(root->right);
  printf("%d ->", root->item);
}

// Create a new Node
struct node* createNode(value) 
{
  struct node* newNode = malloc(sizeof(struct node));
  newNode->item = value;
  newNode->left = NULL;
  newNode->right = NULL;

  return newNode;
}

// Insert on the left of the node
struct node* insertLeft(struct node* root, int value) 
{
  root->left = createNode(value);
  return root->left;
}

// Insert on the right of the node
struct node* insertRight(struct node* root, int value) 
{
  root->right = createNode(value);
  return root->right;
}

int main() 
{
  struct node* root = createNode(1);
  insertLeft(root, 2);
  insertRight(root, 3);
  insertLeft(root->left, 4);

  printf("Inorder traversal \n");
  inorderTraversal(root);

  printf("\nPreorder traversal \n");
  preorderTraversal(root);

  printf("\nPostorder traversal \n");
  postorderTraversal(root);
}

