//
//  VolatilitiesException.cpp
//  HW 6
//
//  Created by Christopher Alpert on 8/28/22.
//

#include <stdio.h>
#include "VolatilitiesException.h"

VolatilitiesException::VolatilitiesException() noexcept : msg_("Volatilities must be not equal and positive") {}
const char* VolatilitiesException::what() const noexcept
{
    return msg_.c_str();
}
