#include <stdio.h>
#include <stdbool.h>

#define MaxSize 10
int q[MaxSize];
int front;
int rear;

//空队列返回true,否则返回false
bool empty() {
    return front == rear;
}
//队列满返回true,否则返回false
bool full() {
    return rear + 1 == MaxSize;
}
//入队列
void push(int x) {
    ++rear;
    q[rear] = x;
}
//取队首元素
int getFront() {
    return q[front+1];
}
//出队列
void pop() {
    ++front;
}

int main(int argc, char const *argv[])
{
    int i;
    front = rear = -1;    //初始化队列

    while (scanf("%d", &i) != EOF) {
        if (i == -1)break;
        if (!full())    //队列未满时
            push(i);    //入队列
        else
            printf("queue is full!\n");
    }
    while (!empty()) {    //输出队列元素
        printf("%d ", getFront());
        pop();
    }
    printf("\n");

    return 0;
}