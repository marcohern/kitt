//
//  OutOfRangeException.hpp
//  kitt
//
//  Created by Marco Hernandez on 2/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#ifndef OutOfRangeException_hpp
#define OutOfRangeException_hpp

#include <stdio.h>
#include "KittException.hpp"

namespace Exceptions {
    class OutOfRangeException : public KittException {
    public:
        OutOfRangeException(string message);
    };
}
#endif /* OutOfRangeException_hpp */
