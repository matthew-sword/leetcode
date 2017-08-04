#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int* findDuplicates(int* nums, int numsSize, int* returnSize);

int main() {

    int num[20] = {3,11,8,16,4,15,4,17,14,14,6,6,2,8,3,12,15,20,20,5};
    int n = 20;
    int re_size = 4;
    int* result;

    result = findDuplicates(num,n,&re_size);

    printf("\n");

    for (int i = 0; i < re_size; ++i)
    {
        printf("%d  ",result[i]);
    }
    //printf("%d  ",result[0]);
    //printf("%d  ",result[1]);

    return 0;
}

int* findDuplicates(int* nums, int numsSize, int* returnSize)
{
    int * outcome = (int *)malloc(sizeof(int));
    int index = 0,j = 0;

    for (int i = 0; i < numsSize;i++)
    {
         index = abs(nums[i])-1;

        if (nums[index] < 0)
        {
            outcome[j++] = abs(nums[i]);
            outcome = (int *)realloc(outcome, (j+1)*sizeof(int));

            *returnSize = j;
        }
        else
            nums[index] = -nums[index];
    }
    return outcome;
}
