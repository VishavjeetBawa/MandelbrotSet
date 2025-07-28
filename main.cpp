#include "Mandelbrot.hpp"

int main(){

    my::Render rndr(1080 , 1080);
    rndr.mandelbrot("Mandelbrot.ppm" , 25);

}