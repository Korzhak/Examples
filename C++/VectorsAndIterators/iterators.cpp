#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int>::iterator i;
    vector<int> v = {1, 2, 3, 5, 6};

    //  [1][2][3][5][6][][][][][]
    //  ^              ^
    // beg.           end
    i = v.begin();
    cout << *(i+2) << endl;


    // Занести дані в масив по ітератору
    *(i) = 999;
    cout << *(i) << endl;

    // проходження циклом по ітераторах
    while (i != v.end()) {
        cout << *(i) << endl;
        i++;
    }
    
    // vector<int>::const_iterator ci = v.begin();

    // отримати інедкс знаючи ітератор
    

    // INSERT

    // Вказівники в масивах
    int myArr[] = {1, 2, 3, 5, 6};
    cout << *(myArr+1) << " " << myArr[1] <<  endl; 
}