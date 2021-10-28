// C++ pgm displays symmetric matrix given any elements in an array.
#include <iostream>
using namespace std;

class Symmetric
{
private:
    int *A, n, x;

public:
    Symmetric(int n);
    void create(int n);
    void set(int i, int j, int x);
    int get(int i, int j);
    void display();
    ~Symmetric();
};

// creates the mat. acc. to dimensions.
Symmetric::Symmetric(int n)
{
    this->n = n;
    A = new int[n * (n + 1) / 2];
}

// get the elements by user.
void Symmetric::create(int n)
{
    this->n = n;
    cout << "Enter the elements for " << n << "x" << n << " matrix: " << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> x;
            set(i, j, x);
        }
    }
}

// set the elements in matrix at proper index.
void Symmetric::set(int i, int j, int x)
{
    if (i >= j)
    {
        // row major mapping
        A[i * (i - 1) / 2 + j - 1] = x;
    }
    else
        // column major mapping
        A[j * (j - 1) / 2 + i - 1] = x;
}

int Symmetric::get(int i, int j)
{
    if (i >= j)
    {
        // row major mapping
        return A[i * (i - 1) / 2 + j - 1];
    }
    else
    {
        // column major mapping
        return A[j * (j - 1) / 2 + i - 1];
    }
}

// display the matrix elements in proper manner.
void Symmetric::display()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i >= j)
            {
                cout << A[(i * (i - 1)) / 2 + (j - 1)] << " ";
            }
            else
            {
                cout << A[j * (j - 1) / 2 + i - 1] << " ";
            }
        }
        cout << endl;
    }
}

// destructor
Symmetric::~Symmetric()
{
    delete[] A;
}

int main()
{
    int n;
    cout << "Enter the dimension for matrix: ";
    cin >> n;

    Symmetric S1(n);
    S1.create(n);
    S1.display();
    // get the elements at specific index function;
    // for 3x3 matrix below, for others u can edit!
    cout << "The element at row 3 & column 2 is: " << S1.get(3, 2) << endl;
    cout << "The element at row 2 & column 1 is: " << S1.get(2, 1) << endl;

    return 0;
}