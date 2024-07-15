/*********************************************
* Name: Jon Welch
* Assignment: 8
* Purpose of the file: This source file contains the implementation of the BinTree class.
* It handles dynamic memory allocation and supports operations such as adding, deleting,
* retrieving, and displaying nodes in a binary search tree.
*
* @note This file is associated with [bintree.h];
*********************************************/

// BACKTEST 7

#include "bintree.h"


BinTree::BinTree() : root(nullptr), count(0)
{
    /*********************************************
    Constructor: Initializes the binary search tree with the root pointer set to nullptr and count to 0.
    *********************************************/
}

BinTree::~BinTree()
{
    /*********************************************
    Destructor: Cleans up all dynamically allocated memory by clearing the tree.
    *********************************************/
    clear();
}

bool BinTree::isEmpty() const
{
    /*********************************************
    isEmpty: Checks if the tree is empty.
    @return : true if the tree is empty, false otherwise.
    *********************************************/
    return root == nullptr;
}

int BinTree::getCount() const
{
    /*********************************************
    getCount: Returns the number of nodes in the tree.
    @return : The count of nodes in the tree.
    *********************************************/
    return count;
}

bool BinTree::getRootData(Data* data) const
{
    /*********************************************
    getRootData: Retrieves the data from the root node.
    @param data : A pointer to a Data object to store the retrieved data.
    @return : true if data was retrieved, false if tree is empty.
    *********************************************/
    bool success = (root != nullptr);
    if (success)
    {
        data->id = root->data.id;
        data->information = root->data.information;
    }
    else
    {
        data->id = -1;
        data->information = "";
    }
    return success;
}

bool BinTree::addNode(int id, const std::string* data)
{
    /*********************************************
    addNode: Adds a new node with the given id and data to the tree.
    @param id : The identifier for the Data.
    @param data : A pointer to the string data.
    @return : true if the new node was successfully inserted, false otherwise.
    *********************************************/
    bool success = (id > 0 && data != nullptr && !data->empty());
    if (success)
    {
        DataNode* newNode = new DataNode;
        newNode->data.id = id;
        newNode->data.information = *data;
        newNode->left = nullptr;
        newNode->right = nullptr;
        success = addNode(newNode, &root);
        count = success ? count + 1 : count;
    }
    return success;
}

bool BinTree::removeNode(int id)
{
    /*********************************************
    removeNode: Removes the node with the given id from the tree.
    @param id : The identifier for the node to remove.
    @return : true if the node was successfully removed, false otherwise.
    *********************************************/
    bool success = (id > 0);
    if (success)
    {
        DataNode* removed = removeNode(id, root);
        if (removed)
        {
            delete removed;
            count--;
        }
        else
        {
            success = false;
        }
    }
    return success;
}

bool BinTree::getNode(Data* data, int id) const
{
    /*********************************************
    getNode: Retrieves the node with the given id and stores its data.
    @param data : A pointer to a Data object to store the retrieved data.
    @param id : The identifier for the node to retrieve.
    @return : true if the node was found and data retrieved, false otherwise.
    *********************************************/
    bool found = (id > 0) ? getNode(data, id, root) : false;
    if (!found)
    {
        data->id = -1;
        data->information = "";
    }
    return found;
}

bool BinTree::contains(int id) const
{
    /*********************************************
    contains: Checks if a node with the given id exists in the tree.
    @param id : The identifier to check for existence.
    @return : true if a node with the given id exists, false otherwise.
    *********************************************/
    return (id > 0) ? contains(id, root) : false;
}

int BinTree::getHeight() const
{
    /*********************************************
    getHeight: Returns the height of the tree.
    @return : The height of the tree.
    *********************************************/
    return getHeight(root);
}

void BinTree::displayTree() const
{
    /*********************************************
    displayTree: Displays all stats for the tree and calls all display order methods.
    *********************************************/
    std::cout << "DISPLAY TREE" << std::endl;
    std::cout << "=============================================" << std::endl;
    std::cout << (isEmpty() ? "Tree is empty" : "Tree is NOT empty") << std::endl;
    std::cout << "Height: " << getHeight() << std::endl;
    std::cout << "Node count: " << getCount() << std::endl;
    std::cout << "Pre-Order Traversal" << std::endl;
    displayPreOrder();
    std::cout << "In-Order Traversal" << std::endl;
    displayInOrder();
    std::cout << "Post-Order Traversal" << std::endl;
    displayPostOrder();
    std::cout << "=============================================" << std::endl;
}

void BinTree::clear()
{
    /*********************************************
    clear: Deallocates the tree and sets it back to "empty."
    *********************************************/
    clear(root);
    root = nullptr;
    count = 0;
}

void BinTree::displayPreOrder() const
{
    /*********************************************
    displayPreOrder: Displays the tree in pre-order traversal.
    *********************************************/
    displayPreOrder(root);
}

void BinTree::displayPostOrder() const
{
    /*********************************************
    displayPostOrder: Displays the tree in post-order traversal.
    *********************************************/
    displayPostOrder(root);
}

void BinTree::displayInOrder() const
{
    /*********************************************
    displayInOrder: Displays the tree in in-order traversal.
    *********************************************/
    displayInOrder(root);
}

// Private methods

bool BinTree::addNode(DataNode* newNode, DataNode** node)
{
    /*********************************************
    addNode: Recursively adds a new node to the tree.
    @param newNode : The new node to be added.
    @param node : Pointer to the current node pointer.
    @return : true if the node was added successfully, false otherwise.
    *********************************************/
    bool success = true;
    if (*node == nullptr)
    {
        *node = newNode;
    }
    else if (newNode->data.id < (*node)->data.id)
    {
        success = addNode(newNode, &((*node)->left));
    }
    else if (newNode->data.id > (*node)->data.id)
    {
        success = addNode(newNode, &((*node)->right));
    }
    else
    {
        success = false;  // Duplicate id
    }
    return success;
}

