//
//  Preset.hpp
//  hnAdsr
//
//  Created by sonir on 9/26/15.
//
//

#ifndef Preset_hpp
#define Preset_hpp

#include <stdio.h>
#include "portSetup.h"

class Preset {
    
    public:
        void setAdsr(note_t *pNt);
        void setForVoid();
        void setForArrived();
        void setForClimax();
        note_t *note;
    
};

#endif /* Preset_hpp */
