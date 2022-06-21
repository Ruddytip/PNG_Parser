#include "PNG.hpp"
#include <fstream>
#include <iostream>

PNG_Image::PNG_Image(const std::string fileName){
    std::ifstream fin(fileName, std::ios::binary);
    if(!fin.is_open()){
        // ERORR!!!
        return;
    }

    // fin.read((char*)&Signature,      sizeof(Signature) * 8);
    std::cout << 0x0a1a0a0d474e5089 << std::endl;
    std::cout << *Signature << std::endl;
    if(*Signature == 0x0a1a0a0d474e5089) std::cout << "signature - OK\n";

    // fin.read((char*)&CHNK.DataLength, sizeof(CHNK.DataLength));
    // fin.read((char*)&CHNK.Type,       sizeof(CHNK.Type));
    // if(CHNK.Type == 0x52444849) std::cout << "Type - OK\n";

    // int count = 1;

    // while(true){
    //     fin.read((char*)&CHNK.DataLength, sizeof(CHNK.DataLength));
    //     fin.read((char*)&CHNK.Type,       sizeof(CHNK.Type));
    //     if(CHNK.Type == 0x49484452) break;
    //     // CHNK.Data = new byte1[CHNK.DataLength];
    //     fin.read((char*)&CHNK.Data,       sizeof(byte1) * CHNK.DataLength);
    //     fin.read((char*)&CHNK.Crc,        sizeof(CHNK.Crc));
    //     std::cout << "chunk " << count++ << " - OK\n";
    //     // delete[] CHNK.Data;
    // }

    fin.close();
    std::cout << "file close\n";
}

PNG_Image::~PNG_Image(){

}