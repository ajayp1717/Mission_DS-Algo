class RandomizedSet {
public:

    unordered_set <int> st;  
    RandomizedSet() {
    }
    
    bool insert(int val) {
        if(st.count(val))return false;
        else{
            st.insert(val);
        }
        return true;
    }
    
    bool remove(int val) {
        auto it=st.find(val);
        if(it==st.end())return false;
        else{
            st.erase(it);
        }
        return true;
    }
    
    int getRandom() {
    
        int rndmidx=rand()%st.size();
        auto it=st.begin();

        advance(it,rndmidx);
        return *it;   
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */