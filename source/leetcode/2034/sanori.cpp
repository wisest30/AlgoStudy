class StockPrice {
  protected:
    std::map<int, int> records;
    std::multiset<int> values;
    void printRec() {
      for (map<int,int>::iterator it = records.begin(); it != records.end(); ++it) {
        cout << ' ' << it->first << ": " << it->second;
      }
      cout << '\n';
    }
    void printVal() {
      for (multiset<int>::iterator it = values.begin(); it != values.end(); ++it) {
        cout << ' ' << *it;
      }
      cout << '\n';
    }

  public:
    StockPrice() {
    }

    void update(int timestamp, int price) {
      if (records.count(timestamp) > 0) {
        int oldVal = records[timestamp];
        values.erase(values.find(oldVal));
      }
      records[timestamp] = price;
      values.insert(price);
    }

    int current() {
      return (records.rbegin())->second;
    }

    int maximum() {
      return *values.rbegin();
    }

    int minimum() {
      return *values.begin();
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */
