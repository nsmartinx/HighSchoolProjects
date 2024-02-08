#include <iostream>
#include <vector>

using namespace std;

struct Move
{
	int jumpCount;
	int startPos;
	int endPos;
	vector<int> jumpedPieces;
};

struct Piece
{
	bool isKing = false;
	int colour; //1 = black 2 = white;
	int space;
	vector<int> moves;

	Piece(int colour, int space) : colour(colour), space(space) {}
};

void printBoard(int* board)
{
	for (size_t i = 0; i < 32; i += 8)
	{
		for (size_t j = 0; j < 4; j++)
		{
			cout << " " << board[i + j];
		}
		cout << endl;
		for (size_t j = 0; j < 4; j++)
		{
			cout << board[i + j + 4] << " ";
		}
		cout << endl;
	}
}

//vector<Move> findAvailableMoves(int* board)
//{
	
//}

int main()
{
    int board[32];//0 = no piece, 1 = black, 2 = white
	for (size_t i = 0; i < 12; i++)
	{
		board[i] = 1;
	}
	for (size_t i = 12; i < 20; i++)
	{
		board[i] = 0;
	}
	for (size_t i = 20; i < 32; i++)
	{
		board[i] = 2;
	}
	printBoard(board);

	vector<Piece> pieces;
	for (size_t i = 0; i < 24; i++)
	{
		int colour = 2;
		if (i < 12)
			colour = 1;
		int space = i;
		if (i >= 12)
			space += 8;
		pieces.push_back(Piece(colour, space));
	}
}
