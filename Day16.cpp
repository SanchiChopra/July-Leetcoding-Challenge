/* QUESTION: Implement pow(x, n), which calculates x raised to the power n (xn).

Example 1:

Input: 2.00000, 10
Output: 1024.00000
Example 2:

Input: 2.10000, 3
Output: 9.26100
Example 3:

Input: 2.00000, -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25
*/

class Solution {
public:
    double myPow(double x, int n) {
        
        if(n==0)
            return 1;
        bool f=0;//to check if the n is negative 
        if(n<0)
            f=1;
        
        n=abs(n);
        double ans=1;
        while(n>1)
        {
            if(n&1)//if the leftmost bit is 1 we will multiply ans by x
            {
                ans=ans*x;
            }
            n=n>>1;
            x=x*x; //for each bit we sqaure the x
            
        }
        ans=ans*x;
        if(f==1)
        return 1/ans;
        else
            return ans;
        
    }
};
