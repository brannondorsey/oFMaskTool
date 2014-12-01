//
//  MaskFrame.h
//  alphaMaskingShaderExample
//
//  Created by bdorse on 12/1/14.
//
//

#ifndef __MaskFrame__
#define __MaskFrame__

#include "ofMain.h"

class MaskFrame : public ofFbo {
public:
    
    MaskFrame();
    
    void clearContents();
    void begin();
    
    bool isCleared();
    
protected:
    
    bool _bIsCleared;
};

#endif /* defined(__MaskFrame__) */
