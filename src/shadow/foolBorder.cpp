#include "foolBorder.h"

//--------------------------------------------------------------
void foolBorder::draw(ofFbo silhouetteFbo_, float offset_) {
    
    //setup
    ofFbo::Settings settings;
    settings.width = silhouetteFbo_.getWidth();
    settings.height = silhouetteFbo_.getHeight();
    settings.internalformat = GL_RGBA;
    settings.textureTarget = GL_TEXTURE_RECTANGLE_ARB;
    settings.maxFilter = GL_LINEAR; GL_NEAREST;
    settings.numSamples = 0;
    settings.numColorbuffers = 1;
    settings.useDepth = false;
    settings.useStencil = false;
    blur.setup(settings);
    blur.blurOffset = offset_;
    blur.blurPasses = 5;
    blur.numBlurOverlays = 1;
    blur.blurOverlayGain = 255;
    blur.beginDrawScene();
    ofClear(0);
    ofSetColor(255);
    silhouetteFbo_.draw(0, 0);
    blur.endDrawScene();
    
    //draw
    blur.drawBlurFbo();
}
