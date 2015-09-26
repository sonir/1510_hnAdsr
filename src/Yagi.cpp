//
//  Yagi.cpp
//  yagiSys
//
//  Created by sonir on 6/22/15.
//
//

#include "Yagi.h"

//FunctionProtoType
void setAdsrWithDuration(note_t note, adsr_t *param);
void setAdsr(command_e cmd, adsr_t *param);

void YagiApp::setup(){

    //Setup Event Manager
    notice = slNotice::instance();
    notice->addEvent("changeScreenColor", this);
    notice->addEvent("TRG_ADSR", this);
    notice->addEvent("VOID", this);
    notice->addEvent("ARRIVED", this);
    notice->addEvent("CLIMAX", this);
    
    //Setup Sequencer
    sqcr.setup();
    cout << "Yagi::setup" << endl;

    
}


void YagiApp::update(){
    
    sqcr.update();
    
}

void YagiApp::draw(){
    
    drawRects();
    drawCircles();
    runLights();

    
}

void YagiApp::drawRects(){
    
    //Draw Color Rect
    switch(sc_color){
            
        case RED:
            ofSetColor(255,0,0);
            break;
            
        case GREEN:
            ofSetColor(0, 255, 0);
            break;
            
        case BLUE:
            ofSetColor(0, 0, 255);
            break;
            
        case BLACK:
            ofSetColor(0, 0, 0);
            break;
            
        default:
            ofSetColor(255, 255, 0);
            break;
            
    }
    ofRect(SC_MARGIN_WIDTH, SC_MARGIN_HEIGHT, SQUARE_SIZE, SQUARE_SIZE);

}

void YagiApp::drawCircles(){
    
    //draw circle
    for(int i=0;i<CIRCLE_NUM; i++){
        float adsr_val = adsr[i].update();
        adsr_now[i] = adsr_val;

        ofSetColor(255*adsr_val,255*adsr_val,255*adsr_val,220*adsr_val);

        float circle_x = (CIRCLE_MARGIN*i)+(SC_MARGIN_WIDTH+CIRCLE_SIZE);
        float row = 0;
        if(i>=CIRCLE_COLUMN){
            row = 1;
            circle_x -= CIRCLE_MARGIN*CIRCLE_COLUMN;
        }
        ofCircle(circle_x, CIRCLE_MARGIN*row+CIRCLE_MARGIN_TOP, CIRCLE_SIZE*adsr_val);
        
    }
    
    
}

void YagiApp::runLights(){
    
    //draw circle
    for(int i=0;i<CIRCLE_NUM; i++){
        
        
        int bulb_id = 0;
        switch(i){
                
            case 0:
                bulb_id = BLB1;

            case 1:
                bulb_id = BLB2;

            case 2:
                bulb_id = BLB3;

            case 3:
                bulb_id = BLB4;

            case 4:
                bulb_id = BLB5;

            case 5:
                bulb_id = BLB6;

            case 6:
                bulb_id = BLB7;

            case 7:
                bulb_id = BLB8;
                
        }
        
        
        
//        dmx.trigger(node_e node, note_type_e note_type, adsr_now[i]);
//        int num=ofRandom(8);
        dmx.simpleTrigger(bulb_id, adsr_now[i]);
        
    }
    
    
}


//--------------------------------------------------------------
void YagiApp::event(event_type tag, void *param){
    //using void type EXAMPLE: int *num = (int *)param;
    
    cout << "YagiApp :: EVENT..COMES" << endl;
    
    if (tag=="VOID"){
        
        cout << "EVT_OCCR: VOID COMES" << endl;
        
#ifdef APP_ASUNA
        note_t *note = (note_t *)param;
        note_t tmp_note = *note;
        
        adsr_t param;
        int num = note->node;        
        setAdsrWithDuration(tmp_note, &param);        
#endif
        
        //Trigger circle with specified ADSR
        adsr[num].setup(param);
        adsr[num].bang();
        
        
    }else if(tag=="ARRIVED"){
        
        cout << "EVT_OCCR: ARRIVED COMES" << endl;
        note_t *note = (note_t *)param;
        note_t tmp_note = *note;
        
        adsr_t param;
        int num = note->node;
        
        setAdsrWithDuration(tmp_note, &param);
        
        //Trigger circle with specified ADSR
        adsr[num].setup(param);
        adsr[num].bang();
        
        cout << "param a:" << param.attack << "d:" << param.decay << endl;
        
    }else if(tag=="CLIMAX"){
        
        cout << "EVT_OCCR: CLIMAX COMES" << endl;
        note_t *note = (note_t *)param;
        note_t tmp_note = *note;
        
        adsr_t param;
        int num = note->node;
        
        setAdsrWithDuration(tmp_note, &param);

        //Trigger circle with specified ADSR
//        int foo = ofRandom(7);
//       cout << "CH----" << foo << endl;
        adsr[num].setup(param);
        adsr[num].bang();
        
    }
    
    
}


// C Func //////////////////////

void setAdsr(note_type_e nt, adsr_t *param){
    
    switch(nt){
            
        case MAIN_M:
#ifdef DEBUG
            cout << "MAIN_S" << endl;
#endif
            param->attack = 0;
            param->decay = 150;
            param->sustain = 0.5f;
            param->duration = 0;
            param->release = 0;
            break;
            
        case SUB1:
#ifdef DEBUG
            cout << "SUB1" << endl;
#endif
            param->attack = 190;
            param->decay = 630;
            param->sustain = 0.5f;
            param->duration = 1200;
            param->release = 1200;
            break;
            
        case PARTICLE1:
#ifdef DEBUG
            cout << "TRG_SLOW" << endl;
#endif
            param->attack = 1250;
            param->decay = 2400;
            param->sustain = 0.5f;
            param->duration = 4000;
            param->release = 2500;
            break;
            
        default:
            param->attack = 0;
            param->decay = 150;
            param->sustain = 0.5f;
            param->duration = 0;
            param->release = 0;
            break;
            
            
    }

    
}

void setAdsrWithDuration(note_t note, adsr_t *param){
    
    switch(note.type){
            
        case MAIN_M:
#ifdef DEBUG
            cout << "MAIN_M" << endl;
#endif
            param->attack = 4300;
            param->decay = 1;
            param->sustain = 1.0f;
            param->duration = 5000; //note.duration*1000;
            param->release = 13800;
            break;
            
        case SUB1:
#ifdef DEBUG
            cout << "SUB1" << endl;
#endif
            param->attack = 4300;
            param->decay = 1;
            param->sustain = 1.0f;
            param->duration =  5000; //note.duration*1000;
            param->release = 13800;
            break;
            
        case PARTICLE1:
#ifdef DEBUG
            cout << "PARTICLE1" << endl;
#endif
            param->attack = 4300;
            param->decay = 1;
            param->sustain = 1.0f;
            param->duration =  5000; //note.duration*1000;
            param->release = 13800;
            break;
            
        default:
            break;
            
            
    }
    
#ifdef DEBUG
    cout << "adsr=" << note.type << endl;
#endif
    
}
