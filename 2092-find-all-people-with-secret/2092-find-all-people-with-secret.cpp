class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings,
                              int firstPerson) {
        vector<vector<pair<int, int>>> adjList(n);
        vector<int> ans(n, 1e9);
        ans[0] = ans[firstPerson] = 0;

        sort(meetings.begin(), meetings.end(),
     [](auto &a, auto &b) { return a[2] < b[2]; });

        for (const auto& meeting : meetings) {
            int u = meeting[0], v = meeting[1], time = meeting[2];
            adjList[u].push_back({v, time});
            adjList[v].push_back({u, time});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        pq.push({0, firstPerson});
        pq.push({0,0});

        while (!pq.empty()) {
            auto [time, person] = pq.top();
            pq.pop();

            for (auto& it : adjList[person]) {
                int currPerson = it.first, currTime = it.second;

                if (currTime >= time && currTime < ans[currPerson]) {
                    ans[currPerson] = currTime;
                    pq.push({currTime, currPerson});
                }
            }
        }

        vector<int> people;
        for (int i = 0; i < n; i++) {
            if (ans[i] != 1e9) {
                people.push_back(i);
            }
        }
        return people;
    }
};