//
//  DivideByZeroException.cpp
//  kitt
//
//  Created by Marco Hernandez on 1/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#include "DivideByZeroException.hpp"
#include <string>

namespace Exceptions {
    using namespace std;
    
    DivideByZeroException::DivideByZeroException(string message): KittException(message) {
        
    }
}
