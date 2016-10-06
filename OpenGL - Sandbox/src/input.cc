/*
 * input.cc
 *
 *  Created on: Sep 15, 2016
 *      Author: phwhitin
 */

#include <Windows.h>
#include <iostream>
#include <math.h>

#define N 100
#define PI 3.14159265358979323846

using namespace std;

unsigned const int size[] = {900, 1600, 100};

/*int main(int argc, char** argv) {

	const int mid_x = size[0] / 2;
	const int mid_y = size[1] / 2;

	int posX = mid_x;
	int posY = mid_y + size[2];

	cout << '(' << posX << ',' << posY << ')' << endl;

	int i = 0;
	while (i < N) {

		SetCursorPos(posX, posY);

		posX = (int)cos((2 * PI * i)/N);
		posY = (int)sin((2 * PI * i)/N);

		posX *= size[2];
		posX += size[0];

		posY *= size[2];
		posY += size[1];

		i++;
	}
	/*do {



		value = GetCursorPos(tp);
	} while (value == 1);*/

	//cout << value << endl;
	//cout << '(' << tp->x << ',' << tp->y << ')' << endl;

} */
