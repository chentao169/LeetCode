/*
http://oj.leetcode.com/problems/generate-parentheses/

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"

*/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string curr="";
        help(0, 0, n, curr, result);
        return result;
    }
    
    void help(int lparen, int rparen, int n, string &curr, vector<string> &result){
        if(lparen == n && rparen == n){
            result.push_back(curr);
            return;
        }
        if(lparen < n){
            curr += "(";
            help(lparen+1, rparen, n, curr, result);
            curr.erase(curr.length()-1);
        }
        
        if(rparen < lparen){
            curr += ")";
            help(lparen, rparen+1, n, curr, result);
            curr.erase(curr.length()-1);
        }
    }
};
