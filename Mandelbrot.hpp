#ifndef MANDELBROT_H
#define MANDELBROT_H
#include<iostream>
#include <vector>
#include<fstream>

namespace my{

    struct rgb{
        uint8_t red;
        uint8_t green;
        uint8_t blue;
    };

    class Render {
        public:
            Render(int w , int h):width(w) , height(h) , screen(w*h){}
            void mandelbrot(const std::string& file  ,const int max_iter);
        private:

            void write(const std::string& file , std::ofstream& fout);

            const int width;
            const int height;
            std::vector<rgb> screen;

    };

}

#endif