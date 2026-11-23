class ProductOfNumbers {
public:
    vector<int>prefix;
    int sz = 0;
    ProductOfNumbers() {
        prefix.push_back(1);
        sz = 0;
    }
    
    void add(int num) {
        if(num == 0)
        {
            prefix = {1};
            sz = 0;
        }
        else
        {
            prefix.push_back(prefix[sz]*num);
            sz++;
        }
    }
    
    int getProduct(int k) {
        if(k > sz) return 0;
        return prefix[sz]/prefix[sz-k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */