
/*
Program to print Right Lower Triangle of given height n
Example:
        *
       **
      ***
     ****
    *****
   ******
  *******
 ********
 where height(n) of triangle is 8.
*/

#include <iostream>
using namespace std;

int main()
{
    int i, j, n;
    cout << "Enter number of rows/height of triangle: ";
    cin >> n;
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= n; j++)
        {
            if (j > n - i)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}