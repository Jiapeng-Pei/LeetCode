#include "../Code/DataStructures.cpp"

int main() {
    map<char, vector<string>> charMap;
    vector<string> strs = {"no", "is", "th", "ti", "fo", "al", "go", "pe", "to", "co", "to", "th", "ai", "of", "th", "pa"};
    for (string& s : strs) {
        charMap[s[1]].push_back(s);
    }

    strs = {};
    for (auto& p : charMap) {
        for (string& s : p.second) 
            strs.push_back(s);
    }

    charMap.clear();
    for (string& s : strs) {
        charMap[s[0]].push_back(s);
    }
    for (auto& p : charMap) {
        for (string& s : p.second) 
            cout << s << " ";
    }
    cout << endl;
}
