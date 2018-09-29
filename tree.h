#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <vector>
#include "node.h"
#include "iterator.h"

class Tree
{
private:
	Node* root;
	int weight;

public:
	Tree():
		root(NULL),weight(0){}

	Iterator begin()
	{
		Iterator start(root);
		return start;
	}

	int getWeight()
	{
		return weight;
	}

	void insert(int data)
	{
		
		if (root == NULL)
		{
			weight++;
			root = new Node (data);
		}

		else if (data < root->data)
			insert(data,root->left_child);

		else if (data > root->data)
			insert(data,root->right_child);
			
		else
			std::cout << "Value already in binary tree! It won't be added." << std::endl;
	}
	
	
	void printInOrder()
	{
		if (root == NULL)
			return;
		
		printInOrder(root->left_child);
		std::cout << root->data << " ";
		printInOrder(root->right_child);
		std::cout << std::endl;
	}

	void printPreOrder()
	{
		if (root == NULL)
			return;
		
		std::cout << root->data << " ";
		printPreOrder(root->left_child);
		printPreOrder(root->right_child);
		std::cout << std::endl;
	}

	void printPostOrder()
	{
		if (root == NULL)
			return;
		
		printPostOrder(root->left_child);
		printPostOrder(root->right_child);
		std::cout << root->data << " ";
		std::cout << std::endl;
	}

	int height()
	{
		if(root == NULL)
			return 0;

		int left = height(root->left_child)+1;
		int right = height(root->right_child)+1;
		if(left > right)
			return left;
		return right;
	}


//ITERATION FUNCTIONS
private:

	void insert(int data, Node* &node)
	{
		
		if (node == NULL)
		{
			weight++;
			node = new Node (data);
		} 

		else if (data < node->data)
			insert(data,node->left_child);

		else if (data > node->data)
			insert(data,node->right_child);
			
		else
			std::cout << "Value already in binary tree! It won't be added." << std::endl;
	}

	void printInOrder(Node* node)
	{
		if (node == NULL)
			return;
		
		printInOrder(node->left_child);
		std::cout << node->data << " ";
		printInOrder(node->right_child);
	}
	
	void printPreOrder(Node* node)
	{
		if (node == NULL)
			return;
		
		std::cout << node->data << " ";
		printPreOrder(node->left_child);
		printPreOrder(node->right_child);
	}

	void printPostOrder(Node* node)
	{
		if (node == NULL)
			return;
		
		printPostOrder(node->left_child);
		printPostOrder(node->right_child);
		std::cout << node->data << " ";
	}

	int height(Node* node)
	{
		if(node == NULL)
			return 0;

		int left = height(node->left_child)+1;
		int right = height(node->right_child)+1;
		
		if(left > right)
			return left;
		return right;
	}


};

#endif