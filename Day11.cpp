/* QUESTION: Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int>sub;
    result.push_back(sub);
    for(int num : nums){
        int size = result.size();
        for(int i=0;i<size;i++){
            vector<int>v = result[i];
            v.push_back(num);
            result.push_back(v);
        }
    }
    return result;
    }
};
