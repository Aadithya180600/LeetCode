class Solution:
    def countSeniors(self, details: List[str]) -> int:
        c = 0
        for s in details:
            if int(s[11:13]) > 60:
                c = c+1
        return c
        