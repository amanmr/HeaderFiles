#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class treeNode
{
public:
  int data;
  treeNode *left;
  treeNode *right;

  treeNode(int d) // constructor
  {
    data = d;
    left = NULL;
    right = NULL;
  }
};


//....................BUILD FROM PREORDER AND INORDER HELPER......................//

treeNode *buildTreePIHelper(vector<int> &preorder, vector<int> &inorder, int s, int e, int &i)
  {
    if (s > e)
      return NULL;
    treeNode *root = new treeNode(preorder[i]);
    int location = -1;
    for (int k = s; k <= e; k++)
    {
      if (inorder[k] == preorder[i])
      {
        location = k;
        break;
      }
    }
    i++;
    root->left = buildTreePIHelper(preorder, inorder, s, location - 1, i);
    root->right = buildTreePIHelper(preorder, inorder, location + 1, e, i);
    return root;
  }

//....................BUILD FROM PREORDER AND INORDER......................//
  treeNode *buildTreePI(vector<int> &preorder, vector<int> &inorder)
  {
    int i = 0;
    return buildTreePIHelper(preorder, inorder, 0, preorder.size() - 1, i);
  }

  //....................PREORDER......................//
  void preorderPrint(treeNode *root)
  {
    if (root == NULL) return;
    cout << root->data << " ";
    preorderPrint(root->left);
    preorderPrint(root->right);
  }


  //....................INORDER......................//
  void inorderPrint(treeNode *root) 
  {
    if (root == NULL) return;
    inorderPrint(root->left);
    cout << root->data << " ";
    inorderPrint(root->right);
  }


  //....................POSTORDER......................//
  void postorderPrint(treeNode *root) 
  {
    if (root == NULL) return;
    postorderPrint(root->left);
    postorderPrint(root->right);
    cout << root->data << " ";
  }

  //....................LEVEL ORDER TRAVERSAL......................//
  void bfs(treeNode *root) {
    if(root==NULL) return;
    queue<treeNode*> q;
    q.push(root);
    while (!q.empty())
    {
      treeNode *front = q.front();
      q.pop();
      cout << front->data << " ";
      if (front->left != NULL)
      {
        q.push(front->left);
      }
      if (front->right != NULL)
      {
        q.push(front->right);
      }
    }
  }

  //....................TOTAL NUMBER OF NODES......................//
  int totalNodes(treeNode *root)
  {
    if (root == NULL) return 0;

    int left = totalNodes(root->left);
    int right = totalNodes(root->right);

    return left + right + 1;
  }