#include <cmath>
#include <iostream>
using namespace std;

class AVLTreeNode {
  public:
    int val;
    // int avl;
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
            if (this->root == NULL) {
                this->root = root;
            }
        } else {
            if (root->val <= val) { // 向右插入
                AVLTreeNode *node = insert(root->right, val);
                if (root->right == NULL) {
                    root->right = node;
                    node->parent = root;
                }
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
                AVLTreeNode *node = insert(root->left, val);
                if (root->left == NULL) {
                    root->left = node;
                    node->parent = root;
                }
                // TODO: judge balance
                if (not judgeSubTreeBalance(root)) {
                    if (val <= root->left->val) {
                        // ll 型
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
    void preOrder(AVLTreeNode *root) {
        if (root == NULL) {
            return;
        }
        cout << root->val << " ";
        preOrder(root->left);
        preOrder(root->right);
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
        // 第一步 修改根节点
        if (root == this->root)
            this->root = temp;
        else {
            temp->parent = root->parent;
            root->parent->right = temp;
        }
        root->right = root->right->left;
        if (root->right)
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
        // 修改根节点
        if (root== this->root) {
            this->root = temp;
        }else {
            temp->parent = root->parent;
            root->parent->left = temp;
        }
        root->left = root->left->right;
        if (root->left)
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

int main(int argc, char *argv[]) {
    AVLTree *s = new AVLTree();
    for (int i = 5; i >=1 ; --i) {
        s->insert(s->root, i);
    }
    s->preOrder(s->root);
    return 0;
}
