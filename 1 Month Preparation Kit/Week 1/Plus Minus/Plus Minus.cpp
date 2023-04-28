#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

vector<string> split_string(string);

/*
 * Complete the 'plusMinus' function below.
 *
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

void plusMinus(int arr_count, int* arr) {
    int pos=0,neg=0,zer=0;
    for(int i=0;i<arr_count;i++){
        if(arr[i]>0){
            pos++;
        }
        else if(arr[i]<0){
            neg++;
        }
        else{
            zer++;
        }
    }
    printf("%.6f\n%.6f\n%.6f\n",(float)pos/arr_count,(float)neg/arr_count,(float)zer/arr_count);
}

int main()
{
    int n;
    scanf("%d",&n);
    int z[n];
    for(int i=0;i<n;i++){
        scanf("%d",&z[i]);
    }
    plusMinus(n,z);
    return 0;
}

vector<string> split_string(string str) {
    char* token = strtok((char*)str.c_str(), " ");

    vector<string> splits;
    while (token != NULL) {
        splits.push_back(string(token));
        token = strtok(NULL, " ");
    }

    return splits;
}
