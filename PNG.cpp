#include "PNG.hpp"
#include <fstream>
#include <iostream>
#include <vector>

PNG_Image::PNG_Image(const std::string fileName){
    std::ifstream fin(fileName, std::ios::binary);
    if(!fin.is_open()){
        // ERORR!!!
        return;
    }

    std::vector<byte1> buffer(std::istreambuf_iterator<char>(fin), {});
    fin.close();
    std::cout << "file close\n";
    
    std::string str = "";
    for(size_t i = 1; i < 4; ++i) str+= buffer[i];
    if(str == "PNG") std::cout << "sdfsdfsdfsf\n";
    std::cout << str << std::endl;

}

PNG_Image::~PNG_Image(){

}