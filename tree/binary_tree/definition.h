#ifndef DEFINITION_H_
#define DEFINITION_H_

#include "config.h"

// 二叉树定义
#ifndef SEQUENTIAL_STORAGE

// 二叉树结点
struct BinaryTreeNode {
  ValueType val;
  struct BinaryTreeNode *lchild;
  struct BinaryTreeNode *rchild;
  BinaryTreeNode(ValueType val) : val(val), lchild(nullptr), rchild(nullptr) {}
};

// 二叉树
// 用指向树根结点的指针表示一棵树
typedef BinaryTreeNode *BinaryTree;

#else // SEQUENTIAL_STORAGE

// 以数组形式存储二叉树, 具有以下特点:
// * 根结点存储在下标为1的位置
// * 对于结点a[i], 其左孩子结点下标为2*i, 其右孩子结点下标为2*i+1;
// * 对于结点a[i], 其父结点下标为i/2.
// * 用下标0的位置存储二叉树的结点个数(可选).
// 说明: 二叉树的顺序存储方案, 适用于二叉树是完全二叉树或满二叉树的情况, 否则,
// 对于一般的二叉树, 需要在数组中维护许多空结点(以与完全二叉树上的结点相对应),
// 如此一来, 会造成空间利用率的下降.

struct BinaryTree {
  ValueType *nodes; // 保存结点值的数组, 从下标1开始存储
  int count;        // 树中结点个数
  /**
   * @param n 树中结点个数
   */
  BinaryTree(int n = 0) : count(n), nodes(nullptr) {
    if (n > 0) {
      nodes = new ValueType[n + 1];
    }
  }
  ~BinaryTree() {
    if (count > 0) {
      delete[] nodes;
    }
  }
  /** 初始化二叉树
   * @param values 用于初始化的数组
   * @param n values数组的长度
   * @return 当n大于等于count时, 只将values中的前count个元素用于初始化;
   *         当n小于count时, 赋值结束后需要更新count值为n
   */
  void Initialize(const ValueType *values, int n) {
    if (n < count) {
      for (int i = 0; i < n; i++) {
        nodes[i + 1] = values[i];
        count = n;
      }
    } else {
      for (int i = 0; i < count; i++) {
        nodes[i + 1] = values[i];
      }
    }
  }
};
/* Example:
BinaryTree bitree(4); // 创建一个可容纳4个结点的二叉树
int values[4] = {1, 2, 3, 4};
bitree.Initialize(values, 4); 初始化二叉树的结点
*/



#endif

#endif // DEFINITION_H_
