//
//  TestRunner.hpp
//  kitt
//
//  Created by Marco Hernandez on 1/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#ifndef TestRunner_hpp
#define TestRunner_hpp

#include <iostream>
#include <exception>
#include <string>
#include <list>

#include "../Exceptions/AssertException.hpp"

namespace Testing {
    using namespace std;
    using namespace Exceptions;
    
    template<class T, typename M>
    class TestRunner {
    private:
        string name;
        T *test;
        M method;
    public:
        
        
        TestRunner(string name, T *t, M m) {
            this->name = name;
            this->test = t;
            this->method = m;
        }
        
        ~TestRunner() {
            this->name = "";
            this->test = NULL;
            this->method = NULL;
        }
        
        void run() {
            try {
                test->setup();
                (test->*method)();
                test->teardown();
                cout << test->getName() << "_" << name <<":OK" << endl;
            }
            catch (AssertException &ex) {
                cout << test->getName() << "_" << name << ":ERROR " << ex.getMessage() << endl;
            }
            catch (exception &ex) {
                cout << test->getName() << "_" << name << ":ERROR " << ex.what() << endl;
            }
            catch (...) {
                cout << test->getName() << "_" << name << ":UNKNOWN ERROR" << endl;
            }

        }
    };
}

#endif /* TestRunner_hpp */
