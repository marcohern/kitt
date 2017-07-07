//
//  Color.hpp
//  kitt
//
//  Created by Marco Hernandez on 6/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#ifndef Color_hpp
#define Color_hpp

#include <stdio.h>

namespace Graphics {
    class Color {
    private:
        float r, g, b, a;
    public:
        static const Color Transparent;
        static const Color TransparentBlack;
        static const Color TransparentGray;
        static const Color TransparentWhite;
        static const Color Black;
        static const Color DarkGrey;
        static const Color Grey;
        static const Color LightGrey;
        static const Color White;
        
        static const Color Red;
        static const Color Green;
        static const Color Blue;
        
        static const Color DarkRed;
        static const Color DarkGreen;
        static const Color DarkBlue;
        
        static const Color Yellow;
        static const Color Magenta;
        static const Color Cyan;
        
        static const Color DarkYellow;
        static const Color DarkMagenta;
        static const Color DarkCyan;
        
        Color();
        Color(int r, int g, int b, int a);
        Color(float r, float g, float b, float a);
        virtual ~Color();
        
        int iR() const;
        int iG() const;
        int iB() const;
        int iA() const;
        
        char cR() const;
        char cG() const;
        char cB() const;
        char cA() const;
        
        float R() const;
        float G() const;
        float B() const;
        float A() const;
        
        void set(int r, int g, int b, int a);
        void set(float r, float g, float b, float a);
        
        void setR(int r);
        void setR(float r);
        void setG(int g);
        void setG(float g);
        void setB(int b);
        void setB(float b);
        void setA(int a);
        void setA(float a);
    };
}
#endif /* Color_hpp */
