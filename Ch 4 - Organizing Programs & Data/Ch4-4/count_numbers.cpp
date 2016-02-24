#include "count_numbers.h"

int count_numbers (int num)
{
   int count = 0;

   if (num == 0)
   {
      return 1;
   }

   while (num != 0)
   {
      count++;
      num /= 10;
   }
   return count;
}

int count_numbers (double num)
{
   int count = 0;

   if (num == 0)
   {
      return 1;
   }

   while (num != 0)
   {
      count++;
      num /= 10;
   }
   return count;
}
