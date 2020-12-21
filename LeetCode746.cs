using System;

namespace LeetCode746
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Hello World!");
        }
    }
    
    public class Solution {
        public int MinCostClimbingStairs(int[] cost)
        {
            int n = cost.Length;
            int prev = 0, curr = 0;
            int next = 0;
            for (int i = 1; i < n; i++)
            {
                next = Math.Min(curr + cost[i], prev + cost[i - 1]);
                prev = curr;
                curr = next;
            }

            return next;
        }
    }
}