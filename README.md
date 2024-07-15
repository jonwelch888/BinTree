# Binary Search Tree Assignment 8 [2436]

## Description

This project implements a Binary Search Tree (BST) class in C++ using a linked list approach. The tree can dynamically grow to any size and supports various operations such as adding, deleting, retrieving, and displaying nodes.

## Project Structure

- `main.cpp` and `main.h`: Provided test suite and main driver code. **Do not modify these files.**
- `bintree.h` and `bintree.cpp`: Header and implementation files for the `BinTree` class.
- `functions.h` and `functions.cpp`: Optional additional functions (not required for this assignment).

## Class Specifications

### Attributes

- `DataNode* root`: Pointer to the root node.
- `int count`: Number of nodes in the tree.

### Public Methods

- **Constructor and Destructor**
  - `BinTree()`: Initializes `root` to `nullptr` and `count` to `0`.
  - `~BinTree()`: Calls `clear()` to deallocate memory.

- **Basic Operations**
  - `bool isEmpty()`: Checks if the tree is empty.
  - `int getCount()`: Returns the number of nodes in the tree.
  - `bool getRootData(Data*)`: Retrieves the data from the root node.
  - `void displayTree()`: Displays tree stats and calls traversal methods.

- **Tree Modifications**
  - `void clear()`: Clears the tree and deallocates memory.
  - `bool addNode(int, const std::string*)`: Adds a new node with the given id and data.
  - `bool removeNode(int)`: Removes the node with the given id.

- **Node Retrieval and Search**
  - `bool getNode(Data*, int)`: Retrieves the node with the given id.
  - `bool contains(int)`: Checks if a node with the given id exists.
  - `int getHeight()`: Calculates the height of the tree.

- **Tree Traversals**
  - `void displayPreOrder()`: Pre-order traversal.
  - `void displayPostOrder()`: Post-order traversal.
  - `void displayInOrder()`: In-order traversal.

### Private Methods (for Recursion)

- `void clear(DataNode*)`
- `bool addNode(DataNode*, DataNode**)`
- `DataNode* removeNode(int, DataNode*, DataNode**)`
- `bool getNode(Data*, int, DataNode*)`
- `bool contains(int, DataNode*)`
- `int getHeight(DataNode*)`
- `void displayPreOrder(DataNode*)`
- `void displayPostOrder(DataNode*)`
- `void displayInOrder(DataNode*)`

## Getting Started

1. Clone the repository:
    ```sh
    git clone <repo-url>
    ```

2. Compile the code:
    ```sh
    g++ -o bst.out main.cpp bintree.cpp functions.cpp
    ```

3. Run the executable:
    ```sh
    ./bst.out
    ```

## Output

The expected output of the program should match the provided example output exactly. Any deviation may result in a grading penalty.

## Notes

- Follow best practices for C++ programming.
- Ensure proper memory management to avoid leaks.
- Do not modify the provided `main.cpp` and `main.h` files.

## Author 
Jon Welch
