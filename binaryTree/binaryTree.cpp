// binaryTree.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

//https://ru.wikipedia.org/wiki/%D0%90%D0%92%D0%9B-%D0%B4%D0%B5%D1%80%D0%B5%D0%B2%D0%BE

Node* BalanceRotation(Node*);

Node* SmallLeftRotation(Node*);
Node* BigLeftRotation(Node*);

Node* SmallRightRotation(Node*);
Node* BigRightRotation(Node*);

int GetHeight(Node* root);

int main(int argc, _TCHAR* argv[])
{
	//printf("hello world");

	Node* root = CreateNode(4, "hello world");
	Node* newItem = CreateNode(5, "fun!");
	root = InsertNode(root, newItem);



	PrintNode(root);

	getchar();
	return 0;
}

Node* BalanceRotation(Node* root)
{
	int left = GetHeight(root->left);
	int right = GetHeight(root->right);

	if (right > left + 1 && root->right)
	{
		left = GetHeight(root->right->left);
		right = GetHeight(root->right->right);

		if (left <= right) return SmallLeftRotation(root);
		else if (root->right->left) return BigLeftRotation(root);
	}
	else if (left > right + 1 && root->left)
	{
		left = GetHeight(root->left->left);
		right = GetHeight(root->left->right);

		if (right <= left) return SmallRightRotation(root);
		else if (root->left->right) return BigRightRotation(root);
	}
	//иначе в балансировке не нуждается
}

Node* SmallLeftRotation(Node* root)
{
	Node* aNode = root;
	Node* bNode = aNode->right;
	Node* centralSubTree = bNode->left;

	aNode->right = centralSubTree;
	bNode->left = aNode;

	return bNode;
}

Node* BigLeftRotation(Node* root)
{
	Node* aNode = root;
	Node* bNode = aNode->right;
	Node* cNode = bNode->left;

	Node* mSubTree = cNode->left;
	Node* nSubTree = cNode->right;

	aNode->right = mSubTree;
	cNode->left = aNode;
	cNode->right = bNode;
	bNode->left = nSubTree;

	return cNode;
}

Node* SmallRightRotation(Node* root)
{
	Node* aNode = root;
	Node* bNode = aNode->left;
	Node* centralSubTree = bNode->right;

	aNode->left = centralSubTree;
	bNode->right = aNode;

	return bNode;
}

Node* BigRightRotation(Node* root)
{
	Node* aNode = root;
	Node* bNode = aNode->left;
	Node* cNode = bNode->right;

	Node* mSubTree = cNode->right;
	Node* nSubTree = cNode->left;

	bNode->right = mSubTree;
	cNode->left = bNode;
	cNode->right = aNode;
	aNode->left = nSubTree;

	return cNode;
}


int GetHeight(Node* root)
{
	int result = 0;

	if (!root) return 0;
	else result = 1;

	int subHeight = GetHeight(root->left);
	if (result < 1 + subHeight) result = 1 + subHeight;

	subHeight = GetHeight(root->right);
	if (result < 1 + subHeight) result = 1 + subHeight;

	root->height = result;
	return result;
}
