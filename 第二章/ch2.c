#include <stdio.h>  
#include <stdlib.h>  
#include <stdbool.h>  
  
#define MAX_SIZE 100 // 线性表的最大长度  
#define OK 1  
#define ERROR 0  
#define OVERFLOW -2  
  
typedef int Status; // 函数返回值类型  
typedef int ElemType; // 元素类型  
  
// 线性表的结构体定义  
typedef struct {  
    ElemType data[MAX_SIZE]; // 数组存储数据元素  
    int length; // 线性表当前长度  
} SqList;  
  
// 初始化线性表  
Status InitList(SqList *L) {  
    L->length = 0;  
    return OK;  
}  
  
// 插入元素到线性表  
Status ListInsert(SqList *L, int i, ElemType e) {  
    if (L->length == MAX_SIZE) {  
        // 线性表已满  
        return ERROR;  
    }  
    if (i < 1 || i > L->length + 1) {  
        // 插入位置不合法  
        return ERROR;  
    }  
    for (int j = L->length; j >= i; j--) {  
        L->data[j] = L->data[j - 1]; // 向后移动元素  
    }  
    L->data[i - 1] = e; // 插入新元素  
    L->length++; // 更新线性表长度  
    return OK;  
}  
  
// 从线性表中删除元素  
Status ListDelete(SqList *L, int i, ElemType *e) {  
    if (L->length == 0) {  
        // 线性表为空  
        return ERROR;  
    }  
    if (i < 1 || i > L->length) {  
        // 删除位置不合法  
        return ERROR;  
    }  
    *e = L->data[i - 1]; // 保存被删除的元素  
    for (int j = i; j < L->length; j++) {  
        L->data[j - 1] = L->data[j]; // 向前移动元素  
    }  
    L->length--; // 更新线性表长度  
    return OK;  
}  
  
// 读取线性表元素  
Status GetElem(SqList L, int i, ElemType *e) {  
    if (i < 1 || i > L.length) {  
        // 读取位置不合法  
        return ERROR;  
    }  
    *e = L.data[i - 1]; // 读取元素  
    return OK;  
}  
  
// 打印线性表  
void PrintList(SqList L) {  
    for (int i = 0; i < L.length; i++) {  
        printf("%d ", L.data[i]);  
    }  
    printf("\n");  
}  
  
int main() {  
    SqList L;  
    ElemType e;  
    Status status;  
  
    // 初始化线性表  
    if (InitList(&L)) {  
        printf("线性表初始化成功！\n");  
    } else {  
        printf("线性表初始化失败！\n");  
        return -1;  
    }  
  
    // 插入元素  
    status = ListInsert(&L, 1, 10);  
    status = ListInsert(&L, 2, 20);  
    status = ListInsert(&L, 3, 30);  
    PrintList(L); // 输出：10 20 30  
  
    // // 删除元素  
    // status = ListDelete(&L, 2, &e);  
    // if (status == OK) {  
    //     printf("删除的元素是：%d\n", e); // 输出：删除的元素是：20  
    // }  
    // PrintList(L); // 输出：10 30  
  
    // // 读取元素  
    // status = GetElem(L, 2, &e);  
    // if (status == OK) {  
    //     printf("读取的元素是：%d\n", e); // 输出：读取的元素是：30  
    // }  
  
    return 0;  
}