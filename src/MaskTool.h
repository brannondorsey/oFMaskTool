//
//  MaskTool.h
//  alphaMaskingShaderExample
//
//  Created by bdorse on 12/1/14.
//
//

#ifndef __MaskTool__
#define __MaskTool__

#include "ofMain.h"
#include "MaskFrame.h"

class MaskTool {
public:
    
    MaskTool();
    ~MaskTool();
    
    void setup(int width, int height, bool sizeChanged = true);
    void reset();
    void reset(int width, int height);
    void update(ofTexture& srcTex);
    void draw(ofTexture & dstTex);
    void setEnabled(bool enable);
    
    void mouseMoved(ofMouseEventArgs& e);
	void mouseDragged(ofMouseEventArgs& e);
	void mousePressed(ofMouseEventArgs& e);
    void mouseReleased(ofMouseEventArgs& e);
    void mouseScrolled(ofMouseEventArgs& e);

    int getMaxNumUndos();
    int getNumUndos();
    
    bool undo();
    bool getEnabled();
    
protected:
    
    // Apply texture 2 to fbo 1
    template<typename BaseHasFbo>
    void _combineFrames(BaseHasFbo& fbo, ofTexture& tex)
    {
        ofFbo tmpFbo = fbo;
        fbo.begin();
        
        _frameCombineShader.begin();
        _frameCombineShader.setUniformTexture("frameTex", tex, 1);
        tmpFbo.draw(0, 0);
        _frameCombineShader.end();
        
        fbo.end();
    }

    
    int _width;
    int _height;
    int _maxNumUndos;
    int _curUndoFrame;
    
    bool _bEnabled;
    bool _bBrushDown;
    bool _bFrameOverflow;
    
    ofFbo _frame;
    ofFbo _maskFrame;
    std::deque<shared_ptr<MaskFrame> > _frameStack;
    
    ofImage _brushImg;
    
    ofShader _frameCombineShader;
    ofShader _maskShader;
    
};

#endif /* defined(__MaskTool__) */
