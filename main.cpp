#include <iostream>
#include <fstream>
#include <locale.h>
#include "function.h"

using namespace std;

void writePair(ofstream &out, coordinates q1, coordinates q2)
{
	char qv1 = (q1.x - 1) + 'a';
	char qv2 = (q2.x - 1) + 'a';
	out << qv1 << q1.y << '-' << qv2 << q2.y << endl;
}

int main(void)
{
	void writePair(ofstream &out, coordinates q1, coordinates q2);
	setlocale(LC_ALL, "Russian");
	coordinates *q = new coordinates[8];
	ofstream in("in.txt");
	ofstream out("out.txt");
	for (int i = 0; i < 8; i++)
	{
		for (int j = i + 1; j < 8; j++)
		{
			if (isThreaten(q[i], q[j]))
				writePair(out, q[i], q[j]);
		}
	}
	in.close();
	out.close();
	system("pause");
	return 0;
}