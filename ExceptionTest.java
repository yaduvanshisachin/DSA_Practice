public class ExceptionTest {
    public static void main(String[] args) {

        try {
            int a = 10;
            int b = 0;

            if (b == 0)
                throw new ArithmeticException("Cannot divide by zero");

            System.out.println(a / b);

        } catch (ArithmeticException e) {
            System.out.println("Arithmetic exception occurred");

        } catch (NullPointerException e) {
            System.out.println("Null pointer exception occurred");

        } catch (IndexOutOfBoundsException e) {
            System.out.println("Index out of bounds exception occurred");
        }
    }
}

