//
//  TrigonometryFactory.cpp
//  kitt
//
//  Created by Marco Hernandez on 2/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#include "TrigonometryFactory.hpp"
#include "./RealtimeTrigonometry.hpp"
#include "./MemoizedTrigonometry.hpp"
#include "./QuadmemTrigonometry.hpp"

namespace Core {
    Trigonometry* TrigonometryFactory::create(const int &type) {
        switch (type) {
        case TRIGO_TYPE_MEMOIZED:
            return new MemoizedTrigonometry();
		case TRIGO_TYPE_QUADMEM:
			return new QuadmemTrigonometry();
        case TRIGO_TYPE_REALTIME:
        default:
            return new RealtimeTrigonometry();
            
        }
    }
}
