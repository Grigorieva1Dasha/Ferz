#include <iostream>
#include <fstream>
#include <locale.h>
#include "function.h"

using namespace std;

int readVert(ifstream &in)
{
	char ch;
	in >> ch;
	if (ch < 'a' || ch > 'h')
		return 0;
	return ch - 'a' + 1;
}

int readHories(ifstream &in)
{
	char ch;
	in >> ch;
	if (ch < '1' || ch > '8')
		return 0;
	return ch - '1' + 1;
}

bool readQueens(const char *fileName, coordinates *q)
{
	ifstream in("in.txt");
	if (!in.is_open())
		return false;
	for (int i = 0; i < 8; i++)
	{
		q[i].x = readVert(in);
		q[i].y = readHories(in);
		if (in.fail() || q[i].x == 0 || q[i].y == 0)
			return false;
	}
	return true;
}

bool isThreaten(coordinates q1, coordinates q2)
{
	return (q1.x == q2.x) || (q1.y == q2.y) ||
		(q1.x - q2.x == q1.y - q2.y) ||
		(q2.x - q1.x == q2.y - q1.y);
}