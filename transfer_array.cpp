//Simple array assignment function

int transfer(int from[], int to[], int size)
{
	for (int i = 0; i < size; i++)
		to[i] = from[i];
	return size;
}

int main()
{
	int a[10], b[10];
	double c[20], d[20];

	transfer(a, b, 10);            //works fine
	transfer(c, d, 20);            //syntax error
}