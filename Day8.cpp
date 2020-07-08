/* QUESTION: Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       
        vector<vector<int>>ans;
         if(nums.size()<=2)return ans;
        unordered_set<string>m;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++){
            int x=i+1;int y=nums.size()-1;
            
            while(x<y){
                int sum=nums[i]+nums[y]+nums[x];
                if(sum==0){
                        vector<int>v;
                    v.push_back(nums[i]);
                    v.push_back(nums[x]);
                    v.push_back(nums[y]);
                  //  sort(v.begin(),v.end());
                    string temp=to_string(v[0])+to_string(v[1])+to_string(v[2]);
                    if(m.find(temp)==m.end())
                    {ans.push_back(v);
                    m.insert(temp);}
                      while(x<y && nums[x]==nums[x+1])
                                x++;
                        while(x<y && nums[y]==nums[y-1])
                                y--;
                    x++;y--;
                }else if(sum<0)x++;
                else y--;
            }
        }
        return  ans;
        
        
    }
};
