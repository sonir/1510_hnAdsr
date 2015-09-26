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
    
    //Setup Sequencer
    sqcr.setup();
    cout << "Yagi::setup" << endl;

    
}


void YagiApp::update(){
    
    sqcr.update();
    output.update();
    
}

void YagiApp::draw(){
    
    drawCircles();
    
}


void YagiApp::drawCircles(){
    
    //draw circle
    for(int i=0; i<output.vals.size(); i++){
        float adsr_val = output.getCurrent(i+1);

        ofSetColor(255*adsr_val,255*adsr_val,255*adsr_val,220*adsr_val);

        float circle_x = (CIRCLE_MARGIN*i)+(SC_MARGIN_WIDTH+CIRCLE_SIZE);
        int row = 0;
        if(i>=CIRCLE_COLUMN){
            row = i/CIRCLE_COLUMN;
            circle_x -= CIRCLE_MARGIN*CIRCLE_COLUMN*row;
        }
        float circle_y = CIRCLE_MARGIN*row+CIRCLE_MARGIN_TOP;
        ofCircle(circle_x, circle_y, CIRCLE_SIZE*adsr_val);
        ofSetColor(128);
        ofDrawBitmapString(ofToString(i+1), circle_x, circle_y);
        
    }
    
    
}


//--------------------------------------------------------------
void YagiApp::event(event_type tag, void *param){

    note_t *note = (note_t *)param;
    note_t tmp_note = *note;
    
    preset.setAdsr(&tmp_note);
    output.setAdsr(tmp_note); //Trigger
    now_phase = tmp_note.phase;
    
    
}
