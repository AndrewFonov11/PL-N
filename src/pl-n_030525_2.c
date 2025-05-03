// Interpreter of the programming language PL-N 1.0.6

// Released into the public domain under CC0

// Before using, I advise you to read pl-n_manual.txt

#include <stdio.h>
#include <stdlib.h>

#define MAX_CODE 99999
#define MAX_MEM 99999

int main()
{
	srand(time(NULL));
	int akt = 1,i = 0,n_m = 1;
	char a;
	printf("PUBLIC DOMAIN SOFTWARE\n");
	printf("PL-N 1.0.6\n");
	char code[MAX_CODE],n_c;
	char mem[MAX_MEM];
	fgets(code,MAX_CODE,stdin);
	int len = strlen(code);
	while (i < len)
	{
		char com = code[i];
		if (com == '+')
		{
			mem[n_m]++;
		}
		else if (com == '-')
		{
			mem[n_m]--;
		}
		else if (com == '/')
		{
			n_m++;
		}
		else if (com == '*')
		{
			n_m--;
		}
		else if (com == 'p')
		{
			printf("%c",mem[n_m]);
		}
		else if (com == 'n')
		{
			printf("%d",mem[n_m]);
		}
		else if (com == 'i')
		{
			scanf(" %c",&mem[n_m]);
		}
		else if (com == 'v')
		{
			n_c = code[i+1];
			int num;
			if (n_c == '+')
			{
				scanf("%d",&num);
				mem[n_m] += num;
				i++;
			}
			else if (n_c == '-')
			{
				scanf("%d",&num);
				mem[n_m] -= num;
				i++;
			}
			else
			{
				scanf("%d",&mem[n_m]);
			}
		}
		else if (com == 'r')
		{
			mem[n_m] = (rand() % 256) - 128;
		}
		else if (com == '@')
		{
			n_m = 0;
		}
		else if (com == '=')
		{
			if (mem[n_m] == mem[n_m+1])
			{
				mem[n_m - 1]++;
			}
			else
			{
				mem[0] = mem[0];
			}
		}
		else if (com == '<')
		{
			if (mem[n_m] < mem[n_m+1])
			{
				mem[n_m - 1] ++;
			}
			else
			{
				mem[0] = mem[0];
			}
		}
		else if (com == '>')
		{
			if (mem[n_m] > mem[n_m+1])
			{
				mem[n_m - 1] ++;
			}
			else
			{
				mem[0] = mem[0];
			}
		}
		else if (com == '^')
		{
			mem[n_m] = 0;
		}
		else if (com == '#')
		{
			mem[n_m] = mem[n_m] * 2;
		}
		else if (com == '!')
		{
			memset(mem,0,sizeof(mem));
		}
		else if (com == 's')
		{
			n_c = code[i+1];
			mem[n_m] = (int) n_c;
			i++;
		}
		else if (com == 'e')
		{
			return 0;
		}
		else if (com == '(')
		{
			if (mem[0] == 0)
			{
				int open = 1;
				while ((open > 0) && (i < len))
				{
					i++;
					if (code[i] == '(') open++;
					else if (code[i] == ')') open--;
				}
			}
		}
		else if (com == ')')
		{
			if (mem[0] != 0)
			{
				int close = 1;
				while ((close > 0) && (i > 0))
				{
					i--;
					if (code[i] == ')') close++;
					else if (code[i] == '(') close--;
				}
				continue;
			}
		}
		else if (com == '{')
		{
			if (mem[n_m] == 0)
			{
				int opena = 1;
				while ((opena > 0) && (i < len))
				{
					i++;
					if (code[i] == '{') opena++;
					else if (code[i] == '}') opena--;
				}
			}
		}
		else if (com == '}')
		{
			if (mem[n_m] != 0)
			{
				int closea = 1;
				while ((closea > 0) && (i > 0))
				{
					i--;
					if (code[i] == '}') closea++;
					else if (code[i] == '{') closea--;
				}
				continue;
			}
		}
		i++;
	}
	printf("\nOk");
	scanf(" %c",&a);
	return 0;
}