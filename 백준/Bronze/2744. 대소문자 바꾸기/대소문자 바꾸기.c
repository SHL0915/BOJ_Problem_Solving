#include <stdio.h>
#include <string.h>

int main(void){
    char word[101]; // 100자 이하의 단어 word
    int len, i; // word의 길이 len
    scanf("%s",word);
    len = strlen(word);
    for(i=0;i<len;i++){
        if(word[i] >= 'a' && word[i] <= 'z') // 소문자인 경우
            word[i] = word[i] - 'a' + 'A';
        else if (word[i] >= 'A' && word[i] <= 'Z') // 대문자인 경우
            word[i] = word[i] - 'A' + 'a';        
    }
    printf("%s",word);
    return 0;
}