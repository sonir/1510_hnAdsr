//
//  Yagi.cpp
//  yagiSys
//
//  Created by sonir on 6/22/15.
//
//

#include "Yagi.h"



void YagiApp::setup(){

    //Setup Event Manager
    notice = slNotice::instance();
    notice->addEvent("TRG_ADSR", this);
    notice->addEvent("SET_OFFSET", this);    
    
    //Setup Sequencer
    sqcr.setup();
    cout << "Yagi::setup" << endl;
    
//    output.setAds;

    
}


void YagiApp::update(){
    
    
    sqcr.update();
    output.update();
    
    
    adsr_t a;
    note_t n;
    n.phase=ARRIVED;
    n.node=NODE_D;
    n.amp=1.0;
    n.adsr=a;
    n.adsr_sound=a;
    output.setAdsr(n); //Trigger
    
    
//    command_e phase;
//    node_e node;
//    note_type_e type;
//    float duration;
//    adsr_t adsr;
//    adsr_t adsr_sound;
//    float amp;

    
}

void YagiApp::draw(){
    
    drawCircles();
    
}


void YagiApp::drawCircles(){
    
    //draw circle
    for(int i=0; i<output.vals.size(); i++){
        float adsr_val = output.getCurrent(i);

        ofSetColor(255*adsr_val,255*adsr_val,255*adsr_val,220*adsr_val);

        float circle_x = (CIRCLE_MARGIN*i)+(SC_MARGIN_WIDTH+CIRCLE_SIZE);
        int row = 0;
        if(i>=CIRCLE_COLUMN){
            row = i/CIRCLE_COLUMN;
            circle_x -= CIRCLE_MARGIN*CIRCLE_COLUMN*row;
        }
        float circle_y = CIRCLE_MARGIN*row+CIRCLE_MARGIN_TOP;
        ofCircle(circle_x, circle_y, CIRCLE_SIZE*adsr_val);
        
        //Disp, ParamID
        ofSetColor(128);
        ofDrawBitmapString(ofToString(i+1), circle_x, circle_y);
        ofDrawBitmapString(ofToString(adsr_val), circle_x, circle_y+15);
        
    }
    
    
}

//--------------------------------------------------------------
void YagiApp::mute(){
    
    output.allMute();    
    
}



//--------------------------------------------------------------
void YagiApp::event(event_type tag, void *param){

    note_t *note = (note_t *)param;
    note_t tmp_note = *note;
    now_phase = tmp_note.phase;
    
    if(tag=="TRG_ADSR"){

        preset.setAdsr(&tmp_note);
        output.setAdsr(tmp_note); //Trigger

    }else if(tag=="SET_OFFSET"){
        
        output.setOffset(tmp_note.node, tmp_note.type);
        
    }
    
    
    
}
