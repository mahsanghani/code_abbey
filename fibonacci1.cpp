unsigned fibonacci(unsigned n)
{
	unsigned sum = 0;
	for (unsigned i = 0, f0 = 0, f1 = 1; i < n - 1; ++i) {
		sum = f0 + f1;
		f0 = f1;
		f1 = sum;
	}
	if (n > 1)
		return sum;
	else
		return n;
}

// needs main(void) function