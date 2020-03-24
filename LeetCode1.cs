public class Solution {
    public int[] TwoSum(int[] nums, int target) {
        int count = nums.Length;
        for(int i = 0; i < count ;i++)
        {
            for(int k = i + 1; k < count ; k ++)
            {
                if(nums[i]+nums[k]==target)
                {
                    int[] Array = new int[2];
                    Array[0] = i;
                    Array[1] = k;
                    return Array;
                }
            }
        }
        return new int[2];
    }
}