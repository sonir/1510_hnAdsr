//
//  SeqManager.cpp
//  yagiSys
//
//  Created by sonir on 6/28/15.
//
//

#include "SeqManager.h"
using namespace std;


void SeqManager::executeOneQuantum(quantum *q){
    

#ifdef APP_ASUNA
//    std::cout << "execute a quantun in Asuna" << std::endl;
    note_t note;
    note.phase = (command_e)q->cmd;
    note.node = (node_e)q->param1;
    note.type = (note_type_e)q->param2;
//    note.duration =  q->param2;
    
    
    switch(note.phase){
            
        case VOID:
            notice->notify("VOID", &note); //invoke animation in ofApp.cpp
            cout << "SEQ::VOID" << endl;
            break;
            
        case ARRIVED:
            notice->notify("ARRIVED", &note); //invoke animation in ofApp.cpp
            cout << "SEQ::ARRIVE" << endl;
            break;
            
        case CLIMAX:
            notice->notify("CLIMAX", &note); //invoke animation in ofApp.cpp
            cout << "SEQ::CRIMAX" << endl;
            break;
        
        default:
            cout << "SEQ::unknown PHASE" << endl;
            
//        case SLOW:
//            notice->notify("TRG_ADSR", &note); //invoke animation in ofApp.cpp
//            break;
            
            
    }
    
#endif

    

    
    
}