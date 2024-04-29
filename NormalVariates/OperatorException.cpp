//
//  OperatorException.cpp
//  HW 6
//
//  Created by Christopher Alpert on 8/29/22.
//

#include "OperatorException.hpp"

OperatorException::OperatorException() noexcept : msg_("Argument must be positive") {}
const char* OperatorException::what() const noexcept
{
    return msg_.c_str();
}
