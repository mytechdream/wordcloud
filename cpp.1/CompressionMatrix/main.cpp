#include <stdio.h>
#include <stdlib.h>

// 1.定义节点结构体
typedef struct Node {
    int row;           // 行下标
    int col;           // 列下标
    int val;           // 非零元素的值
    struct Node* right; // 指向同一行下一个节点
    struct Node* down;  // 指向同一列下一个节点
} Node;

// 2.创建一个新节点
Node* newNode(int row, int col, int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->row = row;
    node->col = col;
    node->val = val;
    node->right = NULL;
    node->down = NULL;
    return node;
}

// 3.遍历整个矩阵，创建十字链表
void createCrossList(int a[][5], int m, int n, Node* headRow[], Node* headCol[]) {
    int i, j;
    // 初始化头节点
    for (i = 1; i <= m; i++) {
        headRow[i] = newNode(i, 0, 0);
    }
    for (j = 1; j <= n; j++) {
        headCol[j] = newNode(0, j, 0);
    }
    // 遍历矩阵
    for (i = 1; i <= m; i++) {
        Node* curRow = NULL;
        for (j = 1; j <= n; j++) {
            if (a[i - 1][j - 1] != 0) {  // 如果是非零元素
                // 创建一个新节点
                Node* node = newNode(i, j, a[i - 1][j - 1]);
                if (headRow[i]->down == NULL) { // 第一个节点
                    headRow[i]->down = node;
                    curRow = node;
                }
                else {
                    curRow->right = node;
                    curRow = curRow->right;
                }
                // 将节点插入到列链表中
                Node* curCol = NULL;
                if (headCol[j]->right == NULL) { // 第一个节点
                    headCol[j]->right = node;
                    curCol = node;
                }
                else {
                    curCol = headCol[j]->right;
                    while (curCol->down != NULL) {
                        curCol = curCol->down;
                    }
                    curCol->down = node;
                }
            }
        }
    }
}

// 4.打印十字链表表示的矩阵
void printCrossList(Node* headRow[], Node* headCol[]) {
    int i, j;
    for (i = 1; i <= 4; i++) {
        Node* curRow = headRow[i]->down;
        for (j = 1; j <= 5; j++) {
            Node* curCol = headCol[j]->right;
            if (curRow != NULL && curRow->col == j) {
                printf("%d ", curRow->val);
                curRow = curRow->right;
            }
            else if (curCol != NULL && curCol->row == i) {
                printf("%d ", curCol->val);
            }
            else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

int main() {
    // 4x5的稀疏矩阵
    int a[4][5] = {
        {1, 0, 0, 0, 2},
        {0, 3, 0, 4, 1},
        {0, 5, 0, 0, 2},
        {0, 0, 6, 0, 0}
    };

    Node* headRow[5];  // 行头指针数组
    Node* headCol[6];  // 列头指针数组

    createCrossList(a, 4, 5, headRow, headCol); // 创建十字链表
    printCrossList(headRow, headCol); // 打印十字链表

    return 0;
}