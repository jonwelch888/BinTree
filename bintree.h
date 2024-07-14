/**************************************
* Name: Jon Welch
* Assignment: 8
* Purpose of the file: This header file contains the definition of the BinTree class.
* It declares the BinTree class methods and attributes.
* them in a binary search tree order based on their id.
*
* @attrib root : pointer to the root node of the tree
* @attrib count : number of nodes in the tree
* @note This file is associated with [BinTree.cpp]&[data.h];
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
    bool isEmpty();
    int getCount();
    bool getRootData(Data*);
    int getHeight();

    /**********************
    Setters/Mutators
    ***********************/
    bool addNode(int, const std::string&);
    bool removeNode(int);
    bool getNode(Data*, int);
    bool contains(int);
    void clear();

    void displayTree();
    void displayPreOrder();
    void displayPostOrder();
    void displayInOrder();

    private:
    DataNode* root;
    int count;

    void clear(DataNode*);
    bool addNode(DataNode*, DataNode**);
    DataNode* removeNode(int, DataNode*);
    DataNode* findMin(DataNode*);
    bool getNode(Data*, int, DataNode*);
    bool contains(int, DataNode*);
    int getHeight(DataNode*);
    void displayPreOrder(DataNode*);
    void displayPostOrder(DataNode*);
    void displayInOrder(DataNode*);

};#endif /* BINTREE_H */


