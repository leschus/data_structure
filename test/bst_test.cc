#include <iostream>
#include "bst.h"
#include "traverse.h"
#include "traverse_nonrecursive.h"
#include "traverse_level_order.h"

using namespace std;

int main() {
  BinaryTree tree = nullptr;
  ValueType values[8] = {53, 17, 9, 45, 23, 78, 65, 87};
  CreateBST(tree, values, 8);

  // InOrderTraverse(tree);
  // cout << endl;
  // InOrderTraverse_Nonrecursive(tree);
  // cout << endl;
  // LevelOrderTraverse(tree);
  // cout << endl;

  // BinaryTreeNode *p = BST_Search(tree, 78);
  // if (p) {
  //   cout << p->lchild->val << endl;
  //   cout << p->rchild->val << endl;
  // }

  // BST_Delete(tree, 45);
  // LevelOrderTraverse(tree);
  // cout << endl;

  BST_Delete(tree, 78);
  LevelOrderTraverse(tree);
  cout << endl;


  return 0;
}