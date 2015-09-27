//
//  Preset.cpp
//  hnAdsr
//
//  Created by sonir on 9/26/15.
//
//

#include "Preset.hpp"

using namespace std;

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

        case MAIN_S:
            note->adsr.attack = 8000;
            note->adsr.decay = 0;
            note->adsr.sustain = 1.0f;
            note->adsr.duration = note->duration;//note->duration; //note->duration*1000;
            note->adsr.release = 3000;
            note->amp = 1.0f;
            note->adsr_sound=note->adsr;
            break;
            
        case MAIN_M:
            note->adsr.attack = 8000;
            note->adsr.decay = 0;
            note->adsr.sustain = 1.0f;
            note->adsr.duration = note->duration;//note->duration; //note->duration*1000;
            note->adsr.release = 3000;
            note->amp = 1.0f;
            note->adsr_sound=note->adsr;
            break;
            
        case MAIN_L:
            note->adsr.attack = 8000;
            note->adsr.decay = 0;
            note->adsr.sustain = 1.0f;
            note->adsr.duration = note->duration;//note->duration; //note->duration*1000;
            note->adsr.release = 3000;
            note->amp = 1.0f;
            note->adsr_sound=note->adsr;
            break;
            
        case SUB1:
            note->adsr.attack = 4300;
            note->adsr.decay = 1;
            note->adsr.sustain = 1.0f;
            note->adsr.duration = note->duration;//note->duration; //note->duration*1000;
            note->adsr.release = 13800;
            note->amp = 1.0f;
            note->adsr_sound=note->adsr;
            break;

        case SUB2:
            note->adsr.attack = 4300;
            note->adsr.decay = 1;
            note->adsr.sustain = 1.0f;
            note->adsr.duration = note->duration;//note->duration; //note->duration*1000;
            note->adsr.release = 13800;
            note->amp = 1.0f;
            note->adsr_sound=note->adsr;
            break;

        case SUB3:
            note->adsr.attack = 4300;
            note->adsr.decay = 1;
            note->adsr.sustain = 1.0f;
            note->adsr.duration = note->duration;//note->duration; //note->duration*1000;
            note->adsr.release = 13800;
            note->amp = 1.0f;
            note->adsr_sound=note->adsr;
            break;
            
            
        case GLITCH1:
            note->adsr.attack = 4300;
            note->adsr.decay = 1;
            note->adsr.sustain = 1.0f;
            note->adsr.duration = note->duration;//note->duration;             //note->duration*1000;
            note->adsr.release = 13800;
            note->amp = 1.0f;
            note->adsr_sound=note->adsr;
            break;

        case GLITCH2:
            note->adsr.attack = 4300;
            note->adsr.decay = 1;
            note->adsr.sustain = 1.0f;
            note->adsr.duration = note->duration;//note->duration;             //note->duration*1000;
            note->adsr.release = 13800;
            note->amp = 1.0f;
            note->adsr_sound=note->adsr;
            break;
            
        case GLITCH3:
            note->adsr.attack = 4300;
            note->adsr.decay = 1;
            note->adsr.sustain = 1.0f;
            note->adsr.duration = note->duration;//note->duration;             //note->duration*1000;
            note->adsr.release = 13800;
            note->amp = 1.0f;
            note->adsr_sound=note->adsr;
            break;

            
        default:
            cout << "[ERR] PRESET.Unknown NOTE_TYPE Comes" << endl;
            break;
            
    }
    

    
}

