/*
http://oj.leetcode.com/problems/3sum/

Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets.
    For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)

*/

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        sort(num.begin(), num.end());
        vector<vector<int> > result;
        
        for(int i=0; i < num.size() && num[i] <= 0; i++){
            if(i>0 && num[i] == num[i-1]) continue;   // avoid duplicates
            
            int front = i+1;
            int rear = num.size()-1;
            while(front < rear){
                if( num[front] + num[rear] + num[i] == 0){
                    vector<int> tmp(3, 0);
                    tmp[0] = num[i];
                    tmp[1] = num[front];
                    tmp[2] = num[rear];
                    result.push_back(tmp);
                    front++;
                    rear--;
                    while (front < rear && num[front] == num[front-1]) front++;  // avoid duplicates
                    while (front < rear && num[rear] == num[rear+1]) rear--;  // avoid duplicates
                    
                }else if( num[front] + num[rear] + num[i] < 0)   front++;
                else rear --;
            }
        }
        return result;
    }
};
