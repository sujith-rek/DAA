package GradedLab2;
import java.util.Scanner;

class Tuple{
    String word;
    int index;
    char ch;
    Tuple(String word,int index,char ch){
        this.word = word;
        this.index = index;
        this.ch = ch;
    }
}

public class L {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        String[] arr = new String[n];
        int len = 0;
        for(int i=0;i<n;i++){
            arr[i] = input.next();
            len += arr[i].length();
        }
        input.close();

        Tuple[] tuples = new Tuple[len];
        for(int i=0;i<n;i++){
            for(int j=0;j<arr[i].length();j++){
                tuples[i*arr[i].length()+j] = new Tuple(arr[i],j,arr[i].charAt(j));
            }
        }

        sort_one(tuples);
        sort_two(tuples);
        print(tuples);





    }

    // print the sorted array
    public static void print(Tuple[] tuples){
        for(int i=0;i<tuples.length;i++){
            System.out.print(tuples[i].word.charAt(tuples[i].index));
        }
        System.out.println();
    }

    // sort tuples by ch with counting sort without using inbuilt sort function
    public static void sort_one(Tuple[] tuples){
        int[] count = new int[26];
        for(int i=0;i<tuples.length;i++){
            count[tuples[i].ch-'a']++;
        }
        Tuple[] sorted = new Tuple[tuples.length];
        for(int i=tuples.length-1;i>=0;i--){
            sorted[count[tuples[i].ch-'a']-1] = tuples[i];
            count[tuples[i].ch-'a']--;
        }
        for(int i=0;i<tuples.length;i++){
            tuples[i] = sorted[i];
        }
    }

    // sort tuples by index with counting sort without using inbuilt sort function
    public static void sort_two(Tuple[] tuples){
        int[] count = new int[tuples.length];
        for(int i=0;i<tuples.length;i++){
            count[tuples[i].index]++;
        }
        for(int i=1;i<tuples.length;i++){
            count[i] += count[i-1];
        }
        Tuple[] sorted = new Tuple[tuples.length];
        for(int i=tuples.length-1;i>=0;i--){
            sorted[count[tuples[i].index]-1] = tuples[i];
            count[tuples[i].index]--;
        }
        for(int i=0;i<tuples.length;i++){
            tuples[i] = sorted[i];
        }
    }

    
}
