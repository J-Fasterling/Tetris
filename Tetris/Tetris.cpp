// Tetris.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
using namespace std;

#include <Windows.h>

wstring tetromino[7];
int iFieldWidth = 12;
int iFieldHeight = 18;
unsigned char* pField = nullptr;

int iScreenWidth = 80;   //Höhe der Konsole
int iScreenHeight = 30;  //Breite der Konsole

int Rotate(int px, int py, int r)
{
	switch (r % 4)
	{
	case 0: return py * 4 + px;			//Rotation um 0 Grad
	case 1: return 12 + py - (px * 4);  //Rotation um 90 Grad
	case 2: return 15 - (py * 4) - px;  //Rotation um 180 Grad
	case 3: return 3 - py + (px * 4);   //Rotation um 270 Grad
	}
	return 0;
}


int main()
{
	//Bausteine erstellen
	tetromino[0].append(L"..X.");
	tetromino[0].append(L"..X.");
	tetromino[0].append(L"..X.");
	tetromino[0].append(L"..X.");

	tetromino[1].append(L"..X.");
	tetromino[1].append(L".XX.");
	tetromino[1].append(L".X..");
	tetromino[1].append(L"....");

	tetromino[2].append(L".X..");
	tetromino[2].append(L".XX.");
	tetromino[2].append(L"..X.");
	tetromino[2].append(L"....");

	tetromino[3].append(L"....");
	tetromino[3].append(L".XX.");
	tetromino[3].append(L".XX.");
	tetromino[3].append(L"....");

	tetromino[4].append(L"..X.");
	tetromino[4].append(L".XX.");
	tetromino[4].append(L"..X.");
	tetromino[4].append(L"....");

	tetromino[5].append(L"....");
	tetromino[5].append(L".XX.");
	tetromino[5].append(L"..X.");
	tetromino[5].append(L"..X.");

	tetromino[6].append(L"....");
	tetromino[6].append(L".XX.");
	tetromino[6].append(L".X..");
	tetromino[6].append(L".X..");

	pField = new unsigned char[iFieldWidth * iFieldHeight]; //Erzeugen des Spielfelds
	for (int x = 0; x < iFieldWidth; x++)
	{
		for (int y = 0; y < iFieldHeight; y++)
		{
			pField[y * iFieldWidth + x] = (x == 0 || x == iFieldWidth - 1 || y == iFieldHeight - 1) ? 9 : 0; //Spielfeldrand erzeugen
		}
	}

	wchar_t* screen = new wchar_t[iScreenWidth * iScreenHeight];
	for (int i = 0; i < iScreenWidth * iScreenHeight; i++)
	{
		screen[i] = L' ';
	}
	HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleActiveScreenBuffer(hConsole);
	DWORD dwBytesWritten = 0;


	bool bGameOver = false;

	while (!bGameOver)
	{
		// Timing für alle Geraete


		//Input des Spielers

		//Logik des Spiels

		//Output Rendern

		//Spielfeld gestalten
		for (int x = 0; x < iFieldWidth; x++)
		{
			for (int y = 0; y < iFieldHeight; y++)
			{
				screen[(y + 2) * iScreenWidth + (x + 2)] = L" ABCDEFG=#"[pField[y * iFieldWidth + x]];
			}
		}
		//Frame darstellen
		WriteConsoleOutputCharacter(hConsole, screen, iScreenWidth * iScreenHeight, { 0,0 }, &dwBytesWritten);
	}

	return 0;
}

