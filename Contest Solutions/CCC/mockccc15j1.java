import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        String phone = scanner.nextLine();
        
        if (!(phone.substring(3, 4).equals(" ")) || phone.length() != 11 || !(phone.substring(0, 3).equals("416") || phone.substring(0, 3).equals("647") || phone.substring(0, 3).equals("437"))) {
            System.out.println("invalid");
        }
        else if (phone.indexOf("416") == 0) {
            System.out.println("valuable");
        }
        else {
            System.out.println("valueless");
        }
    }
}
