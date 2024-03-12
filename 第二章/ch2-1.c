#include <stdio.h>  
#include <string.h>  
  
#define MAX_SIZE 1000  
  
char decode(char ch) {  
    if (ch < 'A' || ch > 'Z') {  
        return ch; // 非字母字符或小写字母直接返回  
    }  
    return ((ch - 'A' - 5 + 26) % 26) + 'A'; // 计算偏移并返回明文字符  
}  
  
int main() {  
    char ciphertext[MAX_SIZE];  
      
    // 使用 scanf 读取一行，直到遇到换行符或 EOF  
    // 注意 scanf 不会自动读取换行符，需要额外处理  
    // 这里使用 "%[^\n]" 格式说明符来读取直到换行符之前的所有字符  
    if (scanf("%[^\n]", ciphertext) != 1) {  
        // 如果没有读取到任何字符，则输出 NULL 并退出  
        printf("NULL\n");  
        return 0;  
    }  
      
    // 清空输入缓冲区中的换行符（如果有的话）  
    int c;  
    while ((c = getchar()) != '\n' && c != EOF);  
      
    // 解密并输出明文字符串  

    for (int i = 0; ciphertext[i] != '\0'; i++) {  
        putchar(decode(ciphertext[i]));  
    }  
    putchar('\n'); // 输出换行符以符合输出格式要求  
      
    return 0;  
}