#ifndef TRAVERSE_NONRECURSIVE_H_
#define TRAVERSE_NONRECURSIVE_H_

#ifndef SEQUENTIAL_STORAGE

// 遍历二叉树(基于链式存储结构)
// 包含前序/中序/后序遍历的非递归版本

#include <stack> // 需要借助栈来实现非递归版本
#include "definition.h"
#include "utils.h"

void PreOrderTraverse_Nonrecursive(BinaryTree tree);
void InOrderTraverse_Nonrecursive(BinaryTree tree);
void PostOrderTraverse_Nonrecursive(BinaryTree tree);

void PreOrderTraverse_Nonrecursive(BinaryTree tree) {
  using std::stack;
  stack<BinaryTreeNode*> st;
  BinaryTreeNode *p = tree;
  while (p || !st.empty()) {
    if (p) {
      Visit(p->val); // 碰到一个结点, 先访问, 再压栈
      st.push(p);
      p = p->lchild;
    } else {
      p = st.top()->rchild;
      st.pop();
    }
  }
}

void InOrderTraverse_Nonrecursive(BinaryTree tree) {
  using std::stack;
  stack<BinaryTreeNode*> st;
  BinaryTreeNode *p = tree;
  while (p || !st.empty()) {
    if (p) {
      st.push(p); // 碰到一个结点, 不访问而是先将其压栈
      p = p->lchild;
    } else {
      p = st.top();
      Visit(p->val); // 在将结点出栈时再访问它
      st.pop();
      p = p->rchild;
    }
  }
}

void PostOrderTraverse_Nonrecursive(BinaryTree tree) {
  using std::stack;
  stack<BinaryTreeNode*> st;
  BinaryTreeNode *p = tree;
  BinaryTreeNode *r = nullptr; // 保存最近一次访问的结点
  while (p || !st.empty()) {
    if (p) {
      st.push(p);
      p = p->lchild;
    } else {
      p = st.top(); // 获取栈顶元素, 但还不能马上访问
      // 当栈顶元素右孩子非空并且右孩子未被访问过时, 先处理其右孩子
      if (p->rchild && p->rchild != r) {
        p = p->rchild;
      } else { // 否则将栈顶元素出栈并对其进行访问
        st.pop();
        Visit(p->val);
        r = p; // 更新最近一次访问的结点
        p = nullptr; // 此时以p为根结点的子树已全部访问完毕, 将其置空以使得
                     // 下一轮对结点p的上一层结点进行处理.
      }
    }
  }
}

#endif // SEQUENTIAL_STORAGE

#endif // TRAVERSE_NONRECURSIVE_H_