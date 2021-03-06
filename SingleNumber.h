/*
Single Number : http://oj.leetcode.com/problems/single-number/
Given an array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

*/

class Solution {
public:
    int singleNumber(int A[], int n) {
        int result = A[0] ;
        int i= 1;
        while(i < n) result ^= A[i++];
        return result;
    }
};
