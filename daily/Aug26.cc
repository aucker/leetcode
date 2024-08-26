#include <map>
#include <vector>
using namespace std;

class Employee {
 public:
  int id;
  int importance;
  vector<int> subordinates;
};

class Solution {
  map<int, Employee*> m;

 public:
  /**
   * @brief Get the Importance object [M] DFS
   * Time: O(N), Space: O(N)
   *
   * @param employees
   * @param id
   * @return int
   */
  int getImportance(vector<Employee*> employees, int id) {
    int len = employees.size();
    for (int i = 0; i < len; i++) {
      m.insert({employees[i]->id, employees[i]});
    }

    return getValue(id);
  }

  int getValue(int id) {
    Employee* master = m[id];
    int ans = master->importance;
    for (int& oid : master->subordinates) {
      Employee* other = m[oid];
      ans += other->importance;
      for (int& sub : other->subordinates) ans += getValue(sub);
    }

    return ans;
  }
};
