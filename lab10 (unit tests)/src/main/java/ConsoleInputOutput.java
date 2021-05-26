import java.util.Scanner;

public class ConsoleInputOutput implements IInputOutput {

    private final Scanner scanner;

    public ConsoleInputOutput() {
        scanner = new Scanner(System.in);
    }

    @Override
    public boolean hasNext() {
        return scanner.hasNext();
    }

    @Override
    public int nextInt() {
        return scanner.nextInt();
    }

    @Override
    public void print(String s) {
        System.out.println(s);
    }
}
