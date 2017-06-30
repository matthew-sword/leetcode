#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int isValid(char* s); 
    
int main(int argc, char *argv[]) 
{
	int result;
	char str[20] = "[][]";
	result = isValid(str); 
	printf("%d",result);
	return 0;
}

int isValid(char* s) 
{
    int len = strlen(s);
    char stack[len];
    int flag = 0,i = 0, stc= 0;
    for (i = 0;i < len;i ++)
    {
    	if (stc == 0 && flag == 0)
    	{
    		stack[stc] = s[i];	//push, and stc will ++
    		flag = 1;
		}
		else
		{
			if ( (stack[stc] == '(' && s[i] == ')')
			||   (stack[stc] == '[' && s[i] == ']')
			||   (stack[stc] == '{' && s[i] == '}') )	// and more [] {}
			{
				if (stc != 0)  //pop
				    stc--;
				else 
				  	flag = 0;
			}
			else
			{
				//stc++;
				stack[++stc] = s[i];
			}
		}
	}
	
	if (stc == 0 && flag == 0)
	    return 1;
    else 
        return 0;
    




}