void Preset::setForArrived(){

    switch(note->type){
            
        case MAIN_S:
            note->adsr.attack = 0;
            note->adsr.decay = 0;
            note->adsr.sustain = 1.0f;
            note->adsr.duration = note->duration; //note->duration*1000;
            note->adsr.release = 600;
            note->adsr_sound.attack = 0;
            note->adsr_sound.decay = 0;
            note->adsr_sound.sustain = 1.0f;
            note->adsr_sound.duration = note->duration;//note->duration; //note->duration*1000;
            note->adsr_sound.release = 600;
            note->amp = 1.0f;
            break;

        
        case MAIN_M:
            note->adsr.attack = 4300;
            note->adsr.decay = 1;
            note->adsr.sustain = 1.0f;
            note->adsr.duration = note->duration; //note->duration*1000;
            note->adsr.release = 8000;
            note->adsr_sound.attack = 500;
            note->adsr_sound.decay = 0;
            note->adsr_sound.sustain = 1.0f;
            note->adsr_sound.duration = note->duration;//note->duration; //note->duration*1000;
            note->adsr_sound.release = 500;
            
            note->amp = 1.0f;
            break;

        case MAIN_L:
            note->adsr.attack = 4300;
            note->adsr.decay = 1;
            note->adsr.sustain = 1.0f;
            note->adsr.duration = note->duration; //note->duration*1000;
            note->adsr.release = 13800;
            note->adsr_sound.attack = 500;
            note->adsr_sound.decay = 0;
            note->adsr_sound.sustain = 1.0f;
            note->adsr_sound.duration = note->duration;//note->duration; //note->duration*1000;
            note->adsr_sound.release = 500;

            note->amp = 1.0f;
            break;
            
            
        case SUB1:
            note->adsr.attack = 4300;
            note->adsr.decay = 1;
            note->adsr.sustain = 1.0f;
            note->adsr.duration =  note->duration; //note->duration*1000;
            note->adsr.release = 13800;
            note->adsr_sound.attack = 500;
            note->adsr_sound.decay = 0;
            note->adsr_sound.sustain = 1.0f;
            note->adsr_sound.duration = note->duration;//note->duration; //note->duration*1000;
            note->adsr_sound.release = 500;
            note->amp = 1.0f;
            break;

        case SUB2:
            note->adsr.attack = 4300;
            note->adsr.decay = 1;
            note->adsr.sustain = 1.0f;
            note->adsr.duration =  note->duration; //note->duration*1000;
            note->adsr.release = 13800;
            note->adsr_sound.attack = 500;
            note->adsr_sound.decay = 0;
            note->adsr_sound.sustain = 1.0f;
            note->adsr_sound.duration = note->duration;//note->duration; //note->duration*1000;
            note->adsr_sound.release = 500;
            note->amp = 1.0f;
            break;

        case SUB3:
            note->adsr.attack = 4300;
            note->adsr.decay = 1;
            note->adsr.sustain = 1.0f;
            note->adsr.duration =  note->duration; //note->duration*1000;
            note->adsr.release = 13800;
            note->adsr_sound.attack = 500;
            note->adsr_sound.decay = 0;
            note->adsr_sound.sustain = 1.0f;
            note->adsr_sound.duration = note->duration;//note->duration; //note->duration*1000;
            note->adsr_sound.release = 500;
            note->amp = 1.0f;
            break;
            
        case GLITCH1:
            note->adsr.attack = 4300;
            note->adsr.decay = 1;
            note->adsr.sustain = 1.0f;
            note->adsr.duration =  note->duration;             //note->duration*1000;
            note->adsr.release = 13800;
            note->adsr_sound=note->adsr;
            note->adsr_sound.attack = 500;
            note->adsr_sound.decay = 0;
            note->adsr_sound.sustain = 1.0f;
            note->adsr_sound.duration = note->duration;//note->duration; //note->duration*1000;
            note->adsr_sound.release = 500;
            note->amp = 1.0f;
            break;

        case GLITCH2:
            note->adsr.attack = 4300;
            note->adsr.decay = 1;
            note->adsr.sustain = 1.0f;
            note->adsr.duration =  note->duration;             //note->duration*1000;
            note->adsr.release = 13800;
            note->adsr_sound=note->adsr;
            note->adsr_sound.attack = 500;
            note->adsr_sound.decay = 0;
            note->adsr_sound.sustain = 1.0f;
            note->adsr_sound.duration = note->duration;//note->duration; //note->duration*1000;
            note->adsr_sound.release = 500;
            note->amp = 1.0f;
            break;
            
            
        default:
            cout << "[ERR] PRESET.Unknown NOTE_TYPE Comes" << endl;
            break;
            
    }
    
    
}

void Preset::setForClimax(){

    switch(note->type){
            
        case MAIN_M:
            note->adsr.attack = 4300;
            note->adsr.decay = 1;
            note->adsr.sustain = 1.0f;
            note->adsr.duration = note->duration;//note->duration; //note->duration*1000;
            note->adsr.release = 13800;
            note->adsr_sound=note->adsr;
            note->amp = 1.0f;
            break;
            
        case MAIN_L:
            note->adsr.attack = 4300;
            note->adsr.decay = 1;
            note->adsr.sustain = 1.0f;
            note->adsr.duration = note->duration;//note->duration; //note->duration*1000;
            note->adsr.release = 13800;
            note->adsr_sound=note->adsr;
            note->adsr_sound.attack = 500;
            note->adsr_sound.decay = 0;
            note->adsr_sound.sustain = 1.0f;
            note->adsr_sound.duration = note->duration;//note->duration; //note->duration*1000;
            note->adsr_sound.release = 500;
            note->amp = 1.0f;
            break;
            
        case SUB1:
            note->adsr.attack = 4300;
            note->adsr.decay = 1;
            note->adsr.sustain = 1.0f;
            note->adsr.duration =  note->duration;//note->duration; //note->duration*1000;
            note->adsr.release = 13800;
            note->adsr_sound=note->adsr;
            note->amp = 1.0f;
            break;
            
        case GLITCH1:
            note->adsr.attack = 4300;
            note->adsr.decay = 1;
            note->adsr.sustain = 1.0f;
            note->adsr.duration =  note->duration;//note->duration;             //note->duration*1000;
            note->adsr.release = 13800;
            note->adsr_sound=note->adsr;
            note->amp = 1.0f;
            break;
            
        default:
            cout << "[ERR] PRESET.Unknown NOTE_TYPE Comes" << endl;
            break;
            
    }
    
    
}

