#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int* twoSum(int* nums, int numsSize, int target);

int main(int argc, char *argv[]) 
{
	int * results;
	int nums[3] = {3,2,4};
	results = twoSum(nums,3,6);
	printf("%d,%d",results[0],results[1]);
	return 0;
}

int* twoSum(int* nums, int numsSize, int target) 
{
    int i, j, find;
    int results[2];
    for (i = 0;i < numsSize;i++)
    {
    	if (nums[i] > target)
    	    i++;
    	else
    	{
    		find = target - nums[i];
    		for (j = i+1;j < numsSize;j++)
    		{
    			if (find == nums[j])
    			{
    				results[0] = i;
    				results[1] = j;
    				
				}
			}
		}	    
	}
	return (results);
}
