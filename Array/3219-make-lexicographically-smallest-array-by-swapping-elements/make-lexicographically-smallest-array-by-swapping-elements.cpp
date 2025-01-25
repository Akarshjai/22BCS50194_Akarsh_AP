class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> parent(n);
        iota(parent.begin(), parent.end(), 0);

        function<int(int)> find = [&](int x) {
            if (x != parent[x]) {
                parent[x] = find(parent[x]);
            }
            return parent[x];
        };

        auto unionSet = [&](int x, int y) {
            int rootX = find(x);
            int rootY = find(y);
            if (rootX != rootY) {
                parent[rootY] = rootX;
            }
        };

        vector<pair<int, int>> valueIndex;
        for (int i = 0; i < n; ++i) {
            valueIndex.emplace_back(nums[i], i);
        }
        sort(valueIndex.begin(), valueIndex.end());

        for (int i = 0; i < n - 1; ++i) {
            if (abs(valueIndex[i].first - valueIndex[i + 1].first) <= limit) {
                unionSet(valueIndex[i].second, valueIndex[i + 1].second);
            }
        }

        vector<vector<int>> groups(n);
        for (int i = 0; i < n; ++i) {
            groups[find(i)].push_back(i);
        }

        for (auto& group : groups) {
            if (!group.empty()) {
                vector<int> values;
                for (int idx : group) {
                    values.push_back(nums[idx]);
                }
                sort(values.begin(), values.end());
                sort(group.begin(), group.end());
                for (int i = 0; i < group.size(); ++i) {
                    nums[group[i]] = values[i];
                }
            }
        }

        return nums;
    }
};
