import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.function.*;
import java.util.regex.*;
import java.util.stream.*;
import static java.util.stream.Collectors.joining;
import static java.util.stream.Collectors.toList;

public class Solution {

    /*
     * Complete the 'plusMinus' function below.
     *
     * The function accepts INTEGER_ARRAY arr as parameter.
     */

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        float pos = 0, neg = 0, zer = 0;
        int[] z = new int[n];
        for (int i = 0; i < n; i++) {
            z[i] = scanner.nextInt();
            if (z[i] > 0) {
                pos++;
            } else if (z[i] < 0) {
                neg++;
            } else {
                zer++;
            }
        }
        System.out.printf("%5f\n%5f\n%5f\n", pos / n, neg / n, zer / n);
        scanner.close();
    }
}
