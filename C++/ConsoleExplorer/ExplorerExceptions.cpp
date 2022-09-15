#include "ExplorerExceptions.h"


ExplorerExceptions::ExplorerExceptions(const char* exception_message) {
    this->message = exception_message;
}


const char* ExplorerExceptions::getMore() const {
    return this->message;
}

const char* ExplorerExceptions::what() const throw () {
    return "Error. See getMore()";
}