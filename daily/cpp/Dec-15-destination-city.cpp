#include <string>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> cities;
        for (const auto& path : paths) {
            cities.insert(path[0]);
        }
        for (const auto& path : paths) {
            const string& dest = path[1];
            if (cities.find(dest) == cities.end()) {
                return dest;
            }
        }
        return "";
    }
};