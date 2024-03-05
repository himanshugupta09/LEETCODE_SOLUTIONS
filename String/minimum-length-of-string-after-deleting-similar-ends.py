left, right = 0, len(s) - 1
        
        while left < right and s[left] == s[right]:
            char = s[left]
            
            # Find the longest prefix of char
            while left <= right and s[left] == char:
                left += 1
            
            # Find the longest suffix of char
            while left <= right and s[right] == char:
                right -= 1
        
        return max(0, right - left + 1)
