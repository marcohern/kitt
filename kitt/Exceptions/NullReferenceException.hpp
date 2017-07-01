//
//  NullReferenceException.hpp
//  kitt
//
//  Created by Marco Hernandez on 1/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#ifndef NullReferenceException_hpp
#define NullReferenceException_hpp

#include <stdio.h>
#include "KittException.hpp"

namespace Exceptions {
    class NullReferenceException : public KittException {
    public:
        NullReferenceException(string message);
    };
}
#endif /* NullReferenceException_hpp */
