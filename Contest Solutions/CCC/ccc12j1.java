import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int limit = scanner.nextInt(), speed = scanner.nextInt();
        
        if (speed <= limit) 
            System.out.println("Congratulations, you are within the speed limit!");
        else {
            System.out.print("You are speeding and your fine is ");
            if (speed - limit >= 1 && speed - limit <= 20) {
                System.out.print("$100.");
            }
            else if (speed - limit >= 21 && speed - limit <= 30) {
                System.out.print("$270.");
            }
            else if (speed - limit >= 31) {
                System.out.print("$500.");
            }
        }
    }
}
