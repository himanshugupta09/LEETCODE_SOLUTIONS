class Solution:
    def findWinners(self, matches: List[List[int]]) -> List[List[int]]:
        
        match = {}
        
        for i in range(len(matches)):
            winner = matches[i][0]
            loser = matches[i][1]
            
            if winner not in match:
                match[winner] = [0,0]
                match[winner][0] += 1
            elif winner in match:
                match[winner][0] += 1
            if loser not in match:
                match[loser] = [0,0]
                match[loser][1] += 1
            elif loser in match:
                match[loser][1] += 1
        win = []
        loss = []
        #print(match)
        for player,data in match.items():
            if data[1] == 0:
                win.append(player)
            elif data[1] == 1:
                loss.append(player)
        win.sort()
        loss.sort()
        return [win,loss]
        
