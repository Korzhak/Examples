#include <iostream>
#include <fstream>

using namespace std;

int main() {
    string filePath = "./myfile.txt";

    ifstream file;


    file.open(filePath);

    if (file.is_open()) {   
        cout << "File open" << endl;
    }

    else {
        cout << "File do not open" << endl;
    }

    file.close();

    return 0;
}