//
//  MaskFrame.cpp
//  alphaMaskingShaderExample
//
//  Created by bdorse on 12/1/14.
//
//

#include "MaskFrame.h"
MaskFrame::MaskFrame():
_bIsCleared(true),
ofFbo()
{
    clearContents();
}


void MaskFrame::begin()
{
    _bIsCleared = false;
    ofFbo::begin();
}


void MaskFrame::clearContents()
{
    ofFbo::begin();
    ofClear(0, 0, 0, 255);
    ofFbo::end();
    _bIsCleared = true;
}


bool MaskFrame::isCleared()
{
    return _bIsCleared;
}