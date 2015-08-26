class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> alpNumS;
  map<char, int> alpNumT;
  if (s.length() != t.length()) return false;
  for (int i = 0; i < s.length(); i++){
   alpNumS[s[i]] += 1;
   alpNumT[t[i]] += 1;
  }
  if (alpNumS.size() != alpNumT.size()) return false;
  map<char, int>::iterator itS;
  for (itS = alpNumS.begin(); itS != alpNumS.end(); ++itS){
   if (itS->second != alpNumT[itS->first]) return false;
  }
  return true;
    }
};