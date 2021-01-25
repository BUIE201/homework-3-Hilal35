
#include <iostream>

using namespace std;

struct Node
{
	int i;
	Node* pLeft;
	Node* pRight;

	Node(int iIn) : i(iIn), pLeft(nullptr), pRight(nullptr) {}
};



Node* createTree() {
	/*
		  5
         / \
        4   8
       /   / \
      11  13  4
     /  \      \
    7    2      1

	*/
	Node* pRoot = new Node(5);

	
	pRoot->pLeft = new Node(4);
	pRoot->pRight = new Node(8);
	pRoot->pLeft->pLeft = new Node(11);
	pRoot->pRight->pLeft = new Node(13);
	pRoot->pRight->pRight = new Node(4);
	pRoot->pLeft->pLeft->pLeft = new Node(7);
	pRoot->pLeft->pLeft->pRight = new Node(2);
	pRoot->pRight->pRight->pRight = new Node(1);

	return pRoot;
}

bool PrintBranch(Node* root, int sum)
{
    
    if (sum == 0)
        return true;

    
    if (root == nullptr)
        return false;

   
    bool left = PrintBranch(root->pLeft, sum - root->i);
    bool right = PrintBranch(root->pRight, sum - root->i);

    
    if (left || right)
        
        cout << root->i << " ";

    return left || right;
}


int FindMaxSum(Node* root)
{
   
    if (root == nullptr)
        return 0;

   
    int left = FindMaxSum(root->pLeft);

   
    int right = FindMaxSum(root->pRight);

   
    return (left > right ? left : right) + root->i;
}



void FindMaxSumBranch(Node* root)
{
    int sum = FindMaxSum(root);
   
    cout << "Branch with the largest sum is: ";

    PrintBranch(root, sum); 
    cout << "-> SUM  " << sum << endl;
}

void main()
{
	int i;
	   
	Node* mytree = createTree();
	

    FindMaxSumBranch(mytree);
	
	
}