#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void search(char *table, char *text, char *pattern, int sizeT, int sizeP)
{
	int m = 0; /* starting index in text where pattern matches */
	int i = 0; /* variable for pattern */

	printf("Size of text and pattern is %d and %d\n",sizeT,sizeP);

	while(m+i < sizeT)
	{
		if(pattern[i] == text[m])
		{
			i++;
			m++;
		}

		if(i == sizeP)
                {
                        printf("Starting index of pattern is %d\n",m-i);
                        i = 0;

                }
		
		else if(pattern[i] != text[m])
		{
			if(table[i] > -1)
			{
				m = m-table[i];	
				i = table[i];
			}
			else
			{
				m++;
				i=0;
			}
		}
	}
	printf("No pattern found\n");
	exit(0);
}


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
	char text[] = "AABAACAADAABAAABAA";
	char pattern[] = "AABA";
	
	int size = strlen(pattern);

	char table[size];

	buildTable(table, pattern, size);
	
	/* prints the table */
	int i=0;
	for(i;i<size;i++)
	{
		printf("%d\t",table[i]);
	}

	search(table,text,pattern,strlen(text),strlen(pattern));
}
