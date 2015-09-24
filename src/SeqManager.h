//
//  SeqManager.h
//  yagiSys
//
//  Created by sonir on 6/28/15.
//
//

#ifndef __yagiSys__SeqManager__
#define __yagiSys__SeqManager__

#include <stdio.h>
#include "slSequencer.h"
#include "setup.h"

//typedef enum {TEST2, FAST, MID, SLOW} command_e;
typedef enum {VOID, ARRIVED, CLIMAX} command_e;
typedef enum {NODE_A, NODE_B, NODE_C, NODE_D} node_e;
typedef enum {MAIN_S, MAIN_M, MAIN_L, SUB1, SUB2, SUB3, PARTICLE1, PARTICLE2, PARTICLE3} note_type_e;
typedef enum {RED,GREEN,BLUE,BLACK} color_e;
typedef struct note_t { //Using trigger with duration (=sustain_time)
    
    command_e phase;
    int node;
    int type;
    float duration;
    
    
}note_t;

class SeqManager : public slSequencer {
  
    public:
        void executeOneQuantum(quantum *q);
    
        void test(){

            std::cout << "SEQ::test invoked." << std::endl;
            
            note_t note;
            note.phase = VOID;
            note.node = NODE_A;
            note.type = MAIN_M;
            notice->notify("VOID", &note); //invoke animation in ofApp.cpp
            
        };
        color_e sc_color = BLACK;

};

#endif /* defined(__yagiSys__SeqManager__) */VOID