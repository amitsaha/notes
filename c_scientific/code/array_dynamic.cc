/*array_blitz.cc*/

/* Dynamic Array objects using Blitz++*/

#include <blitz/array.h>

using namespace blitz;

int main()
{
  int n;

 
  cout << ">>>> Dynamic 1-D Array Demonstration >>>>" << endl << endl;

  Array<float,1> a;
  cout << "Enter the number of elements:: ";
  cin >> n;

  /* Resize the array */
  a.resize(n);

  /* Input the array*/
  for(int i=0;i<n;i++)
    cin >> a(i); /* uses the  () operator to refer each element*/
  
  cout << "a = " << a <<endl << endl;


  cout << ">>>> Dynamic 2-D Array Demonstration >>>>" << endl << endl;

  Array<float,2> A;
  cout << "Enter the number of elements in the two dimensions:: ";
  int r,c;
  cin >> r >> c;

  /* Resize the matrix */
  A.resize(r,c);

  /* Input the array*/
  for(int i=0;i<r;i++)
    {
      for(int j=0;j<c;j++)
	cin >> A(i,j); /* uses the  () operator to refer each element*/
    }
  
  cout << "A = " << A <<endl << endl;


  return 0;
}
