#ifndef BST_H_
#define BST_H_

#ifndef SEQUENTIAL_STORAGE

// 二叉查找树(Binary Search Tree, 又名二叉排序树)的实现
// 基于链式存储结构

#include "definition.h"

/** 在BST中查找元素
 * @param tree 已构建好的一棵二叉查找树
 * @param value 待查找的元素的值
 * @return 若查找成功, 返回对应结点指针, 否则返回nullptr
 * @note BST中不存在值相同的结点, 因此查找结果是唯一的
 */
BinaryTreeNode *BST_Search(BinaryTree tree, ValueType value);

/** 向BST中插入元素
 * @param tree BST
 * @param value 待插入元素的值
 * @return 若tree中不存在值等于value的元素, 则将新元素作为叶结点插入到tree中的
 * 对应位置, 并返回true; 否则返回false.
 */
bool BST_Insert(BinaryTree &tree, ValueType value);

/** 构造BST
 * @param tree 一棵待构造的空二叉树
 * @param values 包含所有待插入元素的数组
 * @param n 数组中的元素个数
 * @return 若tree非空, 返回false; 否则在完成构造后返回true.
 * @note 构造BST的过程其实就是一个不断向树中插入新元素的过程
 */
bool CreateBST(BinaryTree &tree, ValueType values[], int n);

/** 从BST中删除元素
 * @param tree BST
 * @param value 待删除元素的值
 * @return 若tree中存在值为value的元素, 将其删除并返回true; 否则返回false.
 */
bool BST_Delete(BinaryTree &tree, ValueType value);


/***************** Implementations *********************************/

BinaryTreeNode *BST_Search(BinaryTree tree, ValueType value) {
  BinaryTreeNode *p = tree;
  while (p) {
    if (value == p->val) {
      return p;
    } else if (value < p->val) {
      p = p->lchild;
    } else {
      p = p->rchild;
    }
  }
  return nullptr;
}

bool BST_Insert(BinaryTree &tree, ValueType value) {
  if (!tree) {
    tree = new BinaryTreeNode(value);       // 将新元素作为叶结点插入
    return true;
  } else if (value == tree->val) {
    return false;                           // 树中已存在该元素
  } else if (value < tree->val) {
    return BST_Insert(tree->lchild, value); // 插入到左子树
  } else {
    return BST_Insert(tree->rchild, value); // 插入到右子树
  }
}

bool CreateBST(BinaryTree &tree, ValueType values[], int n) {
  if (tree) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    BST_Insert(tree, values[i]);
  }
  return true;
}

bool BST_Delete(BinaryTree &tree, ValueType value) {
  if (!tree) {
    return false;
  }
  if (value < tree->val) {
    return BST_Delete(tree->lchild, value); // 从左子树中删除
  } else if (value > tree->val) {
    return BST_Delete(tree->rchild, value); // 从右子树中删除
  } else { // tree所指结点即是待删除结点
    if (tree->lchild && tree->rchild) { // 左右子树非空
      // 获得右子树中的值最小的结点
      BinaryTreeNode *min = tree->rchild;
      while(min->lchild) {
        min = min->lchild;
      }
      tree->val = min->val; // 替换元素值
      return BST_Delete(tree->rchild, min->val); // 转而从右子树中删除min结点
    } else {
      BinaryTreeNode *tmp = tree;
      if (!tree->lchild) { // 仅左子树为空或左右子树均为空
        tree = tree->rchild;
      } else { // 仅右子树为空
        tree = tree->lchild;
      }
      delete tmp;
      return true;
    }
  }
}

#endif // SEQUENTIAL_STORAGE

#endif // BST_H_