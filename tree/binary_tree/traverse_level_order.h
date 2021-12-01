#ifndef TRAVERSE_LEVEL_ORDER_H_
#define TRAVERSE_LEVEL_ORDER_H_

#ifndef SEQUENTIAL_STORAGE

// 二叉树的层序遍历(基于链式存储结构)

#include <queue> // 需要用到队列
#include "definition.h"
#include "utils.h"

void LevelOrderTraverse(BinaryTree tree);

// 层序遍历思路:
// * 初始化: 将根结点入队
// * 循环过程: 若队列非空, 访问队头元素并将其出队, 同时将队头元素的左孩子和右
//   孩子分别入队.
// * 循环退出: 此时队列为空, 说明树中元素全部访问完毕
void LevelOrderTraverse(BinaryTree tree) {
  using std::queue;
  if (tree) { // 非空树
    queue<BinaryTreeNode*> q;
    BinaryTreeNode *p;
    q.push(tree);
    while (!q.empty()) {
      p = q.front();
      q.pop();
      Visit(p->val);
      if (p->lchild) {
        q.push(p->lchild);
      }
      if (p->rchild) {
        q.push(p->rchild);
      }
    }
  }
}

#endif // SEQUENTIAL_STORAGE

#endif // TRAVERSE_LEVEL_ORDER_H_