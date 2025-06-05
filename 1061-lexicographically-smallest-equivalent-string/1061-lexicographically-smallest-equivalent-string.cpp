class Solution {
public:
    vector<int> parent;
    int findParent(int u) {
        if(u == parent[u]) return u;
        return parent[u]= findParent(parent[u]);
    }

    void merge(int u,int v) {
        int U = findParent(u);
        int V = findParent(v);
        if( U > V) {
            parent[U] = V;
        } else if(V > U) {
            parent[V] = U;
        }
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        parent.resize(26);
        int n = s1.size();
        for(int i=0;i<26;i++) parent[i] = i;
        for(int i=0;i<n;++i) {
            merge(s1[i] - 'a',s2[i]-'a');
        }
        string ans;

        for(int i=0;i< baseStr.size();i++) {
            int node = findParent(baseStr[i] - 'a');
            ans.push_back(node + 'a');
        }
        return ans; 
    }
};