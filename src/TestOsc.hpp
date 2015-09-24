//
//  Osc.hpp
//  testOscManager
//
//  Created by sonir on 9/22/15.
//
//

#ifndef Osc_hpp
#define Osc_hpp

#include <stdio.h>
#include "slOscManager.h"

class TestOsc : public slOscManager {
    
    public:
        TestOsc(int port) : slOscManager(port){
            
            printf("OSC INIT");
            
        }
    
    
        void test(){
            

            cout << "Test was involed" << endl;
            
        }
    
        void fireMessage(ofxOscMessage *m);
    
    
};

#endif /* Osc_hpp */
