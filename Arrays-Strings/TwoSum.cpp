/* Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Output: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1] */

#include<vector>
#include<map>
using namespace std;

// Brute force apporach with O(n2) time complexicity 
vector<int> TwoSumBruteForce(vector<int> nums, int target){
    int n = nums.size();
    vector<int> res;
    for( int i =0; i< n; ++i) {
        for( int j =0; j<n; ++j){
            if( i == j)
                continue;
            
            if(nums[i] + nums[j] == target){
                res.push_back(i);
                res.push_back(j);
                return res;
            } 
        }
    }
    return res;
}
// Using extra space with O(n) time complexicity
vector<int> TwoSum(vector<int> nums, int target){
    map<int, int> mp;
    vector<int> res;
    for( int i =0; i< nums.size(); ++i){
        int val = nums[i];

        if(mp.find(target- val) != mp.end()){
            res.push_back(mp[target-val]);
            res.push_back(i);
            return res;
        } else {
            mp[val] = i;
        }
    }
    return res;
}
#include<iostream>
using namespace std;
int main(){
    vector< int> nums = {2,7,11,15};
    
    vector<int> res = TwoSumBruteForce(nums, 9);

    cout<< res[0] << ","<<res[1]<<endl;

    res = TwoSum(nums, 9);

    cout<< res[0] << ","<<res[1]<<endl;
}