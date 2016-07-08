// ---- Program Info Start----
//FileName:     longestPath.cpp
//
//Author:       Fuchen Duan
//
//Email:        slow295185031@gmail.com
//
//CreatedAt:    2016-04-19 20:10:14
// ---- Program Info End  ----

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class LongestPath {
public:
    LongestPath():maxColor(-1), maxLength(0){};
    int findPath(TreeNode* root) {
        // write code here
        preOrder(root, 0, root->val);
        return maxLength;
    }
    void preOrder(TreeNode * root, int lastLength, int lastColor){
        if(root == NULL) return;
        if(root->val == lastColor){
            ++lastLength;
            if(lastLength>maxLength){
                maxColor = root->val;
                maxLength = lastLength;
            }
        }else{
            lastLength = 0;
        }
        preOrder(root->left, lastLength, lastColor);
        preOrder(root->right, lastLength, lastColor);
        --lastLength;
    }
private:
    int maxColor;
    int maxLength;
};
