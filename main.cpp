#include <iostream>
#include<windows.h>
using namespace std;
char matrix[3][3] = { '1' , '2' , '3' , '4' , '5' , '6' , '7' , '8' , '9' };
int C;
char player = 'X';
void Print()
{
	system("cls");
	cout << "\n\t\t\t\t " << "Tic Tac Toe Game" << endl << endl;

	cout << "\t\t\t\t" << "     |     |     " << endl;
	cout << "\t\t\t\t" << "  " << matrix[0][0] << "  |  " << matrix[0][1] << "  |  " << matrix[0][2] << endl;
	cout << "\t\t\t\t" << "_ _ _|_ _ _|_ _ _" << endl << "\t\t\t\t" << "     |     |     " << endl;
	cout << "\t\t\t\t" << "  " << matrix[1][0] << "  |  " << matrix[1][1] << "  |  " << matrix[1][2] << endl;
	cout << "\t\t\t\t" << "_ _ _|_ _ _|_ _ _" << endl << "\t\t\t\t" << "     |     |     " << endl;
	cout << "\t\t\t\t" << "  " << matrix[2][0] << "  |  " << matrix[2][1] << "  |  " << matrix[2][2] << endl;
	cout << "\t\t\t\t" << "     |     |     " << endl << endl;

}

void Insert()
{
	int f;
	cout << "\t\t\t       It's player " << player << "'s turn" << endl;
	cout << "Choose a field: ";
	cin >> f;
	for (int i = 0; i<3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (f == (i * 3) + (j + 1))
			{
				if (matrix[i][j] != 'O' && matrix[i][j] != 'X')
					matrix[i][j] = player;
				else
				{
					cout << "\t\t     This field is in use, choose another field!" << endl << endl;
					Insert();
				}
			}
		}
	}
}
void ChangePlayer()
{
	if (player == 'X')
		player = 'O';
	else
		player = 'X';
}
char Win()
{
	if ((matrix[0][0] == 'X' && matrix[0][1] == 'X' && matrix[0][2] == 'X')
		|| (matrix[1][0] == 'X' && matrix[1][1] == 'X' && matrix[1][2] == 'X')
		|| (matrix[2][0] == 'X' && matrix[2][1] == 'X' && matrix[2][2] == 'X')
		|| (matrix[0][0] == 'X' && matrix[1][0] == 'X' && matrix[2][0] == 'X')
		|| (matrix[0][1] == 'X' && matrix[1][1] == 'X' && matrix[2][1] == 'X')
		|| (matrix[0][2] == 'X' && matrix[1][2] == 'X' && matrix[2][2] == 'X')
		|| (matrix[0][0] == 'X' && matrix[1][1] == 'X' && matrix[2][2] == 'X')
		|| (matrix[2][0] == 'X' && matrix[1][1] == 'X' && matrix[0][2] == 'X'))
		return 'X';
	if ((matrix[0][0] == 'O' && matrix[0][1] == 'O' && matrix[0][2] == 'O')
		|| (matrix[1][0] == 'O' && matrix[1][1] == 'O' && matrix[1][2] == 'O')
		|| (matrix[2][0] == 'O' && matrix[2][1] == 'O' && matrix[2][2] == 'O')
		|| (matrix[0][0] == 'O' && matrix[1][0] == 'O' && matrix[2][0] == 'O')
		|| (matrix[0][1] == 'O' && matrix[1][1] == 'O' && matrix[2][1] == 'O')
		|| (matrix[0][2] == 'O' && matrix[1][2] == 'O' && matrix[2][2] == 'O')
		|| (matrix[0][0] == 'O' && matrix[1][1] == 'O' && matrix[2][2] == 'O')
		|| (matrix[2][0] == 'O' && matrix[1][1] == 'O' && matrix[0][2] == 'O'))
		return 'O';
	return '/';
}
int main()
{
	C = 0;
	Print();
	while (C <= 9)
	{
		C++;
		Insert();
		Print();
		if (Win() == 'X')
		{
			cout << "\t\t     Congrats, Player X! You are the WINNER!" << endl << endl;
			break;
		}
		else if (Win() == 'O')
		{
			cout << "\t\t     Congrats, Player O! You are the WINNER!" << endl << endl;
			break;
		}
		else if (Win() == '/' && C == 9)
		{
			cout << "\t\t\t\t  It's a Tie!" << endl << endl;
			break;
		}
		ChangePlayer();
	}
	system("pause");
	return 0;
}
