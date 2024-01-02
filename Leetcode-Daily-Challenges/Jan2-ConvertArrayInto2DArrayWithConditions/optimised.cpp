/*

Link : https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions/
You are given an integer array nums. You need to create a 2D array from nums satisfying the following conditions:

The 2D array should contain only the elements of the array nums.
Each row in the 2D array contains distinct integers.
The number of rows in the 2D array should be minimal.
Return the resulting array. If there are multiple answers, return any of them.

Note that the 2D array can have a different number of elements on each row.

 

Example 1:

Input: nums = [1,3,4,1,2,3,1]
Output: [[1,3,4,2],[1,3],[1]]
Explanation: We can create a 2D array that contains the following rows:
- 1,3,4,2
- 1,3
- 1
All elements of nums were used, and each row of the 2D array contains distinct integers, so it is a valid answer.
It can be shown that we cannot have less than 3 rows in a valid array.

*/

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {

// frequency vector is initialized with a size of nums.size() + 1 to accommodate indexing from 0 to nums.size()
        vector<int> frequency(nums.size() + 1);
        
        vector<vector<int>> result;
        for (int num : nums) {

            // If the frequency of integer num (frequency[c]) is equal to or greater than the size of ans, it means we need to add a new empty subarray to the result result.
            if (frequency[num] >= result.size()) {
                result.push_back({});
            }
            
            //The integer num is then added to the subarray in ans corresponding to its current frequency (frequency[c]).
            result[frequency[num]].push_back(num);
            
            frequency[num]++;
        }
        
        return result;
        
    }
};
