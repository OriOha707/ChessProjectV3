#include "Pawns.h"

#include "Tool.h"

Pawns::Pawns(bool color, Point chise) : Tool(color, chise)
{}
Pawns::Pawns() : Tool()
{}
Pawns::~Pawns()
{

}

int Pawns::canMove(Point toMove, Tool* board[8][8])
{
	//checkIfchessMat(toMove, board);
	if (SOLDIER_CANT_MOVE)
	{
		return BAD_MOV;
	}
	if (board[toMove.getY()][toMove.getX()] != nullptr && board[toMove.getY()][toMove.getX()]->getColor() != this->getColor() && board[toMove.getY()][toMove.getX()] == board[this->getPlace().getY() + 1][this->getPlace().getX() + 1])
	{
		return OK_MOV;
	}
	if (board[toMove.getY()][toMove.getX()] != nullptr && board[this->getPlace().getY() - 1][this->getPlace().getX()] != nullptr && (board[toMove.getY()][toMove.getX()] == board[this->getPlace().getY() + 1][this->getPlace().getX()] || board[toMove.getY()][toMove.getX()] == board[this->getPlace().getY() - 1][this->getPlace().getX()]))
	{
		return BAD_MOV_FULL_DST;
	}
	return 0;
}