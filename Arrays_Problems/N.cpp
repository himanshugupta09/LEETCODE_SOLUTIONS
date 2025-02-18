class Solution {
public:
    string smallestNumber(string pattern) {
        string result = "";

        // Start building the sequence by calling the helper function
        buildSequence(0, 0, pattern, result);
        // Reverse the final result
        reverse(result.begin(), result.end());
        return result;
    }

    // Recursively build the sequence
    int buildSequence(int currentIndex, int currentCount, string pattern,
                      string& result) {
        if (currentIndex != pattern.size()) {
            if (pattern[currentIndex] == 'I')
                // If 'I', increment the count and move to the next index
                buildSequence(currentIndex + 1, currentIndex + 1, pattern,
                              result);
            else
                // If 'D', keep the count and move to the next index
                currentCount = buildSequence(currentIndex + 1, currentCount,
                                             pattern, result);
        }

        result += to_string(currentCount + 1);
        // Return the next count for the sequence
        return currentCount + 1;
    }
};
