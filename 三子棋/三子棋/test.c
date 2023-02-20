#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include"game.h"
//测试三子棋游戏逻辑

void menu()
{
	printf("*************************\n");
	printf("******** 1. play ********\n");
	printf("******** 0. exit ********\n");
	printf("*************************\n");

}
void game()
{
	char ret = 0;
	//存放下棋的数据
	char board[ROW][COL] = { 0 };
	//初始化棋盘全为空格
	InitBoard(board, ROW,COL);
	//打印棋盘
	DisplayBoard(board, ROW, COL);
	while (1)
	{
		//玩家下棋
		player_move(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//判断输赢
		ret=is_win(board,ROW,COL);
		if (ret != 'C')
		{
			break;
		}
		//电脑下棋
		computer_move(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret = is_win(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
		printf("玩家赢\n");
	else if (ret == '#')
		printf("电脑赢\n");
	else
		printf("游戏平局\n");
	DisplayBoard(board, ROW, COL);
}
//游戏结束
//玩家赢  '*'
//电脑赢  '#'
//平局    'Q'
//继续	  'C'
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();//游戏
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误\n");
			break;
		}

	} while (input);
}
int main()
{
	test();
	return 0;
}