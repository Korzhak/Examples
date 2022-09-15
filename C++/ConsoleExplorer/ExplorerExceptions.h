#pragma once
#include <iostream>
#include <exception>


class ExplorerExceptions:public std::exception {
public:
    ExplorerExceptions(const char* exception_message);
    const char* getMore() const;
    const char* what() const throw ();

private:
    const char* message;
};


