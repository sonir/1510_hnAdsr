//
//  Dmx.cpp
//  hnAdsr
//
//  Created by sonir on 9/24/15.
//
//
#include "Dmx.hpp"


void Dmx::setup(){
    
    
    
    
}


void Dmx::simpleTrigger(int ch, float fval){
    
    
    dest->send("/dmx/universe/0" , ch, fval);
    
}

void Dmx::trigger(node_e node, note_type_e note_type, float fval){
    
    
    if( note_type == MAIN_S ||  note_type == MAIN_M ||  note_type == MAIN_L ){
        
        switch (node){
                
            case NODE_A:
                cout << "DMX OUT : NODE_A : Main" << endl;
                dest->send("/dmx/universe/0" , ORG_A, fval);
                dest->send("/dmx/universe/0" , ORG_L_A, fval);
                break;
                
            case NODE_B:
                cout << "DMX OUT : NODE_B : Main" << endl;
                dest->send("/dmx/universe/0" , ORG_B, fval);
                dest->send("/dmx/universe/0" , ORG_L_B, fval);
                break;
                
            case NODE_C:
                cout << "DMX OUT : NODE_C : Main" << endl;
                dest->send("/dmx/universe/0" , ORG_C, fval);
                dest->send("/dmx/universe/0" , ORG_L_C, fval);
                break;
                
            case NODE_D:
                cout << "DMX OUT : NODE_D : Main" << endl;
                dest->send("/dmx/universe/0" , ORG_D, fval);
                dest->send("/dmx/universe/0" , ORG_L_D, fval);
                break;
                
        }
        
        
        
    }else if ( note_type == SUB1 ||  note_type == SUB2 ||  note_type == SUB3 ){
        

        switch (node){
                
            case NODE_A:
                cout << "DMX OUT : NODE_A : SUB" << endl;
                break;
                
            case NODE_B:
                cout << "DMX OUT : NODE_A : SUB" << endl;
                break;
                
            case NODE_C:
                cout << "DMX OUT : NODE_A : SUB" << endl;
                break;
                
            case NODE_D:
                cout << "DMX OUT : NODE_A : SUB" << endl;
                break;
                
        }
        
        
    } else {
        
        //Particle is here.
        switch (node){
                
            case NODE_A:
                break;
                
            case NODE_B:
                break;
                
            case NODE_C:
                break;
                
            case NODE_D:
                break;
        
        }
        
    }
    
    
    
}