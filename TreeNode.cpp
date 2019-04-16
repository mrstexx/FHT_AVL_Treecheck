#include "TreeNode.h"

TreeNode::TreeNode(int newValue) {
    this->value = newValue;
    this->left = nullptr;
    this->right = nullptr;
}

/**
 * Function used to add new value into tree. Value can be added if it is smaller or bigger than value of current node.
 * In case those two values are same, we won't do anything -> on this way we avoid adding multiple values.
 *
 * @param newValue
 */
void TreeNode::addNode(int newValue) {
    if (newValue < this->value) {
        if (this->left != nullptr) {
            this->left->addNode(newValue);
        } else {
            this->left = new TreeNode(newValue);
        }
    }
    if (newValue > this->value) {
        if (this->right != nullptr) {
            this->right->addNode(newValue);
        } else {
            this->right = new TreeNode(newValue);
        }
    }
}

/**
 * Function used to get node balance (difference between right and left node height).
 *
 * @return Balance of node.
 */
int TreeNode::getNodeBalance() {
    int leftNodeHeight = 0;
    int rightNodeHeight = 0;
    if (this->left != nullptr) {
        leftNodeHeight = getNodeHeight(this->left);
    }
    if (this->right != nullptr) {
        rightNodeHeight = getNodeHeight(this->right);
    }
    return rightNodeHeight - leftNodeHeight;
}

/**
 * Function used to get height in tree of specific node.
 *
 * @param node Node to get height of.
 * @return Max value of left and right node height.
 */
int TreeNode::getNodeHeight(TreeNode *node) {
    if (node == nullptr) {
        return 0;
    }
    return max(getNodeHeight(node->left), getNodeHeight(node->right)) + 1; // 1 itself node
}

int TreeNode::max(int firstNumber, int secondNumber) {
    return firstNumber > secondNumber ? firstNumber : secondNumber;
}

/**
 * Function used to get min value in tree.
 *
 * @return Min integer value.
 */
int TreeNode::getMin() {
    if (this->left == nullptr) {
        return this->value;
    }
    return this->left->getMin();
}

/**
 * Function used to get max value in tree.
 *
 * @return Max integer value.
 */
int TreeNode::getMax() {
    if (this->right == nullptr) {
        return this->value;
    }
    return this->right->getMax();
}

/**
 * Function used to get average value of all tree values. It calls recursive function getValuesSum.
 *
 * @return Average value of all tree values.
 */
double TreeNode::getAverage() {
    double sumOfElements = 0;
    int numberOfElements = 0;
    sumOfElements = getValuesSum(numberOfElements);
    return (sumOfElements / numberOfElements);
}

int TreeNode::getValuesSum(int &numberOfElements) {
    numberOfElements++;
    int sum = this->value;
    if (this->right != nullptr) {
        sum += this->right->getValuesSum(numberOfElements);
    }
    if (this->left != nullptr) {
        sum += this->left->getValuesSum(numberOfElements);
    }
    return sum;
}

TreeNode::~TreeNode() {
    delete this->left;
    delete this->right;
}