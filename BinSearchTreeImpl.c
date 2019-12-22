/**
 * 二叉排序树实现
 */
#include "BinSearchTree.h"

int insertNode(Node *node, Node father, elementType data) {
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
        (*node)->father = father;
    } else {
        if (data > (*node)->data) {                    //插入右子树
            insertNode(&((*node)->rightChild), *node, data);
        } else if (data < (*node)->data) {             //插入左子树
            insertNode(&((*node)->leftChild), *node, data);
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
        insertNode(&root, NULL, data[i]);
    }
    return root;
}

Node createBalanceTree(elementType data[], int n) {
    int i;
    Node root = NULL;
    for (i = 0; i < n; i++) {
        insertWithBalance(&root, NULL, data[i]);
    }
    return root;
}

Node searchForRemove(Node root, elementType searchElem, int *isLeftOrChild) {
    if (root == NULL) {                                   //已经搜索完树仍未找到，返回NULL
        return NULL;
    } else if (root->data == searchElem) {                  //找到，返回节点(或许为NULL),
        if (root->father->leftChild->data == searchElem) {
            *isLeftOrChild = LEFT_CHILD;
        } else {
            *isLeftOrChild = RIGHT_CHILD;
        }
        return root;
    } else if (searchElem > root->data) {
        return searchForRemove(root->rightChild, searchElem, isLeftOrChild);        //查找右子树
    } else {
        return searchForRemove(root->leftChild, searchElem, isLeftOrChild);         //查找左子树
    }
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

int removeNode(Node root, elementType removeElem) {
    //1，搜索到元素节点
    int isLeftOrRightChild;
    Node removeNode = searchForRemove(root, removeElem, &isLeftOrRightChild);
    if (removeNode == NULL) {
        return NOT_FOUND;
    }
    //2,删除元素
    //a.叶子节点
    if (removeNode->leftChild == NULL && removeNode->rightChild == NULL) {
        removeNode->father->leftChild = NULL;
        removeNode->father->rightChild = NULL;
        free(removeNode);
    }
        //b.removeNode只有左子树，或只有右子树
        //左子树为空，重接右子树
    else if (removeNode->leftChild == NULL) {
        Node delNode = removeNode;
        //重接，这波操作可以滴
        if (isLeftOrRightChild == LEFT_CHILD) {
            removeNode->father->leftChild = removeNode->rightChild;
        } else {
            removeNode->father->rightChild = removeNode->rightChild;
        }
        removeNode->rightChild->father = removeNode->father;
        free(delNode);
        //右子树为空，重接左子树
    } else if (removeNode->rightChild == NULL) {
        Node delNode = removeNode;
        if (isLeftOrRightChild == LEFT_CHILD) {
            removeNode->father->leftChild = removeNode->leftChild;
        } else {
            removeNode->father->rightChild = removeNode->leftChild;
        }
        //修改father指针
        removeNode->leftChild->father = removeNode->father;
        free(delNode);
        /**
         * 左右子树都存在
         * remove节点的左子树重接到父节点的左子树，remove节点的右子树重接到remove节点左孩子的右孩子
         */
    } else {
        /**
         * TODO 左右子树都存在时还没有写呢
         */

    }
    return SUCCESS;
}

int insertWithBalance(Node *node, Node father, elementType data) {
    if ((*node) == NULL) {                             //新建节点
        (*node) = (Node) malloc(sizeof(struct node));
        if ((*node) == NULL) {
            return MALL_ERROR;
        }
        (*node)->leftChild = NULL;
        (*node)->rightChild = NULL;
        (*node)->data = data;
        (*node)->father = father;
    } else {
        if (data > (*node)->data) {                    //插入右子树
            insertWithBalance(&((*node)->rightChild), *node, data);
        } else if (data < (*node)->data) {             //插入左子树
            insertWithBalance(&((*node)->leftChild), *node, data);
        } else {
            return 0;                               //重复元素，不用插入
        }
    }
    //调整平衡
    balance(node);
    return SUCCESS;
}

void balance(Node *node) {
    int leftTreeHeight = height((*node)->leftChild);
    int rightTreeHeight = height((*node)->rightChild);

    //左子树高
    if (leftTreeHeight - rightTreeHeight > 1) {
        if (height((*node)->leftChild->leftChild) > height((*node)->leftChild->rightChild)) {
            //简单右旋
            singleRightRotation(node);
        } else {
            doubleRightRotation(node);
        }
    }

    //右子树高
    if (rightTreeHeight - leftTreeHeight > 1) {
        if (height((*node)->rightChild->rightChild) > height((*node)->rightChild->leftChild)) {
            //简单左旋
            singleLeftRotation(node);
        } else {
            doubleLeftRotation(node);
        }
    }
}

void singleLeftRotation(Node *imbalanceNode) {
    Node tmp = (*imbalanceNode)->rightChild->leftChild;
    Node newRootNode = (*imbalanceNode)->rightChild;

    (*imbalanceNode)->rightChild->leftChild = (*imbalanceNode);
    (*imbalanceNode)->rightChild = tmp;

    //重置根节点
    (*imbalanceNode) = newRootNode;
}

void singleRightRotation(Node *imbalanceNode) {
    Node tmp = (*imbalanceNode)->leftChild->rightChild;
    Node newRootNode = (*imbalanceNode)->leftChild;

    (*imbalanceNode)->leftChild->rightChild = (*imbalanceNode);
    (*imbalanceNode)->leftChild = tmp;

    (*imbalanceNode) = newRootNode;
}

void doubleLeftRotation(Node *imbalanceNode) {
    //先左后右
    singleLeftRotation(&((*imbalanceNode)->leftChild));
    singleRightRotation(imbalanceNode);
}

void doubleRightRotation(Node *imbalanceNode) {
    //先右后左
    singleRightRotation(&((*imbalanceNode)->rightChild));
    singleLeftRotation(imbalanceNode);
}

int height(Node curNode) {
    if (curNode == NULL) {
        return 0;
    } else {
        int leftTreeHeight = height(curNode->leftChild);
        int rightTreeHeight = height(curNode->rightChild);
        return (leftTreeHeight > rightTreeHeight ? leftTreeHeight : rightTreeHeight) + 1;
    }
}

void destroy(Node root) {
    if (root != NULL) {
        destroy(root->leftChild);
        destroy(root->rightChild);
        free(root);
    }
}
