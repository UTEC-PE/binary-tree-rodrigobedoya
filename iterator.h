#ifndef ITERATOR_H
#define ITERATOR_H
#include <vector>
#include "tree.h"

class Iterator
{
	friend class Tree;
public:

	Iterator operator ++()
	{
		increment();
		return *this;
	}

	Iterator operator +(int number)
	{
		for(int i = 0; i < number;i++)
		{
			increment();
		}
		return *this;
	}

	Node* operator *()
	{
		return current;
	}

protected:

	std::vector<Node*> nodes;
	Node* current;
	
	Iterator(Node* node)
	{
		current = leftMostFrom(node);
	}


	Node* leftMostFrom(Node* node)
	{
		if(node->left_child == NULL)
			return node;
		nodes.push_back(node);
		return leftMostFrom(node->left_child);
	}


	

	void increment()
	{
		if(current->left_child== NULL && current->right_child==NULL)
		{
			current = nodes.back();
		}

		else if(current == nodes.back())
		{
			if(current->right_child!=NULL)
			{
				current = current->right_child;
				nodes.pop_back();
				current = leftMostFrom(current);
			}
			else
			{
				nodes.pop_back();
				current = nodes.back();
			}
		}

		else
		{
			current = current->right_child;
			current = leftMostFrom(current);
		}
	}
};

#endif