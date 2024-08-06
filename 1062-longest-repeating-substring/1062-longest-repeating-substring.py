class Solution:
    def longestRepeatingSubstring(self, s: str) -> int:
        n = len(s)
        suf = [s[i:] for i in range(n)]
        suf.sort()
        c = 0
        for i in range(1,n):
            j = 0
            while(j< min(len(suf[i]), len(suf[i-1])) and suf[i][j] == suf[i-1][j]):
                j+=1
            c = max(c, j)
        return c