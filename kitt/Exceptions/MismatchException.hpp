//
//  MismatchException.hpp
//  kitt
//
//  Created by Marco Hernandez on 2/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#ifndef MismatchException_hpp
#define MismatchException_hpp

#include "KittException.hpp"

namespace Exceptions {
    class MismatchException : public KittException {
    public:
        MismatchException(string message);
    };
}
#endif /* MismatchException_hpp */
