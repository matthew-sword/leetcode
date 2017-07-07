<<<<<<< HEAD
=======
<<<<<<< c4ef75fbd52b71f1494cf99a97365772d904b17f
#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int* twoSum(int* nums, int numsSize, int target);

int main(int argc, char *argv[]) 
{
	int * results;
	int nums[6] = {-1,-2,-3,-4,-5};
	results = twoSum(nums,5,-8);
	printf("%d,%d",results[0],results[1]);
	return 0;
}

int* twoSum(int* nums, int numsSize, int target) 
{
    int i, j, find;
    int* results = (int*)malloc(sizeof(int)*2);
    for (i = 0;i < numsSize;i++)
    {
    		for (j = i+1;j < numsSize;j++)
    		{
    			if (target == nums[i] + nums[j])
    			{
    				results[0] = i;
    				results[1] = j;
    				
				}
			}
			    
	}
	return (results);
}
=======
>>>>>>> dev
#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int* twoSum(int* nums, int numsSize, int target);

int main(int argc, char *argv[]) 
{
	int * results;
	int nums[6] = {-1,-2,-3,-4,-5};
	results = twoSum(nums,5,-8);
	printf("%d,%d",results[0],results[1]);
	return 0;
}

int* twoSum(int* nums, int numsSize, int target) 
{
    int i, j, find;
    int* results = (int*)malloc(sizeof(int)*2);
    for (i = 0;i < numsSize;i++)
    {
    		for (j = i+1;j < numsSize;j++)
    		{
    			if (target == nums[i] + nums[j])
    			{
    				results[0] = i;
    				results[1] = j;
    				
				}
			}
			    
	}
	return (results);
}
<<<<<<< HEAD
=======
>>>>>>> test of push
>>>>>>> dev
