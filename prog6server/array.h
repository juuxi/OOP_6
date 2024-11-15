#ifndef TARRAY_H
#define TARRAY_H

#include "number.h"
#include <iostream>

using namespace std;

template <class number>
class TArray
{
    number* arr;
    int size;
public:
    TArray();
    TArray(int);
    friend istream& operator>> (istream&, TArray<number>&);
    friend ostream& operator<< (ostream&, TArray<number>&);
    number& operator[](int);
    void change_size(int);
    number count_average();
    number count_average_square();
    void change_element(int, number);
    void sort(bool);
    int get_size();
    ~TArray();
};

#include <math.h>

template <class number>
TArray<number>::TArray()
{
    arr = nullptr;
    size = 0;
}

template <class number>
TArray<number>::TArray(int numb)
{
    number* arr2 = new number[numb];
    arr = arr2;
    size = numb;
}

template <class number>
istream& operator>> (istream& is, TArray<number>& a)
{
    for (int i = 0; i < a.size; i++)
    {
        is>>a.arr[i];
    }
    return is;
}

template <class number>
ostream& operator<< (ostream& os, TArray<number>& a)
{
    for (int i = 0; i < a.size; i++)
    {
       os<<a.arr[i]<<" ";
    }
    os<<endl;
    return os;
}

template <class number>
number& TArray<number>::operator[](int i)
{
    return arr[i];
}

template <class number>
void TArray<number>::change_size(int new_size)
{
    number* arr2 = new number[new_size];
    if (new_size > size)
    {
        for (int i = 0; i < size; i++)
            arr2[i] = arr[i];
    }
    else
    {
        for (int i = 0; i < new_size; i++)
            arr2[i] = arr[i];
    }
    if(arr != nullptr)
        delete[] arr;
    arr = arr2;
    size = new_size;
}

template <class number>
number TArray<number>::count_average()
{
    number avg = 0;
    for (int i = 0; i < size; i++)
    {
        avg += arr[i];
    }
    return avg/size;
}

template <class number>
number TArray<number>::count_average_square()
{
    number avg = count_average();
    number sum_dif = 0;
    for (int i = 0; i < size; i++)
    {
        sum_dif += (avg-arr[i])*(avg-arr[i]);
    }
    number average_square = sqrt(sum_dif/(size-1));
    return average_square;
}

template <class number>
void TArray<number>::sort(bool reverse)
{
    for (int i = 0; i < size-1; i++)
    {
        for(int j = 0; j < size-1-i; j++)
        {
            if(!reverse)
            {
                if(arr[j] > arr[j+1])
                {
                    number temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }
            else
            {
                if(arr[j] < arr[j+1])
                {
                    number temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }
        }
    }
}

template <class number>
void TArray<number>::change_element(int index, number elem)
{
    arr[index] = elem;
}

template <class number>
int TArray<number>::get_size()
{
    return size;
}

template <class number>
TArray<number>::~TArray()
{
    if(arr != nullptr)
    {
        delete[] arr;
        arr = nullptr;
    }
}


#endif // TARRAY_H
