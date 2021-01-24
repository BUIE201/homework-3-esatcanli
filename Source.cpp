
#include <iostream>
#include <vector>

using namespace std;

// Copy Paste Binary Tree Code

struct Node
{
	int i;
	Node* pLeft;
	// Points to the node on the left
	Node* pRight;
	// Points to the node on the right

	Node(int iIn) : i(iIn), pLeft(nullptr), pRight(nullptr) {}
	// Of course they are null right now, not pointing anywhere
	 // Node has an int value , a left/right null ptr 
};

void InsertToTree(Node*& pRoot, Node* pNew)
// Don't call by value, if you do it takes a new temp proot on the memory, proot will disappear. We should call by reference. 
{
	if (!pRoot) // If the root node is empty (No Root)
	{
		pRoot = pNew; // Put the new one in the root
		return;
		// If the new-comer is smaller than the current root node
	}

	if (pNew->i <= pRoot->i)
		InsertToTree(pRoot->pLeft, pNew);
	// Recursive, must be careful. 
	// Insert the new one on the left sub-tree
	else
		InsertToTree(pRoot->pRight, pNew);
	// Again, careful.
	// Insert the new one on the right sub-tree
}

void PrintTree(Node* pRoot, int Level)
{
	if (!pRoot)
		return;

	PrintTree(pRoot->pRight, Level + 1);

	for (int i = 0; i < Level; i++)
		cout << "  ";
	cout << pRoot->i << endl;

	PrintTree(pRoot->pLeft, Level + 1);
}

void main()
{
	int i;

	Node* pRoot = nullptr;
	while (true)
	{
		cin >> i;
		if (i == 99)
			break;

		Node* p = new Node(i);
		InsertToTree(pRoot, p);
	}
	vector<int>branch;
	vector<vector<int>>branches;
	PrintTree(pRoot, 1);
}

// Find if this is a leaf. 
bool IsThisALeaf(Node*& pRoot) {
	if (pRoot->pLeft || pRoot->pRight)
		// Left of Root
		// If we are on the left/right of a root 
	{
		return false;
	}
	return true;
}

// Find Branches
void BranchFinding(Node*& pRoot, vector<int> branch, vector<vector<int>>& branches) {
	//Needs to be recursive as well
	if (!pRoot) {
		// If you are not at the root:
		return;
	}
	// Branches need to be a vector

}

// Get the largest sum of int's 
void GetBranchWithLargestSum() {

}


