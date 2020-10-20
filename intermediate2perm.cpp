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

int _empty_loc(vector<int> array, int empty_loc, int n){
    int empty_count = 0;
    for (int i = 0; i < n; i++){
        if (array[i] == 0){
            empty_count += 1;
        }
        if (empty_count > empty_loc){
            return i;
        }

    }
    return 0;
}

vector<int> intermediate2perm_inc_method(vector<int> intermediate_value)
{
    vector<int> perm;
    vector<int> auxiliary;  // Indicate which location is already occupied with number.
    int ai;                 // The i-th element of media number.
    int loc_index;
    unsigned long n = intermediate_value.size();
    n += 1;

    for (int i = 0; i < n; i++){ // Init the all the element of perm as 1, which leave out the last step to put 1 into perm.
        perm.push_back(1);
        auxiliary.push_back(0);
    }

    for (int i = 0; i < n - 1; i++){
        ai = intermediate_value[i];               // Get the media number element.
        loc_index = _empty_loc(auxiliary, ai, n); // Find the empty location.
        perm[n - 1 - loc_index] = n - i;                  // The lowest media number corresponding to the largest number
        auxiliary[loc_index] = 1;
    }

    return perm;
}


vector<int> intermediate2perm_dec_method(vector<int> intermediate_value)
{
    vector<int> perm;
    vector<int> auxiliary;  // Indicate which location is already occupied with number.
    int ai;                 // The i-th element of media number.
    int loc_index;
    unsigned long n = intermediate_value.size();
    n += 1;

    for (int i = 0; i < n; i++){ // Init the all the element of perm as 1, which leave out the last step to put 1 into perm.
        perm.push_back(1);
        auxiliary.push_back(0);
    }

    for (int i = n; i >= 2; i--){
        ai = intermediate_value[i - 2];           // Get the media number element.
        loc_index = _empty_loc(auxiliary, ai, n); // Find the empty location.
        perm[n - 1 - loc_index] = i;
        auxiliary[loc_index] = 1;
    }

    return perm;
}






vector<vector<int>> perm_dec_method(unsigned int n){
    vector<vector<int>> results;
    int num = factorial(n);
    for(int i = 0; i < num; i++){
        results.push_back(intermediate2perm_dec_method(idx2intermediate_dec_method(n, i)));
    }
    return results;
}

vector<vector<int>> perm_inc_method(unsigned int n){
    vector<vector<int>> results;
    int num = factorial(n);
    for(int i = 0; i < num; i++){
        results.push_back(intermediate2perm_inc_method(idx2intermediate_inc_method(n, i)));
    }
    return results;
}

/*vector<int> reverse_perm(vector<vector<int>> perms, int idx){
    vector<int> results;
    for(int i = perms[idx].size()-1; i>=0; i--){
        results.push_back(perms[idx][i]);
    }
    return results;
}*/
vector<int> reverse_perm(vector<int> perm){
    vector<int> results;
    for(int i = perm.size()-1; i>=0; i--){
        results.push_back(perm[i]);
    }
    return results;
}

vector<vector<int>> perm_dec_sym_method(unsigned int n){
    vector<vector<int>> results;
    int num = factorial(n);
    for(int i = 0; i < num; i++){
        if(i < num / 2)
            results.push_back(intermediate2perm_dec_method(idx2intermediate_dec_method(n, i)));
        else
            results.push_back(reverse_perm(results[num-1-i]));
            //results.push_back(reverse_perm(results, num-i-1));
    }
    return results;
}

vector<vector<int>> perm_inc_sym_method(unsigned int n){
    vector<vector<int>> results;
    int num = factorial(n);
    for(int i = 0; i < num; i++){
        if(i < num / 2)
            results.push_back(intermediate2perm_inc_method(idx2intermediate_inc_method(n, i)));
        else
            results.push_back(reverse_perm(results[num-1-i]));
            //results.push_back(reverse_perm(results, num-i-1));
    }
    return results;
}


