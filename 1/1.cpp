#include <iostream>
using namespace std;
const int N = 4;

double func(double x)
{
    return (1 / x);
}

double f(double x, int i)
{
    if (i == 0)
        return 1;
    else if (i == 1)
        return x;
    else if (i == 2)
        return (pow(x, 2));
    else
        return 0;
}

void Gauss(double A[N - 1][N], double X[N - 1])
{
    int i, j, k, ind;
    double f, max, obm;
    for (i = 0; i < N - 2; i++)
    {
        ind = i;
        for (j = i + 1; j < N - 1; j++)
        {
            max = abs(A[i][i]);
            if (max < abs(A[j][i]))
            {
                max = abs(A[j][i]);
                ind = j;
            }
        }
        if (ind != i)
        {
            for (j = 0; j < N; j++)
            {
                obm = A[i][j];
                A[i][j] = A[ind][j];
                A[ind][j] = obm;
            }
        }

        for (j = i + 1; j < N - 1; j++)
        {
            f = A[j][i] / A[i][i];
            for (k = 0; k < N; k++)
                A[j][k] = -(f * A[i][k]) + A[j][k];
        }
    }

    for (i = 0; i < N - 1; i++)
    {
        for (j = 0; j < N; j++)
            cout << " " << A[i][j] << "\t";
        cout << endl;
    }

    for (i = N - 2; i >= 0; i--)
    {
        f = A[i][N - 1];
        for (j = i + 1; j < N - 1; j++)
            f -= A[i][j] * X[j];
        X[i] = f / A[i][i];
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int i, j, k;
    double x[N], y[N], C[N - 1][N] = { 0 }, A[N - 1], sum;

    cout << " x\t| y" << endl << "________|________" << endl;
    for (i = 0; i < N; i++)
    {
        x[i] = 0.5 + 0.5 * i;
        y[i] = func(x[i]);
        cout << " " << x[i] << "\t| " << y[i] << endl;
    }

    for (i = 0; i < N - 1; i++)
    {
        for (j = 0; j < N; j++)
        {
            for (k = 0; k < N; k++)
            {
                if (j == (N - 1))
                    C[i][j] += y[k] * f(x[k], i);
                else
                    C[i][j] += f(x[k], i) * f(x[k], j);
            }
            cout << " " << C[i][j] << "\t";
        }
        cout << endl;
    }

    cout << endl << " СЛАУ:" << endl;
    Gauss(C, A);
    cout << endl << " Коэффициенты:" << endl;
    for (i = 0; i < N - 1; i++)
        cout << " " << A[i] << endl;
    return 0;
}