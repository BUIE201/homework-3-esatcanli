
#include <iostream>

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

// Trying to understand this. I don't think we need this!
//void Insert(Node*& pRoot, Node* pNewNode)
//{
//	if (!pRoot)
//		pRoot = pNewNode;
//	else
//	{
//		if (pNewNode->i < pRoot->i)
//			Insert(pRoot->pLeft, pNewNode);
//		else
//			Insert(pRoot->pRight, pNewNode);
//	}
//}

// Don't understand this at the moment. Probably don't need this 
//void DeleteNodeWithTwoChildren(Node*& q, Node*& p)
//{
//	if (p->pRight)
//	{
//		// recursive 
//		DeleteNodeWithTwoChildren(q, p->pRight);
//		return;
//	}
//
//	p->i = q->i;
//	q = p;
//	p = p->pLeft;
//}

// I think I don't need this one. 
//void DeleteNodeFromTree(Node*& pRoot, int i)
//{
//	if (!pRoot)
//		return;
//	// If I'm not at the root
//
//	if (pRoot->i < i)
//	{
//		DeleteNodeFromTree(pRoot->pRight, i);
//		return;
//	}
//
//	if (pRoot->i > i)
//	{
//		DeleteNodeFromTree(pRoot->pLeft, i);
//		return;
//	}
//
//	Node* q = pRoot;
//	if (!q->pRight)
//		pRoot = q->pLeft;
//	else if (!q->pLeft)
//		pRoot = q->pRight;
//	else
//		DeleteNodeWithTwoChildren(q, q->pLeft);
//	// Oh, got it! 
//
//	delete q;
//}

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
void BranchFinding(/*somehting goes into here*/) {

}

// Get the largest sum of int's 
void GetBranchWithLargestSum() {

}