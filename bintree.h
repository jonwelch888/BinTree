/**************************************
* Name: Jon Welch
* Assignment: 8
* Purpose of the file: This file contains the definition of the BinTree class.
* It declares the structure for Data, DataNode, and the BinTree class methods and attributes.
***************************************/

#ifndef BINTREE_H
#define BINTREE_H

#include <iostream>
#include <string>

struct Data
{
    int id;
    std::string data;
};

struct DataNode
{
    Data data;
    DataNode* left;
    DataNode* right;
};

class BinTree
{
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

    public:
    BinTree();
    ~BinTree();

    bool isEmpty();
    int getCount();
    bool getRootData(Data*);
    void displayTree();
    void clear();
    bool addNode(int, const std::string&);
    bool removeNode(int);
    bool getNode(Data*, int);
    bool contains(int);
    int getHeight();
    void displayPreOrder();
    void displayPostOrder();
    void displayInOrder();
};

#endif


