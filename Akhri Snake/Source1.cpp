//#include<iostream>
//#include<iomanip>
//#include<conio.h>
//#include<windows.h>
//using namespace std;
//void SetClr2(int tcl, int bcl)
//{
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (tcl + (bcl * 16)));
//}
//void SetClr(int clr)
//{
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), clr);
//}
//void gotoRowCol(int rpos, int cpos)
//{
//	COORD scrn;
//	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
//	scrn.X = cpos;
//	scrn.Y = rpos;
//	SetConsoleCursorPosition(hOuput, scrn);
//}
//int main3()
//{
//
//	
//	char ch;
//	while (true)
//	{
//
//		if (_kbhit())
//		{
//
//			ch = _getch();
//			{
//				cout << ch << "  Asci  " << int(ch)<<endl;
//			}
//
//
//
//		}
//
//	}
//	return 0;
//}
//void rect(int r, int c, char sym, int rpos, int cpos)
//{
//
//	for (int i = 0; i < r; i++)
//	{
//
//		for (int j = 0; j < c; j++)
//		{
//
//			if (j >= 0 && j < 1)
//			{
//				SetClr(0);
//
//			}
//
//			else if (i % 2 == 0)
//			{
//				if (j % 2 == 0)
//					SetClr(2);
//
//				else SetClr(0);
//			}
//			else
//			{
//				if (j % 2 == 0)
//					SetClr(0);
//
//				else SetClr(2);
//			}
//			if (i == 0 || i == r - 1)
//				(SetClr(2));
//			gotoRowCol(i + rpos, cpos + j);
//
//			cout << char(sym);
//
//		}
//	}
//}
//void rect2(int r, int c, char sym, int rpos, int cpos)
//{
//
//	for (int i = r-1; i >=0; i--)
//	{
//
//		for (int j = c-1; j >=0; j--)
//		{
//
//			if (j ==c-1  && j > c-2)
//			{
//				SetClr(8);
//
//			}
//
//			else if (i % 2 == 0)
//			{
//				if (j % 2 == 0)
//					SetClr(9);
//
//				else SetClr(0);
//			}
//			else
//			{
//				if (j % 2 == 0)
//					SetClr(0);
//
//				else SetClr(9);
//			}
//			if (i == 0 || i == r - 1)
//				(SetClr(9));
//			gotoRowCol( rpos+i, cpos-j);
//
//			cout << char(sym);
//
//		}
//	}
//}
//void rectErA(int r, int c, char sym, int rpos, int cpos)
//{
//
//	for (int i = 0; i < r; i++)
//	{
//
//		for (int j = 0; j < c; j++)
//		{
//
//			gotoRowCol(i + rpos, cpos + j);
//
//			cout << " ";
//
//		}
//	}
//}
//void rectErulta(int r, int c, char sym, int rpos, int cpos)
//{
//
//	for (int i = 0; i<=r; i++)
//	{
//
//		for (int j = 0; j <=c; j++)
//		{
//
//			gotoRowCol(i + rpos, cpos - j);
//
//			cout << " ";
//
//		}
//	}
//}
//void Bx(int rpos, int cpos)
//{
//
//	int r = 10, c = 5;
//
//	for (int i = 0; i < r; i++)
//	{
//		for (int j = 0; j < c; j++)
//		{
//			if ((i == 0 && j == c - 1) || (i == r - 1 && j == c - 1))
//				;
//			
//			else if ((i == 3 && j == 3) || (i == 6 && j == 3))
//			{
//
//				gotoRowCol(rpos + i, cpos + j);
//				SetClr(15);
//				cout << char(-37);
//			}
//			
//			else
//			{
//				gotoRowCol(rpos + i, cpos + j);
//				SetClr(2);
//				cout << char(-37);
//			}
//
//
//
//		}
//	}
//
//}
//void Bx2(int rpos, int cpos)
//{
//
//	int r = 10, c = 5;
//
//	for (int i = 0; i < r; i++)
//	{
//		for (int j = 0; j < c; j++)
//		{
//			if ((i == 0 && j == 0) || (i == r - 1 && j == 0))
//				;
//			else if ((i == 3 && j == 2) || (i == 6 && j == 2))
//			{
//
//				gotoRowCol(rpos + i, cpos + j);
//				SetClr(15);
//				cout << char(-37);
//			}
//
//			
//			else
//			{
//				gotoRowCol(rpos + i, cpos + j);
//				SetClr(9);
//				cout << char(-37);
//			}
//
//		}
//	}
//
//}
//void Zuban(int rpos, int cpos)
//{
//
//	for (int i = 0; i < 6; i++)
//	{
//		for (int j = 0; j < 6; j++)
//		{
//
//			gotoRowCol(rpos + 2 + i, cpos + 2 + i);
//			SetClr(4);
//			cout << char(-37);
//		}
//
//
//	}
//
//	for (int i = 0; i < 6; i++)
//	{
//		for (int j = 0; j < 6; j++)
//		{
//
//			gotoRowCol(rpos + 7 - i, cpos + 2 + i);
//			SetClr(4);
//			cout << char(-37);
//		}
//
//
//	}
//
//}
//
//
//void S(int rpos,int cpos,int s)
//{
//
//	for (int i = 0; i <= s; i++)
//	{
//		SetClr(2);
//		gotoRowCol(rpos, cpos+i);
//		cout << char(-37);
//	}
//	for (int i = 0; i < s; i++)
//	{
//		SetClr(2);
//		gotoRowCol(rpos+i, cpos);
//	
//		cout << char(-37);
//	}
//	for (int i = 0; i < s; i++)
//	{
//		SetClr(2);
//		gotoRowCol(rpos+s, cpos+i);
//		cout << char(-37);
//	}
//	for (int i = 0; i <= s; i++)
//	{
//		SetClr(2);
//		gotoRowCol(rpos + s + i, cpos + s);
//		cout << char(-37);
//	}
//	for (int i = 0; i <= s; i++)
//	{
//		SetClr(2);
//		gotoRowCol(rpos+s+s+1, cpos+s-i);
//		cout << char(-37);
//	}
//
//
//}
//void N(int rpos, int cpos, int s)
//{
//
//	for (int i = 0; i <= s*2; i++)
//	{
//		SetClr(8);
//		gotoRowCol(rpos+i, cpos );
//		cout << char(-37);
//	}
//	for (int i = 0; i < s; i++)
//	{
//		SetClr(8);
//		gotoRowCol(rpos + i, cpos+i);
//
//		cout << char(-37);
//	}
//
//
//	for (int i = 0; i < s * 2; i++)
//	{
//		SetClr(8);
//		gotoRowCol(rpos + i, cpos+s);
//		cout << char(-37);
//	}
//
//}
//void A(int rpos, int cpos, int s,int clr)
//{
//	
//	for (int i = 0; i < s; i++)
//	{
//		SetClr(clr);
//		gotoRowCol(rpos, cpos + i);
//		cout << char(-37);
//	}
//	for (int i = 0; i < s*2; i++)
//	{
//		SetClr(clr);
//		gotoRowCol(rpos + i, cpos);
//
//		cout << char(-37);
//	}
//	for (int i = 0; i < s*2; i++)
//	{
//		SetClr(clr);
//		gotoRowCol(rpos+i, cpos +s);
//		cout << char(-37);
//	}
//	for (int i = 0; i < s; i++)
//	{
//		SetClr(clr);
//		gotoRowCol(rpos + (s / 2+2) , cpos +i);
//		cout << char(-37);
//	}
//	
//
//}
//void A2(int rpos, int cpos, int s, int clr)
//{
//	for (int i = 0; i < s; i++)
//	{
//		SetClr(clr);
//		gotoRowCol(rpos, cpos + i);
//		cout << char(-37);
//	}
//	for (int i = 0; i <= s * 2; i++)
//	{
//		SetClr(clr);
//		gotoRowCol(rpos + i, cpos);
//
//		cout << char(-37);
//	}
//	for (int i = 0; i <= s * 2; i++)
//	{
//		SetClr(clr);
//		gotoRowCol(rpos + i, cpos + s);
//		cout << char(-37);
//	}
//	for (int i = 0; i < s; i++)
//	{
//		SetClr(clr);
//		gotoRowCol(rpos + (s / 2 + 2), cpos + i);
//		cout << char(-37);
//	}
//
//
//}
//void K(int rpos, int cpos, int s)
//{
//
//	
//	for (int i = 0; i < s * 2; i++)
//	{
//		SetClr(8);
//		gotoRowCol(rpos + i, cpos);
//
//		cout << char(-37);
//	}
//	for (int i = 0; i <= s; i++)
//	{
//		SetClr(8);
//		gotoRowCol(rpos + (s/2+3)-i, cpos+i);
//		cout << char(-37);
//	}
//	for (int i = 0; i <= s; i++)
//	{
//		SetClr(8);
//		gotoRowCol(rpos + (s / 2 + 3) + i, cpos + i);
//		cout << char(-37);
//	}
//
//
//}
//void E(int rpos, int cpos, int s,int clr)
//{
//
//	for (int i = 0; i < s; i++)
//	{
//		SetClr(clr);
//		gotoRowCol(rpos, cpos + i);
//		cout << char(-37);
//	}
//	for (int i = 0; i <= s * 2+1; i++)
//	{
//		SetClr(clr);
//		gotoRowCol(rpos + i, cpos);
//
//		cout << char(-37);
//	}
//	
//	for (int i = 0; i < s; i++)
//	{
//		SetClr(clr);
//		gotoRowCol(rpos + (s / 2 + 3), cpos + i);
//		cout << char(-37);
//	}
//	for (int i = 0; i < s; i++)
//	{
//		SetClr(clr);
//		gotoRowCol(rpos + s*2+1, cpos + i);
//		cout << char(-37);
//	}
//
//}
//
//void B(int rpos, int cpos, int s)
//{
//	int clr = 8;
//	for (int i = 0; i < s; i++)
//	{
//		SetClr(clr);
//		gotoRowCol(rpos, cpos + i);
//		cout << char(-37);
//	}
//	for (int i = 0; i <= s * 2+1 ; i++)
//	{
//		SetClr(8);
//		gotoRowCol(rpos + i, cpos);
//
//		cout << char(-37);
//	}
//
//	for (int i = 0; i <= s; i++)
//	{
//		SetClr(8);
//		gotoRowCol(rpos + (s / 2 + 3), cpos + i);
//		cout << char(-37);
//	}
//	for (int i = 0; i <= s; i++)
//	{
//		SetClr(8);
//		gotoRowCol(rpos + s * 2+1 , cpos + i);
//		cout << char(-37);
//	}
//	for (int i = 0; i < s ; i++)
//	{
//		SetClr(8);
//		gotoRowCol(rpos + i, cpos+s);
//
//		cout << char(-37);
//	}
//	for (int i = 0; i <= s+1 ; i++)
//	{
//		SetClr(8);
//		gotoRowCol(rpos+s + i, cpos+s+1);
//
//		cout << char(-37);
//	}
//
//
//}
//
//void L(int rpos, int cpos, int s)
//{
//	int clr = 2;
//
//	for (int i = 0; i < s * 2; i++)
//	{
//		SetClr(clr);
//		gotoRowCol(rpos + i, cpos);
//
//		cout << char(-37);
//	}
//	for (int i = 0; i <= s; i++)
//	{
//		SetClr(clr);
//		gotoRowCol(rpos + s*2 , cpos + i);
//		cout << char(-37);
//	}
//	
//}
//void T(int rpos, int cpos, int s)
//{
//	int clr = 8;
//
//	for (int i = 0; i < s * 2; i++)
//	{
//		SetClr(clr);
//		gotoRowCol(rpos + i, cpos + (s / 2 ));
//
//		cout << char(-37);
//	}
//	for (int i = 0; i < s; i++)
//	{
//		SetClr(clr);
//		gotoRowCol(rpos , cpos + i);
//		cout << char(-37);
//	}
//
//}
//
//void Sd()
//{
//
//
//	int j = 0;
//	for (int i = 0; i < 160; i += 10)
//	{
//		if (i < 150)
//		{
//			Zuban(25, i + 10);
//		}
//		else
//			rect(10, 10, char(-37), 25, i + 8);
//		Bx(25, i + 10);
//		rect(10, 10, char(-37), 25, i);
//		if (i >= 70)
//		{
//			rectErA(10, 10, char(-37), 25, j - 1);
//			j += 10;
//			if (j == 70)
//			{
//				S(25, 60, 5);
//		
//			}
//			if (j == 80)
//			{
//				N(25, 70, 5);
//
//			}
//			if (j == 90)
//			{
//				A(25, 80, 5,2);
//
//			}
//			
//		}
//
//		Sleep(50);
//	}
//	for (j; j < 170; j += 10)
//	{
//		rectErA(10, 10, char(-37), 25, j - 1);
//		if (j == 100)
//		{
//			K(25, 90, 5);
//
//		}
//		if (j == 110)
//		{
//			E(25, 100, 5,2);
//
//		}
//		Sleep(50);
//	}
//
//
//	j = 170;
//	for (int i = 170; i > 0; i -= 10)
//	{
//		if (i > 10)
//		{
//		Zuban(50, i - 20);
//		}
//		else
//			rect2(10, 10, char(-37), 50, i );
//		Bx2(50, i - 15);
//	rect2(10, 10, char(-37), 50, i-3);
//		if (i <=100 )
//		{
//			rectErulta(10, 10, char(-37), 50, j );
//			j -= 10;
//			if (j == 90)
//			{
//				E(50, 105, 5,8);
//			}
//
//			if (j == 80)
//			{
//				L(50, 95, 5);
//			}
//			if (j == 70)
//			{
//				T(50, 85, 5);
//			}
//			if (j == 60)
//			{
//				T(50, 75, 5);
//			}
//			if (j == 50)
//			{
//				A2(50, 65, 5,2);
//			}
//			if (j == 40)
//			{
//				B(50, 55, 5);
//			}
//
//		}
//
//		Sleep(50);
//	}
//	for (j; j >= 0; j -= 10)
//	{
//		rectErulta(10, 10, char(-37), 50, j + 1);
//		if (j == 60)
//		{
//			T(50, 75, 5);
//		}
//		if (j == 50)
//		{
//			A2(50, 65, 5,2);
//		}
//		if (j == 40)
//		{
//			B(50, 55, 5);
//		}
//
//		
//		Sleep(50);
//
//	}
//
//
//
//	
//
//}
//
// 
//
//int main()
//{
//	_getch();
//	Sd();
//	Sleep(1000);
//Rectangl(10, 21, 9, 48, char(-37), 2);
//Rectangl(10, 22, 9, 95, char(-37), 8);
//gotoRowCol(14, 52);
//SetClr2(15, 2);
//cout << "SINGLE PLAYER";
//gotoRowCol(14, 100);
//SetClr2(15, 8);
//cout << "MULTI PLAYER";
//
//	return _getch();
//}