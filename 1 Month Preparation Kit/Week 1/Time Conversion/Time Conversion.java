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

public class Solution{
    /*
     * Complete the 'timeConversion' function below.
     *
     * The function is expected to return a STRING.
     * The function accepts STRING s as parameter.
     */
    public static void main(String[] args) {
        // Write your code here
         Scanner in = new Scanner(System.in);
         String time = in.next();
         String listTime[] = time.split(":");
         String hour = listTime[0];
         String minutes = listTime[1];
         String secounds = listTime[2].substring(0, 2);
         String caser = listTime[2].substring(2, 4);
         if(caser.equals("AM")){
             if(hour.equals("12"))
                    hour="00";
 
             System.out.println(hour+":"+minutes+":"+secounds);
         }else{
             if(!hour.equals("12")){
                 int h = Integer.parseInt(hour); 
                 h = h +12; 
                 hour =""+h; 
             }
             System.out.println(hour+":"+minutes+":"+secounds);
         }
 
    }
}
