//
//  treedisplay.hpp
//  DScode
//
//  Created by Emilio-v on 2023/10/10.
//

#ifndef treedisplay_h
#define treedisplay_h
#include "Node_Define.hpp"
#include "tree.hpp"
#include <vector>
#include <cmath>
using namespace std ;
void printDynamicArray(std::vector<std::vector<char>>& arr) {
    int n = arr.size();    // 获取数组的高度
    int m = arr[0].size(); // 获取数组的宽度

    // 打印数组的元素
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl; // 换行
    }
}

void printBittree_struct(Tree &T){
    int tree_high=count_tree_h(T);
    int n = pow(2,tree_high-1)+tree_high-1; // 例如，高度为5
    int m = pow(2,tree_high)-1; // 例如，宽度为4
    
    // 声明一个动态的二维字符数组并初始化
    std::vector<std::vector<char>> dynamicArray(n, std::vector<char>(m));
    
    
    

    
    printDynamicArray(dynamicArray);//打印该数组   即树的结构
}

#endif /* treedisplay_h */
