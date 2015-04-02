#include "stdafx.h"
#include <malloc.h>

Node* CreateNode(int key, char* value)
{
	Node* result = (Node*)malloc(sizeof(Node));

	result->key = key;
	strcpy_s(result->value, value);

	result->left = NULL;
	result->right = NULL;

	return result;
}


void FreeNode(Node* item)
{
	if (!item) return;

	if (item->left) FreeNode(item->left);
	if (item->right) FreeNode(item->right);

	free(item);
}

Node* InsertNode(Node* root, Node* item)
{
	if (!root) return NULL;
	if (!item) return NULL;

	if (item->key < root->key)
	{
		if (root->left) root->left = InsertNode(root->left, item);
		else root->left = item;
	}
	else if (item->key > root->key)
	{
		if (root->right) root->right = InsertNode(root->right, item);
		else root->right = item;
	}
	else
	{
		strcpy_s(root->value, item->value);
		FreeNode(item);
	}

	return root;
}

void PrintNode(Node* root)
{
	PrintNode(root, 0);
}

void PrintNode(Node* root, int depth)
{
	if (!root) return;

	if (root->left) PrintNode(root->left, depth + 1);

	for (int i = 0; i < depth; i++) printf("  ");
	printf("%d : %s\n", root->key, root->value);

	if (root->right) PrintNode(root->right, depth + 1);
}
