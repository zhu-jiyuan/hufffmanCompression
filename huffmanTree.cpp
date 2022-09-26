//
// Created by zhujiyuan on 2022/9/23.
//

#include "huffmanTree.h"
#include <iostream>


HuffmanTree::HuffmanTree(std::unordered_map<unsigned char, unsigned long long>&wightTable) {
    create(wightTable);
}

//create huffman tree with wight table.
//new node
void HuffmanTree::create(std::unordered_map<unsigned char, unsigned long long> &wightTable) {
    huffmanTable = new node[2*wightTable.size()-1];

    //insert wight node
    int index{0}; //this is a huffmanTable point.
    for(auto &w:wightTable){
        huffmanTable[index].data = w.first;
        huffmanTable[index].wight = w.second;
        index++;
    }


    //important!
    //find two min wight node.

    for(;index<2*wightTable.size()-1;index++){
        connectNode(index);
    }


    //return root node;
    this->root = &huffmanTable[2*wightTable.size()-2];
    getCode();
    //std::cout<<"huffman tree create successful!"<<std::endl;
}

void HuffmanTree::connectNode(int insert_index) {
    //find two min wight node in huffmanTable.
    //lchild and rchild;
    node* l;
    node* r;
    unsigned long long min_temp{0};
    for(int i=0;i<insert_index;i++){
        if(huffmanTable[i].parent==-1){
            min_temp = huffmanTable[i].wight;
            break;
        }
    }

    for(int i=0;i<insert_index;i++){
        if(huffmanTable[i].wight<=min_temp&&huffmanTable[i].parent==-1){
            min_temp = huffmanTable[i].wight;
            l = &huffmanTable[i];
        }
    }
    l->parent = insert_index;

    for(int i=0;i<insert_index;i++){
        if(huffmanTable[i].parent==-1){
            min_temp = huffmanTable[i].wight;
            break;
        }
    }

    for(int i=0;i<insert_index;i++){
        if(huffmanTable[i].wight<=min_temp&&huffmanTable[i].parent==-1){
            min_temp = huffmanTable[i].wight;
            r = &huffmanTable[i];
        }
    }
    r->parent=insert_index;

    //insert node
    huffmanTable[insert_index].lChild = l;
    huffmanTable[insert_index].rChild = r;
    huffmanTable[insert_index].wight = l->wight+r->wight;
}

void HuffmanTree::forEachPre(node *root) const {
    if(root== nullptr)return;

    if(root->lChild== nullptr&&root->rChild== nullptr)
        std::cout<<char(root->data)<<" ";
    forEachPre(root->lChild);
    forEachPre(root->rChild);
}

void HuffmanTree::forEachPre() const {
    forEachPre(root);
}

void HuffmanTree::getCode(node *root, std::string s) {
    if(root== nullptr)return;

    if(root->lChild== nullptr&&root->rChild== nullptr){
        root->code=s;
    }
    getCode(root->lChild,s+"0");
    getCode(root->rChild,s+"1");
}

void HuffmanTree::getCode() {
    getCode(this->root,"");
}

HuffmanTree::~HuffmanTree() {
    if(huffmanTable!= nullptr){
        delete[] huffmanTable;
        huffmanTable = nullptr;
    }
}
