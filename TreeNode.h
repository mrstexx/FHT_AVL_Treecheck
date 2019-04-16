#ifndef FHT_AVL_TREECHECK_TREENODE_H
#define FHT_AVL_TREECHECK_TREENODE_H

class TreeNode {
public:
    int value;
    TreeNode *left;
    TreeNode *right;

    explicit TreeNode(int newValue);

    void addNode(int newValue);

    int getNodeBalance();

    int getMin();

    int getMax();

    double getAverage();

    ~TreeNode();

private:
    static int getNodeHeight(TreeNode *node);

    static int max(int firstNumber, int secondNumber);

    int getValuesSum(int &numberOfElements);
};

#endif //FHT_AVL_TREECHECK_TREENODE_H
