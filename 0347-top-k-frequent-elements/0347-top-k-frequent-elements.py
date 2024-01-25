class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        li = Counter(nums).most_common(k)
        k = [x[0] for x in li]
        return k
        