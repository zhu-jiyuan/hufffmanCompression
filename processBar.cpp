//
// Created by zhujiyuan on 2022/9/26.
//

#include "processBar.h"
#include <iostream>


void ProcessBar::show(int step) {
    cur+=step;
    if(cnt==(cur/total))return;
    else{
        cnt = (cur/total);
        if(cnt>100)cnt=100;
        std::cout<<"\r"<<cnt<<"%[";
        int i{0};
        for(;i<cnt;i++){
            std::cout<<"#";
        }
        for(;i<100;i++){
            std::cout<<" ";
        }
        std::cout<<"]";
    }

}


