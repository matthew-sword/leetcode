#include <stdio.h>
#include <stdlib.h>
//test of push 
int reverse(int x); 

int main(int argc, char *argv[]) 
{
	int num =1563847412;
	int re_num;
	re_num = reverse(num);
	printf("%d",re_num);
	return 0;
}

int reverse(int x) 
{
	int x_arr[10];
	int re_x = 0;
	int i,index = 0,n = 1;
	    
	for (i = 0;i < 10;i ++)
	{
		x_arr[i] = x % 10;
		x = x / 10;
	}
	
	for (i = 9;i >= 0;i --)
	{
		if (x_arr[i] != 0)
		   {
		   	index = i;
		   	break;
		   }
	} 
	for (i = index;i >= 0;i --)
	{	
	   if (n * x_arr[i] / n != x_arr[i])
	   {
	   	re_x = 0;
	   	break;
	   }
	   
	   if ((re_x > 0 && x_arr[i] * n > 0 && re_x + x_arr[i] * n < 0) ||
	       (re_x < 0 && x_arr[i] * n < 0 && re_x + x_arr[i] * n > 0))
		{
			re_x = 0;
	   	    break;
		}  
	   
	    re_x += x_arr[i] * n;
	    n *= 10;
	}    
	
	return (re_x);
    
}
