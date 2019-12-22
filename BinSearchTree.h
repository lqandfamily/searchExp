/**
 * 二叉排序树的头文件
 */
#ifndef BIN_SEARCH_TREE_H
#define BIN_SEARCH_TREE_H

#include <stdio.h>
#include <stdlib.h>

//状态码，动态内存申请失败
#define MALL_ERROR -1
#define SUCCESS 1
#define NOT_FOUND -2

//当前节点是父节点的左孩子还是右孩子
#define LEFT_CHILD 1
#define RIGHT_CHILD 2


typedef int elementType;

typedef struct node {
    elementType data;
    struct node *leftChild;
    struct node *rightChild;
    struct node *father;
} *Node;

/**
 * 二叉排序树创建（兼生成）
 * @param node
 * @param data
 * @return MALLOC_ERROR 动态内存申请失败
 */
int insertNode(Node *node, Node father, elementType data);

/**
 * 从数组中创建二叉排序树
 * @param sortData 数组源
 * @param n 数组长度
 * @return 根节点，失败返回NULL
 */
Node createTree(elementType data[], int n);

/**
 * 创建平衡二叉树
 * @param data
 * @param n
 * @return
 */
Node createBalanceTree(elementType data[], int n);

/**
 * 在二叉排序树中搜索元素
 * @param root 树的根节点
 * @param searchElem
 * @return 返回查找元素所在节点，失败返回NULL
 */
Node search(Node root, elementType searchElem);

/**
 *
 * @param root
 * @param searchElem
 * @param isLeftOrChild 当前节点是父节点的左孩子还是右孩子，建议使用宏LEFT_CHILD，RIGHT_CHILD
 * @return SUCCESS 找到元素并删除
 *         NOT_FOUND 没有找到元素
 */
Node searchForRemove(Node root, elementType searchElem, int *isLeftOrChild);

/**
 * 删除指定元素到节点
 * @param removeElem
 * @param root
 * @return SUCCESS 找到元素并删除
 *         NOT_FOUND 没有找到元素
 */
int removeNode(Node root, elementType removeElem);

/**
 * 插入节点的同时调整平衡性
 * @param node
 * @param data
 */
int insertWithBalance(Node *node, Node father, elementType data);

/**
 * 调整二叉排序树为平衡二叉树
 * @param node
 */
void balance(Node *node);

/**
 * 不平衡简单左旋
 * 适用于RR型
 * @param imbalanceNode
 */
void singleLeftRotation(Node *imbalanceNode);

/**
 * 不平衡简单右旋
 * 适用于LL型
 * @param imbalanceNode
 */
void singleRightRotation(Node *imbalanceNode);

/**
 * 不平衡对称左旋转
 * 先左再右
 * @param imbalanceNode
 */
void doubleLeftRotation(Node *imbalanceNode);

/**
 * 不平衡对称右旋转
 * @param imbalanceNode
 */
void doubleRightRotation(Node *imbalanceNode);


/**
 * 获取以当前节点为临时根的树的高度
 * 本函数目的在于服务二叉树平衡调整
 * @param root
 * @return
 */
int height(Node curNode);

/**
 * 销毁二叉排序树，释放资源
 * @param root
 */
void destroy(Node root);

#endif