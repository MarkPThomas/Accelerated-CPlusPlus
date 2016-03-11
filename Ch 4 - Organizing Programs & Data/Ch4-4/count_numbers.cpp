#include "count_numbers.h"
#include "convert_number_to_string.h"

using namespace std;

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

   string numberString = convert(num);

   count = numberString.length();

   return count;
}
