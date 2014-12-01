//
//  MaskTool.cpp
//  alphaMaskingShaderExample
//
//  Created by bdorse on 12/1/14.
//
//

#include "MaskTool.h"
MaskTool::MaskTool():
_bEnabled(true),
_bBrushDown(false),
_maxNumUndos(20),
_curUndoFrame(0),
_width(0),
_height(0)
{
    ofRegisterMouseEvents(this);
    
#ifdef TARGET_OPENGLES
	_maskShader.load("shadersES2/mask");
    _frameCombineShader.load("shadersES2/frame_combine");
#else
	if(ofIsGLProgrammableRenderer()){
		_maskShader.load("shadersGL3/mask");
        _frameCombineShader.load("shadersGL3/frame_combine");
	}else{
		_maskShader.load("shadersGL2/mask");
        _frameCombineShader.load("shadersGL2/frame_combine");
	}
#endif
    
    _brushImg.loadImage("brush.png");
}

MaskTool::~MaskTool() {
    ofUnregisterMouseEvents(this);
}


void MaskTool::setup(int width, int height, bool sizeChanged)
{
    _width = width;
    _height = height;
    
    if (sizeChanged)
    {
        _maskFrame.allocate(_width, _height, GL_RGBA, 8);
        
        _frame.allocate(_width, _height, GL_RGBA, 8);
        
        _frameStack.clear();
        
        for (int i = 0; i < _maxNumUndos; i++)
        {
            _frameStack.push_back(shared_ptr<MaskFrame>(new MaskFrame()));
            _frameStack[i]->allocate(_width, _height, GL_RGBA, 8);
        }
    }
    
    _maskFrame.begin();
    ofClear(0, 0, 0, 255);
    _maskFrame.end();
    
    _frame.begin();
    ofClear(0, 0, 0, 255);
    _frame.end();

    for (int i = 0; i < _frameStack.size(); i++) {
        _frameStack[i]->clearContents();
    }
}

void MaskTool::reset()
{
    setup(_width, _height, false);
}

void MaskTool::reset(int width, int height)
{
    bool sizeChanged = false;
    
    if (width != _width &&
        height != _height) {
        sizeChanged = true;
    }
    
    setup(width, height, sizeChanged);
}

void MaskTool::update(ofTexture& srcTex)
{
    ofSetColor(255, 255);
    
    if (_bBrushDown)
    {
        _frameStack[_curUndoFrame]->begin();
        _brushImg.draw(ofGetMouseX() - 25, ofGetMouseY() - 25, 50, 50);
        _frameStack[_curUndoFrame]->end();
    }
    
    // combine all frames in _frameStack into _maskFrame
    for (int i = 0; i < _frameStack.size(); i++)
    {
        
        if (!_frameStack[i]->isCleared())
        {
            _maskFrame.begin();

            _frameCombineShader.begin();
            _frameCombineShader.setUniformTexture("frameTex", _frameStack[i]->getTextureReference(), 1);
            _frameCombineShader.end();
            
            _maskFrame.end();
        }
    }

// uncomment later
//    _frame.begin();
//    // Cleaning everthing with alpha mask on 0 in order to make it transparent for default
//    ofClear(0, 0, 0, 0);
//    
//    _maskShader.begin();
//    _maskShader.setUniformTexture("maskTex", _maskFrame.getTextureReference(), 1);
//    
//    srcTex.draw(0,0);
//    
//    _maskShader.end();
//    _frame.end();

}


void MaskTool::draw(ofTexture & dstTex)
{
    ofSetColor(255, 255);
//    _frameStack[_curUndoFrame]->draw(0, 0);
    _maskFrame.draw(0, 0);
//    dstTex.draw(0, 0);
//    _frame.draw(0, 0);
}


void MaskTool::setMaxUndos(int numUndos)
{
    
}


void MaskTool::setEnabled(bool enable)
{
    _bEnabled = enable;
}


void MaskTool::mouseMoved(ofMouseEventArgs& e)
{
    
}


void MaskTool::mouseDragged(ofMouseEventArgs& e)
{
    
}


void MaskTool::mousePressed(ofMouseEventArgs& e)
{
   
    _bBrushDown = true;
    
    shared_ptr<MaskFrame> frame = _frameStack[_curUndoFrame];
    
    if (!frame->isCleared()) frame->clearContents();
}


void MaskTool::mouseReleased(ofMouseEventArgs& e)
{
    _bBrushDown = false;
    
    if (_curUndoFrame < _frameStack.size() - 1)
    {
        _curUndoFrame++;
    }
    else
    {
        _curUndoFrame = 0;
    }
}


int MaskTool::getNumUndos()
{
   
}


int MaskTool::getMaxNumUndos()
{
    return _maxNumUndos;
}


bool MaskTool::undo()
{
    
}


bool MaskTool::getEnabled()
{
    return _bEnabled;
}


