class ProductOfNumbers {
public:
    vector<int>pref;
    int sz = 0;
    ProductOfNumbers() {
        pref.push_back(1);
        sz = 0;
    }
    
    void add(int num) {
        if(num==0)
        {
            pref = {1};
            sz = 0;
        }
        else
        {
            pref.push_back(pref[sz]*num);
            sz++;
        }
    }
    
    int getProduct(int k) {
        if(k > sz) return 0;
        return pref[sz]/pref[sz-k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */