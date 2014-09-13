#include<stdio.h>
#include<string.h>

void buildTable(char *table, char *pattern, int size)
{	
	int i = 2; /*loop variable */
	int cnd = 0;

	table[0] = -1;
	table[1] = 0;

	while( i < size)
	{	
		if(pattern[i-1] == pattern[cnd])
		{
			cnd++;
			table[i] = cnd;
			i++;
		}	

		else if( cnd > 0)
		{
			cnd = table[cnd];
		}

		else
		{
			table[i] = 0;
			i++;
		}
	}
}

void main()
{
	char text[] = "This is a text";
	char pattern[] = "text";
	
	int size = strlen(pattern);

	char table[size];

	buildTable(table, pattern, size);
	
	/* prints the table */
	int i=0;
	for(i;i<size;i++)
	{
		printf("%d\t",table[i]);
	}
}
