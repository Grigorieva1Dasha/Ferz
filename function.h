#pragma once

struct coordinates
{
	int x, y;
};

bool readQueens(const char *fileName, coordinates *q);
bool isThreaten(coordinates q1, coordinates q2);

