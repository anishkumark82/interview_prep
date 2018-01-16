/*
5.1 Insertion: You are given two 32-bit numbers, Nand M, and two bit positions, i and
j. Write a method to insert Minto N such that M starts at bit j and ends at bit i. You
can assume that the bits j through i have enough space to fit all of M. That is, if
M = 10011, you can assume that there are at least 5 bits between j and i. You would not, for
example, have j = 3 and i = 2, because M could not fully fit between bit 3 and bit 2.
*/

#include <iostream>
using namespace std;
int bitwise_insert(int n, int m, int i, int j) // i < j --> J towards MSB
{
    // if i = 2 and j = 4
    // create a mask remaining 24 MSB onces 1110 0011
    // create a mask first mask_1 = 1110 0000
    int mask_1 = ~0;
    mask_1 <<= (j+1);
    // create the second part of the mask_2 = 0000 0011
    int mask_2 = (1 << i)-1;

    int mask = mask_1 | mask_2;

    int n_cleared = n & mask;

    int m_shifted = m << i;
    return (n_cleared | m_shifted);
}
int main()
{
    int n = 1024;
    int m = 19;
    int i = 2;
    int j = 6;
    cout<<bitwise_insert(n, m, i, j);
    return 0;
}
