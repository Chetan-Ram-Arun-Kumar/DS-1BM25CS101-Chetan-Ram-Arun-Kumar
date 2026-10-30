import java.util.Scanner;

public class SwapNumbers {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the first number: ");
        double first = scanner.nextDouble();

        System.out.print("Enter the second number: ");
        double second = scanner.nextDouble();

        System.out.println("\nBefore swapping:");
        System.out.println("First number = " + first);
        System.out.println("Second number = " + second);

        // Swapping using a temporary variable
        double temporary = first;
        first = second;
        second = temporary;

        System.out.println("\nAfter swapping:");
        System.out.println("First number = " + first);
        System.out.println("Second number = " + second);

        scanner.close();
    }
}
