// C++ pgm to print diagonal matrix.
#include <iostream>
using namespace std;

class DiagonalMatrix
{
private:
    int *A, n;

public:
    DiagonalMatrix(int n)
    {
        this->n = n;
        A = new int(n);
    };
    void set(int i, int j, int x);
    int get(int i, int j);
    void display();

    ~DiagonalMatrix();
};

// Here, i & j denotes the position where element should get inserted!
void DiagonalMatrix::set(int i, int j, int x)
{
    // condition to fill elements in diagonal matrix.
    if (i == j)
    {
        // inserting at proper index.
        A[j - 1] = x;
    }
}

// function used to fetch elements at specific index.
int DiagonalMatrix::get(int i, int j)
{
    if (i == j)
    {
        return A[j - 1];
    }
    return 0;
}

// displays diagonal matrix.
void DiagonalMatrix::display()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                cout << A[i] << " ";
            }
            else
            {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}

// destructor
DiagonalMatrix::~DiagonalMatrix()
{
    delete[] A;
}

int main()
{
    // pass dimansions
    DiagonalMatrix DM(4);
    // pass the values according to dimensions.
    DM.set(1, 1, 5);
    DM.set(2, 2, 6);
    DM.set(3, 3, 7);
    DM.set(4, 4, 8);
    DM.display();
    //cout<<DM.get(4,4);

    return 0;
}