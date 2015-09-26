//
//  Dmx.hpp
//  hnAdsr
//
//  Created by sonir on 9/24/15.
//
//

#ifndef Dmx_hpp
#define Dmx_hpp

#include <stdio.h>
#include "setup.h"
#include "Dmx.hpp"
#include "Desitination.h"


//JUST FOR REFERENCE
//ENUM for Event Hundling
//typedef enum {VOID, ARRIVED, CLIMAX} command_e;
//typedef enum {NODE_A, NODE_B, NODE_C, NODE_D} node_e;
//typedef enum {MAIN_S, MAIN_M, MAIN_L, SUB1, SUB2, SUB3, PARTICLE1, PARTICLE2, PARTICLE3} note_type_e;
//typedef enum {RED,GREEN,BLUE,BLACK} color_e;


class Dmx {
    
public:
    Dmx(){
        
        dest = new Destination("224.0.0.1", 7770);
        
    }
    
    Destination *dest;
    void setup();
    void trigger(node_e node, note_type_e note_type, float fval);
    void simpleTrigger(int ch, float fval);
    
};


#endif /* Dmx_hpp */
