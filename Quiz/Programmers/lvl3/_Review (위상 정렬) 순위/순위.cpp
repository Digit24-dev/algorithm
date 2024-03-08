#include <iostream>

#include <string>
#include <vector>

#include <unordered_set>
#include <unordered_map>

using namespace std;

// Topology Sort.

void dfs(int player, unordered_map<int, unordered_set<int>>& g, unordered_set<int>& visited) {
    visited.insert(player);
    for(int opponent : g[player])
    {
        if (visited.find(opponent) == visited.end())
            dfs(opponent, g, visited);
    }
}

int solution(int n, vector<vector<int>> results) {
    int answer = 0;

    unordered_map<int, unordered_set<int>> wins;
    unordered_map<int, unordered_set<int>> losses;

    for (auto& result : results)
    {
        int winner = result[0];
        int loser = result[1];
        wins[loser].insert(winner);
        losses[winner].insert(loser);
    }

    for (int player = 1; player <= n; ++player)
    {
        unordered_set<int> visited;
        dfs(player, wins, visited);
        dfs(player, losses, visited);

        if (visited.size() == n)
            ++answer;
    }

    return answer;
}


int main() {
    int n = 5;
    //vector<vector<int>> results = { {4, 3}, {4, 2}, {3, 2}, {1, 2}, {2, 5} };
    vector<vector<int>> results = { {1,4}, {4, 2}, {2, 5}, {5, 3} };
    cout << solution(n, results) << endl;
    return 0;
}