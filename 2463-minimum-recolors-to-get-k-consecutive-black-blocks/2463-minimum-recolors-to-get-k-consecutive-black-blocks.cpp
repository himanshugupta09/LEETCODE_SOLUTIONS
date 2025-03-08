class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        queue<char>blok;
        int num = 0;
        while(blok.size() < k)
        {
            char cur = blocks[blok.size()];
            if(cur == 'W')
            {
                num++;
            }
            blok.push(cur);
        }
        int numRe = num;
        for(int i=k;i<blocks.size();i++)
        {
            if(blok.front() == 'W') num--;
            blok.pop();
            if(blocks[i] == 'W') num++;
            blok.push(blocks[i]);
            numRe = min(numRe,num);
        }
        return numRe;
    }
};