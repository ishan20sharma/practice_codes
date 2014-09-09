#include<stdio.h>
#include<string.h>

void naive_search(char *text, char *pattern)
{
	int n = strlen(text);
	int m = strlen(pattern);
	int i;

	for(i = 0; i <= n-m; i++)
	{
		int j;
		for(j = 0; j < m ; j++)
		{
			if( pattern[j] != text[i+j])
				break;
		}

	if(j==m)
		printf("Pattern found at index %d \n", i);
	}	
}

void main()
{
	char *text = "This is a text";
	char *pattern = "text";

	naive_search(text, pattern);	
}	
