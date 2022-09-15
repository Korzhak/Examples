#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main() {
    vector<int> a = {5, 4, 6, 7, 1, 7,9, 10, 121, 35, 33, 61};

    auto new_iter = remove(a.begin(), a.end(), 5);
    a.erase(new_iter, a.end());
    
    auto new_iter1 = remove(a.begin(), a.end(), 121);
    a.erase(new_iter1, a.end());

    auto new_iter2 = remove(a.begin(), a.end(), 7);
    a.erase(new_iter2, a.end());

    for (auto i : a) {
        cout << i << endl;
    }

    return 0;
}