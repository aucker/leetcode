#include <string>
using namespace std;

class Solution {
 public:
  string intToRoman(int num) {
    //     string ones[] = {"", "I", "II", "III", "IV", "V", "VI", "VII",
    //     "VIII", "IX"}; string tens[] = {"", "X", "XX", "XXX", "XL", "L",
    //     "LX", "LXX", "LXXX", "XC"}; string hrns[] = {"", "C", "CC", "CCC",
    //     "CD", "D", "DC", "DCC", "DCCC", "CM"}; string ths[] = {"", "M", "MM",
    //     "MMM"};
    //
    //     return ths[num/1000] + hrns[(num%1000)/100] + tens[(num%100)/10] +
    //     ones[(num%10)];

    // another method
    vector<pair<int, string>> map{
        {1, "I"},   {4, "IV"},   {5, "V"},   {9, "IX"},  {10, "X"},
        {40, "XL"}, {50, "L"},   {90, "XC"}, {100, "C"}, {400, "CD"},
        {500, "D"}, {900, "CM"}, {1000, "M"}};

    int l = map.size() - 1;
    string s = "";

    while (num != 0) {
      while (map[l].first > num) {
        l--;
      }
      s += map[l].second;
      num -= map[l].first;
    }
    return s;
  }
};
