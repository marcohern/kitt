//
//  MismatchException.hpp
//  kitt
//
//  Created by Marco Hernandez on 2/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#ifndef MissingAttributeException_hpp
#define MissingAttributeException_hpp

#include "KittException.hpp"

namespace Exceptions {
	class MissingAttributeException : public KittException {
	public:
		MissingAttributeException(string message);
	};
}
#endif /* MissingAttributeException_hpp */
