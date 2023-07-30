import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int jar1 = scanner.nextInt(), jar2 = scanner.nextInt(), jar3 = scanner.nextInt();
        
        if (jar1 == jar2) 
            System.out.println(jar3 - jar2);
        else if (jar2 == jar3)
            System.out.println(jar1 - jar3);
        else if (jar1 == jar3)
            System.out.println(jar2 - jar1);
    }
}
