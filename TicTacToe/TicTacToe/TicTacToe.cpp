// TicTacToe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

class Board
{
public:
	string board[3][3] = { "_","_","_","_","_","_","_","_","_" };
	string falseBoard[3][3] = { "_","_","_","_","_","_","_","_","_" };
	int turn = 0;
	int falseTurn = 1;
	int count = 1;
	int valueA[3][3][10];

	void Display(string board[3][3]);
	void PlayerTurn(string player);
	void setValues(int across, int down, string player, string board[3][3]);
	int Win(string player, string board[3][3]);
	int RecursiveWinCheck();


};


class Turn
{
public:
	int turn = 0; //current turn 
	void NextTurn();

};

void Turn::NextTurn()
{
	turn = turn + 1;
}


void Board::Display(string board[3][3])
{
	cout << endl;
	cout << " " << "_" << board[0][0] << "_|_" << board[1][0] << "_|_" << board[2][0] << "_" << endl;
	cout << " " << "_" << board[0][1] << "_|_" << board[1][1] << "_|_" << board[2][1] << "_" << endl;
	cout << " " << "_" << board[0][2] << "_|_" << board[1][2] << "_|_" << board[2][2] << "_" << endl;
	cout << endl;

}
void Board::setValues(int across, int down, string player, string board[3][3])
{
	board[across][down] = player;
}
int Board::Win(string player, string board[3][3])
{
	for (size_t i = 0; i < 3; i++)
	{

		if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
		{
			//player win
			//return wins
			if (board != falseBoard)
			{
				cout << player << " wins" << endl;
			}
			if (player == "X")
			{
				return 10;
			}
			else
			{
				return -10;
			}
		}
		if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
		{

			//player win
			//return win
			if (board != falseBoard)
			{
				cout << player << " wins" << endl;
			}
			if (player == "X")
			{
				return 10;
			}
			else
			{
				return -10;
			}
		}
	}
	if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
	{
		//player win 
		if (board != falseBoard)
		{
			cout << player << " wins" << endl;
		}
		if (player == "X")
		{
			return 10;
		}
		else
		{
			return -10;
		}
	}
	if (board[2][0] == player && board[1][1] == player && board[0][2] == player)
	{

		//player win
		if (board != falseBoard)
		{
			cout << player << " wins" << endl;
		}
		if (player == "X")
		{
			return 10;
		}
		else
		{
			return -10;
		}
	}
	else if (board[0][0] != "_" && board[1][0] != "_" && board[2][0] != "_" && board[0][1] != "_" && board[1][1] != "_" && board[2][1] != "_" && board[0][2] != "_" && board[1][2] != "_" && board[2][2] != "_")
	{
		//Draw
		if (board != falseBoard)
		{
			cout << "Draw" << endl;
		}
		return 0;
	}
	return 2;
}
int Board::RecursiveWinCheck()
{

	string player;
	//int valueA[3][3];
	int valueWin;
	int valuef = 0;
	int valueX = 10;
	int valueO = -10;
	int place[2];
	//Display(falseBoard);
	
	if (turn%2 == 0 && board[1][1] == "_")
	{
		board[1][1] = "O";
		falseBoard[1][1] = "O";
		return 0;
	}
	

	for (int i = 0; i < 3; i++)
	{
		for (int I = 0; I < 3; I++)
		{
			//cout << i << I << " ";
			if (falseBoard[i][I] == "_")
			{
				if (falseTurn % 2 == 0)
				{
					player = "X";
				}
				else
				{
					player = "O";
				}

				falseBoard[i][I] = player;//set value of space
				//Display(falseBoard);


				valueWin = Win(player, falseBoard);
				if (valueWin != 2)
				{
					//Display(falseBoard);
					falseBoard[i][I] = "_";
					//Display(falseBoard);
					return valueWin;
				}

				falseTurn++;
				count++;
				//Display(falseBoard);
				valueA[i][I][count-1] = RecursiveWinCheck();
				//cout << valueA[i][I][count - 1] << endl;
				//cout << valueA[i][I][count] << "  " << i <<" "<< I << " " << count << endl;
				falseTurn++;
				count--;
				falseBoard[i][I] = "_";
			}

		}

	}

	if (count == 1)
	{
		//cout << "here" << endl;
		for (int c = 0; c < 3; c++)
		{
			for (int C = 0; C < 3; C++)
			{
				//cout << valueA[c][C][count] << ",";
				if (board[c][C] == "_")
				{
					//cout << valueA[c][C][count] << ",";
					if (valueX >= valueA[c][C][count])
					{
						//cout << valueA[c][C][count] << ">";
						valueX = valueA[c][C][count];
						place[0] = c;
						place[1] = C;
						//cout << valuef << place[0] << place[1] << endl;
					}
					
				}

			}

		}
		//cout << "F:" << valueX;
		
		board[place[0]][place[1]] = "O";
		falseBoard[place[0]][place[1]] = "O";
		for (size_t i = 0; i < 3; i++)
		{
			for (size_t I = 0; I < 3; I++)
			{
				for (size_t ii= 0; ii < 10; ii++)
				{
					valueA[i][I][ii] = NULL;
				}
			}

		}
	}
	else
	{
		for (int c = 0; c < 3; c++)
		{
			for (int C = 0; C < 3; C++)
			{
				if (falseTurn % 2 == 1)
				{
					//cout << endl;
					//cout << "O" << endl;
					//cout << valueA[c][C][count] << ",";
					if (valueA[c][C][count] >= -10 && valueA[c][C][count] <= 10)
					{
						if (valueX >= valueA[c][C][count])
						{
							//cout << valuef << ">" << valueA[c][C][count] << endl;
							valueX = valueA[c][C][count];
						}
						//cout << valueA[c][C][count] << ">";
					}
				}
				else
				{
					//cout << "X" << endl;
					//cout << valueA[c][C][count] << ",";
					if (valueA[c][C][count] >= -10 && valueA[c][C][count] <= 10)
					{
						if (valueO <= valueA[c][C][count])
						{
							//cout << valuef << "<" << valueA[c][C][count] << endl;
							valueO = valueA[c][C][count];
						}
						//cout << valueA[c][C][count] << "<";
					}
				}
			}

		}
		//cout << valuef << endl;
		if (falseTurn % 2 == 1)
		{
			//cout << "F:" << valueX << " T:O" <<endl;
			//Display(falseBoard);
			return valueX;

		}
		else
		{
			//cout << "F:" << valueO << " T:X" << endl;
			//Display(falseBoard);
			return valueO;

		}

	}
	return 0;
}
void Board::PlayerTurn(string player)
{
	int across;
	int down;
	string playerX = "X";
	cout << player << " turn" << endl;
	cout << "input the across from 0-2 starting from the left" << endl;
	cin >> across;
	cout << "input the down from 0-2 starting from the top" << endl;
	cin >> down;
	if (board[across][down] == "_")
	{
		setValues(across, down, player, board);
		setValues(across, down, player, falseBoard);
	}
	else
	{
		system("cls");
		Display(board);
		cout << "*** That space is already taken ***" << endl;
		PlayerTurn(player);
	}
}
int main()
{

	string board[3][3] = { "_","_","_","_","_","_","_","_","_" };
	string playerX = "X";
	string playerO = "O";
	string player;
	Turn turncount;
	Board Game;

	while (Game.Win(player, Game.board) == 2)
	{

		if (Game.turn % 2 == 1)
		{
			player = playerO;

		}
		else
		{
			player = playerX;
		}
		Game.turn++;
		system("cls");
		Game.Display(Game.board);
		if (player == "X")
		{
			Game.PlayerTurn(player);
		}
		else
		{
			for (size_t i = 0; i < 3; i++)
			{

				if (Game.board[i][0] == player && Game.board[i][1] == player && Game.board[i][2] == "_")
				{
					Game.board[i][2] = player;
				}
				if (Game.board[i][0] == player && Game.board[i][1] == "_" && Game.board[i][2] == player)
				{
					Game.board[i][1] = player;
				}
				if (Game.board[i][0] == "_" && Game.board[i][1] == player && Game.board[i][2] == player)
				{
					Game.board[i][0] = player;
				}
				if (Game.board[0][i] == player && Game.board[1][i] == player && Game.board[2][i] == "_")
				{
					Game.board[2][i] = player;
				}
				if (Game.board[0][i] == player && Game.board[1][i] == "_" && Game.board[2][i] == player)
				{
					Game.board[1][i] = player;
				}
				if (Game.board[0][i] == "_" && Game.board[1][i] == player && Game.board[2][i] == player)
				{
					Game.board[0][i] = player;
				}
				if (Game.board[2][0] == player && Game.board[1][1] == player && Game.board[0][2] == "_")
				{
					Game.board[0][2] = player;
				}
				if (Game.board[2][0] == player && Game.board[1][1] == "_" && Game.board[0][2] == player)
				{
					Game.board[1][1] = player;
				}
				if (Game.board[2][0] == "_" && Game.board[1][1] == player && Game.board[0][2] == player)
				{
					Game.board[2][0] = player;
				}
				if (Game.board[0][0] == player && Game.board[1][1] == player && Game.board[2][2] == "_")
				{
					Game.board[2][2] = player;
				}
				if (Game.board[0][0] == player && Game.board[1][1] == "_" && Game.board[2][2] == player)
				{
					Game.board[1][1] = player;
				}
				if (Game.board[0][0] == "_" && Game.board[1][1] == player && Game.board[2][2] == player)
				{
					Game.board[0][0] = player;
				}
			}
			
			Game.RecursiveWinCheck();
			
			
		}
		//Game.Win(player, Game.board);

	}

	Game.Display(Game.board);

	return 0;
}
