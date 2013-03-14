/*array_demo.cc*/
/* Simple demonstration of using Array 
   in Blitz++*/

#include <blitz/array.h>

using namespace blitz;

int main()
{

 
  cout << ">>>> 1-D Array Demonstration >>>>" << endl << endl;


  Array<float,1> a(5);
  a=1,2,3,4,5;
  cout << "a = " << a <<endl << endl;

  Array<float,1> b(5);
  b=2,1,3,4,1;
  cout << "b = " << b <<endl << endl;

  cout << " >> Basic Arithmetic Operations >>" << endl << endl;

  Array<float,1> c(5);
  c = a+b;
  cout << "c = a+b = " << c <<endl << endl;

  c = a*b;
  cout << "c = a*b = " << c <<endl << endl;
  
  c = a/b;
  cout << "c = a/b = " << c <<endl << endl;

  cout << ">>>> 2-D Array Demonstration >>>>" << endl << endl;

  Array<float,2> A(3,3);
  A = 1, 2, 3,
    3, 5, 1,
    1, 1, 4;

  cout << "A = " << A << endl;

    Array<float,2> B(3,3);
  B = 1, 2, 3,
    3, 5, 1,
    1, 1, 4;

  cout << "B = " << B << endl; 

    cout << " >> Basic Arithmetic Operations >>" << endl << endl;

  Array<float,2> C(3,3);
  C = A+B;
  cout << "C = A+B = " << C <<endl << endl;

  C = A*B;
  cout << "C = A*B = " << C <<endl << endl;
  
  C = A/B;
  cout << "c = A/B = " << C <<endl << endl;

  return 0;
}
