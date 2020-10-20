//
//  index2intermediate.hpp
//  permutation
//
//  Created by Cyndaquil on 2020/10/17.
//

#ifndef index2intermediate_hpp
#define index2intermediate_hpp

#include <stdio.h>
#include <vector>
using namespace std;
int factorial(unsigned int n);
vector<int> idx2intermediate_dic_method(unsigned int n, int idx);
vector<int> idx2intermediate_inc_method(unsigned int n, int idx);
vector<int> idx2intermediate_dec_method(unsigned int n, int idx);
vector<int> idx2intermediate_nbh_method(unsigned int n, int idx);
#endif /* index2intermediate_hpp */
