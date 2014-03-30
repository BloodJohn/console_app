// binaryTree.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#define NODE_LENGTH 15

//http://ru.wikipedia.org/wiki/Двоичное_дерево_поиска
struct Node
{
	int key;
	char value[NODE_LENGTH];
	Node *left;
	Node *right;
};

Node* CreateNode(int key, char value[NODE_LENGTH]);

Node* InsertNode(Node* root, Node* newNode);

Node* DeleteNode(Node* root, int deletedKey);

void PrintNode(Node* root);
void PrintNode(Node* root, int deep);


int _tmain(int argc, _TCHAR* argv[])
{
	//printf("hello world");

	Node* root = CreateNode(4, "hello world");
	Node* newItem = CreateNode(5, "fun!");
	root = InsertNode(root, newItem);



	PrintNode(root);

	getchar();
	return 0;
}

Node* CreateNode(int key, char value[NODE_LENGTH])
{
	Node* result = new Node;
	result->key = key;
	strncpy_s(result->value, value, NODE_LENGTH);
	result->left = NULL;
	result->right = NULL;

	return result;
}

Node* InsertNode(Node* root, Node* newNode)
{
	if (NULL == root) return NULL;
	if (NULL == newNode) return root;

	if (newNode->key < root->key) //Вставляем влево
	{
		if (NULL == root->left)
		{
			root->left = newNode;
		}
		else
		{
			root->left = InsertNode(root->left, newNode);
		}

		return root;
	}
	else if (newNode->key > root->key) //Вставляем вправо
	{
		if (NULL == root->right)
		{
			root->right = newNode;
		}
		else
		{
			root->right = InsertNode(root->right, newNode);
		}

		return root;
	}
	else //Когда они равны - заменяем
	{
		newNode->left = root->left;
		newNode->right = root->right;
		delete root;

		return newNode;
	}
}

Node* DeleteNode(Node* root, int deletedKey)
{
	//Если дерево T пусто, остановиться;
	if (NULL == root) return NULL;

	//Иначе сравнить K с ключом X корневого узла n. 
	if (deletedKey > root->key)
	{
		//Если K>X, циклически удалить K из правого поддерева Т;
		root->right = DeleteNode(root->right, deletedKey);
		return root;
	}

	//Иначе сравнить K с ключом X корневого узла n. 
	else if (deletedKey < root->key)
	{
		//Если K<X, циклически удалить K из левого поддерева Т;
		root->left = DeleteNode(root->left, deletedKey);
		return root;
	}

	//Если K=X, то необходимо рассмотреть три случая. 
	else
	{
		//Если обоих детей нет, то 
		if (NULL == root->left  && NULL == root->right)
		{
			//удаляем текущий узел и обнуляем ссылку на него у родительского узла;

		}
		//Если нет правого ребенка
		else if (NULL != root->left  && NULL == root->right)
		{
			//удаляем текущий узел
			//возвращаем ссылку на левого ребенка
		}
		//Если нет левого ребенка
		else if (NULL == root->left  && NULL != root->right)
		{
			//удаляем текущий узел
			//возвращаем ссылку на правого ребенка
		}
		//Если оба ребёнка присутствуют, то 
		else if (NULL != root->left  && NULL != root->right)
		{
			//Если левый узел m правого поддерева отсутствует (n->right->left) 
			if (NULL == root->right->left)
			{
				//смещаем правый узел вверх и добавляем к нему левый
			}
			else
			{
				//возьмем самый левый узел m, правого поддерева n->right;
				//рекурсивно удаляем его со старого места
				//переносим удаленный (самый левый) в корень
			}
		}
	}
}

void PrintNode(Node* root)
{
	PrintNode(root, 0);
}

void PrintNode(Node* root, int deep)
{
	if (NULL == root) return;

	for (int i = 0; i<deep; i++) printf("  ");
	printf("%d key: %d value: %s\n", deep, root->key, root->value);

	if (root->left != NULL)
	{
		for (int i = 0; i<deep; i++) printf("  ");
		printf("left:\n");
		for (int i = 0; i<deep; i++) printf("  ");
		PrintNode(root->left, deep + 1);
	}

	if (root->right != NULL)
	{
		for (int i = 0; i<deep; i++) printf("  ");
		printf("right:\n");
		for (int i = 0; i<deep; i++) printf("  ");
		PrintNode(root->right, deep + 1);
	}
}

