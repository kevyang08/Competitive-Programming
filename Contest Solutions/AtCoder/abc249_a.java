import java.io.*;
import java.util.*;
 
public class Main {
    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
 
        int a = scanner.nextInt(), b = scanner.nextInt(), c = scanner.nextInt(), d = scanner.nextInt(), e = scanner.nextInt(), f = scanner.nextInt(), x = scanner.nextInt();
        int bruh1 = 0, bruh2 = 0, bt = 0, ct = 0, et = 0, ft = 0;
        boolean rest1 = false, rest2 = false;
        while (x-- > 0) {
        	if (rest1) {
        		ct++;
        		if (ct == c) {
        			rest1 = false;
        			ct = 0;
        		}
        	}
        	else {
        		bt++;
        		bruh1 += b;
        		if (bt == a) {
        			rest1 = true;
        			bt = 0;
        		}
        	}
        	if (rest2) {
        		ft++;
        		if (ft == f) {
        			rest2 = false;
        			ft = 0;
        		}
        	}
        	else {
        		et++;
        		bruh2 += e;
        		if (et == d) {
        			rest2 = true;
        			et = 0;
        		}
        	}
        }
        System.out.println(bruh1 == bruh2 ? "Draw" : bruh1 > bruh2 ? "Takahashi" : "Aoki");
    }
}
