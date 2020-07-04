/* QUESTION: Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 

Example:

Input: n = 10
Output: 12
Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
*/

class Solution {
public:
    int nthUglyNumber(int n) {
         int p2=0,p3=0,p5=0;
        vector<int> dp;
        dp.push_back(1);
        int i=1;
        while(i<n){
            dp.push_back(min({2*dp[p2],3*dp[p3],5*dp[p5]}));
            if(dp[i]==dp[p2]*2)
                p2++;
            if(dp[i]==dp[p3]*3)
                p3++;
            if(dp[i]==dp[p5]*5)
                p5++;
            i++;
        }
        return dp[n-1];
    }
};
