//
//  perm2next.cpp
//  Permutation
//
//  Created by Cyndaquil on 2020/10/20.
//

#include "perm2next.hpp"
#include <vector>

using namespace std;


int first_decay(vector<int> perm){
    int i;
    for(i=perm.size()-2; i>=0; i--){
        if(perm[i] < perm[i+1])
            break;
    }
    return i;
}

vector<int> next_dic_perm(vector<int> perm, int j){
    vector<int> next;
    for(int i = 0; i < j; i++){
        next.push_back(perm[i]);
    }
    
    for(int i = perm.size() - 1; i > j; i--){
        if(perm[i] > perm[j]){
            next.push_back(perm[i]);
            perm[i] = perm[j];
            break;
        }
    }
    for(int i = perm.size()-1; i > j; i--){
        next.push_back(perm[i]);
    }
    return next;
}


vector<vector<int>> perm_dic_method_seq(unsigned int n){
    vector<vector<int>> results;
    vector<int> perm;
    for(int i = 0; i < n; i++){
        perm.push_back(i+1);
    }
    results.push_back(perm);
    while(1){
        int j = first_decay(perm);
        if(j < 0){
            break;
        }
        vector<int> next = next_dic_perm(perm, j);
        results.push_back(next);
        perm = next;
    }
    return results;
}

vector<int> next_sjt_perm(vector<int> perm, vector<int>& direction, int j){
    vector<int> next;
    for(int i = 0; i < perm.size(); i++){
        next.push_back(perm[i]);
    }
    int d = direction[j];
    next[j+d] = perm[j];
    next[j] = perm[j+d];
    
    int tmp = direction[j+d];
    direction[j+d] = direction[j];
    direction[j] = tmp;
    
    for(int i = 0; i < next.size(); i++){
        if(next[i] > perm[j]){
            direction[i] = -1 * direction[i];
        }
    }
    return next;
}

int largest_mobile(vector<int> perm, vector<int> direction){
    int largest = 0;
    int l_ind = -1;
    for(int i = 0; i < perm.size(); i++){
        if(perm[i] > largest){
            int j = i+direction[i];
            if(j>=0 && j<perm.size()){
                if(perm[j] < perm[i]){
                    largest = perm[i];
                    l_ind = i;
                }
            }
        }
    }
    return l_ind;
}

vector<vector<int>> perm_sjt_method_seq(unsigned int n){
    vector<vector<int>> results;
    vector<int> perm;
    vector<int> direction;
    for(int i = 0; i < n; i++){
        perm.push_back(i+1);
        direction.push_back(-1);
    }
    results.push_back(perm);
    while(1){
        int j = largest_mobile(perm, direction);
        if(j < 0){
            break;
        }
        vector<int> next = next_sjt_perm(perm, direction, j);
        results.push_back(next);
        perm = next;
    }
    return results;
}
