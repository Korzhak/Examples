#include <iostream>
#include <exception>

using namespace std;

/*    
 *      Exceptions:
 * std::exception - parrent class
 * std::logic_error and child class can getting string for message
 * std::runtime_error and child class can getting string for message
 */

double PiR2(int R) {
    // func for calculating lenght of circle
    // 2 * Pi * R
    // R !< 0
    if (R < 0) {
        throw logic_error("less then zero");
        // throw runtime_error("Less then zero");
    }

    return 2 * 3.14 * R;
}


int main() {

    double len_of_circle;

    try {
        len_of_circle = PiR2(-5);
        cout << "Lenght of circle = " << len_of_circle << endl;
    }
    catch (const exception &ex) {
        cout << ex.what() << endl;
    }

    return 0;
}