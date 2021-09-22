#pragma once
#include <cmath>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class AVLTreeNode {
  public:
    int val;
    int avl;
    AVLTreeNode *parent;
    AVLTreeNode *left;
    AVLTreeNode *right;
    AVLTreeNode(int m_val, AVLTreeNode *m_left = NULL,
                AVLTreeNode *m_right = NULL, AVLTreeNode *m_parent = NULL)
        : val(m_val), left(m_left), right(m_right), parent(m_parent) {}
};

class AVLTree {
  public:
    AVLTreeNode *root;
    AVLTreeNode *insert(AVLTreeNode *root, int val) {
        if (root == NULL) {
            root = new AVLTreeNode(val);
            if (root == NULL)
                this->root = root;
        } else {
            if (root->val <= val) { // 向右插入
                AVLTreeNode *node =  insert(root->right, val);
                node->parent = root;
                // TODO: judge balance
                if (not judgeSubTreeBalance(root)) {
                    if (val >= root->right->val) {
                        // rr 型
                        lRotate(root);
                    } else {
                        // rl 型
                        lrRotate(root);
                    }
                }
            } else { // 向左插入
                insert(root->left, val);
                // TODO: judge balance
                if (not judgeSubTreeBalance(root)) {
                    if (val <= root->left->val) {
                        //ll 型
                        rRotate(root);
                    } else {
                        // lr 型
                        rlRotate(root);
                    }
                }
            }
        }
        return root;
    }

  private:
    bool judgeSubTreeBalance(AVLTreeNode *root) {
        int right = getSubTreeDepth(root->right);
        int left = getSubTreeDepth(root->left);
        if (abs(right - left) >= 2) {
            return false;
        }
        return true;
    }

    int getSubTreeDepth(AVLTreeNode *root) {
        if (root == NULL) {
            return 0;
        }
        return max(getSubTreeDepth(root->right), getSubTreeDepth(root->left)) +
               1;
    }

    AVLTreeNode *lRotate(AVLTreeNode *root) {
        AVLTreeNode *temp = root->right;
        if(root==this->root)
            this->root=temp;
        temp->parent =root->parent;
        root->right = root->right->left;
        root->right->parent = root;
        temp->left = root;
        root->parent = temp;
        return temp;
    }
    AVLTreeNode *lrRotate(AVLTreeNode *root) {
        lRotate(root->left);
        return rRotate(root);
    }
    AVLTreeNode *rRotate(AVLTreeNode *root) {
        AVLTreeNode *temp = root->left;
        if (root==this->root) {
            this->root = temp;
        }
            temp->parent = root->parent;
        root->left = root->left->right;
        root->left->parent = root;
        temp->right = root;
        root->parent = temp;
        return temp;
    }
    AVLTreeNode *rlRotate(AVLTreeNode *root) {
        rRotate(root->right);
        return lRotate(root);
    }
};
