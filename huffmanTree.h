//
// Created by zhujiyuan on 2022/9/23.
//

#ifndef HUFFMANZIP_HUFFMANTREE_H
#define HUFFMANZIP_HUFFMANTREE_H
#include <string>
#include <unordered_map>
class node{
public:
    unsigned char data;
    node* lChild{nullptr};
    node* rChild{nullptr};
    unsigned long long wight;
    int parent{-1};
    std::string code;

    node()=default;
    node(int t_data):data(t_data){}
};

class HuffmanTree{
public:
    node* huffmanTable;
    node* root;

    HuffmanTree()=default;
    ~HuffmanTree();
    HuffmanTree(std::unordered_map<unsigned char ,unsigned long long>&wightTable );

    void forEachPre() const;

private:
    void create(std::unordered_map<unsigned char ,unsigned long long>&wightTable );
    //insert connect node
    void connectNode(int insert_index);
    void forEachPre(node *root) const;
    void getCode();
    void getCode(node *root,std::string s);
};

#endif //HUFFMANZIP_HUFFMANTREE_H
