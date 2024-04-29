//
//  VolatilitiesException.h
//  HW 6
//
//  Created by Christopher Alpert on 8/28/22.
//

#ifndef VolatilitiesException_h
#define VolatilitiesException_h

#include <iostream>

class VolatilitiesException : public std::exception {
public:
    // Implement default ctor
    VolatilitiesException() noexcept;
    // Override the what() method:
    virtual const char* what() const noexcept;
private:
std::string msg_;
};
#endif /* VolatilitiesException_h */
