#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void ifplay()
{
	printf("*****************\n");
	printf("**1.play 0.exit**\n");
	printf("*****************\n");
}
void printboard(char qizi[3][3])
{
	int i = 0;
	int k = 0;
	int j = 0;
	for (i = 0;i < 3;i++)
	{
		for (k = 0;k < 3;k++)
		{
			printf(" %c ", qizi[i][k]);
			if(k<2)
			printf("|");
		}
		printf("\n");
		if(i<2)
		for (j = 0;j < 3;j++)
		{
			printf("---");
			if (j< 2)
			{
				printf("|");
			}
		}
		printf("\n");
	}
}
void init(char qizi[3][3])
{
	int i = 0;
	int k = 0;
	for (i = 0;i < 3;i++)
	{
		for (k = 0;k < 3;k++)
		{
			qizi [i][k] = ' ';  
		}
	}
}
void people(char qizi[3][3])
{
	int x;
	int y;
	while (1)
	{
		scanf("%d%d", &x, &y);
		if (x-1 >= 0 && x-1 <= 2 && y-1 >= 0 && y-1<= 2&&qizi[x-1][y-1]==' ')
		{
			qizi[x-1][y-1] = '*';
			break;
		}
		else
			printf("输入格式错误,请重新输入");
	}
}
void robot(char qizi[3][3])
{
	int x;
	int y;
	srand((unsigned int)time(NULL));
	while (1)
	{
		x = rand() % 3;
		y = rand() % 3;
		if (qizi[x][y] == ' ')
		{
			qizi[x][y] = '#';
			break;
		}
	}
}
char ifwin(char qizi[3][3])
{
	int i;
	int j;
	for (i = 0;i < 3;i++)
	{
		if (qizi[i][0] == qizi[i][1]&& qizi[i][1] == qizi[i][2]&&qizi[i][0]!=' ')
			return 'x';
	}
	for (j = 0;j < 3;j++)
	{
		if (qizi[0][j] == qizi[1][j] &&qizi[1][j]==qizi[2][j]&&qizi[0][j]!=' ')
			return 'x';
	}
	if ((qizi[0][0] == qizi[1][1]&& qizi[1][1] == qizi[2][2] || qizi[0][2] == qizi[1][1]&& qizi[1][1] == qizi[2][0])&& qizi[1][1] != ' ')
		return 'x';
	if (ifk(qizi))
		return 'z';
}
int ifk(char qizi[3][3])
{
	int i;
	int j;
	for (i = 0;i < 3;i++)
	{
		for (j = 0;j < 3;j++)
		{
			if (qizi[i][j] == ' ')
				return 0;

		}
	}
	return 1;
}
int main()
{
	for (;;)
	{
		char a;
		char qizi[3][3] = { 0 };
		init(qizi);
		int num;
		ifplay();
		scanf("%d", &num);
		if (num == 0)
		{
			break;
		}
		while (num)
		{
			printboard(qizi);
			printf("请下棋\n");
			people(qizi);
			a = ifwin(qizi);
			if (a == 'x')
			{
				printboard(qizi);
				printf("你赢了\n");
				break;
			}
			else if (a == 'z')
			{
				printboard(qizi);
				printf("平局\n");
				break;
			}
			robot(qizi);
			a = ifwin(qizi);
			if (a == 'x')
			{
				printboard(qizi);
				printf("你输了\n");
				break;
			}
			else if (a == 'z')
			{
				printboard(qizi);
				printf("平局\n");
				break;
			}

		}
	}
}