#include <stdio.h>
#include <stdlib.h>

int strlen_p(char *str){
    int cnt=0;
    while(*str != '\0'){
        cnt++;
        str++;
    }
    return cnt;
}
int strlen_a(char str[]){
    int cnt=0;
    while(str[cnt] != '\0'){
        cnt++;
    }
    return cnt;
}
void strcpy_p(char *dst, char *src){
    while(*src){
        *dst = *src++;
        dst++;
    }
    *dst = *src;
}
void strcpy_a(char dst[], char src[]){
    int i;
    for (i=0; src[i] != '\0'; i++){
        dst[i] = src[i];
    }
    dst[i] = src[i];
}
void strcat_p(char *dst, char *src){
    while(*dst++)
        ;
    dst--;
    while(*src){
        *dst++ = *src++;
    }
    *dst = *src;
}
void strcat_a(char dst[], char src[]){
    int i, j;
    for (i=0; dst[i] != '\0'; i++)
        ;
    for (j=0; src[j] != '\0'; j++){
        dst[i+j] = src[j];
    }
    dst[i+j] = '\0';
}
int strcmp_p(char *dst, char *src){
    while(*(dst) != '\0' && *(src) != '\0'){
        if (*dst > *src) return 1;
        else if (*dst < *src) return -1;
        dst++;
        src++;
    }
    if (*dst == '\0' && *src != '\0') return -1;
    else if (*dst != '\0' && *src == '\0') return 1;
    else return 0;
    
}
int strcmp_a(char dst[], char src[]){
    int i;
    for (i=0; dst[i]!='\0' && src[i]!='\0'; i++){
        if (dst[i] > src[i]) return 1;
        else if (dst[i] < src[i]) return -1;
    }
    if (dst[i] == '\0' && src[i] != '\0') return -1;
    else if (dst[i] != '\0' && src[i] == '\0') return 1;
    else return 0;
}
int main(){
    int len1, len2;
    char str1[20], str2[20];
    
    len1 = strlen_p("Hello");
    len2 = strlen_a("Hello");
    printf("strlen: p=%d, a=%d\n", len1, len2);
    
    strcpy_p(str1, "Hello");
    strcpy_a(str2, "Hello");
    printf("strcpy: p=%s, a=%s\n", str1, str2);

    strcat_p(str1, ", World!");
    strcat_a(str2, ", World!");
    printf("strcat: p=%s, a=%s\n", str1, str2);
    
    printf("strcmp: p=%d, a=%d\n", strcmp_p("Block", "Clock"), strcmp_a("Blur", "Blu"));
}
