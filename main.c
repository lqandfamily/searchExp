#include <stdio.h>
#include "BinSearch.h"
#include "BinSearchTree.h"

/**
 * 测试二分查找
 */
void testBinSearch() {
    elementType data[] = {1, 2, 3, 4, 6, 7, 8, 9, 10, 11, 12, 13, 17, 18, 19, 20, 24, 25, 26, 30, 35, 40, 45, 50, 100};
    elementType searchElem = 110;
    int searchedIndex = binSearch(data, sizeof(data) / sizeof(elementType), searchElem);
    if (searchedIndex != -1) {
        printf("查找元素%d带下标为:%d\n", data[searchedIndex], searchedIndex);
    } else {
        printf("查找元素失败！\n");
    }
}

/**
 * 测试基本的二叉树创建和查找
 */
void testBasedBinSearchTree() {
    elementType data[] = {50, 16, 56, 52, 8};
    elementType searchElem = 52;
    Node root = createTree(data, sizeof(data) / sizeof(elementType));
    if (root != NULL) {
        printf("创建二叉排序树成功！\n");
    } else {
        printf("创建排序树失败！\n");
    }


    Node searchedNode = search(root, searchElem);
    if (searchedNode != NULL) {
        printf("找到元素：%d\n", searchedNode->data);
    } else {
        printf("查找元素失败！\n");
    }

    destroy(root);
}

/**
 * 测试移除二叉排序树到节点
 */
void testRemoveNode() {
    elementType data[] = {50, 16, 56, 52, 8};
    elementType removeElem = 56;
    Node root = createTree(data, sizeof(data) / sizeof(elementType));
    if (root != NULL) {
        printf("创建二叉排序树成功！\n");
    } else {
        printf("创建排序树失败！\n");
    }
    if (removeNode(root, removeElem) == SUCCESS) {
        printf("移除%d成功\n", removeElem);
    } else {
        printf("不存在此元素！\n");
    }
}

/**
 * 测试获取指定节点的树的高度
 */
void testGetHeight() {
    elementType data[] = {50, 16, 56, 52, 8, 7};
    elementType searchElem = 50;
    Node root = createTree(data, sizeof(data) / sizeof(elementType));
    if (root != NULL) {
        printf("创建二叉排序树成功！\n");
    } else {
        printf("创建排序树失败！\n");
    }
    Node searchedNode = search(root, searchElem);
    if (searchedNode != NULL) {
        printf("找到元素：%d\n", searchedNode->data);
        printf("当前节点的高度为：%d\n", height(searchedNode));
    } else {
        printf("查找元素失败！\n");
    }
}

/**
 * 测试基本的二叉树创建和查找
 */
void testBasedBalancedBinTree() {
    elementType data[] = {1, 2, 3, 4, 5};
    elementType searchElem = 52;
    Node root = createBalanceTree(data, sizeof(data) / sizeof(elementType));
    if (root != NULL) {
        printf("创建平衡二叉排序树成功！\n");
    } else {
        printf("创建平衡排序树失败！\n");
    }

/*    Node searchedNode = search(root, searchElem);
    if (searchedNode != NULL) {
        printf("找到元素：%d\n", searchedNode->data);
    } else {
        printf("查找元素失败！\n");
    }*/

    destroy(root);
}

int main() {
//    testBinSearch();
//    testBasedBinSearchTree();
//    testRemoveNode();
//    testGetHeight();
    testBasedBalancedBinTree();
    return 0;
}
