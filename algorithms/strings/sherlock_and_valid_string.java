package vk.hackerrank.contests.may;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class SherlockAndString {

    public static void main(String[] args) throws IOException {

        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

        String in = reader.readLine();

        solve(1, in);
    }

    private static void solve(int testNumber, String in) {
        char[] c = in.toCharArray();
        int[] count = new int[26];
        int maxRepetitions = 0;
        int maxKey = 0;
        
        for (int i = 0; i < c.length; ++i) {
            count[c[i] - 'a']++;
            if(maxRepetitions < count[c[i] - 'a']) {
                maxRepetitions = count[c[i] - 'a'];
            }
        }
        
        int[] mode = new int[maxRepetitions+1];
        maxRepetitions = 0;

        for (int i = 0; i < count.length; i++) {
            if (count[i] != 0) {
                mode[count[i]]++;
                if (maxRepetitions < mode[count[i]]) {
                    maxRepetitions = mode[count[i]];
                    maxKey = count[i];
                }
            }
        }

        // System.out.println(maxKey);
        // System.out.println(maxRepetitions);

        int res = 1;
        for (int i = 0; i < 26; ++i) {
            if (count[i] != 0 && count[i] != maxKey) {
                if(count[i] < maxKey) {
                    System.out.println("NO");
                    return;
                }
                res -= (count[i] - maxKey);
            }
        }

        if (res < 0) {
            System.out.println("NO");
        } else {
            System.out.println("YES");
        }
    }
}
