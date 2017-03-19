#include <iostream>

void printBoard(char mark[]);
bool winner(char mark[], char piece);
bool isDraw(char mark[]);
bool keepPlaying();

int main()
{

	do
	{
		char mark[9] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
		bool turn = true;
		int input;
		
		printBoard(mark);

		do
		{
			if (turn)
				std::cout << std::endl << "Player 1: ";
			else
				std::cout << std::endl << "Player 2: ";

			while (!(std::cin >> input) || true)
			{
				if (!(input < 0 || input > 9))
				{
					if (mark[input - 1] != 'X' || mark[input - 1] != 'O')
						break;
				}

				if (std::cin.fail())
				{
					std::cin.clear();
					std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
				}
			}

			if (turn)
				mark[input - 1] = 'X';
			else
				mark[input - 1] = 'O';

			turn = !turn;
			printBoard(mark);
		} while (!winner(mark, !turn ? 'X' : 'O') && !isDraw(mark));

		if (isDraw(mark))
			std::cout << "Game ends in draw!" << std::endl;
		else
			std::cout << std::endl << "Player " << turn + 1 << " wins!" << std::endl;
		
		system("PAUSE");
	} while (keepPlaying());

	return 0;
}

void printBoard(char mark[])
{
	system("CLS");

	std::cout << "Tic Tac Toe" << std::endl << std::endl;

	std::cout << "   |   |   " << std::endl;
	std::cout << " " << mark[0] << " | " << mark[1] << " | " << mark[2] << std::endl;
	std::cout << "___|___|___" << std::endl;

	std::cout << "   |   |   " << std::endl;
	std::cout << " " << mark[3] << " | " << mark[4] << " | " << mark[5] << std::endl;
	std::cout << "___|___|___" << std::endl;

	std::cout << "   |   |   " << std::endl;
	std::cout << " " << mark[6] << " | " << mark[7] << " | " << mark[8] << std::endl;
	std::cout << "   |   |   " << std::endl;
}

bool winner(char mark[], char piece)
{
	if (mark[0] == piece && mark[1] == piece && mark[2] == piece) //Row one
		return true;
	else if (mark[3] == piece && mark[4] == piece && mark[5] == piece) //Row two
		return true;
	else if (mark[6] == piece && mark[7] == piece && mark[8] == piece) //Row three
		return true;
	else if (mark[0] == piece && mark[4] == piece && mark[8] == piece) //Diagnol '\'
		return true;
	else if (mark[6] == piece && mark[4] == piece && mark[2] == piece) //Diagnol '/'
		return true;
	else if (mark[0] == piece && mark[3] == piece && mark[6] == piece) //Column one
		return true;
	else if (mark[1] == piece && mark[4] == piece && mark[7] == piece) //Column two
		return true;
	else if (mark[2] == piece && mark[5] == piece && mark[8] == piece) //Column three
		return true;
	else
		return false;
}

bool isDraw(char mark[])
{
	if (!winner(mark, 'X') || !winner(mark, 'O'))
	{
		for (int i = 0; i < 9; i++)
		{
			if (mark[i] != 'X' && mark[i] != 'O')
				return false;
		}
		return true;
	}
	return false;
}

bool keepPlaying()
{
	std::cout << "Play again? [Y]es or [N]o: ";

	char input;
	std::cin >> input;
	input = toupper(input);

	if (input == 'Y')
		return true;
	else if (input == 'N')
		return false;
	else
		keepPlaying();
}