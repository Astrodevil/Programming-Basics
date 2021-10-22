#include<iostream>
using namespace std;
class matrix
{
public:
  int i, j, n, x[10][10], y[20], n1;
  int input ()
  {
    cout << "Enter the order of matrix." << endl;
    cin >> n;
    cout << "Enter the elements of matrix." << endl;
    for (i = 0; i < n; i++)
      {
	for (j = 0; j < n; j++)
	  {
	    cin >> x[i][j];
	  }
      }
    return 0;
  }
  int process ()
  {
    n1 = 0;
    for (i = 0; i < n; i++)
      {
	for (j = 0; j < n; j++)
	  {
	    if (i + j >= n - 1)
	      {
		y[n1] = x[i][j];
		n1++;
	      }
	  }
      }
    return 0;
  }
  int output ()
  {
    cout << "The array of lower triangle is ";
    if (n%2!=0)
    {
    for (n1 = 0; n1 < n*2; n1++)
      {
	cout << "  " << y[n1];
      }
    }
    else
    {
     for (n1 = 0; n1 < (n+1)*2; n1++)
      {
	cout << "  " << y[n1];
      } 
    }
    return 0;
  }
};

int
main ()
{
  matrix obj;
  obj.input ();
  obj.process ();
  obj.output ();
  return 0;
}
