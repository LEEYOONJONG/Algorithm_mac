#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//#include <conio.h>

int main(void)
{
   char ch, i, j, k, l,Q;
   int x, y;
   x = 0;
   y = 0;

   printf("문자 i,j,k,l중 하나를 입력하시오");
   

   while (1)
   {
      
      printf("\n입력된 문자:");
      ch = _getch();

      if (ch == 'i')
         y += 1;
      else if (ch == 'k')
         y -= 1;
      else if (ch == 'j')
         x += 1;
      else if (ch == 'l')
         x -= 1;
      else if (ch == 'Q')
         break;

      printf("\n x좌표:%d, y좌표:%d", x, y);
   }
   printf("종료되었습니다.");

   return 0;

}
