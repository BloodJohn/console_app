struct Node
{
	int key;
	char value[50];
	int height;
	Node* left;
	Node* right;
};

Node* CreateNode(int key, char* value);
void FreeNode(Node* item);

Node* InsertNode(Node* root, Node* item);

void PrintNode(Node* root);
void PrintNode(Node* root, int depth);