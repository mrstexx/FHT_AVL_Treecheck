#include <iostream>
#include <iomanip>
#include <fstream>
#include "TreeNode.h"
#include "TreecheckHelper.h"

using namespace std;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        cout << "Wrong data input." << endl;
        return 1;
    }
    string fileName = argv[1]; // always take second param as file name
    TreeNode *headNode = nullptr;
    readData(fileName, headNode);

    if (printTree(headNode)) {
        cout << "AVL: yes" << endl;
    } else {
        cout << "AVL: no" << endl;
    }
    cout << "min: " << headNode->getMin()
         << ", max: " << headNode->getMax()
         << ", avg: " << fixed << setprecision(2) << headNode->getAverage() << endl;
    delete (headNode);
    return 0;
}