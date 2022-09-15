#include <iostream>
#include <fstream>

using namespace std;

int main() {
    string filePath = "./myfile.tx";

    ifstream file;
    file.exceptions ( ifstream::failbit | ifstream::badbit );

    try {
        file.open(filePath);
        cout << "File open" << endl;
        file.close();
    }
    catch (const exception &e) {
        cout << e.what() << endl;
        cout << "File not open" << endl;
    }
    
    return 0;
}