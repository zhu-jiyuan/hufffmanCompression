#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <unordered_map>
#include "huffmanTree.h"
#include "compress.h"

using namespace std;



int main(int argc,char* argv[]) {


    Compress temp("test.txt");
    temp.compressFile();
    temp.decompressFile();





    return 0;
}
