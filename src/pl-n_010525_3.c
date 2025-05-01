// Interpreter of the programming language PL-N 1.0.3

// Released into the public domain under CC0

// Before using, I advise you to read pl-n_manual.txt

#include <stdio.h>
#include <stdlib.h>

#define MAX_CODE 99999
#define MAX_MEM 99999

int main()
{
	int akt = 1,i = 0,n_m = 1;
	char a;
	printf("PUBLIC DOMAIN SOFTWARE\n");
	printf("PL-N 1.0.3\n");
	char code[MAX_CODE],n_c;
	char mem[MAX_MEM];
	fgets(code,MAX_CODE,stdin);
	int len = strlen(code);
	while (i < len)
	{
		char com = code[i];
		int m = mem[n_m];
		if (com == '+')
		{
			m++;
			mem[n_m] = m;
		}
		else if (com == '-')
		{
			m--;
			mem[n_m] = m;
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
			printf("%c",m);
		}
		else if (com == 'i')
		{
			scanf(" %c",&mem[n_m]);
		}
		else if (com == '=')
		{
			int m2 = mem[n_m + 1];
			if (m == m2)
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
			int m2 = mem[n_m + 1];
			if (m < m2)
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
			int m2 = mem[n_m + 1];
			if (m > m2)
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
			m = 0;
			mem[n_m] = m;
		}
		else if (com == '#')
		{
			m = m * 2;
			mem[n_m] = m;
		}
		else if (com == '!')
		{
			memset(mem,0,sizeof(mem));
			m = 0;
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