#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <unordered_map>
#include "huffmanTree.h"
#include "compress.h"
#include "processBar.h"
using namespace std;



int main(int argc,char* argv[]) {


    Compress temp("test.txt");
    temp.compressFile();
    temp.decompressFile();
//    cout<<"Sdsadsa";
//    cout<<"\r";
//    cout<<"1";
//    cout<<"2";
//    ProcessBar bar(100);
//    int i=0;
//    while(i<100){
//        bar.show(1);
//        i++;
//    }




    return 0;
}
