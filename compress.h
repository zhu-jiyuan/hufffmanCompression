//
// Created by zhujiyuan on 2022/9/25.
//

#ifndef HUFFMANZIP_COMPRESS_H
#define HUFFMANZIP_COMPRESS_H
#include "huffmanTree.h"
#include <unordered_map>
class FileIO{
public:
    unsigned char*buf;
    long buf_size;
    FileIO()=default;
    void readIntoBuf(const char* fileName);
};

class Compress:public FileIO{
public:
    HuffmanTree *h_tree;
    int endBit;//add 0 number
    std::unordered_map<unsigned char,unsigned long long>hash;
    Compress()=default;
    Compress(const char* filename);

    void compressFile();
    void decompressFile();
private:
    void init(const char* filename);
    inline unsigned char strBinToUchar(const std::string&s);
    inline std::string ucharToStrBin(unsigned char s);
};


inline unsigned char Compress::strBinToUchar(const std::string &s) {
    unsigned char sum{0};
    for(const char&a:s){
        sum = sum*2 + (a-'0');
    }
    return sum;
}

inline std::string Compress::ucharToStrBin(unsigned char s){
    std::string ans = "";
    while(s!=0){
        if(s%2!=0){
            ans = '1'+ans;
        }else{
            ans = '0'+ans;
        }
        s/=2;
    }
    while(ans.length()!=8){
        ans = '0'+ans;
    }
    return ans;
}
#endif //HUFFMANZIP_COMPRESS_H
