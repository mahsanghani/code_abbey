//template stack implementation

template <class TYPE>
class stack {
public:
	explicit stack(int size = 100)
		: max_len(size), top(EMPTY), s(new TYPE[size])
	{
		assert(s != 0);
	}
	~stack() { delete[]s; }
	void  reset() { top = EMPTY; }
	void  push(TYPE c) { s[++top] = c; }
	TYPE  pop() { return s[top--]; }
	TYPE  top_of()const { return s[top]; }
	bool  empty()const { return top == EMPTY; }
	bool  full()const { return top == max_len - 1; }
private:
	enum { EMPTY = -1 };
	TYPE*  s;
	int    max_len;
	int    top;
};