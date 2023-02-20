#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include"game.h"
//������������Ϸ�߼�

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
	//������������
	char board[ROW][COL] = { 0 };
	//��ʼ������ȫΪ�ո�
	InitBoard(board, ROW,COL);
	//��ӡ����
	DisplayBoard(board, ROW, COL);
	while (1)
	{
		//�������
		player_move(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//�ж���Ӯ
		ret=is_win(board,ROW,COL);
		if (ret != 'C')
		{
			break;
		}
		//��������
		computer_move(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret = is_win(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
		printf("���Ӯ\n");
	else if (ret == '#')
		printf("����Ӯ\n");
	else
		printf("��Ϸƽ��\n");
	DisplayBoard(board, ROW, COL);
}
//��Ϸ����
//���Ӯ  '*'
//����Ӯ  '#'
//ƽ��    'Q'
//����	  'C'
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("��ѡ��:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();//��Ϸ
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("�������\n");
			break;
		}

	} while (input);
}
int main()
{
	test();
	return 0;
}