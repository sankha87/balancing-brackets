#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<malloc.h>
bool isForward(char ch)
{
	if (ch == '[' || ch == '{' || ch == '(')
		return true;
	else
		return false;
}
bool isBackward(char ch)
{
	if (ch == ']' || ch == '}' || ch == ')')
		return true;
	else
		return false;
}
bool closing_brackets(char ch1, char ch2)
{
	if (ch1 == '[' && ch2 == ']')
		return true;
	else if (ch1 == '{' && ch2 == '}')
		return true;
	else if (ch1 == '(' && ch2 == ')')
		return true;
	else
		return false;
}
void main()
{
	int n;
	bool bb = true;
	char *ch;
	printf("enter no of brackets : \n");
	scanf("%d", &n);
	ch = (char *)malloc(n*sizeof(char));
	printf("enter brackets : \n");
		scanf("%s",ch);

		char b[20] = {};
		for (int i = 0, j = 0; i < n; i++, j++)
		{
			if (isForward(*(ch + i)))
				b[j] = *(ch+i);
			if (isBackward(*(ch + i)))
			{
				if (closing_brackets(b[j - 1], *(ch + i)))
				{
					b[j - 1] = '\0';
					j -= 2;
				}
				else
					bb = false;
			}
		}
if(b[0] == '\0' && bb)
	printf(" balanced");
else
	printf("not balanced");
_getch();
}