//
//  Receiver.hpp
//  yagiSys
//
//  Created by sonir on 9/22/15.
//
//

#ifndef Receiver_hpp
#define Receiver_hpp

#include <stdio.h>
#include "slOscManager.h"
class Receiver : public slOscManager {
    
    public:
        Receiver(int port):slOscManager(port){
            
            
            
        }
        void fireMessage(ofxOscMessage *m);
    
    
};

#endif /* Receiver_hpp */
