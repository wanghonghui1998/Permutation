//
//  intermediate2perm.cpp
//  permutation
//
//  Created by Cyndaquil on 2020/10/17.
//

#include "intermediate2perm.hpp"
#include "index2intermediate.hpp"
#include <vector>
#include <iostream>
using namespace std;

vector<int> intermediate2perm_dic_method(vector<int> intermediate_value)
{
    
    vector<bool> picked;
    vector<int> perm;
    unsigned long n = intermediate_value.size();
    n += 1;
    for(long i = 0; i < n; i++){
        picked.push_back(false);
    }
    for(long i = 0; i < n - 1; i++){
        int curr_num = intermediate_value[i];
        curr_num++;
        for(int j = 0; j < curr_num; j++){
            if(picked[j])
                curr_num++;
        }
        perm.push_back(curr_num);
        picked[curr_num-1] = true;
    }
    for(long i = 0; i < n; i++){
        if(!picked[i]){
            perm.push_back(i+1);
            break;
        }
    }

    return perm;
}

vector<vector<int>> perm_dic_method(unsigned int n){
    vector<vector<int>> results;
    int num = factorial(n);
    for(int i = 0; i < num; i++){
        results.push_back(intermediate2perm_dic_method(idx2intermediate_dic_method(n, i)));
    }
    
    return results;
}



vector<int> intermediate2perm_nbh_method(vector<int> intermediate_value)
{
    
    vector<int> perm;
    vector<int> direction; // 0-left, 1-right
    unsigned long n = intermediate_value.size();
    n += 1;
    for(long i = 0; i < n; i++){
        perm.push_back(0);
    }
    direction.push_back(0);
    for(long i = 1; i < n - 1; i++){
        if(i % 2 == 0){
            direction.push_back((intermediate_value[i-1]+intermediate_value[i-2]) % 2);
        }
        else{
            direction.push_back(intermediate_value[i-1] % 2);
        }
    }
    for(long i = n - 2; i >= 0; i--){
        int count = 0;
        int block = intermediate_value[i];
        block++;
        if(direction[i] == 1){
            for(long j = 0; j < n; j++){
                if(perm[j] == 0){
                    count++;
                    if(count == block){
                        perm[j] = i + 2;
                        break;
                    }
                }
                
            }
        }
        else{
            for(long j = n - 1; j >= 0; j--){
                if(perm[j] == 0){
                    count++;
                    if(count == block){
                        perm[j] = i + 2;
                        break;
                    }
                }
                
            }
            
        }
    }
    for(long i = 0; i < n; i++){
        if(perm[i] == 0)
            perm[i] = 1;
    }
    
    return perm;
}

vector<vector<int>> perm_nbh_method(unsigned int n){
    vector<vector<int>> results;
    int num = factorial(n);
    for(int i = 0; i < num; i++){
        results.push_back(intermediate2perm_nbh_method(idx2intermediate_nbh_method(n, i)));
    }
    
    return results;
}
