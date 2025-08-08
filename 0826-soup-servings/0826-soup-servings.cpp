class Solution {
public:
    vector<pair<int, int>> serves = {{4, 0}, {3, 1}, {2, 2}, {1, 3}};
    vector<vector<double>> t;

    double solve(double a,double b) {
        if (a <= 0 && b <= 0) return 0.5;
        if (a <= 0) return 1.0;
        if (b <= 0) return 0.0;

        if (t[a][b] != -1.0) {
            return t[a][b];
        }

        double probability = 0.0;
        for (auto &p : serves) {
            probability += 0.25 * solve(a - p.first, b - p.second);
        }
        return t[a][b] = probability;
    }

    double soupServings(int n) {
        if(n >= 4800) return 1.0;

        int units = (n + 24) / 25; // round up to nearest unit
        t.assign(units + 1, vector<double>(units + 1, -1.0));
        return solve(units,units);

    }
};