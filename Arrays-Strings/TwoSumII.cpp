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
using namespace std;

int BinarySearch(vector<int> nums, int key, int start){
    int L = start, R = nums.size()-1; 
    while ( L < R){
        int M = (L+R)/2;
        if(nums[M] < key){
            L = M+1;
        } else {
            R = M;
        } 
    }
    return (L == R && nums[L] == key)?L:-1;
}


vector<int> TwoSum(vector<int> nums, int target){
    vector<int> res;
    for( int i =0; i<nums.size(); ++i){
        int j = BinarySearch(nums, target-nums[i], i+1);
        if( j != -1){
            res.push_back(i);
            res.push_back(j);
            return res;
        }
    }
    return res;
}

#include<iostream>
using namespace std;
int main(){
    vector< int> nums = {2,7,11,15};
    
    vector<int> res = TwoSum(nums, 9);

    cout<< res[0] << ","<<res[1]<<endl;

}