/*

The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Given two integers x and y, calculate the Hamming distance.

Note:
0 ≤ x, y < 231.

Example:

Input: x = 1, y = 4

Output: 2

Explanation:
1   (0 0 0 1)
4   (0 1 0 0)
       ?   ?

The above arrows point to positions where the corresponding bits are different.
*/

public class Solution {
// you need to treat n as an unsigned value
public int hammingWeight(int n) {
    int result = 0;
    while(n!=0){
        n = n & (n-1);
        result++;
    }
    return result;
}