class OrderedStream {
private:
    vector<string> stream;
    int ptr;
public:
    OrderedStream(int n) {
        stream.clear();
        stream.resize(n, "");
        ptr = 0;
    }
    
    vector<string> insert(int id, string value) {
        stream[id-1] = value;
        vector<string> ret;
        while (ptr < stream.size() && stream[ptr] != "") {
            ret.push_back(stream[ptr++]);
        }
        return ret;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(id,value);
 */
