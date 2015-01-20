// binaryTree.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#define NODE_LENGTH 15

//http://ru.wikipedia.org/wiki/Двоичное_дерево_поиска
//АВЛ-деревья
//http://habrahabr.ru/post/150732/ 

struct Node
{
	int key;
	int height;
	char value[NODE_LENGTH];
	Node *left;
	Node *right;
};

Node* CreateNode(int key, char value[NODE_LENGTH]);

Node* InsertNode(Node* root, Node* newNode);

Node* DeleteNode(Node* root, int deletedKey);

void PrintNode(Node* root);
void PrintNode(Node* root, int deep);


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

Node* CreateNode(int key, char value[NODE_LENGTH])
{
	Node* result = new Node;
	result->key = key;
	strncpy_s(result->value, value, NODE_LENGTH);
	result->height = 1;
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
			newNode->height = root->height + 1;
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
			newNode->height = root->height + 1;
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
		newNode->height = root->height;

		delete root;

		return newNode;
	}
}

Node* DeleteNode(Node* parent, Node* current, int deletedKey)
{
	//Если дерево T пусто, остановиться;
	if (NULL == current) return NULL;

	//Иначе сравнить K с ключом X корневого узла n. 
	if (deletedKey > current->key)
	{
		//Если K>X, циклически удалить K из правого поддерева Т;
		current->right = DeleteNode(current, current->right, deletedKey);
		return current;
	}

	//Иначе сравнить K с ключом X корневого узла n. 
	else if (deletedKey < current->key)
	{
		//Если K<X, циклически удалить K из левого поддерева Т;
		current->left = DeleteNode(current, current->left, deletedKey);
		return current;
	}

	//Если K=X, то необходимо рассмотреть три случая. 
	else
	{
		Node* result = NULL;

		//Если обоих детей нет, то 
		if (NULL == current->left  && NULL == current->right)
		{
			//удаляем текущий узел и обнуляем ссылку на него у родительского узла;
			delete current;
			return result;
		}
		//Если нет правого ребенка
		else if (NULL != current->left  && NULL == current->right)
		{		
			//возвращаем ссылку на левого ребенка
			result = current->right;
			//удаляем текущий узел
			delete current;
			return result;
		}
		//Если нет левого ребенка
		else if (NULL == current->left  && NULL != current->right)
		{		
			//возвращаем ссылку на правого ребенка
			result = current->right;
			//удаляем текущий узел
			delete current;
			return result;
		}
		//Если оба ребёнка присутствуют, то 
		else if (NULL != current->left  && NULL != current->right)
		{
			result = current->right;
			//Если левый узел m правого поддерева отсутствует (n->right->left) 
			if (NULL == result->left)
			{
				//смещаем правый узел вверх и добавляем к нему левый
				result->left = current->left;
				delete current;
				return result;
			}
			else
			{
				Node* lastLeft = current->right;
				//возьмем самый левый узел m, правого поддерева n->right;
				while (lastLeft->left != NULL)	lastLeft = lastLeft->left;

				//скопируем данные (кроме ссылок на дочерние элементы) из m в n;
				current->key = lastLeft->key;
				strncpy_s(current->value, lastLeft->value, NODE_LENGTH);
				
				//рекурсивно удаляем его со старого места
				current->right = DeleteNode(current, current->right, current->key);

				return current;
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
	printf("%d(%d) key: %d value: %s\n", deep, root->height, root->key, root->value);

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

