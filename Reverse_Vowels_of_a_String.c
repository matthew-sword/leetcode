#include <stdio.h>

char* reverseVowels(char* s);

int is_vowel(char c);

int main()
{
    char str[] = "leetcode";
    char* re;
    re = reverseVowels(str);
    printf("%s\n",re);
    return 0;
}

char* reverseVowels(char* s)
{
    int len = 0,i = 0;

    while (s[i] != '\0')
    {
        len ++;
        i ++;
    }

    int le = 0,ri = len-1;
    char temp;

    while (le < ri)
    {
        if (!is_vowel(s[le]))
            le ++;

        if (!is_vowel(s[ri]))
            ri --;

        if ( is_vowel(s[le]) && is_vowel(s[ri]))
        {
            temp = s[le];
            s[le] = s[ri];
            s[ri] = temp;
            le ++;
            ri --;
        }


    }

    return s;
}

int is_vowel(char c)
{
    char vowels[10] = {'A','E','I','O','U','a','e','i','o','u'};
    int low = 0, high = 9, mid;

    while (low <= high)
    {
        mid = (low + high)/2;

        if (c > vowels[mid])
            low = mid + 1;
        else if (c < vowels[mid])
            high = mid - 1;
        else
            return 1;
    }
    return 0;
}










