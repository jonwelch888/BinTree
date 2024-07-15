/**************************************
* Name: Jon Welch
* Assignment: 8
* Purpose of the file: This header file contains the definition of the BinTree class.
* It declares the BinTree class methods and attributes.
* them in a binary search tree order based on their id.
*
* @attrib root : pointer to the root node of the tree
* @attrib count : number of nodes in the tree
* @note This file is associated with [bintree.cpp], & [data.h];
***************************************/

#ifndef BINTREE_H
#define BINTREE_H

#include <iostream>
#include <string>
#include "data.h"

using std::cout;
using std::endl;
using std::string;

class BinTree
{
    public:
    /**********************
    Constructors/Destructor
    ***********************/
    BinTree();
    ~BinTree();

    /**********************
    Getters/Accessors
    ***********************/
    bool isEmpty() const;
    int getCount() const;
    bool getRootData(Data*) const;
    int getHeight() const;

    /**********************
    Setters/Mutators
    ***********************/
    bool addNode(int, const std::string*);
    bool removeNode(int);
    bool getNode(Data*, int) const;
    bool contains(int) const;
    void clear();

    void displayTree() const;
    void displayPreOrder() const;
    void displayPostOrder() const;
    void displayInOrder() const;

    private:
    DataNode* root;
    int count;

    void clear(DataNode*);
    bool addNode(DataNode*, DataNode**);
    DataNode* removeNode(int, DataNode*, DataNode**);
    DataNode* findMin(DataNode*) const;
    bool getNode(Data*, int, DataNode*) const;
    bool contains(int, DataNode*) const;
    int getHeight(DataNode*) const;
    void displayPreOrder(DataNode*) const;
    void displayPostOrder(DataNode*) const;
    void displayInOrder(DataNode*) const;

};

#endif /* BINTREE_H */



