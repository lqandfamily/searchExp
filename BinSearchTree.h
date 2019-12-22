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

typedef int elementType;

typedef struct node {
    elementType data;
    struct node *leftChild;
    struct node *rightChild;
} *Node;

/**
 * 二叉排序树创建（兼生成）
 * @param node
 * @param data
 * @return MALLOC_ERROR 动态内存申请失败
 */
int insertNode(Node *node, elementType data);

/**
 * 从数组中创建二叉排序树
 * @param sortData 数组源
 * @param n 数组长度
 * @return 根节点，失败返回NULL
 */
Node createTree(elementType data[], int n);

/**
 * 在二叉排序树中搜索元素
 * @param root 树的根节点
 * @param searchElem
 * @return 返回查找元素所在节点，失败返回NULL
 */
Node search(Node root, elementType searchElem);

/**
 * 销毁二叉排序树，释放资源
 * @param root
 */
void destroy(Node root);

#endif