class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes,
                                  vector<vector<string>>& ingredients,
                                  vector<string>& supplies) {
        // Track available ingredients and recipes
        unordered_set<string> available(supplies.begin(), supplies.end());

        // Queue to process recipe indices
        queue<int> recipeQueue;
        for (int idx = 0; idx < recipes.size(); ++idx) {
            recipeQueue.push(idx);
        }

        vector<string> createdRecipes;
        int lastSize = -1;

        // Continue while we keep finding new recipes
        while (static_cast<int>(available.size()) > lastSize) {
            lastSize = available.size();
            int queueSize = recipeQueue.size();

            // Process all recipes in current queue
            while (queueSize-- > 0) {
                int recipeIdx = recipeQueue.front();
                recipeQueue.pop();
                bool canCreate = true;

                // Check if all ingredients are available
                for (string& ingredient : ingredients[recipeIdx]) {
                    if (!available.count(ingredient)) {
                        canCreate = false;
                        break;
                    }
                }

                if (!canCreate) {
                    recipeQueue.push(recipeIdx);
                } else {
                    // Recipe can be created - add to available items
                    available.insert(recipes[recipeIdx]);
                    createdRecipes.push_back(recipes[recipeIdx]);
                }
            }
        }

        return createdRecipes;
    }
};