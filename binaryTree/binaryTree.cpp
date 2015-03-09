// binaryTree.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"




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

