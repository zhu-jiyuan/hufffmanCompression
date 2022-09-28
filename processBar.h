//
// Created by zhujiyuan on 2022/9/26.
//

#ifndef HUFFMANZIP_PROCESSBAR_H
#define HUFFMANZIP_PROCESSBAR_H
#include <iostream>
class ProcessBar{
private:
    const long total;
    long cur;
    int cnt;

public:

    ProcessBar(const long &total_size):total(total_size/100),cur(0),cnt(0){};
    void show(int step=1);
};


#endif //HUFFMANZIP_PROCESSBAR_H
