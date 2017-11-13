// Given an array of integers, return indices of the two numbers such that they add up to a specific target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// Given nums = [2, 7, 11, 15], target = 9,
// Because nums[0] + nums[1] = 2 + 7 = 9,
// return [0, 1].

// Below solution using std::map. This should be O(n) solution
#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // create a map of the number
        std::map <int, int> target_map;
        vector<int> ret;
        for(int i = 0; i<= nums.size()-1; i++)
        {
            //cout<< nums[i]<<endl;
            std::map<int,int>::iterator it = target_map.find(target - nums[i]);
            if(it != target_map.end())
            {
                ret.push_back(it->second);
                ret.push_back(i);
                //cout<< "ret : "<<endl;
                return ret;
            }
            target_map[nums[i]] = i;
            //cout<<"(key, value): " <<nums[i] <<" "<< target_map[nums[i]] << endl;
        }
        return ret;
    }
};
