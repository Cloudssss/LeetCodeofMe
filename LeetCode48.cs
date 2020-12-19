using System;

namespace LeetCode48
{
    class Program
    {
        static void Main(string[] args)
        {
            
        }
    }
    
    public class Solution {
        public void Rotate(int[][] matrix)
        {
            int n = matrix.Length;
            int half = n / 2;
            for (int i = 0; i < half; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    int m = matrix[i][j];
                    matrix[i][j] = matrix[n - i - 1][j];
                    matrix[n-i-1][j] = m;
                }
            }

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < i; j++)
                {
                    int m = matrix[i][j];
                    matrix[i][j] = matrix[j][i];
                    matrix[j][i] = m;
                }
            }
        }
    }
}