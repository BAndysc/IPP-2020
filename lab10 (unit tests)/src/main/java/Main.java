import java.io.IOException;

public class Main {
    public static void main(String args[]) throws IOException {
        new FizzBuzz(new ConsoleInputOutput(), new FizzBuzzService(new SettingsService(new SettingsProvider()).isUseBazz())).run();
    }
}
