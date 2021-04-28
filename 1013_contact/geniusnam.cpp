#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    regex re("(100+1+|01)+");
    for(int i = 0; i < n; i++) {
        string pattern;
        cin >> pattern;
        bool isProperPattern = regex_match(pattern, re);
        cout << (isProperPattern ? "YES" : "NO") << endl;
    }
    return 0;
}