public class Solution {
    public int LengthOfLongestSubstring(string s) {
            int WinFirst = 0;
            int WinLast = 0;
            int max = 0;
            if (s.Length==1)
            {
                return 1;
            }
            while (WinLast<s.Length-1)
            {
                WinLast++;
                for (int i = WinFirst; i < WinLast; i++)
                {
                    if (s[WinLast]==s[i])
                    {
                        WinFirst=i+1;
                        break;
                    }
                }

                if (WinLast-WinFirst+1>max)
                {
                    max = WinLast - WinFirst + 1;
                }
            }

            return max;

    }
}