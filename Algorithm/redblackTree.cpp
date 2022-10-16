#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>
using namespace std;
struct node {
	bool color = true; //1=red,0=black
	int data;
	node* left = NULL; //default are leaf node
	node* right = NULL;
	node* top = NULL; //store the parent node
	node(int data = 0) {
		this->data = data;
	}
};
int _get_height(node* sr)
{
	if (!sr)
		return -1;
	return 1 + max(_get_height(sr->left), _get_height(sr->right));
}

void _display_subtree(node* q, vector<string>& output, int left, int top, int width)
{
	string str = to_string(q->data);
	if (q->color) {
		str += "r";
	}
	else {
		str += "b";
	}

	int left_begin_shift = 1 - (str.length() - 1) / 2;
	for (size_t i = 0; i < str.length() && left + width / 2 + i < output[top].length(); i++)
		output[top][left + width / 2 + left_begin_shift + i] = str[i];

	int branch_off_set = (width + 3) / pow(2, 3);
	int mid = left + width / 2;
	int left_mid = left + (width / 2 - 1) / 2;
	int right_mid = left + width / 2 + 2 + (width / 2 - 1) / 2;

	if (q->left)
	{
		int branch_position = mid - branch_off_set + 1;
		for (int pos = mid + left_begin_shift - 2; pos > branch_position; pos--)
			output[top][pos] = '_';
		output[top + 1][branch_position] = '/';
		for (int pos = branch_position - 1; pos > left_mid + 2; pos--)
			output[top + 1][pos] = '_';
		_display_subtree(q->left, output, left, top + 2, width / 2 - 1);
	}

	if (q->right)
	{
		int branch_position = mid + branch_off_set + 1;
		for (int pos = mid + left_begin_shift + str.length() + 1; pos < branch_position; pos++)
			output[top][pos] = '_';
		output[top + 1][branch_position] = '\\';
		for (int pos = branch_position + 1; pos < right_mid; pos++)
			output[top + 1][pos] = '_';
		_display_subtree(q->right, output, left + width / 2 + 2, top + 2, width / 2 - 1);
	}
}
void _display_tree(node* root)
{
	if (!root)
		return;

	int height = _get_height(root);
	int width_display = 4 * pow(2, height) - 3;
	int height_display = 2 * height + 1;

	vector<string> output(height_display);
	for (size_t i = 0; i < output.size(); i++)
		output[i] = string(width_display + 4, ' ');

	_display_subtree(root, output, 0, 0, width_display);

	for (int row = 0; row < height_display; row++)
		cout << output[row] << endl;
}
node* _search(node* head,int data) {
	while (head != NULL) {
		if (data == head->data) {
			return head;
		}
		else if (data > head->data) {
			head = head->right;
		}
		else if (data < head->data) {
			head = head->left;
		}
	}
	return head;
}
//Insert
void ll(node*& head, node*& temp) {
	temp->color = false;
	temp->right = temp->top;
	temp->right->color = true;
	temp->right->left = NULL;
	temp->top = temp->top->top;
	temp->right->top = temp;
	// If convert to become root node
	if (temp->top == NULL) {
		head = temp;
		return;
	}
	if (temp->top->left->data == temp->right->data) {
		temp->top->left = temp;
	}
	else {
		temp->top->right = temp;
	}
}
void lr(node*& head, node*& temp) {
	temp->right->color = false;
	temp->top->color = true;
	temp->right->left = temp;
	temp->right->right = temp->top;
	temp->right->top = temp->top->top;
	temp->top->left = NULL;
	temp->top->top = temp->right;
	temp->top = temp->right;
	temp->right = NULL;
	temp = temp->top;
	// If convert to become root node
	if (temp->top == NULL) {
		head = temp;
		return;
	}
	if (temp->top->left->data == temp->right->data) {
		temp->top->left = temp;
	}
	else {
		temp->top->right = temp;
	}
}
void rl(node* &head, node* &temp) {
	temp->left->color = false;
	temp->top->color = true;
	temp->left->right = temp;
	temp->left->left = temp->top;
	temp->left->top = temp->top->top;
	temp->top->right = NULL;
	temp->top->top = temp->left;
	temp->top = temp->left;
	temp->left = NULL;
	temp = temp->top;
	if (temp->top == NULL) {
		head = temp;
		return;
	}
	if (temp->top->right->data == temp->left->data) {
		temp->top->right = temp;
	}
	else {
		temp->top->left = temp;
	}
}
void rr(node*& head, node*& temp) {
	temp->color = false;
	temp->left = temp->top;
	temp->left->color = true;
	temp->left->right = NULL;
	temp->top = temp->top->top;
	temp->left->top = temp;
	// If convert to become root node
	if (temp->top == NULL) {
		head = temp;
		return;
	}
	if (temp->top->right->data == temp->left->data) {
		temp->top->right = temp;
	}
	else {
		temp->top->left = temp;
	}
}
void _rotate(node* &head, node* &temp) {
	if (temp->top->right == NULL || temp->top->left == NULL) { //grandparent only have 1 node
		if (temp->top->left != NULL && temp->left != NULL) { //left-left
			ll(head, temp);
		}
		else if (temp->top->left != NULL && temp->right != NULL) { //left-right
			lr(head, temp);
		}
		else if (temp->top->right != NULL && temp->left != NULL) { //right-left
			rl(head, temp);
		}
		else if (temp->top->right != NULL && temp->right != NULL) { //right-right
			rr(head, temp);
		}
	}
	else { //grandparent have two nodes
		if (temp->top->right->color == true && temp->top->left->color == true) 
		{
			temp->top->right->color = false;
			temp->top->left->color = false;
			temp->top->color = true;
			if (temp->top == head)
			{
				temp->top->color = false; //root node always black
				return;
			}
			temp = temp->top->top;
			if (temp->color) {
				_rotate(head, temp);
			}
		}
		else if (temp->top->right->color==true && temp->right->color==true) {
			node* temp2 = temp->left;
			rr(head, temp);
			temp->left->right = temp2;
			temp2->top = temp->left;
		}
		else if (temp->top->left->color == true && temp->right->color == true) {
			node* temp2 = temp->right->left;
			temp->right->top = temp->top;
			temp->top->left = temp->right;
			temp->right->left = temp;
			temp->top = temp->right;
			temp->right = temp2;
			temp2->top = temp;
			temp = temp->top;
			temp2 = temp->right;
			ll(head, temp);
			temp->right->left = temp2;
			temp2->top = temp->right;
		}
		else if (temp->top->right->color == true && temp->left->color == true) {
			node* temp2 = temp->left->right;
			temp->left->top = temp->top;
			temp->top->right = temp->left;
			temp->left->right = temp;
			temp->top = temp->left;
			temp->left = temp2;
			temp2->top = temp;
			temp = temp->top;
			temp2 = temp->left;
			rr(head, temp);
			temp->left->right = temp2;
			temp2->top = temp->left;
		}
		else {
			node* temp2 = temp->right;
			ll(head, temp);
			temp->right->left = temp2;
			temp2->top = temp->right;
		}
	}
}
void _insert(node*& head, int data) {
	node* container = new node(data);
	//Case 1 : Root node
	if (head == NULL) {
		head = container;
		head->color = false;
		return;
	}
	node* temp = head;
	//Add node fisrt
	while (temp != NULL)
	{
		if (temp->data == data)
		{
			return;
		}
		else if (temp->data < data)
		{
			if (temp->right == NULL)
			{
				temp->right = container;
				container->top = temp;
				break;
			}
			temp = temp->right;
		}
		else if (temp->data > data)
		{
			if (temp->left == NULL)
			{
				container->top = temp;
				temp->left = container;
				break;
			}
			temp = temp->left;
		}
	}
	//Solving Red counter problem
	//red one
	if (temp->color) {
		_rotate(head, temp);
	}
}
//Delete;
node* _rr(node*& temp, node*& head)
{
	node* x = temp->left;
	temp->left = x->right;
	if (x->right != NULL)
		x->right->top = temp;
	//root->parent->child = x;
	x->top = temp->top;
	if (temp->top == NULL)
		// if root is Root, Root = x;
		head = x;
	else if (temp->top->left == temp)
		temp->top->left = x;
	else if (temp->top->right == temp)
		temp->top->right = x;
	// x->right = root
	x->right = temp;
	temp->top = x;
	return x;
}
node* _rl(node* &temp,node*& head)
{
	node* y = temp->right;
	temp->right = y->left;
	if (y->left != NULL)
		y->left->top = temp;
	//root->parent->child = y;
	y->top = temp->top;
	if (temp->top == NULL)
		head = y;
	else if (temp->top->left == temp)
		temp->top->left = y;
	else if (temp->top->right == temp)
		temp->top->right = y;
	//y->left = root; 
	y->left = temp;
	temp->top = y;
	return y;
}
node* samebranch(node* temp)
{
	if (temp->top == NULL)
		return NULL;
	if (temp->top->left == temp)
		return temp->top->right;
	else
		return temp->top->left;
}
bool _haschild(node* temp)
{
	if (temp->left != NULL)
		if (temp->left->color == 1)
			return 1;
	if (temp->right != NULL)
		if (temp->right->color == 1)
			return 1;
	return 0;
}
void doubleB(node*& temp, node*& head)
{
	if (temp == head)
		return;
	node* sib = samebranch(temp);
	node* top = temp->top;
	if (sib == NULL)
		doubleB(top, head);
	else
	{
		if (sib->color == 1)
		{
			top->color = 1;
			sib->color = 0;
			if (sib->top->left == sib)
				top = _rr(top, head);
			else
				top = _rl(top, head);
			doubleB(temp, head);
		}
		else
		{
			if (_haschild(sib))
			{
				//sibling is left child of parent (ll or lr case)
				if (sib->top->left == sib)
				{
					// left left case
					if (sib->left != NULL && sib->left->color)
					{
						sib->left->color = sib->color;
						sib->color = top->color;
						top->color = 0;
						top = _rr(top, head);
					}
					else // left right case
					{
						sib->right->color = top->color;
						top->color = 0;
						sib = _rl(sib, head);
						top = _rr(top, head);
					}
				}
				else//sibling is right child of parent (rr or rl case)
				{
					// rigt rigt case
					if (sib->right != NULL && sib->right->color)
					{
						sib->right->color = sib->color;
						sib->color = top->color;
						top->color = 0;
						top = _rl(top, head);
					}
					else // right left case
					{
						sib->left->color = top->color;
						top->color = 0;
						sib = _rr(sib, head);
						top = _rl(top, head);
					}
				}
			}
			else // 
			{
				sib->color = 1;
				if (!top->color)
					doubleB(top, head);
				else
					top->color = 0;
			}
		}
	}
}
node* _maxnode(node* root)
{
	node* temp;
	temp = root;
	while (temp->right != NULL)
		temp = temp->right;
	return temp;
}
void _delete(node*& vDelete, node*& head)
{
	node* uReplace;
	if ((vDelete->left != NULL) && (vDelete->right != NULL))
		uReplace = _maxnode(vDelete->left);
	else if (vDelete->left != NULL)
		uReplace = vDelete->left;
	else if (vDelete->right != NULL)
		uReplace = vDelete->right;
	else
		uReplace = NULL;
	// this bool to flag Black Black case;
	bool uvBlack = ((uReplace == NULL) || (uReplace->color == 0)) && (vDelete->color == 0);
	node* top = vDelete->top;
	node* sib = samebranch(vDelete);
	//Went vDelete is Leaf, mean we can't find uReplace
	if (uReplace == NULL) {
		if (vDelete == head) {
			head = NULL;
		}
		else {
			if (uvBlack)
				doubleB(vDelete,head);
			else if (sib != NULL)
				sib->color = 1;

			if (vDelete->top->left == vDelete)
				top->left = NULL;
			else
				top->right = NULL;
		}
		delete vDelete;
		return;
	}
	//case vDelete have one child
	if (vDelete->left == NULL || vDelete->right == NULL) {
		if (vDelete == head) {
			vDelete->data = uReplace->data;
			vDelete->left = vDelete->right = NULL;
			delete uReplace;
		}
		else {
			//Replace value of vDelete as value of uReplace
			// Delete vDalete 
			if (vDelete->top->left == vDelete)
				top->left = uReplace;
			else
				top->right = uReplace;
			delete vDelete;

			uReplace->top = top;
			// if double black case solve it or uReplace->color = black;
			if (uvBlack)
				doubleB(uReplace,head);
			else
				uReplace->color = 0;
		}
		return;
	}
	//swap value of u and v
	int tmp = vDelete->data;
	vDelete->data = uReplace->data;
	uReplace->data = tmp;
	//Call Recusive to delete uReplace
	_delete(uReplace,head);
}

int mainrbtree()
{
	node* root = NULL;
	int arr[] = {10,15,20,25,30,35,40,45,50,55,60,65,70,75,80,85,90,95};
	int arr1[] = { 15,27,18,40,30,85,70,55,10 };
	cout << "Chu y: r la mau do cua node , b la mau den cua node do." << endl;
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {
		_insert(root, arr[i]);
		cout << "Insert node " << arr[i] << " into red-black tree: " << endl;
		_display_tree(root);
		cout << endl;
	}
	for (int i = 0; i < sizeof(arr1) / sizeof(int); i++) {
		node*temp = _search(root, arr1[i]);
		if (temp==NULL) 
		{
			cout << "Node " << arr1[i] << " doesn't exist in tree: "<<endl;
		}
		else {
			_delete(temp, root);
			cout << "Delete node " << arr1[i] << " from red-black tree: "<<endl;
			_display_tree(root);
		}
	}
	return 0;
}
