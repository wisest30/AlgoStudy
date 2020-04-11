
// ref
// https://leetcode.com/problems/design-underground-system/discuss/554899/C%2B%2B-minimalizm
class UndergroundSystem {
public:
    map<int, pair<string, int>> reg;
    map<string, pair<int, int>> stats;
    UndergroundSystem() {

    }
    void checkIn(int id, string stationName, int t) {
        reg[id] = make_pair(stationName, t);
    }
    void checkOut(int id, string stationName, int t) {
        pair<string, int> in = reg[id];
        pair<int, int> stat = stats[in.first+":"+stationName];
        stats[in.first+":"+stationName] = make_pair(stat.first+(t-in.second), stat.second+1);
    }
    double getAverageTime(string startStation, string endStation) {
        pair<int, int> stat = stats[startStation+":"+endStation];
        return (double)stat.first/stat.second;
    }
};
