#include<iostream>
#include<iomanip>
#include<conio.h>
#include<windows.h>
#include<mmsystem.h>
#include<Time.h>
#include<string>
using namespace std;
int Width = 149;
int  Height = 67;
void SetClr2(int tcl, int bcl)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (tcl + (bcl * 16)));
}
void gotoRowCol(int rpos, int cpos)
{
	COORD scrn;
	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X = cpos;
	scrn.Y = rpos;
	SetConsoleCursorPosition(hOuput, scrn);
}
void SetClr(int clr)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), clr);
}
void getRowColbyLeftClick(int& rpos, int& cpos)
{
	HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
	DWORD Events;
	INPUT_RECORD InputRecord;
	SetConsoleMode(hInput, ENABLE_PROCESSED_INPUT | ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS);
	do
	{
		ReadConsoleInput(hInput, &InputRecord, 1, &Events);
		if (InputRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
		{
			cpos = InputRecord.Event.MouseEvent.dwMousePosition.X;
			rpos = InputRecord.Event.MouseEvent.dwMousePosition.Y;
			break;
		}
	} while (true);
}
enum Direction { Up, Down, Left, Right };
enum Mode { easy, medium, hard };
struct Position
{
	int ri, ci;

};
struct Snake
{
	Position* p;
	int size;
	int score;
	char sym;
	Direction Dir;
	string Pname;
	int UPKEY, DOOWNKEY, LEFTKEY, RIGHTKEY;

};
void O(int row, int col, int s, int clr)
{
	SetClr(clr);

	for (int i = 0; i <= s; i++)
	{
		gotoRowCol(row, col + i);

		cout << char(-37);
	}

	for (int i = 0; i <= 2 * s; i++)
	{
		gotoRowCol(row + i, col + s);

		cout << char(-37);
	}

	for (int i = 0; i <= s; i++)
	{
		gotoRowCol(row + s + s, col + s - i);

		cout << char(-37);
	}

	for (int i = 0; i <= 2 * s; i++)
	{
		gotoRowCol(row + s + s - i, col);

		cout << char(-37);
	}

}
void C(int row, int col, int s, int clr)
{
	SetClr(clr);

	for (int i = 0; i <= s; i++)
	{
		gotoRowCol(row, col + i);

		cout << char(-37);
	}

	for (int i = 0; i <= 2 * s; i++)
	{
		gotoRowCol(row + i, col);

		cout << char(-37);
	}

	for (int i = 0; i <= s; i++)
	{
		gotoRowCol(row + s + s, col + s - i);

		cout << char(-37);
	}


}
void U(int row, int col, int s, int clr)
{
	SetClr(clr);

	for (int i = 0; i <= 2 * s; i++)
	{
		gotoRowCol(row + i, col + s);

		cout << char(-37);
	}

	for (int i = 0; i <= s; i++)
	{
		gotoRowCol(row + s + s, col + s - i);

		cout << char(-37);
	}

	for (int i = 0; i <= 2 * s; i++)
	{
		gotoRowCol(row + s + s - i, col);

		cout << char(-37);
	}

}
void I(int rpos, int cpos, int s,int clr)
{
	

	for (int i = 0; i <= s * 2; i++)
	{
		SetClr(clr);
		gotoRowCol(rpos + i, cpos + (s / 2));

		cout << char(-37);
	}
	

}
void L(int rpos, int cpos, int s, int clr)
{
	for (int i = 0; i <= s * 2; i++)
	{
		SetClr(clr);
		gotoRowCol(rpos + i, cpos );

		cout << char(-37);
	}
	for (int i = 0; i <= s; i++)
	{
		SetClr(clr);
		gotoRowCol(rpos+(s*2), cpos+i);

		cout << char(-37);
	}


}
void T(int rpos, int cpos, int s, int clr)
{


	for (int i = 0; i <= s * 2; i++)
	{
		SetClr(clr);
		gotoRowCol(rpos + i, cpos + (s / 2)+1);

		cout << char(-37);
	}
	for (int i = 0; i <= s+1; i++)
	{
		SetClr(clr);
		gotoRowCol(rpos, cpos + i);
		cout << char(-37);
	}

}
void Y(int rpos, int cpos, int s, int clr)
{


	for (int i = 0; i <= s; i++)
	{
		SetClr(clr);
		gotoRowCol(rpos + i, cpos + i);

		cout << char(-37);
	}
	for (int i = 0; i <= s*2; i++)
	{
		SetClr(clr);
		gotoRowCol(rpos+(s*2)-i, cpos + i);
		cout << char(-37);
	}

}
void P(int rpos, int cpos, int s,int clr)
{
	for (int i = 0; i < s; i++)
	{
		SetClr(clr);
		gotoRowCol(rpos, cpos + i);
		cout << char(-37);
	}
	for (int i = 0; i <= s * 2; i++)
	{
		SetClr(clr);
		gotoRowCol(rpos + i, cpos);

		cout << char(-37);
	}

	for (int i = 0; i <= s; i++)
	{
		SetClr(clr);
		gotoRowCol(rpos + (s / 2 +2), cpos + i);
		cout << char(-37);
	}
	
	for (int i = 0; i < s; i++)
	{
		SetClr(clr);
		gotoRowCol(rpos + i, cpos + s);

		cout << char(-37);
	}


}
void D(int row, int col, int s, int clr)
{
	SetClr(clr);



	for (int i = 0; i <= 2 * s; i++)
	{
		gotoRowCol(row + i, col);

		cout << char(-37);
	}
	for (int i = 0; i <= s; i++)
	{
		gotoRowCol(row + i, col + i);

		cout << char(-37);
	}
	for (int i = 0; i < s; i++)
	{
		gotoRowCol(row + s + s - i, col + i);

		cout << char(-37);
	}


}
void V(int rpos, int cpos, int s, int clr)
{

	for (int i = 0; i <= s; i++)
	{
		SetClr(clr);
		gotoRowCol(rpos + i, cpos);

		cout << char(-37);
	}
	for (int i = 0; i <= s; i++)
	{
		SetClr(clr);
		gotoRowCol(rpos + i, cpos + s * 2);
		cout << char(-37);
	}
	for (int i = 0; i <= s; i++)
	{
		SetClr(clr);
		gotoRowCol(rpos + s + i, cpos + i);

		cout << char(-37);
	}
	for (int i = 0; i <= s; i++)
	{
		SetClr(clr);
		gotoRowCol(rpos + s + i, cpos + (s * 2) - i);
		cout << char(-37);
	}

}
void R(int rpos, int cpos, int s, int clr)
{

	for (int i = 0; i <= s * 2; i++)
	{
		SetClr(clr);
		gotoRowCol(rpos + i, cpos);

		cout << char(-37);
	}
	for (int i = 0; i <= s; i++)
	{
		SetClr(clr);
		gotoRowCol(rpos, cpos + i);
		cout << char(-37);
	}
	for (int i = 0; i <= s; i++)
	{
		SetClr(clr);
		gotoRowCol(rpos + i, cpos + s);

		cout << char(-37);
	}
	for (int i = 0; i <= s; i++)
	{
		SetClr(clr);
		gotoRowCol(rpos + s, cpos + s - i);
		cout << char(-37);
	}
	for (int i = 0; i <= s; i++)
	{
		SetClr(clr);
		gotoRowCol(rpos + s + i, cpos + i);
		cout << char(-37);
	}

}
void G(int row, int col, int s, int clr)
{
	SetClr(clr);

	for (int i = 0; i <= s; i++)
	{
		gotoRowCol(row, col + i);

		cout << char(-37);
	}


	for (int i = 0; i < s; i++)
	{
		gotoRowCol(row + s + i, col + s);

		cout << char(-37);
	}

	for (int i = 0; i <= s - 2; i++)
	{
		gotoRowCol(row + s, col + s - i);

		cout << char(-37);
	}

	for (int i = 0; i < s; i++)
	{
		gotoRowCol(row + s + s, col + s - i);

		cout << char(-37);
	}

	for (int i = 0; i < 2 * s; i++)
	{
		gotoRowCol(row + s + s - i, col);

		cout << char(-37);
	}

}
void A(int rpos, int cpos, int s, int clr)
{

	for (int i = 0; i < s; i++)
	{
		SetClr(clr);
		gotoRowCol(rpos, cpos + i);
		cout << char(-37);
	}
	for (int i = 0; i <= s * 2; i++)
	{
		SetClr(clr);
		gotoRowCol(rpos + i, cpos);

		cout << char(-37);
	}
	for (int i = 0; i <= s * 2; i++)
	{
		SetClr(clr);
		gotoRowCol(rpos + i, cpos + s);
		cout << char(-37);
	}
	for (int i = 0; i < s; i++)
	{
		SetClr(clr);
		gotoRowCol(rpos + (s / 2 + 2), cpos + i);
		cout << char(-37);
	}


}
void M(int rpos, int cpos, int s, int clr)
{

	for (int i = 0; i <= s * 2; i++)
	{
		SetClr(clr);
		gotoRowCol(rpos + i, cpos);

		cout << char(-37);
	}
	for (int i = 0; i <= s; i++)
	{
		SetClr(clr);
		gotoRowCol(rpos + i, cpos + i);
		cout << char(-37);
	}
	for (int i = 0; i <= s; i++)
	{
		SetClr(clr);
		gotoRowCol(rpos + i, cpos + (2 * s) - i);
		cout << char(-37);
	}
	for (int i = 0; i <= s * 2; i++)
	{
		SetClr(clr);
		gotoRowCol(rpos + i, cpos + 2 * s);
		cout << char(-37);
	}


}
void E(int rpos, int cpos, int s, int clr)
{

	for (int i = 0; i < s; i++)
	{
		SetClr(clr);
		gotoRowCol(rpos, cpos + i);
		cout << char(-37);
	}
	for (int i = 0; i <= s * 2; i++)
	{
		SetClr(clr);
		gotoRowCol(rpos + i, cpos);

		cout << char(-37);
	}

	for (int i = 0; i < s; i++)
	{
		SetClr(clr);
		gotoRowCol(rpos + (s / 2 + 2), cpos + i);
		cout << char(-37);
	}
	for (int i = 0; i < s; i++)
	{
		SetClr(clr);
		gotoRowCol(rpos + s * 2, cpos + i);
		cout << char(-37);
	}

}
void F(int rpos, int cpos, int s, int clr)
{

	for (int i = 0; i < s; i++)
	{
		SetClr(clr);
		gotoRowCol(rpos, cpos + i);
		cout << char(-37);
	}
	for (int i = 0; i <= s * 2; i++)
	{
		SetClr(clr);
		gotoRowCol(rpos + i, cpos);

		cout << char(-37);
	}

	for (int i = 0; i < s; i++)
	{
		SetClr(clr);
		gotoRowCol(rpos + (s / 2 + 3), cpos + i);
		cout << char(-37);
	}
	

}
void PrintGameOver()
{
	int c = Width / 2 - 20;
	G(75, c, 3, 15);
	Sleep(200);
	A(75, c + 6, 3, 15);
	Sleep(200);
	M(75, c + 12, 3, 15);
	Sleep(200);
	E(75, c + 21, 3, 15);
	Sleep(200);
	O(75, c + 32, 3, 15);
	Sleep(200);
	V(75, c + 38, 3, 15);
	Sleep(200);
	E(75, c + 47, 3, 15);
	Sleep(200);
	R(75, c + 53, 3, 15);
}
void PrinTimeUp()
{
	int c = Width / 2 - 18;
	T(75, c, 3, 15);
	Sleep(200);
	I(75, c + 6, 3, 15);
	Sleep(200);
	M(75, c + 12, 3, 15);
	Sleep(200);
	E(75, c + 21, 3, 15);
	Sleep(200);
	U(75, c + 32, 3, 15);
	Sleep(200);
	P(75, c + 38, 3, 15);
}
void Rectangl(int rows, int cols, int rpos, int cpos, char sym, int clr)
{
	SetClr(clr);
	for (int r = 0; r < rows; r++)
	{
		for (int c = 0; c < cols; c++)
		{
			gotoRowCol(rpos + r, cpos + c);
			cout << sym;
		}
	}
}
int MultPlayers()
{

	int rpos = 0, cpos = 0;

	int clr = 15, col = 74;

	SetClr2(15, 0);
	gotoRowCol(17, col);
	cout << "2 PLAYERS";
	gotoRowCol(42, col);
	cout << "3 PLAYERS";
	gotoRowCol(67, col);
	cout << "4 PLAYERS";
	getRowColbyLeftClick(rpos, cpos);

	if (rpos >= 10 && rpos <= 25 && cpos >= 66 && cpos <= 92)
	{
		return 2;
	}
	if (rpos >= 35 && rpos <= 50 && cpos >= 66 && cpos <= 92)
	{
		return 3;
	}
	if (rpos >= 60 && rpos <= 75 && cpos >= 66 && cpos <= 92)
	{
		return 4;
	}
	else return 0;



}
void intrface()
{
	Rectangl(10, 21, 9, 48, char(-37), 2);
	Rectangl(10, 22, 9, 95, char(-37), 8);
	gotoRowCol(14, 52);
	SetClr2(15, 2);
	cout << "SINGLE PLAYER";
	gotoRowCol(14, 100);
	SetClr2(15, 8);
	cout << "MULTI PLAYER";


}
void QuitGm()
{
	system("cls");
	Rectangl(10, 21, 9, 48, char(-37), 4);
	Rectangl(10, 22, 9, 95, char(-37), 15);
	gotoRowCol(14, 54);
	SetClr2(15, 4);
	cout << "QUIT GAME";
	gotoRowCol(14, 104);
	SetClr2(0, 15);
	cout << "HOME";
	SetClr2(15, 0);

}
int Players()
{
	
	int rpos = 0, cpos = 0;
	getRowColbyLeftClick(rpos, cpos);
	if (rpos >= 9 && rpos <= 19 && cpos >= 48 && cpos <= 69)
	{
		SetClr2(15, 0);
		system("cls");
		return 1;
	}
	else if (rpos >= 9 && rpos <= 19 && cpos >= 95 && cpos <= 117)
	{
		SetClr2(15, 2);
		system("cls");
		int clr = 0, col = 74;
		Rectangl(15, 26, 10, 66, char(-37), clr);
		Rectangl(15, 26, 35, 66, char(-37), clr);
		Rectangl(15, 26, 60, 66, char(-37), clr);
		int nop = 0;
		while (nop == 0)
		{
			nop = MultPlayers();
		}
		return nop;
	}
	else return 0;

}
int Quit() 
{
	int rpos = 0, cpos = 0;
	getRowColbyLeftClick(rpos, cpos);
	if (rpos >= 9 && rpos <= 19 && cpos >= 48 && cpos <= 69)
	{
		SetClr2(15, 0);
		system("cls");
		return 1;
	}
	else if (rpos >= 9 && rpos <= 19 && cpos >= 95 && cpos <= 117)
	{
		SetClr2(15, 0);
		system("cls");
		return 2;
	}
	else return 0;
}
void Init1(Snake*& S, Position& Fd, int nop, Mode md)
{
	if (nop == 1 || nop == 2 || nop == 3 || nop == 4)
	{

		S[0].p = new Position[3];

		S[0].p[0].ci = Width / 2 - 29;
		S[0].p[0].ri = Height / 2-20;

		S[0].p[1].ci = (Width / 2) - 29;
		S[0].p[1].ri = Height / 2 - 21;

		S[0].p[2].ci = (Width / 2) - 29;
		S[0].p[2].ri = Height / 2 - 22;


		S[0].Dir = Down;
		S[0].UPKEY = 72;
		S[0].DOOWNKEY = 80;
		S[0].LEFTKEY = 75;
		S[0].RIGHTKEY = 77;

	}

	if (nop == 2 || nop == 3 || nop == 4)

	{

		S[1].p = new Position[3];

		S[1].p[0].ci = Width / 2 - 26;
		S[1].p[0].ri = Height / 2 -23;

		S[1].p[1].ci = (Width / 2) - 27;
		S[1].p[1].ri = Height / 2 -23;

		S[1].p[2].ci = (Width / 2) - 28;
		S[1].p[2].ri = Height / 2 -23;


		S[1].Dir = Right;
		S[1].UPKEY = 119;
		S[1].DOOWNKEY = 115;
		S[1].LEFTKEY = 97;
		S[1].RIGHTKEY = 100;
	}
	if (nop == 3 || nop == 4)
	{
		S[2].p = new Position[3];

		S[2].p[0].ci = Width / 2 +50;
		S[2].p[0].ri = Height / 2 +37 ;
		S[2].p[1].ci = (Width / 2) +50;
		S[2].p[1].ri = Height / 2 +36;
		S[2].p[2].ci = (Width / 2) +50;
		S[2].p[2].ri = Height / 2 +35;


		S[2].Dir = Up;
		S[2].UPKEY = 121;//y
		S[2].DOOWNKEY = 104;//h
		S[2].LEFTKEY = 103;//g
		S[2].RIGHTKEY = 106;//j
	}
	if (nop == 4)
	{
		S[3].p = new Position[3];

		S[3].p[0].ci = Width / 2 +47;
		S[3].p[0].ri = Height / 2 + 37;
		S[3].p[1].ci = (Width / 2) +48;
		S[3].p[1].ri = Height / 2 + 37;
		S[3].p[2].ci = (Width / 2) +49;
		S[3].p[2].ri = Height / 2 + 37;


		S[3].Dir = Left;
		S[3].UPKEY = 111;//y
		S[3].DOOWNKEY = 108;//h
		S[3].LEFTKEY = 107;//g
		S[3].RIGHTKEY = 59;//j
	}
	system("cls");
	for (int n = 0, j = 0; n < nop; n++, j += 8)
	{
		S[n].size = 3;
		S[n].score = 0;
		S[n].sym = '@';
		Rectangl(5, 26, 18 + j, 27, char(-37), 15);
		gotoRowCol(20 + j, 30);
		SetClr2(0, 15);
		cout << "ENTER PLAYER "<< n+1 <<"'s NAME :";
		SetClr2(15, 0); cout << "    ";
		getline(cin, S[n].Pname);
	}
	SetClr2(15, 0);
	system("cls");

	int t = 0;
	int t2 = 0;
	Fd.ri = rand() % 72;
	if (Fd.ri < 9)
	{
		t = 9 - Fd.ri;

		Fd.ri += t;
	}
	Fd.ci = rand() % 129;
	if (Fd.ci < 36)
	{
		t2 = 36 - Fd.ci;

		Fd.ci += t2;
	}

	SetClr(11);
	gotoRowCol(Fd.ri, Fd.ci);
	cout << "@";
	
}
void Win(Snake*& S, int nop)
{
	string winner{};
	int ok = 0;
	int i = 0;
	for (int j = 0; j < nop; j++, i++)
	{
		ok = 0;
		for (int n = 0; n < nop; n++)
		{
			if (S[i].score >= S[n].score)
			{
				if (i != n)
					ok++;
			}
		}
		if (ok == nop - 1)
			break;
	}
	bool res = 0;
	winner = S[i].Pname;
	for (int k = 0; k < nop; k++)
	{
		if (i != k)
		{
			if (S[i].score == S[k].score)
			{
				res = 1;
			}
		}
	}
	
	 if (res == 1)
	{
		SetClr(15);
		
		Rectangl(5, 15, 55, 140, char(-37), 1);
		SetClr2(15, 1);
		gotoRowCol(57, 142);
		cout << "MATCH TIED!";
		SetClr2(15, 0);
	}
	else
	{
		SetClr(15);
		
		Rectangl(5, 20, 55, 138, char(-37), 4);
		SetClr2(15, 4);
		gotoRowCol(57, 140);
		cout << winner << " WINS !!";
		SetClr2(15, 0);

	}
}
void BOX(int size, Mode md)
{
	if (md == easy)
	{
		SetClr(2);
	}
	else
		SetClr(4);

	for (int r = 0; r < size - 20; r++)
	{
		for (int c = 0; c < size + 10; c++)
		{
			if (r == 0 || c == 0 || r == size - 20 - 1 || c == size + 10 - 1)
			{
				gotoRowCol(r + 8, c + 35);
				cout << char(-37);
			}
		}
	}

	if (md == hard)
	{
		for (int r = 0; r < size - 20; r++)
		{
			for (int c = 0; c < size + 10; c++)
			{
				if ((r == 33 && (c >= 16 && c <= 76)) || (c == 46 && (r >= 10 && r <= 27)) || (c == 46 && (r >= 40 && r <= 55)))
				{
					gotoRowCol(r + 8, c + 35);
					cout << char(-37);
				}
			}
		}
	}



}
void DisplaySnake1(Snake*& S, int nop)
{
	for (int j = 0; j < nop; j++)
	{
		for (int i = 0; i < S[j].size; i++)
		{
			if (j == 0)
			{
				SetClr(15);
			}
			if (j == 1)
			{
				SetClr(4);
			}
			if (j == 2)
			{
				SetClr(15);
			}
			if (j == 3)
			{
				SetClr(15);
			}


			if (i == 0)
			{
				if (j == 0)
				{
					SetClr(4);
				}
				if (j == 1)
				{
					SetClr(2);

				}
				if (j == 2)
				{
					SetClr(1);
				}
				if (j == 3)
				{
					SetClr(6);
				}

				gotoRowCol(S[j].p[i].ri, S[j].p[i].ci);
				cout << '0';
			}

			else {

				if (i % 2 == 0)
				{
					if (j == 0)
					{
						SetClr(3);
					}
					if (j == 1)
					{
						SetClr(15);
					}
					if (j == 2)
					{
						SetClr(13);
					}
					if (j == 3)
					{
						SetClr(9);
					}
				}
				if (i % 3 == 0)
				{
					if (j == 0)
					{
						SetClr(6);
					}
					if (j == 1)
					{
						SetClr(13);
					}
					if (j == 2)
					{
						SetClr(8);
					}
					if (j == 3)
					{
						SetClr(7);
					}
				}
				gotoRowCol(S[j].p[i].ri, S[j].p[i].ci);
				cout << S[j].sym;
			}
		}
	}
}
void EraseSnake1(Snake*& S, int nop)
{
	int sz = 0;
	for (int n = 0; n < nop; n++)
	{
		for (int i = 0; i < S[n].size; i++)
		{
			gotoRowCol(S[n].p[i].ri, S[n].p[i].ci);
			cout << " ";
		}
	
	}
}
void MoveSnake1(Snake*& S, int nop)
{
	for (int n = 0; n < nop; n++)
	{
		for (int i = S[n].size - 1; i >= 1; i--)
		{
			S[n].p[i] = S[n].p[i - 1];
		}
		if (S[n].Dir == Right)
		{
			S[n].p[0].ci++;
		}
		else if (S[n].Dir == Left)
		{
			S[n].p[0].ci--;
		}
		else if (S[n].Dir == Up)
		{
			S[n].p[0].ri--;
		}
		else if (S[n].Dir == Down)
		{
			S[n].p[0].ri++;
		}
		if (S[n].p[0].ri == 8)
		{
			S[n].p[0].ri = 65 + 6;
		}
		else if (S[n].p[0].ci == 35)
		{
			S[n].p[0].ci = 95 + 33;
		}
		else if (S[n].p[0].ri == 65 + 7)
		{
			S[n].p[0].ri = 9;
		}
		else if (S[n].p[0].ci == 95 + 34)
		{
			S[n].p[0].ci = 36;
		}
	}

}
void ChangeDir1(Snake*& S, char ch, int nop)
{
	for (int n = 0; n < nop; n++)
	{
		if (ch == S[n].DOOWNKEY)
		{
			if (S[n].Dir != Up)
				S[n].Dir = Down;
		}
		else if (ch == S[n].UPKEY)
		{
			if (S[n].Dir != Down)
				S[n].Dir = Up;
		}
		else if (ch == S[n].LEFTKEY)
		{
			if (S[n].Dir != Right)
				S[n].Dir = Left;
		}
		else if (ch == S[n].RIGHTKEY)
		{
			if (S[n].Dir != Left)
				S[n].Dir = Right;
		}
	}

}
bool IslegalFood(Snake* S, int nop, Position Fd,Position Bf,Mode md)
{

	for (int k = 0; k < nop; k++)
	{
		for (int i = 0; i < S[k].size; i++)
		{

			if ((Fd.ri == S[k].p[i].ri && Fd.ci == S[k].p[i].ci))
			{

				return false;
			}

		}
	}
	if (md == hard)
	{

		if ((Fd.ri == 33 + 8 && (Fd.ci >= 16 + 35 && Fd.ci <= 76 + 35)) || (((Fd.ri >= 10 + 8 && Fd.ri <= 27 + 8) || (Fd.ri >= 40 + 8 && Fd.ri <= 55 + 8)) && Fd.ci == 46 + 35))
		{
			return false;
		}

	}
	if(Fd.ri==Bf.ri&&Fd.ci==Bf.ci)
	{ 
		return false;
	}
	return true;
}
void FoodnScore1(Snake*& S, Position& Fd,Position Bf, int nop,Mode md)
{
	int t = 0;
	int t2 = 0;
	for (int n = 0; n < nop; n++)
	{
		if ((S[n].p[0].ri == Fd.ri && S[n].p[0].ci == Fd.ci))
		{
			PlaySound(TEXT("EAT.wav"), NULL, SND_ASYNC);
			int temp = 0;
			S[n].score++;
			temp = S[n].size;
			S[n].size++;
			Position* Tp;

			Tp = new Position[temp]{};

			for (int i = 0; i < temp; i++)
			{
				Tp[i] = S[n].p[i];
			}
			delete S[n].p;

			S[n].p = new Position[S[n].size]{};
			for (int i = 0; i < S[n].size - 1; i++)
			{
				S[n].p[i] = Tp[i];
			}
			delete Tp;
			Tp = nullptr;

			gotoRowCol(Fd.ri, Fd.ci);
			cout << " ";
			Fd.ri = rand() % 72;
			Fd.ci = rand() % 129;
			while (!IslegalFood(S, nop, Fd,Bf, md))
			{
				Fd.ri = rand() % 72;
				Fd.ci = rand() % 129;
			}

			if (Fd.ri < 9)
			{
				t = 9 - Fd.ri;

				Fd.ri += t;
			}

			if (Fd.ci < 36)
			{
				t2 = 36 - Fd.ci;
				Fd.ci += t2;
			}
			SetClr(11);
			gotoRowCol(Fd.ri, Fd.ci);
			cout << "@";
		}
	}
}
void BonusFd(Snake* S, Position& Fd,Position OFd, int nop, Mode md)
{
	int t = 0;
	int t2 = 0;
	Fd.ri = rand() % 72;
	Fd.ci = rand() % 129;
	while (!IslegalFood(S, nop, Fd, OFd, md))
	{
		Fd.ri = rand() % 72;
		Fd.ci = rand() % 129;
	}

	if (Fd.ri < 9)
	{
		t = 9 - Fd.ri;

		Fd.ri += t;
	}

	if (Fd.ci < 36)
	{
		t2 = 36 - Fd.ci;
		Fd.ci += t2;
	}
	SetClr(13);
	gotoRowCol(Fd.ri, Fd.ci);
	cout << char(-37);

				
}
void BonusFdErase(Snake*&S, Position Fd,int nop,int& t,int &e)
{
	for (int n = 0; n < nop; n++)
	{
		if ((S[n].p[0].ri == Fd.ri && S[n].p[0].ci == Fd.ci))
		{
			PlaySound(TEXT("EAT.wav"), NULL, SND_ASYNC);
			int temp = 0;
			S[n].score += 3;
			temp = S[n].size;
			S[n].size += 3;
			Position* Tp;

			Tp = new Position[temp]{};

			for (int i = 0; i < temp; i++)
			{
				Tp[i] = S[n].p[i];
			}
			delete S[n].p;

			S[n].p = new Position[S[n].size]{};
			for (int i = 0; i < S[n].size - 1; i++)
			{
				S[n].p[i] = Tp[i];
			}
			delete Tp;
			Tp = nullptr;

			gotoRowCol(Fd.ri, Fd.ci);
			cout << " ";
			t = 0, e = 0;
		}
	}

	if (e == 87)
	{
		gotoRowCol(Fd.ri, Fd.ci);
		cout << " ";
		t = 0, e = 0;
	}
}
bool kill(Snake* S, int nop, Mode md)
{
	for (int n = 0; n < nop; n++)
	{

		for (int i = 0; i < nop; i++)
		{

			if (S[n].Dir == Up)
			{
				for (int j = 0; j < S[i].size; j++)
				{
					if (S[n].p[0].ri - 1 == S[i].p[j].ri && S[n].p[0].ci == S[i].p[j].ci)
					{
						return true;
					}
				}

				if (md == medium || md == hard)
				{
					if (S[n].p[0].ri - 1 == 8)
					{
						return true;
					}
				}
				if (md == hard)
				{
					if (S[n].p[0].ri - 1 == 33 + 8 && (S[n].p[0].ci >= 16 + 35 && S[n].p[0].ci <= 76 + 35))
					{
						return true;
					}
					if (S[n].p[0].ri - 1 == 27 + 8 && S[n].p[0].ci == 46 + 35)
					{
						return true;
					}
					if (S[n].p[0].ri - 1 == 55 + 8 && S[n].p[0].ci == 46 + 35)
					{
						return true;
					}
				}

			}

			if (S[n].Dir == Down)
			{
				for (int j = 0; j < S[i].size; j++)
				{
					if (S[n].p[0].ri + 1 == S[i].p[j].ri && S[n].p[0].ci == S[i].p[j].ci)
					{
						return true;
					}
				}

				if (md == medium || md == hard)
				{
					if (S[n].p[0].ri + 1 == 72)
					{
						return true;
					}
				}
				if (md == hard)
				{
					if (S[n].p[0].ri + 1 == 33 + 8 && (S[n].p[0].ci >= 16 + 35 && S[n].p[0].ci <= 76 + 35))
					{
						return true;
					}
					if (S[n].p[0].ri + 1 == 10 + 8 && S[n].p[0].ci == 46 + 35)
					{
						return true;
					}
					if (S[n].p[0].ri + 1 == 40 + 8 && S[n].p[0].ci == 46 + 35)
					{
						return true;
					}
				}
			}
			if (S[n].Dir == Left)
			{
				for (int j = 0; j < S[i].size; j++)
				{
					if (S[n].p[0].ci - 1 == S[i].p[j].ci && S[n].p[0].ri == S[i].p[j].ri)
					{
						return true;
					}

				}
				if (md == medium || md == hard)
				{
					if (S[n].p[0].ci - 1 == 35)
					{
						return true;
					}
				}
				if (md == hard)
				{
					if (S[n].p[0].ci - 1 == 76 + 35 && (S[n].p[0].ri == 33 + 8))
					{
						return true;
					}
					if (S[n].p[0].ci - 1 == 46 + 35 && (S[n].p[0].ri >= 10 + 8 && S[n].p[0].ri <= 27 + 8))
					{
						return true;
					}
					if (S[n].p[0].ci - 1 == 46 + 35 && (S[n].p[0].ri >= 40 + 8 && S[n].p[0].ri <= 55 + 8))
					{
						return true;
					}
				}
			}
			if (S[n].Dir == Right)
			{
				for (int j = 0; j < S[i].size; j++)
				{
					if (S[n].p[0].ci + 1 == S[i].p[j].ci && S[n].p[0].ri == S[i].p[j].ri)
					{
						return true;
					}

				}

				if (md == medium || md == hard)
				{

					if (S[n].p[0].ci + 1 == 95 + 34)
					{
						return true;
					}
				}
				if (md == hard)
				{
					if (S[n].p[0].ci + 1 == 16 + 35 && (S[n].p[0].ri == 33 + 8))
					{
						return true;
					}
					if (S[n].p[0].ci + 1 == 46 + 35 && (S[n].p[0].ri >= 10 + 8 && S[n].p[0].ri <= 27 + 8))
					{
						return true;
					}
					if (S[n].p[0].ci + 1 == 46 + 35 && (S[n].p[0].ri >= 40 + 8 && S[n].p[0].ri <= 55 + 8))
					{
						return true;
					}
				}
			}


		}


	}





	return false;
}
void ScoreDis(Snake*& S, int nop)
{

	for (int n = 0, i = 0; n < nop; n++, i += 5)
	{
		
		SetClr2(0, 15);
		gotoRowCol(27 + i, 158);
		cout << S[n].score;
	}

	SetClr2(15, 0);
}
int SelMode()
{
	int rpos = 0, cpos = 0;
	getRowColbyLeftClick(rpos, cpos);
	if (rpos >= 38 && rpos <= 47 && cpos >= 44 && cpos <= 64)
		return 1;
	if (rpos >= 38 && rpos <= 47 && cpos >= 69 && cpos <= 89)
		return 2;
	if (rpos >= 38 && rpos <= 47 && cpos >= 94 && cpos <= 114)
		return 3;

	return 0;

}
int SelTimeB()
{
	
	int rpos = 0, cpos = 0;
	getRowColbyLeftClick(rpos, cpos);
	if (rpos >= 38 && rpos <= 51 && cpos >= 67 && cpos <= 90)
		return 1;
	if (rpos >= 55 && rpos <= 68 && cpos >= 67 && cpos <= 90)
		return 2;

	return 0;
	
}
Mode ModBox()
{
	SetClr2(15, 0);
	system("cls");
	int  col = 74;
	D(18, 40, 5, 2);
	I(18, 48, 5, 2);
	F(18, 56, 5, 2);
	F(18, 64, 5, 2);
	I(18, 72, 5, 2);
	C(18, 80, 5, 2);
	U(18, 88, 5, 2);
	L(18, 96, 5, 2);
	T(18, 104, 5, 2);
	Y(18, 112, 5, 2);
	Rectangl(9, 20, 38, 44, char(-37), 15);
	Rectangl(9, 20, 38, 69, char(-37), 15);
	Rectangl(9, 20, 38, 94, char(-37), 15);
	gotoRowCol(42, 51);
	SetClr2(2, 15);
	cout << "EASY";
	gotoRowCol(42, 76);
	SetClr2(0, 15);
	cout << "MEDIUM";
	gotoRowCol(42, 101);
	SetClr2(4, 15);
	cout << "HARD";

	int md = 0;

	while (md == 0)
	{
		md = SelMode();
	}
	SetClr2(15, 0);
	system("cls");
	if (md == 1)
		return easy;
	if (md == 2)
		return medium;
	if (md == 3)
		return hard;

}
int tBaseGm()
{
	SetClr2(11, 15);
	system("cls");
	int  col = 74;
	M(18, 62, 5, 0);
	O(18, 76, 5, 0);
	D(18, 85, 5, 0);
	E(18, 94, 5, 0);
	Rectangl(13, 23, 38, 67, char(-37), 2);
	Rectangl(13, 23, 55, 67, char(-37), 2);
	
	gotoRowCol(45, 75);
	SetClr2(0, 2);
	cout << "SIMPLE";
	gotoRowCol(62, 74);
	SetClr2(0, 2);
	cout << "TIME RUN";
	int md = 0;
	while (md == 0)
	{
		md = SelTimeB();
	}
	SetClr2(15, 0);
	system("cls");
	return md;
}
void NameDisp(Snake* S, int nop)
{
	Rectangl(5, 26, 20 , 135, char(-37), 2);
	SetClr2(15, 2);
	gotoRowCol(22 , 142);
	cout << "SCORE CARD";
	for (int n = 0, i = 0; n < nop; n++, i += 5)
	{
		Rectangl(5, 26, 25 + i, 135,char(-37),15);
		SetClr2(0, 15);
		gotoRowCol(27 + i, 138);
		cout << S[n].Pname;
	}
	SetClr2(15, 0);
}
void Cloack(int gt,int rpos,int cpos)
{
	
	if (gt <= 50)
	{
		Rectangl(5, 7, rpos - 2, cpos - 2, char(-37), 15);
		SetClr2(0, 15);
	}
	else

	{
		
		Rectangl(5, 7, rpos - 2, cpos - 2, char(-37), 4);
	SetClr2(15, 4);
	}
	gotoRowCol(rpos, cpos-1);
	cout <<"00:" << setw(2) << setfill('0') << gt;
	SetClr2(15, 0);
}
void rect(int r, int c, char sym, int rpos, int cpos)
{

	for (int i = 0; i < r; i++)
	{

		for (int j = 0; j < c; j++)
		{

			if (j >= 0 && j < 1)
			{
				SetClr(0);

			}

			else if (i % 2 == 0)
			{
				if (j % 2 == 0)
					SetClr(2);

				else SetClr(0);
			}
			else
			{
				if (j % 2 == 0)
					SetClr(0);

				else SetClr(2);
			}
			if (i == 0 || i == r - 1)
				(SetClr(2));
			gotoRowCol(i + rpos, cpos + j);

			cout << char(sym);

		}
	}
}
void rect2(int r, int c, char sym, int rpos, int cpos)
{

	for (int i = r - 1; i >= 0; i--)
	{

		for (int j = c - 1; j >= 0; j--)
		{

			if (j == c - 1 && j > c - 2)
			{
				SetClr(8);

			}

			else if (i % 2 == 0)
			{
				if (j % 2 == 0)
					SetClr(9);

				else SetClr(0);
			}
			else
			{
				if (j % 2 == 0)
					SetClr(0);

				else SetClr(9);
			}
			if (i == 0 || i == r - 1)
				(SetClr(9));
			gotoRowCol(rpos + i, cpos - j);

			cout << char(sym);

		}
	}
}
void rectErA(int r, int c, char sym, int rpos, int cpos)
{

	for (int i = 0; i < r; i++)
	{

		for (int j = 0; j < c; j++)
		{

			gotoRowCol(i + rpos, cpos + j);

			cout << " ";

		}
	}
}
void rectErulta(int r, int c, char sym, int rpos, int cpos)
{

	for (int i = 0; i <= r; i++)
	{

		for (int j = 0; j <= c; j++)
		{

			gotoRowCol(i + rpos, cpos - j);

			cout << " ";

		}
	}
}
void Bx(int rpos, int cpos)
{

	int r = 10, c = 5;

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if ((i == 0 && j == c - 1) || (i == r - 1 && j == c - 1))
				;

			else if ((i == 3 && j == 3) || (i == 6 && j == 3))
			{

				gotoRowCol(rpos + i, cpos + j);
				SetClr(15);
				cout << char(-37);
			}

			else
			{
				gotoRowCol(rpos + i, cpos + j);
				SetClr(2);
				cout << char(-37);
			}



		}
	}

}
void Bx2(int rpos, int cpos)
{

	int r = 10, c = 5;

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if ((i == 0 && j == 0) || (i == r - 1 && j == 0))
				;
			else if ((i == 3 && j == 2) || (i == 6 && j == 2))
			{

				gotoRowCol(rpos + i, cpos + j);
				SetClr(15);
				cout << char(-37);
			}


			else
			{
				gotoRowCol(rpos + i, cpos + j);
				SetClr(9);
				cout << char(-37);
			}

		}
	}

}
void Zuban(int rpos, int cpos)
{

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{

			gotoRowCol(rpos + 2 + i, cpos + 2 + i);
			SetClr(4);
			cout << char(-37);
		}


	}

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{

			gotoRowCol(rpos + 7 - i, cpos + 2 + i);
			SetClr(4);
			cout << char(-37);
		}


	}

}
void S(int rpos, int cpos, int s)
{

	for (int i = 0; i <= s; i++)
	{
		SetClr(2);
		gotoRowCol(rpos, cpos + i);
		cout << char(-37);
	}
	for (int i = 0; i < s; i++)
	{
		SetClr(2);
		gotoRowCol(rpos + i, cpos);

		cout << char(-37);
	}
	for (int i = 0; i < s; i++)
	{
		SetClr(2);
		gotoRowCol(rpos + s, cpos + i);
		cout << char(-37);
	}
	for (int i = 0; i <= s; i++)
	{
		SetClr(2);
		gotoRowCol(rpos + s + i, cpos + s);
		cout << char(-37);
	}
	for (int i = 0; i <= s; i++)
	{
		SetClr(2);
		gotoRowCol(rpos + s + s + 1, cpos + s - i);
		cout << char(-37);
	}


}
void N(int rpos, int cpos, int s)
{

	for (int i = 0; i <= s * 2; i++)
	{
		SetClr(8);
		gotoRowCol(rpos + i, cpos);
		cout << char(-37);
	}
	for (int i = 0; i < s; i++)
	{
		SetClr(8);
		gotoRowCol(rpos + i, cpos + i);

		cout << char(-37);
	}


	for (int i = 0; i < s * 2; i++)
	{
		SetClr(8);
		gotoRowCol(rpos + i, cpos + s);
		cout << char(-37);
	}

}
void A2(int rpos, int cpos, int s, int clr)
{
	for (int i = 0; i < s; i++)
	{
		SetClr(clr);
		gotoRowCol(rpos, cpos + i);
		cout << char(-37);
	}
	for (int i = 0; i <= s * 2; i++)
	{
		SetClr(clr);
		gotoRowCol(rpos + i, cpos);

		cout << char(-37);
	}
	for (int i = 0; i <= s * 2; i++)
	{
		SetClr(clr);
		gotoRowCol(rpos + i, cpos + s);
		cout << char(-37);
	}
	for (int i = 0; i < s; i++)
	{
		SetClr(clr);
		gotoRowCol(rpos + (s / 2 + 2), cpos + i);
		cout << char(-37);
	}


}
void K(int rpos, int cpos, int s)
{


	for (int i = 0; i < s * 2; i++)
	{
		SetClr(8);
		gotoRowCol(rpos + i, cpos);

		cout << char(-37);
	}
	for (int i = 0; i <= s; i++)
	{
		SetClr(8);
		gotoRowCol(rpos + (s / 2 + 3) - i, cpos + i);
		cout << char(-37);
	}
	for (int i = 0; i <= s; i++)
	{
		SetClr(8);
		gotoRowCol(rpos + (s / 2 + 3) + i, cpos + i);
		cout << char(-37);
	}


}
void B(int rpos, int cpos, int s)
{
	int clr = 8;
	for (int i = 0; i < s; i++)
	{
		SetClr(clr);
		gotoRowCol(rpos, cpos + i);
		cout << char(-37);
	}
	for (int i = 0; i <= s * 2 + 1; i++)
	{
		SetClr(8);
		gotoRowCol(rpos + i, cpos);

		cout << char(-37);
	}

	for (int i = 0; i <= s; i++)
	{
		SetClr(8);
		gotoRowCol(rpos + (s / 2 + 3), cpos + i);
		cout << char(-37);
	}
	for (int i = 0; i <= s; i++)
	{
		SetClr(8);
		gotoRowCol(rpos + s * 2 + 1, cpos + i);
		cout << char(-37);
	}
	for (int i = 0; i < s; i++)
	{
		SetClr(8);
		gotoRowCol(rpos + i, cpos + s);

		cout << char(-37);
	}
	for (int i = 0; i <= s + 1; i++)
	{
		SetClr(8);
		gotoRowCol(rpos + s + i, cpos + s + 1);

		cout << char(-37);
	}


}
void SNAKEBTL()
{
	PlaySound(TEXT("StrangerThingsOrg.wav"), NULL, SND_ASYNC);
	S(25, 60, 5); N(25, 70, 5); A(25, 80, 5, 2); E(25, 100, 5, 2); K(25, 90, 5); E(50, 105, 5, 8); B(50, 55, 5); E(50, 105, 5, 8); L(50, 95, 5, 2); T(50, 85, 5, 8); T(50, 75, 5, 8); A2(50, 65, 5, 2); B(50, 55, 5);
}
void Sd()
{

	PlaySound(TEXT("StrangerThingsOrg.wav"), NULL, SND_ASYNC);
	int j = 0;
	for (int i = 0; i < 160; i += 10)
	{
		if (i < 150)
		{
			Zuban(25, i + 10);
		}
		else
			rect(10, 10, char(-37), 25, i + 8);
		Bx(25, i + 10);
		rect(10, 10, char(-37), 25, i);
		if (i >= 70)
		{
			rectErA(10, 10, char(-37), 25, j - 1);
			j += 10;
			if (j == 70)
			{
				S(25, 60, 5);

			}
			if (j == 80)
			{
				N(25, 70, 5);

			}
			if (j == 90)
			{
				A(25, 80, 5, 2);

			}

		}

		Sleep(50);
	}
	for (j; j < 170; j += 10)
	{
		rectErA(10, 10, char(-37), 25, j - 1);
		if (j == 100)
		{
			K(25, 90, 5);

		}
		if (j == 110)
		{
			E(25, 100, 5, 2);

		}
		Sleep(50);
	}


	j = 170;
	for (int i = 170; i > 0; i -= 10)
	{
		if (i > 10)
		{
			Zuban(50, i - 20);
		}
		else
			rect2(10, 10, char(-37), 50, i);
		Bx2(50, i - 15);
		rect2(10, 10, char(-37), 50, i - 3);
		if (i <= 100)
		{
			rectErulta(10, 10, char(-37), 50, j);
			j -= 10;
			if (j == 90)
			{
				E(50, 105, 5, 8);
			}

			if (j == 80)
			{
				L(50, 95, 5,2);
			}
			if (j == 70)
			{
				T(50, 85, 5,8);
			}
			if (j == 60)
			{
				T(50, 75, 5,8);
			}
			if (j == 50)
			{
				A2(50, 65, 5, 2);
			}
			if (j == 40)
			{
				B(50, 55, 5);
			}

		}

		Sleep(50);
	}
	for (j; j >= 0; j -= 10)
	{
		rectErulta(10, 10, char(-37), 50, j + 1);
		if (j == 60)
		{
			T(50, 75, 5,8);
		}
		if (j == 50)
		{
			A2(50, 65, 5, 2);
		}
		if (j == 40)
		{
			B(50, 55, 5);
		}


		Sleep(50);

	}





}
int GAME()
{
	intrface();
	Mode md;
	srand(time(0));
	int nop = 0;
	int TimeLp=0;
	while (nop == 0)
	{
		nop = Players();
	}

	TimeLp=tBaseGm();
	
	md = ModBox();
	Snake* S;
	S = new Snake[nop];
	char ch = 0;
	Position Fd{};
	Position Bf{};
	int t = 0, e = 0; 
	int c1 = 0, c2 = 0;
	
	Init1(S, Fd, nop, md);
	BOX(85, md);
	NameDisp(S, nop);
	PlaySound(TEXT("START.wav"), NULL, SND_ASYNC);
	while (true)
	{
		EraseSnake1(S, nop);
		MoveSnake1(S, nop);
		DisplaySnake1(S, nop);
		FoodnScore1(S, Fd,Bf, nop,md);
		Sleep(50);
		ScoreDis(S, nop);
		t++, e++; 
		if (t == 50)
		{
			BonusFd(S, Bf, Fd, nop, md);	
		}
		if (t >= 50)
			BonusFdErase(S, Bf, nop, t,e);
		
		if (_kbhit())
		{
			ch = _getch();
			if (ch == -32)
			{
				ch = _getch();
				ChangeDir1(S, ch, nop);
			}

			if (ch == 119 || ch == 100 || ch == 97 || ch == 115)
			{
				ChangeDir1(S, ch, nop);
			}
			if (ch == 121 || ch == 103 || ch == 104 || ch == 106)
			{
				ChangeDir1(S, ch, nop);
			}
			if (ch == 111 || ch == 107 || ch == 108 || ch == 59)
			{
				ChangeDir1(S, ch, nop);
			}

		}
		if (TimeLp == 2)
		{
			c1++;
			if (c1 == 16)
			{
				c2 += 1;
				c1 = 0;
				Cloack(c2,4,Width/2+3);
			}
			if (c2 == 59)
			{
				PlaySound(TEXT("TIMEUPSIREN"), NULL, SND_ASYNC);
				PrinTimeUp();
				if(nop!=1)Win(S, nop);
				break;
			}
		}
		if (kill(S, nop, md))
		{
			if(nop!=1)
			{

				Win(S, nop);
			}PlaySound(TEXT("GAMEOV (2).wav"), NULL, SND_ASYNC);
			SetClr(15);
			PrintGameOver();
			break;
		}
	}

	Sleep(4500);

	int quit = 0;
	QuitGm();
	while (quit == 0)
	{
		quit = Quit();
	}
	return quit;
}
int main()
{
	Sd();
	Sleep(200);

	int i = 0;
	int qt = 2;
	while(qt==2)
	{
		if (i > 0)
			SNAKEBTL();
	qt=	GAME();		
	Sleep(200);
	i++;
	}
	
	return 0;
}