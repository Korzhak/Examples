#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*
 * Розказати про унарні і бінарні предикати
 */


/* -------- БІНАРНИЙ ПРЕДИКАТ --------- */
bool SortMethod(int a, int b) {
    return a < b; // < descending, > ascending
}

int main() {
    vector<int> v = {1, 5,3 , 2, 7, 9, 4, 4, 12};

    sort(v.begin(), v.end(), [](int a, int b) {
        return a > b;
    });

    for_each(v.begin(), v.end(), [](int a){
        cout << a << endl;
    });

    cout << "------------------------" << endl;

    int arr[] = {5, 4, 1, 8, 6, 12, 125, 33, 11, 10, -4};
    int size_arr = sizeof(arr) / sizeof(int);

    sort(arr, arr + size_arr);
    for_each(arr, arr+size_arr, [](int a) {
        cout << a << endl;
    });
    
    return 0;
}