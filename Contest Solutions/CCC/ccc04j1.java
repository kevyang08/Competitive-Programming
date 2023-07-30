import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int tiles = scanner.nextInt();
        
        System.out.println("The largest square has side length " + (int)Math.sqrt(tiles) + ".");
    }
}
