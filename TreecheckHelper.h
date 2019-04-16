#ifndef FHT_AVL_TREECHECK_TREECHECKHELPER_H
#define FHT_AVL_TREECHECK_TREECHECKHELPER_H

#include "TreeNode.h"

using namespace std;

/**
 * Recursive function to print all tree values. It reads first nodes from right side,
 * then left and at the end current node.
 *
 * @param node Current tree.
 * @return True if tree is AVL. False if tree is not AVL.
 */
bool printTree(TreeNode *node) {
    bool isLeftBalanced = true;
    bool isRightBalanced = true;
    if (node != nullptr) {
        isRightBalanced = printTree(node->right);
        isLeftBalanced = printTree(node->left);
        int nodeBalance = node->getNodeBalance();
        if (nodeBalance >= -1 && nodeBalance <= 1) {
            cout << "bal(" << node->value << ") = " << nodeBalance << endl;
        } else {
            cout << "bal(" << node->value << ") = " << nodeBalance << " (AVL violation!)" << endl;
            return false;
        }
    }
    return (isLeftBalanced && isRightBalanced);
}

/**
 * Reading data from text file and adding new nodes to tree.
 *
 * @param fileName File from where data will be values read.
 * @param node Tree in which will be data added.
 */
void readData(string &fileName, TreeNode *&node) {
    ifstream input;
    input.open(fileName);
    if (!input.is_open()) {
        // safety handling in case something failed
        cout << "File cannot be opened." << endl;
        return;
    }
    int data = 0;
    while (input.good()) {
        if (input.fail()) {
            // safety handling in case something failed
            input.clear();
            input.ignore();
            continue;
        }
        input >> data;
        if (node == nullptr) {
            node = new TreeNode(data);
        } else {
            node->addNode(data);
        }
    }
    input.close();
}

#endif //FHT_AVL_TREECHECK_TREECHECKHELPER_H
