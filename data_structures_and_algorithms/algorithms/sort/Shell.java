package data_structures_and_algorithms.algorithms.sort;

import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;

public class Shell {
    // This class should not be instantiated.
    private Shell() {
    }

    public static void sort(Comparable[] a) {
        // 6 7 1 2 9 5 3 10 4
        int n = a.length;
        // 3x+1 increment sequence: 1, 4, 13, 40, 121, 364, 1093, ...
        int h = 1;
        while (h < n / 3) {
            h = 3 * h + 1;
        }

        while (h >= 1) {
            // h-sort the array
            for (int i = h; i < n; i++) {
                /*
                 * 也可以使用 while 的形式
                 * int j = i;
                 * while (j >=h && less(a[j], a[j - h])){
                 * exch(a, j, j-h)
                 * j -= h
                 * }
                 */
                for (int j = i; j >= h && less(a[j], a[j - h]); j -= h) {
                    exch(a, j, j - h);
                }
            }
            h /= 3;
        }
    }

    /***************************************************************************
     * Helper sorting functions.
     ***************************************************************************/
    // is v < w ?
    private static boolean less(Comparable v, Comparable w) {
        return v.compareTo(w) < 0;
    }

    // exchange a[i] and a[j]
    private static void exch(Object[] a, int i, int j) {
        Object swap = a[i];
        a[i] = a[j];
        a[j] = swap;
    }

    // print array to standard output
    private static void show(Comparable[] a) {
        for (int i = 0; i < a.length; i++) {
            StdOut.println(a[i]);
        }
    }

    public static void main(String[] args) {
        String[] a = StdIn.readAllStrings();
        Shell.sort(a);
        show(a);
    }
}
