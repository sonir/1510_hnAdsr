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

    note_t note;
    note.phase = (command_e)q->cmd;
    note.node = (node_e)q->param1;
    note.type = (note_type_e)q->param2;
    note.duration = q->param3;        
    notice->notify("TRG_ADSR", &note); //invoke animation in ofApp.cpp
    
#endif

    

    
    
}