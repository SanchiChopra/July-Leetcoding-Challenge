/* QUESTION: Given a non-empty array of integers, return the k most frequent elements.

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>res;
        map<int,int>m;
        priority_queue<pair<int,int>>j;
        
        
        for(int i=0;i<nums.size();i++)
            m[nums[i]]++;
        
        for(auto i:m)
            j.push({i.second,i.first});
        
        for(int i=1;i<=k;i++)
            {res.push_back(j.top().second);
            j.pop();
            }

        
        return res;
        
    }
};
