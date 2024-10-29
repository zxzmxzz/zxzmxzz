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
//函数定义块
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
//函数定义块div
char username[90][20];//账号用户名存储地
char userpassword[90][20];//账号密码存储地
char user[90][1];//账号身份存储地
int user_id=1;//身份键值
//条件查询
void query_condition(int id)
{
	int i = 1, g = 1, dy = 1, zs = 0, l=0,po=0;
	for (l = 0; l < 90; l++)
	{
		if (user[l][0] == '1')
		{
			zs++;
		}
	}//总共有多少学生
	while (1)
	{
		int j = 1, p = 1,test=0;
		char ch = 0, ch1 = 0, ch2[4] = {0};
		fflush(stdin);
		system("cls");
		frame(35, 24, 25, 1);
		gotoxy(45, 3);
		printf("*子翔考试系统考生全部查询界面*");
		gotoxy(42, 4);
		printf("欢迎%s,", username[id]);
		if (user[id][0] == '1')
		{
			printf("考生");
		}
		else if (user[id][0] == '2')
		{
			printf("管理员");
		}
		gotoxy(60, 4);
		ms();
		gotoxy(42,6);
		printf("查看考生ID");
		frame(12, 3, 50, 5);
		frame_a(40, 9);
		gotoxy(45, 10);
		printf("ID");
		gotoxy(53, 10);
		printf("姓名");
		gotoxy(62, 10);
		printf("密码");
		gotoxy(73, 10);
		printf("状态");
		gotoxy(41, 18);
		printf("<-  ->左右键翻页");
		gotoxy(60, 18);
		printf("%d",dy);
		gotoxy(61, 18);
		printf("/");
		gotoxy(62, 18);
		printf("%d", (zs - 1) / 3 + 1);
		gotoxy(55, 19);
		printf("双击回车键进行搜索");
		for (j = 0; j <= 2; j++)//显示当前框该显示的学生
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
				j--;//改行框不显示等到下一个为考生的账号输入
			}
			g++;
		}
		if (ch = getch())
		{
			if (ch == 27)//按下ESC键退出
			{
				nser_mana(id);
			}
			ch1 = getch();
			if (ch1 == 75)//按下左键的反馈
			{
				if (dy == 1)//当前页为第一页时
				{
					gotoxy(65, 18);
					printf("已经是第一页");
					g = 1;
					i = 1;
					Sleep(500);
					continue;
				}
				else//当前页为其他页时
				{
					dy--;//将当前页数回退一页
					i = dy + (dy - 1) * 2;//当前页数第一个ID数据
					j = 1;
					p = 1;
					printf("%d", i);
					while (1)
					{
						if (j == i)//找到ID所对应的考生
						{
							break;
						}
						if (user[p][0] == '1')//寻找是否为考生
						{
							j++;
						}
						p++;
					}
					g = j;
				}
			}
			else if (ch1 == 77)//按下右键的反馈
			{
				if (dy == (zs - 1) / 3 + 1)
				{
					gotoxy(65, 18);
					printf("已经是最后一页");
					i = 1 + (3 * (dy - 1));
					g = 1 + (3 * (dy - 1));
					Sleep(500);
					continue;
				}
				else
				{
					dy++;//页数往后加一页
				}
			}
			else//条件框输入
			{		
				gotoxy(52, 6);
				scanf("%s", &ch2);
				for (j = 0; j < 90; j++)
				{
					if (user[p][0] == '1')
					{
						p++;//学生总数
					}
				}
				for (j = 1; j <= 3; j++)
				{
					test = test + (ch2[j] - 48) * pow(10, 3 - j);//求出输入条件为第几个考生
				}
				if (test >= 1 && test <= p - 1)//检测输入是否在列表范围之内
				{
					po = ((test - 1) / 3 + 1);//求出输入项的对应页面
					i = po + (po - 1) * 2;//对应页面的第一个数值
					j = 1;
					p = 1;
					while (1)
					{
						if (j == i)//找出id对应的学生
						{
							break;
						}
						if (user[p][0] == '1')//寻找是否为考生
						{
							j++;
						}
						p++;
					}
					g = j;
					dy = po;
				}
				else//输入错误
				{
					gotoxy(67, 18);
					printf("无该考生信息");
					g = 1;
					i = 1;
					Sleep(500);
					continue;
				}
			}
		}
	}
}
//全部查询
void query_all(int id)
{
	int i = 1,g=1,dy=1,zs=0,l;
	for (l = 0; l < 90; l++)
	{
		if (user[l][0] == '1')
		{
			zs++;
		}
	}//总共有多少学生
	while (1)
	{
		int j = 1, p = 1;
		char ch = 0, ch1 = 0;
		fflush(stdin);
		system("cls");
		frame(35, 24, 25, 1);
		gotoxy(45, 3);
		printf("*子翔考试系统考生全部查询界面*");
		gotoxy(42, 4);
		printf("欢迎%s,", username[id]);
		if (user[id][0] == '1')
		{
			printf("考生");
		}
		else if (user[id][0] == '2')
		{
			printf("管理员");
		}
		gotoxy(60, 4);
		ms();//显示时间
		frame_a(40, 6);
		gotoxy(45, 7);
		printf("ID");
		gotoxy(53, 7);
		printf("姓名");
		gotoxy(62, 7);
		printf("密码");
		gotoxy(73, 7);
		printf("状态");
		gotoxy(41, 16);
		printf("<-  ->左右键翻页");
		gotoxy(60, 16);
		printf("%d", dy);
		gotoxy(61, 16);
		printf("/");
		gotoxy(62, 16);
		printf("%d",(zs-1)/3+1);
		for (j = 0; j <= 2; j++)//显示当前框该显示的学生
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
				j--;//改行框不显示等到下一个为考生的账号输入
			}
			g++;
			
		}
		if (ch = getch())
		{
			if (ch == 27)//按下ESC键退出
			{
				nser_mana(id);
			}
			ch1 = getch();
			if (ch1 == 75)//按下左键的反馈
			{
				if (dy == 1)//当前页为第一页时
				{
					gotoxy(65, 16);
					printf("已经是第一页");
					g = 1;
					i = 1;
					Sleep(500);
					continue;
				}
				else//当前页为其他页时
				{
					dy--;//将当前页数回退一页
					i = dy+(dy-1)*2;//当前页数第一个ID数据
					j = 1;
					p = 1;
					while (1)
					{
						if (j == i)//找到ID所对应的考生
						{
							break;
						}
						if (user[p][0] == '1')//寻找是否为考生
						{
							j++;
						}
						p++;
					}
					g = j;
				}
			}
			else if (ch1 == 77)//按下右键的反馈
			{
				if (dy == (zs-1)/3+1)//当前页为最后一页时
				{
					gotoxy(65, 16);
					printf("已经是最后一页");
					i = 1 + (3 * (dy - 1));
					g = 1 + (3 * (dy - 1));
					Sleep(500);
					continue;
				}
				else
				{
					dy++;//页数往后加一页
				}
			}
			else//输入其他键时
			{
				gotoxy(65, 16);
				printf("输入错误请重新输入");
				Sleep(500);
				i = 1 + (3 * (dy - 1));
				g = 1 + (3 * (dy - 1));
				continue;
			}
		}
	}

}
//修改密码录入界面
int entering_password(char name[], char password[], char id[])
{
	int i = 0;
	for (i = 0; i < 90; i++)
	{
		if (strcmp(username[i], name) == 0)//寻找账号对应的数组下标
		{
			break;
		}
	}
	strcpy(username[i], name);
	strcpy(userpassword[i], password);
	strcpy(user[i], id);
}
//注册录入信息界面
int entering(char name[],char password[],char id[])
{
	int i=0,l=1;
	for (i = 0; i < 90; i++)
	{
		if (strcmp(username[i], name) == 0)//检测账号是否已存在
		{
			l = 0;
			break;
		}
	}
	if (l == 1)//账号不存在数据导入
	{
		strcpy(username[user_id], name);
		strcpy(userpassword[user_id], password);
		strcpy(user[user_id], id);
		user_id++;
	}
	return l;
}
//登录验证界面
int verify(char name[],char password[])
{
	int i=0, j=0,test=no;
	for (i = 0; i < 90; i++)
	{
		if (strcmp(username[i], name) == 0 && strcmp(userpassword[i], password) == 0&&user[i][0]=='1')//账号为学生
		{
			test = yes_str;
			break;
		}
		else if (strcmp(username[i], name) == 0 && strcmp(userpassword[i], password) == 0 && user[i][0] == '2')//账号为老师
		{
			test = yes_admin;
			break;
		}
	}
	return test;
}
//输入控制函数
int input(char str[],int len,int test,int x,int y)
{
	char str1[11] = {0};
	char ch = 0;
	int i = 0,p=0;
	fflush(stdin);
	while (1)
	{
		ch = getch();
		if (ch == '\r')//按下回车的反应
		{
			if (i == 0)//检测账号或者密码数组是否为空
			{
				gotoxy(50, 19);
				printf("输入不能为空");
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
		else if (ch == '\b')//按下退格键的反应
		{
			if (i >0)
			{
				printf("\b \b");
				str[i] = ' ';
				i--;
			}
		}
		else if (ch == 27)//按下ESC键退出
		{
			return err;
		}
		else if (test == 0)//账号输入检测
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
		else if (test == 1)//密码输入检测
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
		else if (test == 2)//确认密码输入检测
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
	
	if (test == 2)//确认密码与密码是否相同
	{
		str1[i] = '\0';
		if (strcmp(str, str1) != 0)
		{
			return 3;
		}
	}
}
//时间函数
void ms()
{
	char buffer[80];
	time_t rawtime;
	struct tm* info;
	time(&rawtime);
	info = localtime(&rawtime);
	strftime(buffer, 80, "%Y-%m-%d", info);
	printf("日期:%s\n", buffer);
}
//光标定位函数
void gotoxy(int x, int y)
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord = { x, y };
	SetConsoleCursorPosition(hOut, coord);
}
//画框函数—01
void frame(int c,int k,int x,int y)
{
	int i,j;
	for (i = 0; i < k; i++)
	{
			if (i == 0)//首行画框
			{
				gotoxy(x, y);
				for (j = 0; j < c; j++)
				{
					if (j == 0)
					{
						printf("╒ ");
					}
					else if (j == c - 1)
					{
						printf("┐\n");
					}
					else
					{
						printf("═ ");
					}
				}
			}
			else if (i == k-1)//尾行画框
			{
				gotoxy(x, y + k - 1);
				for (j = 0; j < c; j++)
				{
					if (j == 0)
					{
						printf("╘ ");
					}
					else if (j == c - 1)
					{
						printf("╛ \n");
					}
					else
					{
						printf("═ ");
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
						printf("║ ");
					}
					else if (j == c - 1)
					{
						printf("║ \n");
					}
					else
					{
						printf("  ");
					}
				}
			}
	}
}
//画框函数—02
void frame_a(int x,int y)
{
	int i,j;
	for (i = 1; i <= 9; i++)
	{
		if (i == 1)//首行画框
		{
			gotoxy(x, y);
			printf("┌ ");
			for (j = 1; j <= 19; j++)
			{
				if (j % 5 == 0)
				{
					printf("┬");
				}
				else
				{
					printf("─ ");
				}
			}
			printf("┐\n");
		}
		else if (i == 9)//尾行画框
		{
			gotoxy(x, y+8);
			printf("└ ");
			for (j = 1; j <= 19; j++)
			{
				if (j % 5 == 0)
				{
					printf("┴");
				}
				else
				{
					printf("─ ");
				}
			}
			printf("┘\n");
			break;
		}
		if (i % 2 != 0)//其余行
		{
			gotoxy(x, y + i);
			printf("│ ");
				for (j = 1; j <= 19; j++)
				{
					if (j % 5 == 0)
					{
						printf("│");
					}
					else
					{
						printf("  ");
					}
				}
			printf("│\n");
		}
		else
		{
			gotoxy(x, y + i);
			printf("├ ");
			{
				for (j = 1; j <= 19; j++)
				{
					if (j % 5 == 0)
					{
						printf("┼");
					}
					else
					{
						printf("─ ");
					}
				}
			}
			printf("┤\n");
		}
	}
}
//退出函数
void out()
{
	system("cls");
	exit(0);
}
//登录界面
void login()
{
	while (1)
	{
		int i;
		char username_a[20] = { 0 };//输入账号的副数组
		char userpassword_a[20] = { 0 };//输入密码的副数组
		system("cls");
		frame(20, 20, 35, 2);
		gotoxy(43, 5);
		printf("* 子翔考试系统登录界面 * \n");
		gotoxy(53, 6);
		ms();
		gotoxy(42, 8);
		printf("用户名: ");
		frame(10, 3, 49, 7);
		gotoxy(42, 12);
		printf("密码： ");
		frame(10, 3, 49, 11);
		gotoxy(42, 15);
		printf("提示：按回车登陆验证，ESC返回");
		gotoxy(51, 8);
		if (input(username_a, 6, 0,51,8) == err)//同时检测ESC键退出与账号输入回显
		{
			break;
		}
		gotoxy(51, 12);
		if (input(userpassword_a, 6, 1,51,12) == err)//同时检测ESC键退出与密码输入回显
		{
			break;
		}
		if (verify(username_a, userpassword_a) == yes_str)//检测账号为学生账号
		{
			for (i = 0; i < 50; i++)
			{
				if (strcmp(username[i], username_a) == 0)//寻找账号对应的数组下标
				{
					break;
				}
			}
			student(i);
		}
		else if (verify(username_a, userpassword_a) == yes_admin)//检测账号为管理员账号
		{
			for (i = 0; i < 50; i++)
			{
				if (strcmp(username[i], username_a) == 0)//寻找账号对应的数组下标
				{
					break;
				}
			}
			administrator(i);
		}
	}
}
//考生主界面
void student(int i)
{
	int sr;
	system("cls");
	frame(24, 28, 30, 1);
	gotoxy(43, 3);
	printf("*子翔考试系统考生主界面*");
	gotoxy(40, 5);
	printf("欢迎%s,考生", username[i]);
	gotoxy(60, 5);
	ms();
	frame(10, 3, 45, 7);
	gotoxy(51, 8);
	printf("1-修改密码");
	frame(10, 3, 45, 10);
	gotoxy(51, 11);
	printf("2-考    试");
	frame(10, 3, 45, 13);
	gotoxy(51, 14);
	printf("3-成绩查询");
	gotoxy(45, 16);
	printf("请选择:");
	scanf("%d",&sr);
	switch (sr)
	{
	case 1: modify_password(i); break;
	case 2: test(); break;
	case 3: query_result(i); break;
	default:gotoxy(43, 22); printf("请输入1 2 3以保程序正常运行\n"); getch(); break;
	};

}
//管理员主界面
void administrator(int i)
{
	int sr;
	system("cls");
	frame(24, 28, 30, 1);
	gotoxy(43, 3);
	printf("*子翔考试系统管理员主界面*");
	gotoxy(40, 5);
	printf("欢迎%s,管理员", username[i]);
	gotoxy(60, 5);
	ms();
	frame(10, 3, 45, 7);
	gotoxy(51, 8);
	printf("1-修改密码");
	frame(10, 3, 45, 10);
	gotoxy(51, 11);
	printf("2-用户查询");
	frame(10, 3, 45, 13);
	gotoxy(51, 14);
	printf("3-成绩查询");
	frame(10, 3, 45, 16);
	gotoxy(51, 17);
	printf("4-考题管理*");
	frame(10, 3, 45, 19);
	gotoxy(51, 20);
	printf("5-考卷管理*");
	gotoxy(51, 23);
	printf("请输入:");
	scanf("%d",&sr);
	switch (sr)
	{
	case 1: modify_password(i); break;
	case 2: nser_mana(i) ; break;
	case 3: query_result(i); break;
	case 4: mana_t(); break;
	case 5: mana_j(); break;
	default:gotoxy(43, 22); printf("请输入1 2 3以保程序正常运行\n"); getch(); break;
	};
}
//注册界面
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
		printf("* 子翔考试系统注册界面 * \n");
		gotoxy(53, 6);
		ms();
		gotoxy(42, 8);
		printf("用户名: ");
		frame(10, 3, 51, 7);
		gotoxy(42, 11);
		printf("密码： ");
		frame(10, 3, 51, 10);
		gotoxy(41, 14);
		printf("确认密码： ");
		frame(10, 3, 51, 13);
		gotoxy(42, 17);
		printf("角色： ");
		frame(10, 3, 51, 16);
		gotoxy(42, 20);
		printf("提示：按回车登陆验证，ESC返回");
		gotoxy(48, 21);
		printf("1为学生端 2为管理员端");
		gotoxy(53, 8);
		if (input(username_a, 6, 0,53,8) == err)//同时检测按ESC键退出和账号的检测与输入
		{
			break;
		}
		gotoxy(53, 11);
		if (input(userpassword_a, 6, 1,53,11) == err)//同时检测按ESC键退出和密码的检测与输入
		{
			break;
		}
		gotoxy(53, 14);
		moba = input(userpassword_a, 6, 2,53,14);//将确实密码的输入和回显并且将所返回值赋给检测变量
		 if (moba == 3)//确认密码与原密码不符合
		{
			
			gotoxy(42, 22);
			printf("确认密码与原密码不符请重新输入");
			getch();
			continue;
		}
		 else if (moba == err)//在确认密码处按下了ESC键
		 {
			 break;
		 }
		gotoxy(53, 17);
		if (input(user_a, 1, 0,53,17) == err)//将用户身份代码输入并检测是否按了ESC键
		{
			break;
		}
		if (entering(username_a, userpassword_a, user_a) == 0)//检测是否账号已存在
		{
			gotoxy(53, 22);
			printf("账号已存在请重新输入");
			getch();
		}
		else
		{
			gotoxy(53, 22);
			printf("注册成功");
			getch();
			login();
		}
	}
}
//开始界面
void begin()
{
	while (1)
	{
		int i = 0;
		system("cls");
		frame(20, 20, 35, 2);
		gotoxy(47, 5);
		printf("* 子翔考试系统 * \n");
		gotoxy(58, 6);
		ms();
		frame(8, 3, 47, 7);
		gotoxy(50, 8);
		printf(" 1-登  录 ");
		frame(8, 3, 47, 10);
		gotoxy(50, 11);
		printf(" 2-注  册 ");
		frame(8, 3, 47, 13);
		gotoxy(50, 14);
		printf(" 3-退  出 ");
		gotoxy(47, 18);
		printf("请选择:");
		gotoxy(55, 18);
		scanf("%d", &i);
		switch (i)
		{
		case 1:login(); break;//登录界面
		case 2:regis(); break;//注册界面
		case 3:out(); break;//退出
		default:gotoxy(43, 22); printf("请输入1 2 3以保程序正常运行\n");getch(); break;
		};
	}
}
//修改密码
void modify_password(int id)
{
	while (1)
	{
		char userpassword_a[20] = { 0 };
		int i = 0, j = 0;
		system("cls");
		frame(20, 23, 35, 2);
		gotoxy(40, 5);
		printf("* 子翔考试系统修改密码界面 * \n");
		gotoxy(53, 6);
		ms();
		gotoxy(42, 8);
		printf("旧密码: ");
		frame(10, 3, 51, 7);
		gotoxy(42, 11);
		printf("新密码: ");
		frame(10, 3, 51, 10);
		gotoxy(39, 14);
		printf("确认新密码： ");
		frame(10, 3, 51, 13);
		gotoxy(42, 20);
		printf("提示：按回车登陆验证，ESC返回");
		gotoxy(53, 8);
		input(userpassword_a, 6, 1,53,8);//将旧密码输入进去并带回显
		for (i = 0; i < 90; i++)
		{
			if (strcmp(userpassword[i], userpassword_a) == 0 &&strcmp(username[i],username[id])==0)//寻找到账号对应的密码数组下标
			{
				j = 1;
				break;
			}
		}
		if (j == 0)//检测是否旧密码输入错误
		{
			gotoxy(53, 19);
			printf("旧密码错误");
			getch();
		}
		else
		{
			gotoxy(53, 11);
			input(userpassword_a, 6, 1,53,11);//将新密码输入进去并带回显
			if (strcmp(userpassword_a, userpassword[i]) == 0)//比较新旧密码是否相等
			{
				gotoxy(48, 17);
				printf("新密码与旧密码不能相同");
				getch();
				continue;
			}
			gotoxy(53, 14);
			if (input(userpassword_a, 6, 2,53,14) == 3)//将确认密码输入进去并检测与新密码符不符合
			{
				gotoxy(48, 17);
				printf("新密码与确认密码不符合");
				getch();
			}
			else
			{
				entering_password(username[i],userpassword_a,user[i]);
				gotoxy(50, 17);
				printf("密码修改成功");
				getch();
				break;
			}
		}
	}
}
//考试界面
void test()
{

}
//成绩查询
void query_result(int id)
{
	frame(40, 20, 20, 2);
	gotoxy(40, 5);
	printf("*子翔考试系统考生成绩查询界面*");
	gotoxy(35, 6);
	printf("欢迎%s,", username[id]);
	if (user[id][0] == '1')
	{
		printf("考生");
	}
	else if (user[id][0] == '2')
	{
		printf("管理员");
	}


}
//考题管理
void mana_t()
{

}
//考卷管理
void mana_j()
{

}
//用户查询
void nser_mana(int id)
{
	int sr;
	system("cls");
	frame(24, 28, 30, 1);
	gotoxy(43, 3);
	printf("*子翔考试系统考生查询界面*");
	gotoxy(40, 5);
	printf("欢迎%s,考生", username[id]);
	gotoxy(60, 5);
	ms();
	frame(10, 3, 45, 7);
	gotoxy(50, 8);
	printf("1-全部查询");
	frame(10, 3, 45, 10);
	gotoxy(50, 11);
	printf("2-条件查询");
	frame(10, 3, 45, 13);
	gotoxy(50, 14);
	printf("3-返    回");
	gotoxy(45, 16);
	printf("请选择:");
	scanf("%d", &sr);
	switch (sr)
	{
	case 1: query_all(id); break;
	case 2: query_condition(id); break;
	case 3: administrator(id); break;
	};
}
//主函数
int main()
{
	begin();
	return 0;
}