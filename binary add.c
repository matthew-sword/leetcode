#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* addBinary(char* a, char* b);

int main() {
    char* a = "110010100000000000010111100111100101010010111101101100010001111101100110101011000110111111110000";
    char* b= "11000000001101110101000111110011100100100001110111011010001001";
    char* sum;
    sum =  addBinary(a, b);
    printf("%s",sum);
    return 0;
}

char* addBinary(char* a, char* b)
{
    int len_a = 0,len_b = 0,i = 0;
    char holder = '0';

    while (a[i] != '\0')
    {
        len_a ++;
        i ++;
    }

    i = 0;
    while (b[i] != '\0')
    {
        len_b ++;
        i ++;
    }
    int len_sum = len_a > len_b ? (len_a+1) : (len_b+1);
    char* sum = (char*)malloc(sizeof(char) * (len_sum+1));
    memset(sum,0,(len_sum+1)*sizeof(char));

    for ( i = len_sum-1; i >= 0 && len_a>0 && len_b>0; i --)
    {
        sum[i] = (a[len_a-1] + b[len_b-1] + holder - '0'*3) % 2 + '0';

        holder = (a[len_a-1] + b[len_b-1] + holder - '0'*3) / 2 + '0';
        len_a--;
        len_b--;
    }

    if (len_a == 0)
    {
        while (len_b > 0)
        {
            sum[i] = (b[len_b-1] + holder - '0'*2) % 2 + '0';

            holder = (b[len_b-1] + holder - '0'*2) / 2 + '0';
            i--;
            len_b--;
        }
    }
    else if (len_b == 0)
    {
        while (len_a > 0)
        {
            sum[i] = (a[len_a-1] + holder - '0'*2) % 2 + '0';

            holder = (a[len_a-1] + holder - '0'*2) / 2 + '0';
            i--;
            len_a--;
        }
    }
    if (holder == '1')
    {
        sum[0] = '1';
        return sum;
    }

   char* sum0 = (char*)malloc(sizeof(char) * (len_sum));
    strcpy(sum0,sum+1);
    return sum0;
}