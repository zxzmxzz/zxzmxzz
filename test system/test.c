#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<conio.h>
#include<math.h>
#define yes_str 1
#define yes_admin 2
#define no 0
#define err -1
//���������
int verify(char name[], char password[]);
int input(char str[], int len, int test,int x,int y);
void ms();
void gotoxy(int x, int y);
void frame(int c, int k, int x, int y);
void out();
void login();
void student(str);
void regis();
void begin();
int entering(char name[], char password[], char id[]);
void administrator(int i);
void modify_password(int id);
void test();
void query_result();
void mana_t();
void mana_j();
void nser_mana(int id);
void query_condition(int id);
void query_all(int id);
void frame_a(int x, int y);
//���������div
char username[90][20];//�˺��û����洢��
char userpassword[90][20];//�˺�����洢��
char user[90][1];//�˺���ݴ洢��
int user_id=1;//��ݼ�ֵ
//������ѯ
void query_condition(int id)
{
	int i = 1, g = 1, dy = 1, zs = 0, l=0,po=0;
	for (l = 0; l < 90; l++)
	{
		if (user[l][0] == '1')
		{
			zs++;
		}
	}//�ܹ��ж���ѧ��
	while (1)
	{
		int j = 1, p = 1,test=0;
		char ch = 0, ch1 = 0, ch2[4] = {0};
		fflush(stdin);
		system("cls");
		frame(35, 24, 25, 1);
		gotoxy(45, 3);
		printf("*���迼��ϵͳ����ȫ����ѯ����*");
		gotoxy(42, 4);
		printf("��ӭ%s,", username[id]);
		if (user[id][0] == '1')
		{
			printf("����");
		}
		else if (user[id][0] == '2')
		{
			printf("����Ա");
		}
		gotoxy(60, 4);
		ms();
		gotoxy(42,6);
		printf("�鿴����ID");
		frame(12, 3, 50, 5);
		frame_a(40, 9);
		gotoxy(45, 10);
		printf("ID");
		gotoxy(53, 10);
		printf("����");
		gotoxy(62, 10);
		printf("����");
		gotoxy(73, 10);
		printf("״̬");
		gotoxy(41, 18);
		printf("<-  ->���Ҽ���ҳ");
		gotoxy(60, 18);
		printf("%d",dy);
		gotoxy(61, 18);
		printf("/");
		gotoxy(62, 18);
		printf("%d", (zs - 1) / 3 + 1);
		gotoxy(55, 19);
		printf("˫���س�����������");
		for (j = 0; j <= 2; j++)//��ʾ��ǰ�����ʾ��ѧ��
		{
			if (user[g][0] == '1')
			{
				gotoxy(43, 12 + j * 2);
				printf("1%03d", i);
				gotoxy(51, 12 + j * 2);
				printf("%s", username[g]);
				gotoxy(60, 12 + j * 2);
				printf("%s", userpassword[g]);
				i++;
			}
			else if (user[g][0] == '2')
			{
				j--;//���п���ʾ�ȵ���һ��Ϊ�������˺�����
			}
			g++;
		}
		if (ch = getch())
		{
			if (ch == 27)//����ESC���˳�
			{
				nser_mana(id);
			}
			ch1 = getch();
			if (ch1 == 75)//��������ķ���
			{
				if (dy == 1)//��ǰҳΪ��һҳʱ
				{
					gotoxy(65, 18);
					printf("�Ѿ��ǵ�һҳ");
					g = 1;
					i = 1;
					Sleep(500);
					continue;
				}
				else//��ǰҳΪ����ҳʱ
				{
					dy--;//����ǰҳ������һҳ
					i = dy + (dy - 1) * 2;//��ǰҳ����һ��ID����
					j = 1;
					p = 1;
					printf("%d", i);
					while (1)
					{
						if (j == i)//�ҵ�ID����Ӧ�Ŀ���
						{
							break;
						}
						if (user[p][0] == '1')//Ѱ���Ƿ�Ϊ����
						{
							j++;
						}
						p++;
					}
					g = j;
				}
			}
			else if (ch1 == 77)//�����Ҽ��ķ���
			{
				if (dy == (zs - 1) / 3 + 1)
				{
					gotoxy(65, 18);
					printf("�Ѿ������һҳ");
					i = 1 + (3 * (dy - 1));
					g = 1 + (3 * (dy - 1));
					Sleep(500);
					continue;
				}
				else
				{
					dy++;//ҳ�������һҳ
				}
			}
			else//����������
			{		
				gotoxy(52, 6);
				scanf("%s", &ch2);
				for (j = 0; j < 90; j++)
				{
					if (user[p][0] == '1')
					{
						p++;//ѧ������
					}
				}
				for (j = 1; j <= 3; j++)
				{
					test = test + (ch2[j] - 48) * pow(10, 3 - j);//�����������Ϊ�ڼ�������
				}
				if (test >= 1 && test <= p - 1)//��������Ƿ����б�Χ֮��
				{
					po = ((test - 1) / 3 + 1);//���������Ķ�Ӧҳ��
					i = po + (po - 1) * 2;//��Ӧҳ��ĵ�һ����ֵ
					j = 1;
					p = 1;
					while (1)
					{
						if (j == i)//�ҳ�id��Ӧ��ѧ��
						{
							break;
						}
						if (user[p][0] == '1')//Ѱ���Ƿ�Ϊ����
						{
							j++;
						}
						p++;
					}
					g = j;
					dy = po;
				}
				else//�������
				{
					gotoxy(67, 18);
					printf("�޸ÿ�����Ϣ");
					g = 1;
					i = 1;
					Sleep(500);
					continue;
				}
			}
		}
	}
}
//ȫ����ѯ
void query_all(int id)
{
	int i = 1,g=1,dy=1,zs=0,l;
	for (l = 0; l < 90; l++)
	{
		if (user[l][0] == '1')
		{
			zs++;
		}
	}//�ܹ��ж���ѧ��
	while (1)
	{
		int j = 1, p = 1;
		char ch = 0, ch1 = 0;
		fflush(stdin);
		system("cls");
		frame(35, 24, 25, 1);
		gotoxy(45, 3);
		printf("*���迼��ϵͳ����ȫ����ѯ����*");
		gotoxy(42, 4);
		printf("��ӭ%s,", username[id]);
		if (user[id][0] == '1')
		{
			printf("����");
		}
		else if (user[id][0] == '2')
		{
			printf("����Ա");
		}
		gotoxy(60, 4);
		ms();//��ʾʱ��
		frame_a(40, 6);
		gotoxy(45, 7);
		printf("ID");
		gotoxy(53, 7);
		printf("����");
		gotoxy(62, 7);
		printf("����");
		gotoxy(73, 7);
		printf("״̬");
		gotoxy(41, 16);
		printf("<-  ->���Ҽ���ҳ");
		gotoxy(60, 16);
		printf("%d", dy);
		gotoxy(61, 16);
		printf("/");
		gotoxy(62, 16);
		printf("%d",(zs-1)/3+1);
		for (j = 0; j <= 2; j++)//��ʾ��ǰ�����ʾ��ѧ��
		{
			if (user[g][0] == '1')
			{
				gotoxy(43, 9 + j * 2);
				printf("1%03d", i);
				gotoxy(51, 9 + j * 2);
				printf("%s", username[g]);
				gotoxy(60, 9 + j * 2);
				printf("%s", userpassword[g]);
				i++;
			}
			else if(user[g][0]=='2')
			{
				j--;//���п���ʾ�ȵ���һ��Ϊ�������˺�����
			}
			g++;
			
		}
		if (ch = getch())
		{
			if (ch == 27)//����ESC���˳�
			{
				nser_mana(id);
			}
			ch1 = getch();
			if (ch1 == 75)//��������ķ���
			{
				if (dy == 1)//��ǰҳΪ��һҳʱ
				{
					gotoxy(65, 16);
					printf("�Ѿ��ǵ�һҳ");
					g = 1;
					i = 1;
					Sleep(500);
					continue;
				}
				else//��ǰҳΪ����ҳʱ
				{
					dy--;//����ǰҳ������һҳ
					i = dy+(dy-1)*2;//��ǰҳ����һ��ID����
					j = 1;
					p = 1;
					while (1)
					{
						if (j == i)//�ҵ�ID����Ӧ�Ŀ���
						{
							break;
						}
						if (user[p][0] == '1')//Ѱ���Ƿ�Ϊ����
						{
							j++;
						}
						p++;
					}
					g = j;
				}
			}
			else if (ch1 == 77)//�����Ҽ��ķ���
			{
				if (dy == (zs-1)/3+1)//��ǰҳΪ���һҳʱ
				{
					gotoxy(65, 16);
					printf("�Ѿ������һҳ");
					i = 1 + (3 * (dy - 1));
					g = 1 + (3 * (dy - 1));
					Sleep(500);
					continue;
				}
				else
				{
					dy++;//ҳ�������һҳ
				}
			}
			else//����������ʱ
			{
				gotoxy(65, 16);
				printf("�����������������");
				Sleep(500);
				i = 1 + (3 * (dy - 1));
				g = 1 + (3 * (dy - 1));
				continue;
			}
		}
	}

}
//�޸�����¼�����
int entering_password(char name[], char password[], char id[])
{
	int i = 0;
	for (i = 0; i < 90; i++)
	{
		if (strcmp(username[i], name) == 0)//Ѱ���˺Ŷ�Ӧ�������±�
		{
			break;
		}
	}
	strcpy(username[i], name);
	strcpy(userpassword[i], password);
	strcpy(user[i], id);
}
//ע��¼����Ϣ����
int entering(char name[],char password[],char id[])
{
	int i=0,l=1;
	for (i = 0; i < 90; i++)
	{
		if (strcmp(username[i], name) == 0)//����˺��Ƿ��Ѵ���
		{
			l = 0;
			break;
		}
	}
	if (l == 1)//�˺Ų��������ݵ���
	{
		strcpy(username[user_id], name);
		strcpy(userpassword[user_id], password);
		strcpy(user[user_id], id);
		user_id++;
	}
	return l;
}
//��¼��֤����
int verify(char name[],char password[])
{
	int i=0, j=0,test=no;
	for (i = 0; i < 90; i++)
	{
		if (strcmp(username[i], name) == 0 && strcmp(userpassword[i], password) == 0&&user[i][0]=='1')//�˺�Ϊѧ��
		{
			test = yes_str;
			break;
		}
		else if (strcmp(username[i], name) == 0 && strcmp(userpassword[i], password) == 0 && user[i][0] == '2')//�˺�Ϊ��ʦ
		{
			test = yes_admin;
			break;
		}
	}
	return test;
}
//������ƺ���
int input(char str[],int len,int test,int x,int y)
{
	char str1[11] = {0};
	char ch = 0;
	int i = 0,p=0;
	fflush(stdin);
	while (1)
	{
		ch = getch();
		if (ch == '\r')//���»س��ķ�Ӧ
		{
			if (i == 0)//����˺Ż������������Ƿ�Ϊ��
			{
				gotoxy(50, 19);
				printf("���벻��Ϊ��");
				getch();
				gotoxy(x, y);
			}
			else if (test == 0&&i<len)
			{
				continue;
			}
			else if (test == 1 && i < len)
			{
				continue;
			}
			else if (test == 2 && i < len)
			{
				continue;
			}
			else
			{
				break;
			}
		}
		else if (ch == '\b')//�����˸���ķ�Ӧ
		{
			if (i >0)
			{
				printf("\b \b");
				str[i] = ' ';
				i--;
			}
		}
		else if (ch == 27)//����ESC���˳�
		{
			return err;
		}
		else if (test == 0)//�˺�������
		{
			if (i >= len )
			{
				continue;
			}
			if (ch >= '0' && ch <= '9' || ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z')
			{
				putchar(ch);
				str[i] = ch;
				i++;
			}
		}
		else if (test == 1)//����������
		{
			if (i >= len+4 )
			{
				break;
			}
			if (ch >= '0' && ch <= '9' || ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z')
			{
				putchar('*');
				str[i] = ch;
				i++;
			}
		}
		else if (test == 2)//ȷ������������
		{
			if (i >= len + 4)
			{
				break;
			}
			if (ch >= '0' && ch <= '9' || ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z')
			{
				putchar('*');
				str1[i] = ch;
				i++;
			}
		}
	}
	
	if (test == 2)//ȷ�������������Ƿ���ͬ
	{
		str1[i] = '\0';
		if (strcmp(str, str1) != 0)
		{
			return 3;
		}
	}
}
//ʱ�亯��
void ms()
{
	char buffer[80];
	time_t rawtime;
	struct tm* info;
	time(&rawtime);
	info = localtime(&rawtime);
	strftime(buffer, 80, "%Y-%m-%d", info);
	printf("����:%s\n", buffer);
}
//��궨λ����
void gotoxy(int x, int y)
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord = { x, y };
	SetConsoleCursorPosition(hOut, coord);
}
//��������01
void frame(int c,int k,int x,int y)
{
	int i,j;
	for (i = 0; i < k; i++)
	{
			if (i == 0)//���л���
			{
				gotoxy(x, y);
				for (j = 0; j < c; j++)
				{
					if (j == 0)
					{
						printf("�V ");
					}
					else if (j == c - 1)
					{
						printf("��\n");
					}
					else
					{
						printf("�T ");
					}
				}
			}
			else if (i == k-1)//β�л���
			{
				gotoxy(x, y + k - 1);
				for (j = 0; j < c; j++)
				{
					if (j == 0)
					{
						printf("�\ ");
					}
					else if (j == c - 1)
					{
						printf("�_ \n");
					}
					else
					{
						printf("�T ");
					}
				}
			}
			else
			{
				gotoxy(x, y + i);
				for (j = 0; j < c; j++)
				{
					if (j == 0)
					{
						printf("�U ");
					}
					else if (j == c - 1)
					{
						printf("�U \n");
					}
					else
					{
						printf("  ");
					}
				}
			}
	}
}
//��������02
void frame_a(int x,int y)
{
	int i,j;
	for (i = 1; i <= 9; i++)
	{
		if (i == 1)//���л���
		{
			gotoxy(x, y);
			printf("�� ");
			for (j = 1; j <= 19; j++)
			{
				if (j % 5 == 0)
				{
					printf("��");
				}
				else
				{
					printf("�� ");
				}
			}
			printf("��\n");
		}
		else if (i == 9)//β�л���
		{
			gotoxy(x, y+8);
			printf("�� ");
			for (j = 1; j <= 19; j++)
			{
				if (j % 5 == 0)
				{
					printf("��");
				}
				else
				{
					printf("�� ");
				}
			}
			printf("��\n");
			break;
		}
		if (i % 2 != 0)//������
		{
			gotoxy(x, y + i);
			printf("�� ");
				for (j = 1; j <= 19; j++)
				{
					if (j % 5 == 0)
					{
						printf("��");
					}
					else
					{
						printf("  ");
					}
				}
			printf("��\n");
		}
		else
		{
			gotoxy(x, y + i);
			printf("�� ");
			{
				for (j = 1; j <= 19; j++)
				{
					if (j % 5 == 0)
					{
						printf("��");
					}
					else
					{
						printf("�� ");
					}
				}
			}
			printf("��\n");
		}
	}
}
//�˳�����
void out()
{
	system("cls");
	exit(0);
}
//��¼����
void login()
{
	while (1)
	{
		int i;
		char username_a[20] = { 0 };//�����˺ŵĸ�����
		char userpassword_a[20] = { 0 };//��������ĸ�����
		system("cls");
		frame(20, 20, 35, 2);
		gotoxy(43, 5);
		printf("* ���迼��ϵͳ��¼���� * \n");
		gotoxy(53, 6);
		ms();
		gotoxy(42, 8);
		printf("�û���: ");
		frame(10, 3, 49, 7);
		gotoxy(42, 12);
		printf("���룺 ");
		frame(10, 3, 49, 11);
		gotoxy(42, 15);
		printf("��ʾ�����س���½��֤��ESC����");
		gotoxy(51, 8);
		if (input(username_a, 6, 0,51,8) == err)//ͬʱ���ESC���˳����˺��������
		{
			break;
		}
		gotoxy(51, 12);
		if (input(userpassword_a, 6, 1,51,12) == err)//ͬʱ���ESC���˳��������������
		{
			break;
		}
		if (verify(username_a, userpassword_a) == yes_str)//����˺�Ϊѧ���˺�
		{
			for (i = 0; i < 50; i++)
			{
				if (strcmp(username[i], username_a) == 0)//Ѱ���˺Ŷ�Ӧ�������±�
				{
					break;
				}
			}
			student(i);
		}
		else if (verify(username_a, userpassword_a) == yes_admin)//����˺�Ϊ����Ա�˺�
		{
			for (i = 0; i < 50; i++)
			{
				if (strcmp(username[i], username_a) == 0)//Ѱ���˺Ŷ�Ӧ�������±�
				{
					break;
				}
			}
			administrator(i);
		}
	}
}
//����������
void student(int i)
{
	int sr;
	system("cls");
	frame(24, 28, 30, 1);
	gotoxy(43, 3);
	printf("*���迼��ϵͳ����������*");
	gotoxy(40, 5);
	printf("��ӭ%s,����", username[i]);
	gotoxy(60, 5);
	ms();
	frame(10, 3, 45, 7);
	gotoxy(51, 8);
	printf("1-�޸�����");
	frame(10, 3, 45, 10);
	gotoxy(51, 11);
	printf("2-��    ��");
	frame(10, 3, 45, 13);
	gotoxy(51, 14);
	printf("3-�ɼ���ѯ");
	gotoxy(45, 16);
	printf("��ѡ��:");
	scanf("%d",&sr);
	switch (sr)
	{
	case 1: modify_password(i); break;
	case 2: test(); break;
	case 3: query_result(i); break;
	default:gotoxy(43, 22); printf("������1 2 3�Ա�������������\n"); getch(); break;
	};

}
//����Ա������
void administrator(int i)
{
	int sr;
	system("cls");
	frame(24, 28, 30, 1);
	gotoxy(43, 3);
	printf("*���迼��ϵͳ����Ա������*");
	gotoxy(40, 5);
	printf("��ӭ%s,����Ա", username[i]);
	gotoxy(60, 5);
	ms();
	frame(10, 3, 45, 7);
	gotoxy(51, 8);
	printf("1-�޸�����");
	frame(10, 3, 45, 10);
	gotoxy(51, 11);
	printf("2-�û���ѯ");
	frame(10, 3, 45, 13);
	gotoxy(51, 14);
	printf("3-�ɼ���ѯ");
	frame(10, 3, 45, 16);
	gotoxy(51, 17);
	printf("4-�������*");
	frame(10, 3, 45, 19);
	gotoxy(51, 20);
	printf("5-�������*");
	gotoxy(51, 23);
	printf("������:");
	scanf("%d",&sr);
	switch (sr)
	{
	case 1: modify_password(i); break;
	case 2: nser_mana(i) ; break;
	case 3: query_result(i); break;
	case 4: mana_t(); break;
	case 5: mana_j(); break;
	default:gotoxy(43, 22); printf("������1 2 3�Ա�������������\n"); getch(); break;
	};
}
//ע�����
void regis()
{
	while (1)
	{
		char username_a[20] = { 0 };
		char userpassword_a[20] = { 0 };
		int  user_a[1] = { 0 };
		int moba = 0;
		system("cls");
		frame(20, 23, 35, 2);
		gotoxy(43, 5);
		printf("* ���迼��ϵͳע����� * \n");
		gotoxy(53, 6);
		ms();
		gotoxy(42, 8);
		printf("�û���: ");
		frame(10, 3, 51, 7);
		gotoxy(42, 11);
		printf("���룺 ");
		frame(10, 3, 51, 10);
		gotoxy(41, 14);
		printf("ȷ�����룺 ");
		frame(10, 3, 51, 13);
		gotoxy(42, 17);
		printf("��ɫ�� ");
		frame(10, 3, 51, 16);
		gotoxy(42, 20);
		printf("��ʾ�����س���½��֤��ESC����");
		gotoxy(48, 21);
		printf("1Ϊѧ���� 2Ϊ����Ա��");
		gotoxy(53, 8);
		if (input(username_a, 6, 0,53,8) == err)//ͬʱ��ⰴESC���˳����˺ŵļ��������
		{
			break;
		}
		gotoxy(53, 11);
		if (input(userpassword_a, 6, 1,53,11) == err)//ͬʱ��ⰴESC���˳�������ļ��������
		{
			break;
		}
		gotoxy(53, 14);
		moba = input(userpassword_a, 6, 2,53,14);//��ȷʵ���������ͻ��Բ��ҽ�������ֵ����������
		 if (moba == 3)//ȷ��������ԭ���벻����
		{
			
			gotoxy(42, 22);
			printf("ȷ��������ԭ���벻������������");
			getch();
			continue;
		}
		 else if (moba == err)//��ȷ�����봦������ESC��
		 {
			 break;
		 }
		gotoxy(53, 17);
		if (input(user_a, 1, 0,53,17) == err)//���û���ݴ������벢����Ƿ���ESC��
		{
			break;
		}
		if (entering(username_a, userpassword_a, user_a) == 0)//����Ƿ��˺��Ѵ���
		{
			gotoxy(53, 22);
			printf("�˺��Ѵ�������������");
			getch();
		}
		else
		{
			gotoxy(53, 22);
			printf("ע��ɹ�");
			getch();
			login();
		}
	}
}
//��ʼ����
void begin()
{
	while (1)
	{
		int i = 0;
		system("cls");
		frame(20, 20, 35, 2);
		gotoxy(47, 5);
		printf("* ���迼��ϵͳ * \n");
		gotoxy(58, 6);
		ms();
		frame(8, 3, 47, 7);
		gotoxy(50, 8);
		printf(" 1-��  ¼ ");
		frame(8, 3, 47, 10);
		gotoxy(50, 11);
		printf(" 2-ע  �� ");
		frame(8, 3, 47, 13);
		gotoxy(50, 14);
		printf(" 3-��  �� ");
		gotoxy(47, 18);
		printf("��ѡ��:");
		gotoxy(55, 18);
		scanf("%d", &i);
		switch (i)
		{
		case 1:login(); break;//��¼����
		case 2:regis(); break;//ע�����
		case 3:out(); break;//�˳�
		default:gotoxy(43, 22); printf("������1 2 3�Ա�������������\n");getch(); break;
		};
	}
}
//�޸�����
void modify_password(int id)
{
	while (1)
	{
		char userpassword_a[20] = { 0 };
		int i = 0, j = 0;
		system("cls");
		frame(20, 23, 35, 2);
		gotoxy(40, 5);
		printf("* ���迼��ϵͳ�޸�������� * \n");
		gotoxy(53, 6);
		ms();
		gotoxy(42, 8);
		printf("������: ");
		frame(10, 3, 51, 7);
		gotoxy(42, 11);
		printf("������: ");
		frame(10, 3, 51, 10);
		gotoxy(39, 14);
		printf("ȷ�������룺 ");
		frame(10, 3, 51, 13);
		gotoxy(42, 20);
		printf("��ʾ�����س���½��֤��ESC����");
		gotoxy(53, 8);
		input(userpassword_a, 6, 1,53,8);//�������������ȥ��������
		for (i = 0; i < 90; i++)
		{
			if (strcmp(userpassword[i], userpassword_a) == 0 &&strcmp(username[i],username[id])==0)//Ѱ�ҵ��˺Ŷ�Ӧ�����������±�
			{
				j = 1;
				break;
			}
		}
		if (j == 0)//����Ƿ�������������
		{
			gotoxy(53, 19);
			printf("���������");
			getch();
		}
		else
		{
			gotoxy(53, 11);
			input(userpassword_a, 6, 1,53,11);//�������������ȥ��������
			if (strcmp(userpassword_a, userpassword[i]) == 0)//�Ƚ��¾������Ƿ����
			{
				gotoxy(48, 17);
				printf("������������벻����ͬ");
				getch();
				continue;
			}
			gotoxy(53, 14);
			if (input(userpassword_a, 6, 2,53,14) == 3)//��ȷ�����������ȥ��������������������
			{
				gotoxy(48, 17);
				printf("��������ȷ�����벻����");
				getch();
			}
			else
			{
				entering_password(username[i],userpassword_a,user[i]);
				gotoxy(50, 17);
				printf("�����޸ĳɹ�");
				getch();
				break;
			}
		}
	}
}
//���Խ���
void test()
{

}
//�ɼ���ѯ
void query_result(int id)
{
	frame(40, 20, 20, 2);
	gotoxy(40, 5);
	printf("*���迼��ϵͳ�����ɼ���ѯ����*");
	gotoxy(35, 6);
	printf("��ӭ%s,", username[id]);
	if (user[id][0] == '1')
	{
		printf("����");
	}
	else if (user[id][0] == '2')
	{
		printf("����Ա");
	}


}
//�������
void mana_t()
{

}
//�������
void mana_j()
{

}
//�û���ѯ
void nser_mana(int id)
{
	int sr;
	system("cls");
	frame(24, 28, 30, 1);
	gotoxy(43, 3);
	printf("*���迼��ϵͳ������ѯ����*");
	gotoxy(40, 5);
	printf("��ӭ%s,����", username[id]);
	gotoxy(60, 5);
	ms();
	frame(10, 3, 45, 7);
	gotoxy(50, 8);
	printf("1-ȫ����ѯ");
	frame(10, 3, 45, 10);
	gotoxy(50, 11);
	printf("2-������ѯ");
	frame(10, 3, 45, 13);
	gotoxy(50, 14);
	printf("3-��    ��");
	gotoxy(45, 16);
	printf("��ѡ��:");
	scanf("%d", &sr);
	switch (sr)
	{
	case 1: query_all(id); break;
	case 2: query_condition(id); break;
	case 3: administrator(id); break;
	};
}
//������
int main()
{
	begin();
	return 0;
}