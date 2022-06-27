//Overloading functions

#include <iostream>
using namespace std;


// Overloading functions

class rational {
public:
   rational(int n = 0) : a(n), q(1) { }
   rational(int i, int j) : a(i), q(j) { }
   rational(double r) : a(static_cast<long>
                         (r * BIG)), q(BIG) { }
   void  print() const { cout << a << " / " << q; }
   operator double() 
              { return static_cast<double>(a) / q; }
   friend ostream& operator<<(ostream& out, const rational& x);
   friend istream& operator>>(istream& in, rational& x);
   friend bool operator>(rational w, rational z);
private:
   long  a, q;
   enum { BIG = 100 };
};



ostream& operator<<(ostream& out, const rational& x)
{
    return (out << x.a << " / " << x.q << '\t');
}

istream& operator>>(istream& in, rational& x)
{
   return (in >> x.a >> x.q);
}


bool operator>(rational w, rational z)
{ 
   return (static_cast<double>(w.a) / w.q >            static_cast<double>(z.a) / z.q); 
}


inline int     greater(int i, int j) 
      { return (i > j ? i : j); }

inline double  greater(double x, double y)
      { return (x > y ? x : y); }

inline rational greater(rational w, rational z)
      { return (w > z ? w : z); }

int main()
{
   int     i = 10, j = 5;
   float   x = 7.0;
   double  y = 14.5;
   rational w(10), z(3.5), zmax;

   cout << "\ngreater(" << i << ", " << j << ") = "
        << greater(i, j);
   cout << "\ngreater(" << x << ", " << y << ") = "
        << greater(x, y);
   cout << "\ngreater(" << i << ", ";
   z.print();
   cout << ") = "
        << greater(static_cast<rational>(i), z);
   zmax = greater(w, z);
   cout << "\ngreater("; 
   w.print();
   cout << ", ";
   z.print();
   cout << ") = ";
   zmax.print();
   cout << endl;
}