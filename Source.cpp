
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


// Find if this is a leaf. 
bool IsThisALeaf(Node*& pRoot) {
	if (pRoot->pLeft || pRoot->pRight)
		// Left of Root
		// Ift there is a pointer pointing to a left or a right side of a node, then it's not a leaf!
	{
		return false;
	}
	// Otherwise it is. 
	return true;
}

// Find Branches
void BranchFinding(Node*& pRoot, vector<int> branch, vector<vector<int>>& branches) {
	//Needs to be recursive as well
	if (!pRoot) {
		// If you are null
		return;
	}
	branch.push_back(pRoot->i);
	// Create the "branch" here push the i of root here
	if (IsThisALeaf(pRoot)) {
		// Check if root
		branches.push_back(branch);
		// Create a vector for branches and put "branch" here
		branch.clear();
		// Clear branch for recursive
	}
	else {
		BranchFinding(pRoot->pLeft, branch, branches);
		// If you are on the left side, then send it back to the top for the below node. 
		BranchFinding(pRoot->pRight, branch, branches);
		// If you are on the right side, then send it back to the top for the below node. 
	}


	// Branches need to be a vector

}

// Get the largest sum of int's 
void GetBranchWithLargestSum(vector<vector<int>>& branches) {
	int mostSum = 0;
	int branchIndex = 0;
	for (int i = 0; i < branches.size(); i++) {
		int sumForBranch = 0;
		for (int j = 0; j < branches[i].size();j++) {
			sumForBranch += branches[i][j];
		}
		if (sumForBranch >= mostSum) {
			branchIndex = i;
			mostSum = sumForBranch;
		}

	}
	cout << "Branch with largest sum is: ";
	for (int i : branches[branchIndex]) {
		cout << i << " ";
	}
	cout << "-> SUM = " << mostSum;

}


int main()
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
	BranchFinding(pRoot, branch, branches);
	GetBranchWithLargestSum(branches);

	return 0;

}

