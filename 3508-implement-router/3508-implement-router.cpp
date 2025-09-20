class Router {
private:
    using t = tuple<int,int,int> ;
    deque<t> packetQueue ;
    unordered_set<string> packetSet ;
    unordered_map<int,int> startIndex ;
    unordered_map<int,vector<int>> timestamps ; //dest -> timestamps
    int maxSize = 0;

    string key(int src ,int dest, int ts) {
        return to_string(src) + "-" + to_string(dest) + "-" + to_string(ts) ;
    }

public:
    Router(int memoryLimit) {
        maxSize = memoryLimit ;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        string k = key(source,destination,timestamp);
        if(packetSet.count(k)) return false ;

        if(packetQueue.size() == maxSize) {
            auto [s,d,t] = packetQueue.front();
            packetQueue.pop_front();
            packetSet.erase(key(s,d,t));
            startIndex[d]++;
        }

        packetQueue.push_back({source, destination, timestamp});
        packetSet.insert(k);
        timestamps[destination].push_back(timestamp) ;
        return true ;
    }
    
    vector<int> forwardPacket() {
        if(packetQueue.empty()) return {} ;
        auto [s,d,t] = packetQueue.front();
        packetQueue.pop_front();
        packetSet.erase(key(s,d,t));
        startIndex[d]++;

        return {s,d,t};
    }
    
    int getCount(int destination, int startTime, int endTime) {
        if (timestamps.find(destination) == timestamps.end()) return 0;

        auto &ts = timestamps[destination];
        int idx = startIndex[destination]; // skip old packets

        auto itStart = lower_bound(ts.begin() + idx, ts.end(), startTime);
        auto itEnd = upper_bound(ts.begin() + idx, ts.end(), endTime);
        return int(itEnd - itStart);
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */