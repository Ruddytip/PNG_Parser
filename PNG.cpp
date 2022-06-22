#include "PNG.hpp"
#include <fstream>
#include <iostream>

void foo(){
    
}

PNG_Image::PNG_Image(const std::string fileName){
    std::ifstream fin(fileName, std::ios_base::binary);
    if(!fin.is_open()){
        // ERROR!!!
        // Файл не открылся
        std::cerr << "file error\n";
        return;
    }

    std::vector<byte1> buffer(std::istreambuf_iterator<char>(fin), {});
    fin.close();
    int iterat = 8;

    // Проверка сигнатуры файла =============================================
    Signature = 0;
    for(size_t i = 0; i < sizeof(Signature); ++i) Signature = Signature * 0x100 + buffer[i];
    if(Signature != 0x89504e470d0a1a0a){  // 0x89504e470d0a1a0a - корректная сигнатура файла PNG
        // ERROR!!!
        // Файл не яввляется PNG изображением
        std::cerr << "signature error\n";
        return;
    }
    // ======================================================================

    while(true){
        Chunk cnk;
        for(size_t i = 0; i < sizeof(cnk.DataLength); ++i)
            cnk.DataLength = cnk.DataLength * 0x100 + buffer[i + iterat];
        std::cout << std::dec << cnk.DataLength << std::endl;
        iterat+=sizeof(cnk.Type);
        for(size_t i = 0; i < sizeof(cnk.Type); ++i)
            cnk.Type = cnk.Type * 0x100 + buffer[i + iterat];
        iterat+=sizeof(cnk.Type);
        std::cout << std::hex << cnk.Type << std::endl;
        if(cnk.Type == TYPES::IEND) break;
        for(size_t i = iterat; i < iterat + cnk.DataLength; ++i)
            cnk.Data.push_back(buffer[i]);
        iterat+=cnk.DataLength;
        std::cout << std::dec << cnk.Data.size() << std::endl;
        for(size_t i = 0; i < sizeof(cnk.Crc); ++i)
            cnk.Crc = cnk.Crc * 0x100 + buffer[i + iterat];
        iterat+=sizeof(cnk.Crc);
        std::cout << std::hex << cnk.Crc << std::endl;
    }

}

PNG_Image::~PNG_Image(){

}