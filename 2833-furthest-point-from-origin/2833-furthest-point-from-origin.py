class Solution:
    def furthestDistanceFromOrigin(self, moves: str) -> int:
        un = moves.count('_')
        lm = moves.count('L')
        rm = moves.count('R')
        un = un + (max(lm,rm)-min(lm,rm))
        return un