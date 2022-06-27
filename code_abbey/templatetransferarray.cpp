template< class T>
int transfer(T* from, T* to, int size)
{
	for (int i = 0; i < size; i++)
		to[i] = from[i];
	return size;
}