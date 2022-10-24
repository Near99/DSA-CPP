#include <iostream>

using namespace std;

int main()
{
    /**
     * NOT (~), which flips the bits of the number. e.g. ~0 = 1, ~1 = 0
     * flips 101 to get 010 which is 2 but due to the what the fuck two's
     * complement, the result in this unary operation will be -(n+1) which
     * gives us -6.
     */
    int n = 5;
    cout << ~n << endl; // -6

    /**
     * AND (&), binary operator compares operands' bits one by one, returns
     * 1 if and only if two bits are both 1, otherwise returns 0. 
     * e.g. 0101 & 0011 = 0001
     * 
     * 1 & 1 = 1
     * 1 & 0 = 0
     * 0 & 1 = 0
     * 0 & 0 = 0
     */
    int a = 5, b = 3;
    cout << (a & b) << endl; // 1

    /**
     * OR (|), binary operator compares operands bits one by one, returns 1 
     * if at least one of the operands is 1, otherwise returns 0. In other
     * words, only two 0s will get an 0 back.
     * e.g. 0111 | 1001 = 1111
     * 
     * 1 | 1 = 1 
     * 1 | 0 = 1
     * 0 | 1 = 1
     * 0 | 0 = 0
     */
    int j = 7, k = 9;
    cout << (j | k) << endl; // 15

    /**
     * XOR (^), binary operator compares operaneds bits one by one, returns 1
     * if and only if just one of the operands is 1, otherwise returns 0.
     * e.g.  0100 | 1000 = 1100
     * 
     * 1 ^ 1 = 0
     * 1 ^ 0 = 1
     * 0 ^ 1 = 1
     * 0 ^ 0 = 0
     */
    int r = 4, t = 8;
    cout << (r ^ t) << endl; // 12

    /**
     * Right Shift (>>), shifts bits to the right by kth position,
     * can be used as division.
     * e.g. 1 1 1 1 0
     *      0 1 1 1 1
     */
    int p = 30;
    cout << (p >> 1) << endl; // 15

    /**
     * Left Shift (<<), shits bits to the left by kth position,
     * can be used as multiplication.
     * e.g. 0 0 0 1 0 1
     *      1 0 1 0 0 0
     */
    int y = 5;
    cout << (y << 3) << endl; // 40

    return 0;
}
