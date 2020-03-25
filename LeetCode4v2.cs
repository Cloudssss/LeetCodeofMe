public class Solution { 
        public double FindMedianSortedArrays(int[] nums1, int[] nums2)
        {
            int m = nums1.Length;
            int n = nums2.Length;
            if (m>n)//to make sure m<=n
            {
                int[] temp = nums1;
                nums1 = nums2;
                nums2 = temp;
                int tem = m;
                m = n;
                n = tem;
            }

            if (m==0)
            {
                if (n%2==1)
                {
                    return nums2[n / 2];
                }
                else
                {
                    return (nums2[n / 2 - 1] + nums2[n / 2]) / 2.0;
                }
            }

            int iMin = 0;
            int iMax = m;
            int halflen = (m + n +1) / 2;
            while (iMin<=iMax)
            {
                int i = (iMax + iMin) / 2;
                int j = halflen - i ;
                
                if(i<iMax&&nums2[j-1]>nums1[i])
                {
                    iMin = i + 1;
                }
                else if(i>iMin&&nums1[i-1]>nums2[j])
                {
                    iMax = i - 1;
                }
                else
                {
                    int maxLeft=0;
                    if (i==0)
                    {
                        maxLeft = nums2[j - 1];
                    }

                    else if (j==0)
                    {
                        maxLeft = nums1[i - 1];
                    }
                    else
                    {
                        maxLeft = max(nums1[i - 1], nums2[j - 1]);
                    }
                    if ((m + n) % 2 == 1)
                        return maxLeft;

                    int rightMin = 0;
                    if (i == m)
                    {
                        rightMin = nums2[j];
                    }
                    else if (j==n)
                    {
                        rightMin = nums1[i];
                    }
                    else
                    {
                        rightMin = min(nums2[j], nums1[i]);
                    }

                    return (maxLeft + rightMin) / 2.0;
                }
                
            }

            return 0;
        }

        public int max(int a, int b)
        {
            if (a<b)
            {
                return b;
            }
            else
            {
                return a;
            }
        }

        public int min(int a, int b)
        {
            if (a<b)
            {
                return a;
            }
            else
            {
                return b;
            }
        }
}