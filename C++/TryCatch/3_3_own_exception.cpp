#include <iostream>
#include <exception>

using namespace std;

struct MyException : public exception {
    MyException(const char * exception_message) {
        this->message = exception_message;
    }

    const char * get_more() const {
        return this->message;
    }
    
    const char * what () const throw () {
        return "Error. See get_more()";
    }
private: 
    const char * message;
};



double division(double a, double b) {
    if (b == 0) 
        throw MyException("Division by zero");

    return a / b;
}



int main() {
    try {
        cout << division(0, 4) << endl;
    }
    catch (const MyException & ex) {
        cout << ex.what() << endl;
        cout << ex.get_more() << endl;
    }

    return 0;
}