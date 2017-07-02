//
//  OutOfRangeException.cpp
//  kitt
//
//  Created by Marco Hernandez on 2/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#include "OutOfRangeException.hpp"
#include <string>

namespace Exceptions {
    using namespace std;
    
    OutOfRangeException::OutOfRangeException(string message): KittException(message) {
        
    }
}
