#ifndef TRAVERSE_H_
#define TRAVERSE_H_

#ifndef SEQUENTIAL_STORAGE

// 遍历二叉树(基于链式存储结构)
// 包含前序/中序/后序遍历的递归版本

#include "definition.h"
#include "utils.h"

void PreOrderTraverse(BinaryTree tree);
void InOrderTraverse(BinaryTree tree);
void PostOrderTraverse(BinaryTree tree);

void PreOrderTraverse(BinaryTree tree) {
  if (tree) {
    Visit(tree->val);
    PreOrderTraverse(tree->lchild);
    PreOrderTraverse(tree->rchild);
  }
}

void InOrderTraverse(BinaryTree tree) {
  if (tree) {
    InOrderTraverse(tree->lchild);
    Visit(tree->val);
    InOrderTraverse(tree->rchild);
  }
}

void PostOrderTraverse(BinaryTree tree) {
  if (tree) {
    PostOrderTraverse(tree->lchild);
    PostOrderTraverse(tree->rchild);
    Visit(tree->val);
  }
}



#endif // SEQUENTIAL_STORAGE

#endif // TRAVERSE_H_