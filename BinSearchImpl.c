/**
 * 二分查找的实现
 */
#include "BinSearch.h"

int binSearch(const int data[], int n, int searchElem) {
    //注意此处数组下标
    int highIndex = n - 1;
    int lowIndex = 0;
    int midIndex;
    while (highIndex > lowIndex) {
        midIndex = (highIndex + lowIndex) / 2;
#ifdef PRINT_DETAIL_INFO
        printf("midIndex:%d\n", midIndex);            //调试，打印midIndex
#endif
        if (data[midIndex] == searchElem) {         //找到
            return midIndex;
        } else if (data[midIndex] > searchElem) {   //查找前半部分
            highIndex = midIndex - 1;
        } else {
            lowIndex = midIndex + 1;                //查找后半部分
        }
    }

    return -1;
}
