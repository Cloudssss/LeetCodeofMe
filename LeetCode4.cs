public class Solution {
    public double FindMedianSortedArrays(int[] nums1, int[] nums2) {
        if (nums1.Length == 0)
            {
                if (nums2.Length % 2 == 1) return nums2[nums2.Length / 2];
                else return (nums2[nums2.Length / 2] + nums2[nums2.Length / 2 - 1]) / 2.0;
            }
            if (nums2.Length == 0)
            {
                if (nums1.Length % 2 == 1) return nums1[nums1.Length / 2];
                else return (nums1[nums1.Length / 2] + nums1[nums1.Length / 2 - 1]) / 2.0;
            }
            
            int count = nums1.Length + nums2.Length;
            double medium=0;
            int num=0;
            int i=0, j=0;
            while (num!=count/2)
            {
                if (j>=nums2.Length||i<nums1.Length&&nums1[i]<nums2[j])
                {
                    medium = nums1[i];
                    i++;
                }
                else
                {
                    medium = nums2[j];
                    j++;
                }

                num++;
            }

            if (count%2==1)
            {
                if (i==nums1.Length)
                {
                    medium = nums2[j];
                }else if (j == nums2.Length)
                {
                    medium = nums1[i];
                }
                else if (nums1[i]<nums2[j])
                {
                    medium = nums1[i];
                }else
                {
                    medium = nums2[j];
                }
            }
            else
            {
                if (i == nums1.Length)
                {
                    medium = (nums2[j] + medium) / 2.0;
                } 
                else if(j == nums2.Length)
                {
                    medium = (nums1[i] + medium) / 2.0;
                } else if (nums1[i]<nums2[j])
                {
                    medium = (nums1[i]+medium)/2.0;
                }
                else
                {
                    medium = (nums2[j]+medium)/2.0;
                }
            }

            return medium;
    }
}