#ifndef NODE_H
#define NODE_H

struct Node
{
	int data;
	Node* left_child;
	Node* right_child;

	Node(int data, Node *left_child = NULL, Node *right_child = NULL):
		data(data),
		left_child(left_child),
		right_child(right_child)
	{}

	void copy(Node node)
	{
		data = node.data;
		left_child = node.left_child;
		right_child = node.right_child;
	}
};

#endif