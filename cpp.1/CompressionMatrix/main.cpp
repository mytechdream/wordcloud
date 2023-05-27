#include <stdio.h>
#include <stdlib.h>

// 1.����ڵ�ṹ��
typedef struct Node {
    int row;           // ���±�
    int col;           // ���±�
    int val;           // ����Ԫ�ص�ֵ
    struct Node* right; // ָ��ͬһ����һ���ڵ�
    struct Node* down;  // ָ��ͬһ����һ���ڵ�
} Node;

// 2.����һ���½ڵ�
Node* newNode(int row, int col, int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->row = row;
    node->col = col;
    node->val = val;
    node->right = NULL;
    node->down = NULL;
    return node;
}

// 3.�����������󣬴���ʮ������
void createCrossList(int a[][5], int m, int n, Node* headRow[], Node* headCol[]) {
    int i, j;
    // ��ʼ��ͷ�ڵ�
    for (i = 1; i <= m; i++) {
        headRow[i] = newNode(i, 0, 0);
    }
    for (j = 1; j <= n; j++) {
        headCol[j] = newNode(0, j, 0);
    }
    // ��������
    for (i = 1; i <= m; i++) {
        Node* curRow = NULL;
        for (j = 1; j <= n; j++) {
            if (a[i - 1][j - 1] != 0) {  // ����Ƿ���Ԫ��
                // ����һ���½ڵ�
                Node* node = newNode(i, j, a[i - 1][j - 1]);
                if (headRow[i]->down == NULL) { // ��һ���ڵ�
                    headRow[i]->down = node;
                    curRow = node;
                }
                else {
                    curRow->right = node;
                    curRow = curRow->right;
                }
                // ���ڵ���뵽��������
                Node* curCol = NULL;
                if (headCol[j]->right == NULL) { // ��һ���ڵ�
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

// 4.��ӡʮ�������ʾ�ľ���
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
    // 4x5��ϡ�����
    int a[4][5] = {
        {1, 0, 0, 0, 2},
        {0, 3, 0, 4, 1},
        {0, 5, 0, 0, 2},
        {0, 0, 6, 0, 0}
    };

    Node* headRow[5];  // ��ͷָ������
    Node* headCol[6];  // ��ͷָ������

    createCrossList(a, 4, 5, headRow, headCol); // ����ʮ������
    printCrossList(headRow, headCol); // ��ӡʮ������

    return 0;
}