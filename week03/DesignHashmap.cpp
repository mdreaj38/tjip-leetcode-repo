//TC: O(N)
//MC: O(N)
class MyHashMap {
public:
    const int MOD = 491;
    vector<vector<pair<int,int>>>bucket;
    
    MyHashMap() {
        bucket.resize(MOD);
    }
    
    void put(int key, int value) {
        for(auto &kv: bucket[key%MOD]){
            if(kv.first==key){
                kv.second = value;
                return ;
            }
        }
        bucket[key%MOD].emplace_back(make_pair(key, value));
        
        return ;
    }
    
    int get(int key) {
        for(auto kv: bucket[key%MOD]){
            if(kv.first==key)
                return kv.second;
        }
        
        return -1;
    }
    
    void remove(int key) {
        int index = key%MOD;
        for(int i=0; i<bucket[key%MOD].size(); ++i){
            if(bucket[index][i].first==key){
                bucket[index].erase(bucket[index].begin()+i);
                
                return ;
            }
        }
        
        return ;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
