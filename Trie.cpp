struct Node
{
	bool flag = false;
	Node *a[26];
};

Node *getNode()
{
	struct Node *temp = new Node;
	temp->flag = false;
	for(int i = 0 ; i < 26; i++)
	{
		temp->a[i] = NULL;
	}
	return temp;
}

void insert(struct Node* root, string key)
{
	struct Node *temp = root;
	for(int i = 0; i < key.size(); i++)
	{
		int idx = key[i] - 'a';
		if(temp->a[idx] == NULL)
		{
			temp->a[idx] = getNode();
		}
		temp = temp->a[idx];
	}
	temp->flag = true;
}

bool search(struct Node* root, string key)
{
	struct Node* temp = root;
	for(int i = 0; i < key.size(); i++)
	{
		int idx = key[i]-'a';
		if(!temp->a[idx])
			return false;
		temp = temp->a[idx];
	}
	return (temp != NULL && temp->flag == true);
}
