class LFUCache {
private:
    int cap;
    int size;

    unordered_map<int,list<vector<int>>::iterator>m;
    map<int,list<vector<int>>>freq;
    public:
    LFUCache(int capacity) {
        cap=capacity;
        size=0;
    }
    
    void makeFrequenctlyUsed(int key)
    {
         auto &vec=*(m[key]);
         int value=vec[1];
         int f=vec[2];

         freq[f].erase(m[key]);
         if(freq[f].empty())
         freq.erase(f);

         f++;
         freq[f].push_front({key,value,f});
         m[key]=freq[f].begin();
    }


    int get(int key) {
        if(m.find(key)!=m.end())
        {
           auto vec=(*(m[key])); //{key,value,count}
           int value=vec[1];
           makeFrequenctlyUsed(key);
           return value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end())
        {
            auto &vec=(*(m[key]));
            vec[1]=value;
            makeFrequenctlyUsed(key);


        }
        else if(size<cap)
        {
            size++;
            freq[1].push_front(vector<int>({key,value,1}));
            m[key]=freq[1].begin();
        }
        else
        {
            auto &kaun_sa_list=freq.begin()->second;
            int key_to_delete=(kaun_sa_list.back())[0];
            kaun_sa_list.pop_back();

            m.erase(key_to_delete);

            if(kaun_sa_list.empty())
            freq.erase(freq.begin()->first);

            freq[1].push_front(vector<int>({key,value,1}));
            
            m[key]=freq[1].begin();
        }
    }
};