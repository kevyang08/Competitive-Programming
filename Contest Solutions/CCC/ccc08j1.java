import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        double weight = scanner.nextDouble(), height = scanner.nextDouble(), bmi = weight/Math.pow(height, 2);
        
        if (bmi > 25) {
            System.out.println("Overweight");
        }
        else if (bmi <= 25 && bmi >= 18.5) {
            System.out.println("Normal weight");
        }
        else if (bmi < 18.5) {
            System.out.println("Underweight");
        }
    }
}