DataNode* BinTree::removeNode(int id, DataNode* node)
{
    std::cout << "Entering removeNode with id: " << id << std::endl;
    DataNode* result = node;

    if (node != nullptr)
    {
        std::cout << "Current node id: " << node->data.id << std::endl;
        if (id < node->data.id)
        {
            std::cout << "Going left from node id: " << node->data.id << std::endl;
            node->left = removeNode(id, node->left);
        }
        else if (id > node->data.id)
        {
            std::cout << "Going right from node id: " << node->data.id << std::endl;
            node->right = removeNode(id, node->right);
        }
        else
        {
            std::cout << "Node found with id: " << id << std::endl;
            if (node->left == nullptr || node->right == nullptr)
            {
                std::cout << "Node has one or no children" << std::endl;
                DataNode* temp = node->left ? node->left : node->right;
                std::cout << "Deleting node with id: " << node->data.id << std::endl;
                delete node;
                result = temp;
                std::cout << "Node deleted, result set to child or nullptr" << std::endl;
            }
            else
            {
                std::cout << "Node has two children, finding inorder successor" << std::endl;
                DataNode* temp = findMin(node->right);
                std::cout << "Inorder successor found with id: " << temp->data.id << std::endl;
                node->data = temp->data;
                std::cout << "Node data replaced with inorder successor's data, new node data id: " << node->data.id << std::endl;
                node->right = removeNode(temp->data.id, node->right);
                result = node;
                std::cout << "Inorder successor replaced and node adjusted" << std::endl;
            }
        }
    }
    std::cout << "Exiting removeNode, returning node with id: " << (result ? result->data.id : -1) << std::endl;
    std::cout << "Tree state after operation:" << std::endl;
    printTree(root);
    return result;
}



DataNode* BinTree::findMin(DataNode* node) const
{
    std::cout << "Entering findMin" << std::endl;
    DataNode* current = node;
    while (current && current->left != nullptr)
    {
        current = current->left;
    }
    if (current) {
        std::cout << "Minimum node found with id: " << current->data.id << std::endl;
    } else {
        std::cout << "Minimum node not found, current is nullptr" << std::endl;
    }
    return current;
}

bool BinTree::getNode(Data* data, int id, DataNode* node) const
{
    /*********************************************
    getNode: Recursively searches for a node with the given id.
    @param data : Pointer to a Data struct to store the retrieved data.
    @param id : The id of the node to retrieve.
    @param node : The current node being checked.
    @return : true if node was found and data retrieved, false otherwise.
    *********************************************/
    bool found = false;
    if (node != nullptr)
    {
        if (id == node->data.id)
        {
            *data = node->data;
            found = true;
        }
        else
        {
            found = (id < node->data.id) ? getNode(data, id, node->left) : getNode(data, id, node->right);
        }
    }
    return found;
}

bool BinTree::contains(int id, DataNode* node) const
{
    /*********************************************
    contains: Recursively checks if a node with the given id exists.
    @param id : The id to search for.
    @param node : The current node being checked.
    @return : true if a node with the given id exists, false otherwise.
    *********************************************/
    return (node == nullptr) ? false : (id == node->data.id) ? true : (id < node->data.id) ? contains(id, node->left) : contains(id, node->right);
}

int BinTree::getHeight(DataNode* node) const
{
    /*********************************************
    getHeight: Recursively calculates the height of the tree.
    @param node : The current node being checked.
    @return : The height of the subtree rooted at the given node.
    *********************************************/
    return node == nullptr ? 0 : 1 + std::max(getHeight(node->left), getHeight(node->right));
}

void BinTree::clear(DataNode* node)
{
    /*********************************************
    clear: Recursively clears the tree.
    @param node : The current node being cleared.
    *********************************************/
    if (node != nullptr)
    {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}

void BinTree::displayPreOrder(DataNode* node) const
{
    /*********************************************
    displayPreOrder: Recursively displays the tree in pre-order traversal.
    @param node : The current node being displayed.
    *********************************************/
    if (node != nullptr)
    {
        std::cout << node->data.id << " " << node->data.information << std::endl;
        displayPreOrder(node->left);
        displayPreOrder(node->right);
    }
}

void BinTree::displayPostOrder(DataNode* node) const
{
    /*********************************************
    displayPostOrder: Recursively displays the tree in post-order traversal.
    @param node : The current node being displayed.
    *********************************************/
    if (node != nullptr)
    {
        displayPostOrder(node->left);
        displayPostOrder(node->right);
        std::cout << node->data.id << " " << node->data.information << std::endl;
    }
}

void BinTree::displayInOrder(DataNode* node) const
{
    /*********************************************
    displayInOrder: Recursively displays the tree in in-order traversal.
    @param node : The current node being displayed.
    *********************************************/
    if (node != nullptr)
    {
        displayInOrder(node->left);
        std::cout << node->data.id << " " << node->data.information << std::endl;
        displayInOrder(node->right);
    }
}


void BinTree::printTree(DataNode* node, std::string indent, bool last) const {
    if (node != nullptr) {
        std::cout << indent;
        if (last) {
            std::cout << "└─";
            indent += "  ";
        } else {
            std::cout << "├─";
            indent += "| ";
        }
        std::cout << node->data.id << std::endl;
        printTree(node->left, indent, false);
        printTree(node->right, indent, true);
    }
}

void BinTree::printTree() const {
    printTree(root);
}




