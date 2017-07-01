//
//  DivideByZeroException.hpp
//  kitt
//
//  Created by Marco Hernandez on 1/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#ifndef DivideByZeroException_hpp
#define DivideByZeroException_hpp

#include <stdio.h>
#include "KittException.hpp"

namespace Exceptions {
    class DivideByZeroException : public KittException {
    public:
        DivideByZeroException(string message);
    };
}
#endif /* DivideByZeroException_hpp */
