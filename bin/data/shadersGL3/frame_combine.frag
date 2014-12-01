#version 150

// these are our textures
uniform sampler2DRect maskFrameTex;
uniform sampler2DRect frameTex;

// this comes from the vertex shader
in vec2 texCoordVarying;

// this is the output of the fragment shader
out vec4 outputColor;

void main()
{
    // get rgb from tex0
    float maskR = texture(maskFrameTex, texCoordVarying).r;
    float frameR = texture(frameTex, texCoordVarying).r;
    maskR += frameR;
    maskR = clamp(maskR, 0, 255);
    vec3 brightness = vec3(maskR, maskR, maskR);
    outputColor = vec4(brightness, 255);
}