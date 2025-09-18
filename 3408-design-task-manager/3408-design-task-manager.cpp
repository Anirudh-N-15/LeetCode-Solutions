class TaskManager {
public:
    //taskId -> {userId, priority}
    map<int, pair<int, int>> mp;
    //{priority, taskId}
    set<pair<int, int>> st;
    TaskManager(vector<vector<int>>& tasks) {
        for(auto it: tasks){
            st.insert({it[2], it[1]});
            mp[it[1]] = {it[0], it[2]};
        }
    }
    
    void add(int userId, int taskId, int priority) {
        st.insert({priority, taskId});
        mp[taskId] = {userId, priority};
    }
    
    void edit(int taskId, int newPriority) {
        pair<int, int> p = mp[taskId];
        p = {p.second, taskId};
        auto it = st.find(p);
        st.erase(it);
        st.insert({newPriority, taskId});
        mp[taskId] = {mp[taskId].first, newPriority};
    }
    
    void rmv(int taskId) {
        pair<int, int> p = mp[taskId];
        p = {p.second, taskId};
        auto it = st.find(p);
        st.erase(it);
        mp.erase(taskId);
    }
    
    int execTop() {
        if(mp.size() == 0) return -1;
        auto it = st.end();
        it--;
        //get the task with the hight priority 
        pair<int, int> p = *it;
        int ans = mp[p.second].first;
        mp.erase(p.second);
        st.erase(it);
        return ans;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */