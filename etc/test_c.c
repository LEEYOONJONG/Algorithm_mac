#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)

{
   char fruit;

   int num, price, total,a,b;

   a = 990;
   b = 1280;
   total = 0;

   printf("과일 입력:");
   scanf("%c", &fruit);


   printf("개수 입력:");
   scanf("%d", &num);

   price = (fruit == a) ? 990 : 1280;

   total = price * num;
   
   printf("결제 금액은 %d원 입니다.\n", total);
   
   
   return 0;
}
