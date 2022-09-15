#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main() {
    string s = "This;is;my;text";

    replace(s.begin(), s.end(), ';', ' ');
    cout << s << endl;

    auto remove_iter = remove(s.begin(), s.end(), ' ');
    s.erase(remove_iter, s.end());

    cout << s << endl;

    return 0;
}