import java.io.IOException;

public class FizzBuzz {

    private IInputOutput inputOutput;
    private IFizzBuzzService fizzBuzzService;

    public FizzBuzz(IInputOutput inputOutput,
                    IFizzBuzzService fizzBuzzService) throws IOException {
        this.inputOutput = inputOutput;
        this.fizzBuzzService = fizzBuzzService;
    }

    public void run() {
        while (inputOutput.hasNext()) {
            int number = inputOutput.nextInt();
            inputOutput.print(fizzBuzzService.evaluate(number));
        }
    }
}
