//
//  Color.cpp
//  kitt
//
//  Created by Marco Hernandez on 6/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#include "Color.hpp"

namespace Graphics {
    
    
    const Color Color::Transparent     (  0.0f,  0.0f,  0.0f,  0.0);
    const Color Color::TransparentBlack(  0.0f,  0.0f,  0.0f,  0.0);
    const Color Color::TransparentGray (127.0f,127.0f,127.0f,  0.0);
    const Color Color::TransparentWhite(255.0f,255.0f,255.0f,255.0);
    
    const Color Color::Black    (  0.0f,  0.0f,  0.0f,255.0f);
    const Color Color::DarkGrey ( 64.0f, 64.0f, 64.0f,255.0f);
    const Color Color::Grey     (128.0f,128.0f,128.0f,255.0f);
    const Color Color::LightGrey(192.0f,192.0f,192.0f,255.0f);
    const Color Color::White    (255.0f,255.0f,255.0f,255.0f);
    
    const Color Color::Red  (255.0f,  0.0f,  0.0f,255.0f);
    const Color Color::Green(  0.0f,255.0f,  0.0f,255.0f);
    const Color Color::Blue (  0.0f,  0.0f,255.0f,255.0f);
    
    const Color Color::DarkRed  (128.0f,  0.0f,  0.0f,255.0f);
    const Color Color::DarkGreen(  0.0f,128.0f,  0.0f,255.0f);
    const Color Color::DarkBlue (  0.0f,  0.0f,128.0f,255.0f);
    
    const Color Color::Yellow (255.0f,255.0f,  0.0f,255.0f);
    const Color Color::Magenta(255.0f,  0.0f,255.0f,255.0f);
    const Color Color::Cyan   (  0.0f,255.0f,255.0f,255.0f);
    
    const Color Color::DarkYellow (128.0f,128.0f,  0.0f,255.0f);
    const Color Color::DarkMagenta(128.0f,  0.0f,128.0f,255.0f);
    const Color Color::DarkCyan   (  0.0f,128.0f,128.0f,255.0f);
    
    Color::Color() {
        this->set(0,0,0,0);
    }
    
    Color::Color(int r, int g, int b, int a) {
        this->set(r,g,b,a);
    }
    
    Color::Color(float r, float g, float b, float a) {
        this->set(r,g,b,a);
    }
    
    Color::~Color() {
        this->set(0,0,0,0);
    }
    
    int Color::iR() const { return (int)r; }
    int Color::iG() const { return (int)g; }
    int Color::iB() const { return (int)b; }
    int Color::iA() const { return (int)a; }
    
    char Color::cR() const { return (char)r; }
    char Color::cG() const { return (char)g; }
    char Color::cB() const { return (char)b; }
    char Color::cA() const { return (char)a; }
    
    float Color::R() const { return r; }
    float Color::G() const { return g; }
    float Color::B() const { return b; }
    float Color::A() const { return a; }
    
    void Color::set(int r, int g, int b, int a) {
        this->r = (float)r;
        this->g = (float)g;
        this->b = (float)b;
        this->a = (float)a;
    }
    
    void Color::set(float r, float g, float b, float a) {
        this->r = r;
        this->g = g;
        this->b = b;
        this->a = a;
    }
    
    void Color::setR(int r) { this->r = (float)r; }
    void Color::setG(int g) { this->g = (float)g; }
    void Color::setB(int b) { this->b = (float)b; }
    void Color::setA(int a) { this->a = (float)a; }
    
    void Color::setR(float r) { this->r = r; }
    void Color::setG(float g) { this->g = g; }
    void Color::setB(float b) { this->b = b; }
    void Color::setA(float a) { this->a = a; }
}
