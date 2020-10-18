//
//  index2intermediate.cpp
//  permutation
//
//  Created by Cyndaquil on 2020/10/17.
//

#include "index2intermediate.hpp"

#include <iostream>
#include <vector>
 
using namespace std;

int factorial(unsigned int n);
vector<int> idx2intermediate_dic_method(unsigned int n, int idx);
vector<int> idx2intermediate_inc_method(unsigned int n, int idx);
vector<int> idx2intermediate_dec_method(unsigned int n, int idx);
vector<int> idx2intermediate_nbh_method(unsigned int n, int idx);
/*
int main( )
{
    vector<int> return_value;
    int n = 8;
    int idx = 23412;
    int i;

    return_value = idx2intermediate_dic_method(n, idx);
    for(i = 0; i < n - 1; i++)
    {
        cout << "value of vec [" << i << "] = " << return_value[i] << endl;
        // cout << "value of vec [" << i << "] " << endl;
    }

    return 0;
}
*/


/* index to intermediate function for Dictionary method */
vector<int> idx2intermediate_dic_method(unsigned int n, int idx)
{
    vector<int> intermediate_value;
    int remain;
    
    remain = idx;

    for(int i = n - 1; i >= 1; i--)
    {
        unsigned long long fac = factorial(i);
        intermediate_value.push_back(remain / fac);
        remain = remain % fac;
    }

    return intermediate_value;
}


/* index to intermediate function for Increasing method */
vector<int> idx2intermediate_inc_method(unsigned int n, int idx)
{
    vector<int> intermediate_value;
    int remain;
    
    remain = idx;

    for(int i = n - 1; i >= 1; i--)
    {
        unsigned long long fac = factorial(i);
        intermediate_value.push_back(remain / fac);
        remain = remain % fac;
    }

    return intermediate_value;
}


/* index to intermediate function for Decreasing method */
vector<int> idx2intermediate_dec_method(unsigned int n, int idx)
{
    vector<int> intermediate_value;
    int remain;
    
    remain = idx;

    for(int i = 2; i <= n; i++)
    {
        unsigned long long facn = factorial(n);
        unsigned long long faci = factorial(i);
        unsigned long long divisor = facn / faci;

        intermediate_value.push_back(remain / divisor);
        remain = remain % divisor;
    }

    return intermediate_value;
}


/* index to intermediate function for Neighbor Swap method */
vector<int> idx2intermediate_nbh_method(unsigned int n, int idx)
{
    vector<int> intermediate_value;
    int remain;
    
    remain = idx;

    for(int i = 2; i <= n; i++)
    {
        unsigned long long facn = factorial(n);
        unsigned long long faci = factorial(i);
        unsigned long long divisor = facn / faci;

        intermediate_value.push_back(remain / divisor);
        remain = remain % divisor;
    }

    return intermediate_value;
}


/* get factorial of n */
int factorial(unsigned int n)
{
    unsigned long long factorial = 1;
 
    for(int i = 1; i <= n; ++i)
    {
        factorial *= i;
    }
 
    return factorial;
}
