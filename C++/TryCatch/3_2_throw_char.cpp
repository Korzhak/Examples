#include <iostream>
#include <fstream>

using namespace std;


double PiR2(int R) { 
    // func for calculating lenght of circle
    // 2 * Pi * R
    // R !< 0
    if (R < 0) {
        throw "Number less zero";
    }

    return 2 * 3.14 * R;
}


int main() {

    double len_of_circle;
   
    try {
        len_of_circle = PiR2(-5);
        cout << "Lenght of circle = " << len_of_circle << endl;
    }
    catch (const char *ex) {
       cout << ex << endl;
    }
    
    return 0;
}