//
//  Preset.cpp
//  hnAdsr
//
//  Created by sonir on 9/26/15.
//
//

#include "Preset.hpp"

void Preset::setAdsr(note_t *pNt){
    
    note = pNt;    
    
    switch(note->phase){
            
        case VOID:
            setForVoid();
            break;

        case ARRIVED:
            setForArrived();
            break;

        case CLIMAX:
            setForClimax();
            break;
            
        default:
            std::cout << "[Preset.setAdsr()]ERR: unknown phase was assigned." << std::endl;
            
    }
    
}


void Preset::setForVoid(){
    
    switch(note->type){
            
        case MAIN_M:
            note->adsr.attack = 4300;
            note->adsr.decay = 1;
            note->adsr.sustain = 1.0f;
            note->adsr.duration = 5000;//note->duration; //note->duration*1000;
            note->adsr.release = 13800;
            note->amp = 1.0f;
            note->adsr_sound=note->adsr;
            break;
            
        case SUB1:
            note->adsr.attack = 4300;
            note->adsr.decay = 1;
            note->adsr.sustain = 1.0f;
            note->adsr.duration =  5000;//note->duration; //note->duration*1000;
            note->adsr.release = 13800;
            note->amp = 1.0f;
            note->adsr_sound=note->adsr;
            break;
            
        case GLITCH1:
            note->adsr.attack = 4300;
            note->adsr.decay = 1;
            note->adsr.sustain = 1.0f;
            note->adsr.duration =  5000;//note->duration;             //note->duration*1000;
            note->adsr.release = 13800;
            note->amp = 1.0f;
            note->adsr_sound=note->adsr;
            break;
            
        default:
            break;
            
    }
    

    
}

void Preset::setForArrived(){

    switch(note->type){
            
        case MAIN_M:
            note->adsr.attack = 4300;
            note->adsr.decay = 1;
            note->adsr.sustain = 1.0f;
            note->adsr.duration = 5000;//note->duration; //note->duration*1000;
            note->adsr.release = 13800;
            note->adsr_sound=note->adsr;
            note->amp = 1.0f;
            break;
            
        case SUB1:
            note->adsr.attack = 4300;
            note->adsr.decay = 1;
            note->adsr.sustain = 1.0f;
            note->adsr.duration =  5000;//note->duration; //note->duration*1000;
            note->adsr.release = 13800;
            note->adsr_sound=note->adsr;
            note->amp = 1.0f;
            break;
            
        case GLITCH1:
            note->adsr.attack = 4300;
            note->adsr.decay = 1;
            note->adsr.sustain = 1.0f;
            note->adsr.duration =  5000;//note->duration;             //note->duration*1000;
            note->adsr.release = 13800;
            note->adsr_sound=note->adsr;
            note->amp = 1.0f;
            break;
            
        default:
            break;
            
    }
    
    
}

void Preset::setForClimax(){

    switch(note->type){
            
        case MAIN_M:
            note->adsr.attack = 4300;
            note->adsr.decay = 1;
            note->adsr.sustain = 1.0f;
            note->adsr.duration = 5000;//note->duration; //note->duration*1000;
            note->adsr.release = 13800;
            note->adsr_sound=note->adsr;
            note->amp = 1.0f;
            break;
            
        case SUB1:
            note->adsr.attack = 4300;
            note->adsr.decay = 1;
            note->adsr.sustain = 1.0f;
            note->adsr.duration =  5000;//note->duration; //note->duration*1000;
            note->adsr.release = 13800;
            note->adsr_sound=note->adsr;
            note->amp = 1.0f;
            break;
            
        case GLITCH1:
            note->adsr.attack = 4300;
            note->adsr.decay = 1;
            note->adsr.sustain = 1.0f;
            note->adsr.duration =  5000;//note->duration;             //note->duration*1000;
            note->adsr.release = 13800;
            note->adsr_sound=note->adsr;
            note->amp = 1.0f;
            break;
            
        default:
            break;
            
    }
    
    
}

