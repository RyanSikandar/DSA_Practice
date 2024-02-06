#include <iostream>
#include <vector>

// Definition for a tree node.
template <typename T>
struct TreeNode {
    T data;
    std::vector<TreeNode<T>*> children;

    TreeNode(T val) : data(val) {}
};

// Class for a general tree
template <typename T>
class Tree {
public:
    // Constructor
    Tree() : root(nullptr) {}

    // Function to insert a new node into the tree
    void insert(T val) {
        root = insertRecursive(root, val);
    }

    // Function for preorder traversal
    void preorderTraversal() {
        preorderTraversalRecursive(root);
        std::cout << std::endl;
    }

    // Function for inorder traversal
    void inorderTraversal() {
        inorderTraversalRecursive(root);
        std::cout << std::endl;
    }

    // Function for postorder traversal
    void postorderTraversal() {
        postorderTraversalRecursive(root);
        std::cout << std::endl;
    }

private:
    // Recursive function to insert a new node
    TreeNode<T>* insertRecursive(TreeNode<T>* node, T val) {
        if (node == nullptr) {
            return new TreeNode<T>(val);
        }

        TreeNode<T>* newNode = new TreeNode<T>(val);
        node->children.push_back(newNode);

        return node;
    }

    // Recursive function for preorder traversal
    void preorderTraversalRecursive(TreeNode<T>* node) {
        if (node != nullptr) {
            std::cout << node->data << " ";
            for (TreeNode<T>* child : node->children) {
                preorderTraversalRecursive(child);
            }
        }
    }

    // Recursive function for inorder traversal
    void inorderTraversalRecursive(TreeNode<T>* node) {
        if (node != nullptr) {
            for (TreeNode<T>* child : node->children) {
                inorderTraversalRecursive(child);
                std::cout << node->data << " ";
            }
        }
    }

    // Recursive function for postorder traversal
    void postorderTraversalRecursive(TreeNode<T>* node) {
        if (node != nullptr) {
            for (TreeNode<T>* child : node->children) {
                postorderTraversalRecursive(child);
            }
            std::cout << node->data << " ";
        }
    }

    // Root of the tree
    TreeNode<T>* root;
};

int main() {
    // Create a general tree
    Tree<int> tree;

    // Insert nodes into the tree
    tree.insert(1);
    tree.insert(2);
    tree.insert(3);
    tree.insert(4);
    tree.insert(5);

    // Perform traversals
    std::cout << "Preorder Traversal: ";
    tree.preorderTraversal();

    std::cout << "Inorder Traversal: ";
    tree.inorderTraversal();

    std::cout << "Postorder Traversal: ";
    tree.postorderTraversal();

    return 0;
}
