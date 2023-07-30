import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int burger = scanner.nextInt() - 1, side = scanner.nextInt() - 1, drink = scanner.nextInt() - 1, dessert = scanner.nextInt() - 1;
        int[] burgers = {461, 431, 420, 0}, sides = {100, 57, 70, 0}, drinks = {130, 160, 118, 0}, desserts = {167, 266, 75, 0};
        
        System.out.println("Your total Calorie count is " + (burgers[burger] + sides[side] + drinks[drink] + desserts[dessert]) + ".");
    }
}
