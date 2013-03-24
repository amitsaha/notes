/*normal_demo.c*/

/* Using the Uniform Random number Generator*/

#include <random/normal.h>
#include <blitz/array.h>

using namespace blitz;
using namespace ranlib;

Array<double,1> randompool_unform(int n);

/* Returns a pool of n uniformly distributed random numbers*/
Array<double,1> randompool_uniform(int n)
{
  /* Uniform Normal distribution with mean 0 and standarad deviation 1*/
  Normal<double> rnd_normal(0,1);

  /* Setup the seed*/
  rnd_normal.seed((unsigned int)time(0));

  /* Declare an array and create the pool*/
  Array<double,1> rnd_array(n);
  for(int i=0;i<n;i++)
    rnd_array(i) = rnd_normal.random();   

  /* return */
  return rnd_array;
}


int main()
{
  int n;
  cout << "Number of unifromly distributed random integers? :: " ;
  cin >> n;

  Array<double,1> rnd_array;
  rnd_array.resize(n);

  /* Call the random pool*/
  rnd_array = randompool_uniform(n);
  
  /* print each element individually to facilitate
     plotting*/
  for(int i=0;i<n;i++)
    cout << rnd_array(i) << endl;
  return 0;  
    
}

