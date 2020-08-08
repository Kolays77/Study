#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#include "read.h"
#include "student.h"

void heapsorted (student *array,
                 int length)
{
  int idx, current_length;
  for (idx = 1; idx < length; idx++)
    {
      sift_up (array, idx);
    }
  for (current_length = length - 1; current_length > 0; current_length--)
    {
      array[0].swap (array[current_length]);
      sift_down (array, 0, current_length);
    }
}

void sift_up (student *binary_tree,
              int position)
{
  //student *parent = binary_tree;
  while (position != 0)
    {
      //parent = binary_tree + (position - 1) / 2;
      if (binary_tree[position / 2] < binary_tree[position])
        {
          binary_tree[position].swap (binary_tree[position / 2]);
          position--;
          position /= 2;
        }
      else
        {
          return;
        }
    }
  return;
}

void sift_down (student *binary_tree,
                int position,
                int length)
{
   while (position * 2 + 1 < length)
     {
       int index = 2 * position + 1;
       if (index + 1 < length &&
           binary_tree[index] < binary_tree[index + 1])
         {
           index++;
         }
       if (binary_tree[position] < binary_tree[index])
         {
           binary_tree[position].swap (binary_tree[index]);
           position = index;
         }
       else
         {
           return;
         }
     }
}




//void sift_up (student *binary_tree,
//              int position)
//{
//  student *parent = binary_tree, element = binary_tree[position];
//  while (position != 0)
//    {
//      parent = binary_tree + (position - 1) / 2;
//      if (*parent < element)
//        {
//          binary_tree[position] = parent[0];
//          position--;
//          position /= 2;
//        }
//      else
//        {
//          break;
//        }
//    }
//  binary_tree[position] = element;
//  return;
//}

//void sift_down (student *binary_tree,
//                int position,
//                int length)
//{
//  student element = binary_tree[position];
//  while (position * 2 + 1 < length)
//    {
//      if (position * 2 + 2 < length &&
//          binary_tree[position * 2 + 1] < binary_tree[position * 2 + 2] &&
//          element < binary_tree[position * 2 + 2])
//        {
//          binary_tree[position] = binary_tree[position * 2 + 2];
//          position *= 2;
//          position += 2;
//          continue;
//        }
//      if (element < binary_tree[position * 2 + 1])
//        {
//          binary_tree[position] = binary_tree[position * 2 + 1];
//          position *= 2;
//          position += 1;
//          continue;
//        }
//      binary_tree[position] = element;
//      return;
//    }
//  binary_tree[position] = element;
//  return;
//}
