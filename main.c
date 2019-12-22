#include <stdio.h>
#include "BinSearch.h"

void testBinSearch() {
    typedef int elementType;
    elementType data[] = {1, 2, 3, 4, 6, 7, 8, 9, 10, 11, 12, 13, 17, 18, 19, 20, 24, 25, 26, 30, 35, 40, 45, 50, 100};
    elementType searchElem = 110;
    int searchedIndex = binSearch(data, sizeof(data) / sizeof(elementType), searchElem);
    if (searchedIndex != -1) {
        printf("查找元素%d带下标为:%d\n", data[searchedIndex], searchedIndex);
    } else {
        printf("查找元素失败！\n");
    }
}

int main() {
    testBinSearch();
    return 0;
}
