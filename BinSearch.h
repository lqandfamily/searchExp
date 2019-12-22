/**
 * 二分查找的头文件
 */
#ifndef BIN_SEARCH_H
#define BIN_SEARCH_H

#include <stdio.h>

#define PRINT_DETAIL_INFO


/**
 * 二分查找
 * @param data，数据源数组
 * @param n 数组长度
 * @param searchElem 待查找元素
 * @return 返回带查找元素的下标，查找失败返回-1
 */
int binSearch(const int data[], int n, int searchElem);

#endif
