//
//  perm2next.hpp
//  Permutation
//
//  Created by Cyndaquil on 2020/10/20.
//

#ifndef perm2next_hpp
#define perm2next_hpp

#include <stdio.h>
#include <vector>
using namespace std;
vector<int> next_dic_perm(vector<int> perm, int j);
vector<vector<int>> perm_dic_method_seq(unsigned int n);
vector<int> next_sjt_perm(vector<int> perm, vector<int>& direction);
vector<vector<int>> perm_sjt_method_seq(unsigned int n);

#endif /* perm2next_hpp */
