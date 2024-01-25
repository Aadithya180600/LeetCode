class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        d = {}
        for i in strs:
            k = tuple(sorted(i))
            if k in d:
                d[k].append(i)
            else:
                d[k] = []
                d[k].append(i)
        # print(d.values())
        return d.values()