import random
class RandomizedSet:

    def __init__(self):
        self.st = set()
        

    def insert(self, val: int) -> bool:
        if val in self.st:
            return False
        else:
            self.st.add(val)
            return True

    def remove(self, val: int) -> bool:
        if val in self.st:
            self.st.remove(val)
            return True
        else:
            return False
        

    def getRandom(self) -> int:
        ls = list(self.st)
        return random.choice(ls)


# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()
