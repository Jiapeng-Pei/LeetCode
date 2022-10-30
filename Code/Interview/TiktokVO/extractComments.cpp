#include "../../DataStructures.cpp"

vector<string> extractComments(string& str) {
    int n = str.size();
    vector<string> ret;
    if (n <= 2) return ret;
    int begin = 0, next = 0;
    while (begin < n) {
        char c = str[begin];

        // encounter a string, ignore it.
        if (c == '"') {
            next = begin + 1;  
            while (next < n && str[next] != '"') next++;
            begin = next + 1;
        }
        // encounter a line comment. add it to the result.
        else if (begin + 1 < n && c == '/' && str[begin+1] == '/') {
            next = begin + 2;
            begin += 2;
            while (next < n && str[next] != '\n') next++;
            ret.push_back(str.substr(begin, next - begin));

            // str[next] = '\n'
            begin = next + 1;
        }
        // encounter a block comment. add it to the result
        else if (begin + 1 < n && c == '/' && str[begin+1] == '*') {
            next = begin + 2;
            begin += 2;
            while (next + 1 < n) {
                if (str[next] == '*' && str[next+1] == '/') break;
                next++;
            }
            ret.push_back(str.substr(begin, next - begin));

            // str[next] == '*'
            begin = next + 2;
        }
        // a normal text. ignore it.
        else {
            begin++;
        }
    }

    return ret;
}

int main() {
    string str = "/*comment1 ||\ncomment2*/ \n string b = \"this is a fake comment\" \n int c = 2 + 3\n return c //this is result\n";
    for (auto& s : extractComments(str))
        cout << s << endl;
}