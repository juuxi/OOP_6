#ifndef POLINOM_H
#define POLINOM_H

#include "array.h"

enum EPrintMode
{
    EPrintModeClassic,
    EPrintModeCanonic,
};

template <class number>
class TPolinom
{
    EPrintMode printMode;
    TArray<number> roots;
    TArray<number> coefficients;
    int N;
public:
    TPolinom();
    TPolinom(number, number*, int);
    template <class T>
    friend ostream& operator<< (ostream&, TPolinom<T>&);
    template <class T>
    friend QString& operator<< (QString&, TPolinom<T>&);
    template <class T>
    friend istream& operator>> (istream&, TPolinom<T>&);
    void set_print_mode (EPrintMode);
    number count_value (number);
    void change_an (number);
    void change_root (number, size_t);
    void change_size (int);
    int get_size();
private:
    void count_coefficients(number);
};

#include <math.h>

template <class number>
TPolinom<number>::TPolinom()
{
    N = 0;
    printMode = EPrintModeClassic;
}

template <class number>
TPolinom<number>::TPolinom(number _an, number* _roots, int _size)
{
    N = _size;
    roots.change_size(N);
    coefficients.change_size(N+1);
    for (int i = 0; i < N; i++)
        roots[i] = _roots[i];
    count_coefficients(_an);
    printMode = EPrintModeClassic;
}

template <class number>
void TPolinom<number>::count_coefficients (number _an)

{
    for (int i = 0; i < N; i++)
        coefficients[i] = 0;
    coefficients[N] = _an;
    coefficients[1] = 1;
    coefficients[0] = -roots[0];
    for (int k = 2; k <= N; k++)
    {
        coefficients[k] = coefficients[k-1];
        for (int i = k-1; i > 0; i--)
            coefficients[i] = coefficients[i-1] - coefficients[i] * roots[k-1];
        coefficients[0] = -coefficients[0] * roots[k-1];
    }
    for (int i = 0; i <= N; i++)
          coefficients[i] = coefficients[i] * _an;
}

template <class number>
void TPolinom<number>::set_print_mode (EPrintMode _printMode)
{
    printMode = _printMode;
}

template <class number>
ostream& operator<< (ostream& os, TPolinom<number>& pol)
{
    if (pol.printMode == EPrintModeCanonic)
    {
        for (int i = pol.N; i > 0; i--)
            os << pol.coefficients[i] << " x^" << i << " + ";
        os << pol.coefficients[0] << std::endl;
    }
    else
    {
        os << pol.coefficients[pol.N] << " * ";
        for (int i = 0; i < pol.N - 1; i++)
            os << "(x - " << pol.roots[i] << ") * ";
        os << "(x - " << pol.roots[pol.N - 1] << ")" << std::endl;
    }
    return os;
}

template <class number>
QString& operator<< (QString& os, TPolinom<number>& pol)
{
    if (pol.printMode == EPrintModeCanonic)
    {
        for (int i = pol.N; i > 0; i--)
        {
            os << pol.coefficients[i];
            os += " x^";
            os += QString().setNum(i);
            os += " + ";
        }
        os << pol.coefficients[0];
        os += "\n";
    }
    else
    {
        os << pol.coefficients[pol.N];
        os += " * ";
        for (int i = 0; i < pol.N - 1; i++)
        {
            os += "(x - ";
            os << pol.roots[i];
            os +=  ") * ";
        }
        os += "(x - ";
        os << pol.roots[pol.N - 1];
        os += ")";
        os += "\n";
    }
    return os;
}

template <class number>
istream& operator>> (istream& is, TPolinom<number>& pol)
{
    is >> pol.coefficients[pol.N];
    for (int i = 0; i < pol.N; i++)
        is >> pol.roots[i];
    pol.count_coefficients(pol.coefficients[pol.N]);
    return is;
}

template <class number>
number TPolinom<number>::count_value (number _point)
{
    number val = coefficients[N];
    for (int i = 0; i < N; i++)
        val = (_point - roots[i]) * val;
    return val;
}

template <class number>
void TPolinom<number>::change_an(number _an)
{
    coefficients[N] = _an;
    count_coefficients(coefficients[N]);
}

template <class number>
void TPolinom<number>::change_root(number _new_root, size_t _index)
{
    roots[_index] = _new_root;
    count_coefficients(coefficients[N]);
}

template <class number>
void TPolinom<number>::change_size(int new_size)
{
    roots.change_size(new_size);
    coefficients.change_size(new_size + 1);
    N = new_size;
}

template <class number>
int TPolinom<number>::get_size()
{
    return N;
}


#endif // POLINOM_H
