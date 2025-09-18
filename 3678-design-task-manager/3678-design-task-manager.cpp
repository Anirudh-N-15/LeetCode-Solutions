class TaskManager {
public:
  TaskManager(vector<vector<int>>& tasks) {
    for (vector<int>& t : tasks) {
      int userId = t[0], taskId = t[1], priority = t[2];
      m[taskId] = {userId, priority};
      pq.push({priority, taskId});
    }
  }
  
  void add(int userId, int taskId, int priority) {
    m[taskId] = {userId, priority};
    pq.push({priority, taskId});
  }
  
  void edit(int taskId, int newPriority) {
    int userId = m[taskId].first;
    m[taskId] = {userId, newPriority};
    pq.push({newPriority, taskId});
  }
  
  void rmv(int taskId) {
    m.erase(taskId);
  }
  
  int execTop() {
    if (m.empty()) {
      return -1;
    }
    while (!pq.empty()) {
      auto [priority, taskId] = pq.top();
      pq.pop();
      if (m.count(taskId) == 0 || m[taskId].second != priority) {
        continue;
      }
      int userId = m[taskId].first;
      m.erase(taskId);
      return userId;
    }
    return -1;
  }

unordered_map<int, pair<int, int>> m; // {taskID, {userID, priority}}
priority_queue<pair<int, int>> pq; //{priority, taskID}
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */