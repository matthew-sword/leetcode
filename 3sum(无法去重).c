#include <stdio.h>
#include <stdlib.h>

void quickSort(int* nums,int first,int end);

int** threeSum(int* nums, int numsSize, int* returnSize);


int main()
{
    int nums[8]={0, 0, 0, 0, 0,0,0,0};
    int** result;
    int return_size = 0;

    result = threeSum(nums,8,&return_size);//return_size修改

    for (int i = 0; i < return_size; i ++)
    {
        for (int j = 0; j < 3; j++)
        {
             printf("%d  ",result[i][j]);
        }
        printf("\n");
    }
    printf("finished\n");


    return 0;
}

int** threeSum(int* nums, int numsSize, int* returnSize)
{
    int low = 0, high = numsSize-1, mid, i = 0,find;
    int** triple = (int**)malloc(sizeof(int)*(numsSize*(numsSize-1)*(numsSize-2))/6);  //C(3,n)

    if (numsSize < 3)
    {
        *returnSize = 0;
        return triple;
    }
    quickSort(nums,0,numsSize-1);   //排序

    while (low < high)
    {
          find = 0;   //每次寻找标志

          if (nums[low] == nums[low+1])
              low++;
          if (nums[high] == nums[high-1])
              high--;

          if (nums[low] + nums[high] >= 0)
          {
              mid = low+1;
              while (nums[mid] <= 0)
              {
                  if (nums[low] + nums[mid] + nums[high] == 0)
                  {
                      find= 1;

                      //赋值给triple
                      triple[i] = (int*)malloc(sizeof(int)*3);
                      triple[i][0] = nums[low];
                      triple[i][1] = nums[mid];
                      triple[i][2] = nums[high];
                      i++;

                      //移动指针,跳出mid循环
                      low++;
                      high--;
                      break;
                  }
                  mid ++;
              }

              if (find == 0)    //没有匹配的mid
                  high--;
          }

          else  //nums[low] + nums[high] <= 0
          {

              mid = high-1;
              while (nums[mid] >= 0)
              {
                  if (nums[low] + nums[mid] + nums[high] == 0)
                  {
                      find = 1;

                      //赋值给triple
                      triple[i] = (int*)malloc(sizeof(int)*3);
                      triple[i][0] = nums[low];
                      triple[i][1] = nums[mid];
                      triple[i][2] = nums[high];
                      i++;

                      //移动指针,跳出mid循环
                      low++;
                      high--;
                      break;
                  }
                  mid --;
              }

              if (find == 0)
                  low ++;
          }
    }

    *returnSize = i;
    return triple;


}

void quickSort(int* nums,int first,int end)
{
    int temp,l,r;
    if(first>=end)return;

    temp=nums[first];
    l=first;r=end;

    while(l<r)
    {
        while(l<r && nums[r]>=temp)
              r--;

        if(l<r)nums[l]=nums[r];

        while(l<r && nums[l]<=temp)
              l++;

        if(l<r)nums[r]=nums[l];
    }

    nums[l]=temp;
    quickSort(nums,first,l-1);
    quickSort(nums,l+1,end);
}