
// Longest Consecutive Sequence
// Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
//
// You must write an algorithm that runs in O(n) time.

// Example 1:
//
// Input: nums = [100,4,200,1,3,2]
// Output: 4
// Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> hashSet;
        for( int num: nums)
        {
            hashSet.insert(num);
        }

        int longestLength = 0;
        for(int num: nums)
        {
            if(!hashSet.count(num-1))
            {
                int currentNum = num;
                int currentStreak = 1;

                while(hashSet.count(currentNum+1))
                {
                    currentNum +=1;
                    currentStreak +=1;
                }

                longestLength = max(longestLength, currentStreak);
            }
        }
        return longestLength;
    }
};
