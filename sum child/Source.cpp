#include<iostream>
using namespace std;
class bnode {
public:
	int data;
	int height;
	bnode* left;
	bnode* right;
	bnode* parent;
public:
	bnode(int x)
	{
		data = x;
		height = 1;
		left = nullptr;
		right = nullptr;
		parent = nullptr;
	}
	friend class bst;
};
class bst
{
public:
	bnode* node;
	bnode* findMax(bnode* node)
	{
		if (node == nullptr || node->right == nullptr)
		{
			return node;
		}
		return findMax(node->right);
	}
	bnode* insert(bnode* root, int value)
	{

		if (root == nullptr)
		{
			bnode* newnode = new bnode(value);
			return newnode;
		}
		if (value < root->data) {
			bnode* n = insert(root->left, value);
			root->left = n;
			n->parent = root;
			return root;
		}
		else if (value > root->data)
		{
			bnode* n = insert(root->right, value);
			root->right = n;
			n->parent = root;
			return root;
		}
		else if (value == root->data)
		{
			cout << "insertion not possible:" << endl;
			return root;
		}
		return root;
	}
	void inorder(bnode* root) {
		if (root == nullptr)
		{
			return;
		}
		inorder(root->left);
		cout << root->data << " ";
		inorder(root->right);
	}

	void postorder(bnode* root) {
		if (root == nullptr)
		{
			return;
		}
		postorder(root->left);
		postorder(root->right);
		cout << root->data << " ";
	}
	int l, r;
	int c = 0;
	int sum = 0;
	void adpostorder(bnode* root) {
		if (root == nullptr)
		{
			return;
		}
		adpostorder(root->left);
		adpostorder(root->right);
		if (c == 0) {
			cout << root->data << " ";
			l = root->data;
			c++;
		}
		else if (c == 1) {
			cout << root->data << " ";
			r = root->data;
			c++;
		}
		else {
			cout << root->data << endl;
			sum = l + r;
			root->data = sum;
			cout << "after sum" << root->data << endl;
			c = 0;
		}

	}
	void preorder(bnode* root) {
		if (root == nullptr)
		{
			return;
		}
		cout << root->data << " ";
		preorder(root->left);
		preorder(root->right);
	}
	//void addpostorder(bnode* root) {
	//	bnode* parent;
	//	
	//	
	//	if (root == nullptr)
	//	{
	//		return;
	//	}
	//	parent = root;
	//	/*if (parent->left == nullptr && parent->left) {
	//		postorder(parent->parent->right)
	//	}*/
	//	else if (parent->left == nullptr) {
	//		addpostorder(parent->right);
	//	}
	//	else if (parent->right == nullptr) {

	//	}
	//	else {

	//	}
	//}

};
int main() {

	bnode* root = nullptr;
	bst t1;
	int value = 0;
	root = t1.insert(root, 7);
	root = t1.insert(root, 5);
	root = t1.insert(root, 9);
	root = t1.insert(root, 4);
	root = t1.insert(root, 6);
	root = t1.insert(root, 8);
	root = t1.insert(root, 10);

	cout << " inorder\n" << endl;
	t1.adpostorder(root);
	root->data = root->left->data + root->right->data;
	cout << endl;
	t1.preorder(root);

}