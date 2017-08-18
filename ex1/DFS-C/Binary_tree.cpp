//
// Created by adi on 20/11/16.
//
#include "Binary_tree.h"
#include <cmath>

using namespace std;
/******************************************************************************
* The Function Operation: recurusivly realse the tree that is routed in
* the calling node
******************************************************************************/
Binary_tree::~Binary_tree(){
    if (!left) delete left;
    if (!right) delete right;
}
/******************************************************************************
* The Function Operation: recurusivly create a full binary tree with nunOfLeaves
* leaves
******************************************************************************/
void Binary_tree::create_full_tree(int numOfLeaves){
    int height = (int) log2((double) numOfLeaves);
    this->full_tree(height);
}
/******************************************************************************
* The Function Operation: the recurusive body of the create_full_tree function
******************************************************************************/
void Binary_tree::full_tree(int height){
    // static incremetal variable to asgin to the data field of each node
    static int number = 1;
    data = number;
    number++;
    // stop condition, when the height remainig to add is 0
    if (height == 0) return;
    left = new Binary_tree(0);
    left->full_tree(height - 1);
    right = new Binary_tree(0);
    right->full_tree(height - 1);
}
/******************************************************************************
* The Function Operation: go through the tree in the dfs way
******************************************************************************/
void Binary_tree::dfs(){
    //go through the left branch
    if (left != NULL) left->dfs();
    delete left;
    //go through the right branch
    if (right != NULL) right->dfs();
    delete right;
}

