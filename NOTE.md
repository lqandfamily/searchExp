# 查找实验记录
## 二分查找
- 注意初始化highIndex为n-1，不是n
```c
int highIndex = n - 1;
```

## 二叉排序树
- 一定一定要注意指针传值，特别是指针的指针的使用
- 注意判空和操作数据的顺序
```c
if (root == NULL || root->data == searchElem) {                 //找到或已经搜索完树仍未找到，返回节点(或许为NULL)
        return root;
    }
```
- 注意使用return形式的递归时的递归写法
```c
Node search(Node root, elementType searchElem) {
    if (root == NULL || root->data == searchElem) {                 //找到或已经搜索完树仍未找到，返回节点(或许为NULL)
        return root;
    } else if (searchElem > root->data) {
        return search(root->rightChild, searchElem);        //查找右子树
    } else {
        return search(root->leftChild, searchElem);         //查找左子树
    }
}
```