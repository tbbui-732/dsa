#include <iostream>
#include <memory>

class Node {
public:
    int data;
    std::unique_ptr<Node> left;
    std::unique_ptr<Node> right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinaryTree {
    private:
        std::unique_ptr<Node> root;

        void insertNode(std::unique_ptr<Node>& node, int value) {
            if (node == nullptr) {
                node = std::make_unique<Node>(value);
            } else if (value < node->data) {
                insertNode(node->left, value);
            } else {
                insertNode(node->right, value);
            }
        }

        void inOrderTraversal(const std::unique_ptr<Node>& node) const {
            if (node == nullptr) {
                return;
            }
            inOrderTraversal(node->left);
            std::cout << node->data << " ";
            inOrderTraversal(node->right);
        }

    public:
        BinaryTree() : root(nullptr) {}

        void insert(int value) {
            insertNode(root, value);
        }

        void inOrder() const {
            inOrderTraversal(root);
            std::cout << std::endl;
        }
};

int main() {
    BinaryTree tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);

    std::cout << "In-order traversal: ";
    tree.inOrder();

    return 0;
}

