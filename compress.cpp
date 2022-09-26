//
// Created by zhujiyuan on 2022/9/25.
//

#include "compress.h"
#include <unordered_map>
#include <iostream>
#include <string.h>
void FileIO::readIntoBuf(const char *fileName) {

    FILE * q = fopen(fileName,"rb");
    //get file size
    fseek(q,0,SEEK_END);
    this->buf_size = ftell(q);
    //create file size buf
    this->buf = new unsigned char[buf_size];
    fseek(q,0,SEEK_SET);
    fread(this->buf,1,buf_size,q);
    fclose(q);

}

Compress::Compress(const char *filename) {
    init(filename);
}

void Compress::init(const char *filename) {
    readIntoBuf(filename);

    for(long i{0};i<buf_size;i++){
        hash[buf[i]]++;
    }
    h_tree = new HuffmanTree(hash);
}

void Compress::compressFile() {
    //create find table,key is node's data,value is node's code.
    std::unordered_map<unsigned char,std::string> quickTable;
    for(int i{0};i<hash.size();i++){
        quickTable[this->h_tree->huffmanTable[i].data]=this->h_tree->huffmanTable[i].code;
    }

    FILE *q = fopen("test.hip","wb");
    //start compress!!!
    std::string byteBuf="";

    unsigned char streamBuf[1048576];
    memset(streamBuf,0,sizeof(streamBuf));

    int cnt{0};
    for(long i{0};i<buf_size;i++){
        byteBuf.append(quickTable[buf[i]]);
    }
    //add 0 to bytrBuf
    endBit=0;
    while(byteBuf.length()%8!=0){
        byteBuf.push_back('0');
        endBit++;
    }
    //delete buf
    if(buf!= nullptr){
        delete[]buf;
        buf = nullptr;
    }
    //write into stream buf.
    for(long i{0};i<byteBuf.length();i+=8){
        streamBuf[cnt++] = strBinToUchar(byteBuf.substr(i,8));
        if(cnt%1048576==0){
            cnt=0;
            fwrite(streamBuf,sizeof(streamBuf),1,q);
        }
    }
    if(cnt!=0){
        fwrite(streamBuf,sizeof(unsigned char)*cnt,1,q);
    }
    fclose(q);

}

void Compress::decompressFile() {
    node* sign = this->h_tree->root;
    unsigned char streamBuf[1048576];
    memset(streamBuf,0,sizeof(streamBuf));
    FILE *q = fopen("test.hip","rb");
    FILE *uq = fopen("test.unhip","wb");
    int cnt{0};

    std::string codeTxt="";
    unsigned char t;

    while(fread(&t,sizeof(unsigned char),1,q)!=0){
        codeTxt.append(ucharToStrBin(t));
    }
    while(endBit!=0){
        codeTxt.pop_back();
        endBit--;
    }
    //std::cout<<codeTxt<<std::endl;
    fclose(q);
    for(const char&s:codeTxt){
        if(s=='0'){
            sign=sign->lChild;
        }else{
            sign=sign->rChild;
        }
        if(sign->rChild== nullptr&&sign->lChild== nullptr){
            streamBuf[cnt++]=sign->data;
            sign=this->h_tree->root;
            if(cnt%1048576==0){
                fwrite(streamBuf,sizeof (streamBuf),1,uq);
                cnt=0;
            }
        }
    }
    if (cnt!=0){
        fwrite(streamBuf,sizeof (unsigned char )*cnt,1,uq);
    }
    fclose(uq);
}


