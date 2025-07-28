#include "Mandelbrot.hpp"
#include<complex>
#include <fstream>

namespace my{
    
    void Render::mandelbrot(const std::string&  file , const int max_iter){
        int index;
        double real , imag;
        for(int x = 0 ; x<width ; ++x){
            double real = (x - width/2.0)*4.0/width;
            for(int y =0 ; y<height ; ++y){
                double imag = (y- height/2.0)*4.0/height;
                std::complex<double> z(0.0 , 0.0);
                std::complex<double> c(real , imag);
                index = x + y*width;
                int iter = 0;
                while(iter<=max_iter && std::abs(z)<=2){
                    z = z*z +c;
                    ++iter;
                }
                screen[index] = {uint8_t(0.0) , uint8_t(0.0) , uint8_t(255.0*iter/max_iter)};
            }
            std::clog<<"Scanlines Remaining.....\r"<<x+1<<" ";

        }
        std::ofstream fout(file , std::ios::binary);
        write(file , fout );
        std::clog<<std::endl;
    }

    void Render::write(const std::string& file , std::ofstream& fout){
        fout<<"P6\n"<<width<<" "<<height<<"\n255\n";
        for(int i = 0 ; i<screen.size() ; ++i){
            fout<<uint8_t(screen[i].red)<<uint8_t(screen[i].green)<<uint8_t(screen[i].blue);
        }
    }

}