public class Factorial {
    public static void main(String[] args) {
        int num = 5; // Change this number to find its factorial
        long factorial = 1;

        for (int i = 1; i <= num; i++) {
            factorial *= i; // Multiplies factorial by i in each iteration
        }

        System.out.println("The factorial of " + num + " is: " + factorial);
    }
}