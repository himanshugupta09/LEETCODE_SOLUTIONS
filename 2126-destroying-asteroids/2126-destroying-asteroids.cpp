class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        long long mass1 = mass;
        for(const int ast:asteroids)
        {
            if(mass1 < ast)
            {
                return false;
            }
            mass1 +=  ast;
        }
        return true;

    }
};