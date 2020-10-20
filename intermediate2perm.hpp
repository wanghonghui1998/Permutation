//
//  intermediate2perm.hpp
//  permutation
//
//  Created by Cyndaquil on 2020/10/17.
//

#ifndef intermediate2perm_hpp
#define intermediate2perm_hpp

#include <stdio.h>
#include <vector>
using namespace std;
vector<int> intermediate2perm_dic_method(vector<int> intermediate_value);
vector<int> intermediate2perm_inc_method(vector<int> intermediate_value);
vector<int> intermediate2perm_dec_method(vector<int> intermediate_value);
vector<int> intermediate2perm_nbh_method(vector<int> intermediate_value);
vector<vector<int>> perm_dic_method(unsigned int n);
vector<vector<int>> perm_dec_method(unsigned int n);
vector<vector<int>> perm_inc_method(unsigned int n);
vector<vector<int>> perm_nbh_method(unsigned int n);
vector<vector<int>> perm_dec_sym_method(unsigned int n);
vector<vector<int>> perm_inc_sym_method(unsigned int n);
vector<int> reverse_perm(vector<vector<int>> perms, int idx);


#endif /* intermediate2perm_hpp */
