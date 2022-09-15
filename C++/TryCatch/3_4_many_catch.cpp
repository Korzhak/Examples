#include <iostream>
#include <exception>

using namespace std;


struct MyException : public exception {
public:
    MyException(const char * exception_message, int data_state) {
        this->message = exception_message;
        this->data_state = data_state;
    }

    const char * get_more() const {
        return this->message;
    }
    //                         throw в кінці означає, що, функ. не може давати жодних ексепшнів
    const char * what () const throw () {
        return "Error. See get_more()";
    }

    int getDataState() const {
        return this->data_state;
    }

private: 
    const char * message;
    int data_state;
};



double division(double a, double b) {
    if (a == 0 && b == 0) {
        throw invalid_argument("You can't give me zero and zero");
    }
    else if (b == 0) 
        throw MyException("Division by zero", 0);

    else if (b == 1) {
        throw exception();
    }

    return a / b;
}



int main() {
    try {
        cout << division(0, 0) << endl;
    }
    // Батьківський клас винятків має стояти в кінці
    // Інакше він ловитиме всі помилки
    catch (const exception & ex) {
        cout << ex.what() << endl;
    } 

    catch (const invalid_argument & ex) { 
        cout << ex.what() << endl;
        cout << "invalid_argument" << endl;
    }

    catch (const MyException & ex) {
        cout << ex.what() << endl;
        cout << ex.get_more() << endl;
        cout << ex.getDataState() << endl;
        cout << "MyException" << endl;
    }

     

    return 0;
}