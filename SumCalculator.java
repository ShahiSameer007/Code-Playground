import java.util.Scanner;

public class SumCalculator {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Prompt the user to enter the first number
        System.out.print("Enter the first number: ");
        double num1 = scanner.nextDouble();

        // Prompt the user to enter the second number
        System.out.print("Enter the second number: ");
        double num2 = scanner.nextDouble();

        // Calculate the sum
        double sum = num1 + num2;

        // Display the result
        System.out.println("Sum: " + sum);

        // Close the scanner to avoid resource leak
        scanner.close();
    }
}
