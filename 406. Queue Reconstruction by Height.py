class Solution:
    def reconstructQueue(self, people: List[List[int]]) -> List[List[int]]:
        people.sort(key= lambda people : (-people[0],people[1]))
        res = []
        for people in people:
            res.insert(people[1],people)
        return res