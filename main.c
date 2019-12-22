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


    Node searchedNode = search(root,searchElem);
    if(searchedNode != NULL){
        printf("找到元素：%d\n",searchedNode->data);
    } else{
        printf("查找元素失败！\n");
    }

    destroy(root);
}

int main() {
//    testBinSearch();
    testBasedBinSearchTree();
    return 0;
}
