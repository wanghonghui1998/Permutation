//
//  main.cpp
//  permutation
//
//  Created by Cyndaquil on 2020/10/17.
//

#include <iostream>
#include <vector>
#include "index2intermediate.hpp"
#include "intermediate2perm.hpp"
using namespace std;



int main( )
{
    vector<vector<int>> results;
    unsigned int n = 4;
    cout << "permutations generated by Dictionary method" << endl;
    results = perm_dic_method(n);
    for(int j = 0; j < results.size(); j++){
        for(int i = 0; i < results[j].size(); i++){
            cout << results[j][i] << ' ';
        }
        cout << endl;
    }
    cout << "permutations generated by Neighbor Swap method" << endl;
    results = perm_nbh_method(n);
    for(int j = 0; j < results.size(); j++){
        for(int i = 0; i < results[j].size(); i++){
            cout << results[j][i] << ' ';
        }
        cout << endl;
    }
    

    return 0;
}