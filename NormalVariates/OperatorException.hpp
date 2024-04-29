//
//  OperatorException.hpp
//  HW 6
//
//  Created by Christopher Alpert on 8/29/22.
//

#ifndef OperatorException_hpp
#define OperatorException_hpp

#include <stdio.h>
#include <iostream>

class OperatorException : public std::exception {
public:
    // Implement default ctor
    OperatorException() noexcept;
    // Override the what() method:
    virtual const char* what() const noexcept;
private:
std::string msg_;
};

#endif /* OperatorException_hpp */
