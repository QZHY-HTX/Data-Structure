#include <stdio.h>  
#include <stdbool.h>  
  
#define QUEUE_SIZE 5  
  
int queue[QUEUE_SIZE];  
int front = 0;  // 队头索引  
int rear = -1;  // 队尾索引  
  
// 检查队列是否为空  
bool isQueueEmpty() {  
    return front > rear;  
}  
  
// 检查队列是否已满  
bool isQueueFull() {  
    return rear == QUEUE_SIZE - 1;  
}  
  
// 入队操作  
void enqueue(int data) {  
    if (isQueueFull()) {  
        printf("Queue is full. Cannot enqueue.\n");  
        return;  
    }  
    rear++;    
    queue[rear] = data;  
    printf("%d Enqueue!\n", data);  
}  
  
// 出队操作  
void dequeue() {  
    if (isQueueEmpty()) {  
        printf("Queue is empty. Cannot dequeue.\n");  
        return;  
    }
    printf("%d Dequeue!\n", queue[front]);
    queue[front] = -1;  
    front++;    
}  
// 遍历队列
void printQueue(){
    int i;
    for(i = 0; i < QUEUE_SIZE; i++){
        if(i==QUEUE_SIZE-1){
            printf("%d\n", queue[i]);
        }
        printf("%d ", queue[i]);
    }
}
  
int main() {  
    enqueue(10);  
    enqueue(20);  
    enqueue(30);
    enqueue(40);  
    enqueue(50); 
    enqueue(60);//表满，无法入队
    printQueue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();//队空，无法出队
    return 0;  
}