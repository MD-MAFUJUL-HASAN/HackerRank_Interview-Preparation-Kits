using System.CodeDom.Compiler;
using System.Collections.Generic;
using System.Collections;
using System.ComponentModel;
using System.Diagnostics.CodeAnalysis;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Runtime.Serialization;
using System.Text.RegularExpressions;
using System.Text;
using System;

class Solution {
   /*
     * Complete the 'plusMinus' function below.
     *
     * The function accepts INTEGER_ARRAY arr as parameter.
     */

    static void plusMinus(int arr_count, int[] arr) {
        float pos=0,neg=0,zer=0;
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
        Console.WriteLine("{0:F6}\n{1:F6}\n{2:F6}",pos/arr_count,neg/arr_count,zer/arr_count);
    }
    static void Main(string[] args) {
        int n = Convert.ToInt32(Console.ReadLine());
        int[] arr = Array.ConvertAll(Console.ReadLine().Split(' '), arrTemp => Convert.ToInt32(arrTemp));
        plusMinus(n, arr);
    }
}
