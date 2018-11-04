#include <iostream>
#include <vector>

using namespace std;

void dfs(int root, vector<int>& path, vector<vector<int>>& result) {
    path.push_back(root);
    if (path.size() == 3) {
        result.push_back(path);
    	path.pop_back();
        return;
    }
    for (auto i=0; i<2; i++) {
        dfs(2*root+i, path, result);
    }
    path.pop_back();
    return;
}

int main() {
    vector<int> path;
    vector<vector<int>> result;
    dfs(1, path, result);
    for (auto i=0; i<result.size(); i++) {
        for (auto j=0; j<result[i].size(); j++) {
            std::cout << result[i][j] << " ";
        }
        std::cout << std::endl;
    }
    cout << result.size() << endl;
    return 0;
}
