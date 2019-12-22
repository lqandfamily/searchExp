/**
 * 二叉排序树实现
 */
#include "BinSearchTree.h"

int insertNode(Node *node, elementType data) {
    if ((*node) == NULL) {                             //新建节点
        (*node) = (Node) malloc(sizeof(struct node));
        /**
         * BUG：MALL_ERROR按理要层层返回，这里就不做了
         */
        if ((*node) == NULL) {
            return MALL_ERROR;
        }
        (*node)->leftChild = NULL;
        (*node)->rightChild = NULL;
        (*node)->data = data;
    } else {
        if (data > (*node)->data) {                    //插入右子树
            insertNode(&((*node)->rightChild), data);
        } else if (data < (*node)->data) {             //插入左子树
            insertNode(&((*node)->leftChild), data);
        } else {
            return 0;                               //重复元素，不用插入
        }
    }
    return SUCCESS;
}

Node createTree(elementType data[], int n) {
    int i;
    Node root = NULL;
    for (i = 0; i < n; i++) {
        insertNode(&root, data[i]);
    }
    return root;
}


Node search(Node root, elementType searchElem) {
    if (root == NULL || root->data == searchElem) {                 //找到或已经搜索完树仍未找到，返回节点(或许为NULL)
        return root;
    } else if (searchElem > root->data) {
        return search(root->rightChild, searchElem);        //查找右子树
    } else {
        return search(root->leftChild, searchElem);         //查找左子树
    }
}


void destroy(Node root) {
    if (root != NULL) {
        destroy(root->leftChild);
        destroy(root->rightChild);
        free(root);
    }
}