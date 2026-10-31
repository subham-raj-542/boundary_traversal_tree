
class Solution {
public:

    // 1. Left Boundary
    void leftBoundary(Node* root, vector<int>& ans) {

        if (root == NULL)
            return;

        // Leaf node ko include nahi karna
        if (root->left == NULL && root->right == NULL)
            return;

        ans.push_back(root->data);

        // Prefer left, otherwise right
        if (root->left)
            leftBoundary(root->left, ans);
        else
            leftBoundary(root->right, ans);
    }


    // 2. Leaf Nodes (Left to Right)
    void leafNodes(Node* root, vector<int>& ans) {

        if (root == NULL)
            return;

        // Check leaf node
        if (root->left == NULL && root->right == NULL) {
            ans.push_back(root->data);
            return;
        }

        // First left subtree
        leafNodes(root->left, ans);

        // Then right subtree
        leafNodes(root->right, ans);
    }


    // 3. Right Boundary (Bottom to Top)
    void rightBoundary(Node* root, vector<int>& ans) {

        if (root == NULL)
            return;

        // Leaf node ko include nahi karna
        if (root->left == NULL && root->right == NULL)
            return;

        // First traverse boundary
        if (root->right)
            rightBoundary(root->right, ans);
        else
            rightBoundary(root->left, ans);

        // Add while returning (backtracking)
        ans.push_back(root->data);
    }


    // Main Function
    vector<int> boundaryTraversal(Node* root) {

        vector<int> ans;

        if (root == NULL)
            return ans;

        // Add root only once
        if (root->left != NULL || root->right != NULL)
            ans.push_back(root->data);
        else
            return {root->data};

        // Left Boundary
        leftBoundary(root->left, ans);

        // All Leaf Nodes
        leafNodes(root, ans);

        // Right Boundary
        rightBoundary(root->right, ans);

        return ans;
    }
};
