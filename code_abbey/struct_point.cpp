#include <iostream>
using namespace std;


// Compute an average point

struct point { double x, y; };
point average(const point* d, int size)
{
	point sum = { 0, 0 };

	for (int i = 0; i < size; i++) {
		sum.x += d->x;
		sum.y += d->y;
		d++;      	// d is iterator accessing each point
	}
	sum.x = sum.x / size;
	sum.y = sum.y / size;
	return sum;
}

int main()
{
	point data[5] = { {1.0, 2.0}, {1.0, 3.3},
					{5.1, 0.5}, {2.0, 2.0}, {0, 0} };
	point average_point;

	average_point = average(data, 5);
	cout << "average point = (" << average_point.x
		<< ", " << average_point.y << ") " << endl;
}