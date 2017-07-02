//
//  MismatchException.cpp
//  kitt
//
//  Created by Marco Hernandez on 2/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#include "MismatchException.hpp"
#include <string>

namespace Exceptions {
    using namespace std;
    
    MismatchException::MismatchException(string message): KittException(message) {
        
    }
}
