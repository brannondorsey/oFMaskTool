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
    void setMaxUndos(int numUndos);
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
    
    int _width;
    int _height;
    int _maxNumUndos;
    int _curUndoFrame;
    
    bool _bEnabled;
    bool _bBrushDown;
    
    ofFbo _frame;
    ofFbo _maskFrame;
    std::vector<shared_ptr<MaskFrame> > _frameStack;
    
    ofImage _brushImg;
    
    ofShader _frameCombineShader;
    ofShader _maskShader;
    
};

#endif /* defined(__MaskTool__) */
