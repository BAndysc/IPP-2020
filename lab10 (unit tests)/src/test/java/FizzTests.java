import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.extension.ExtendWith;
import org.mockito.Mock;
import org.mockito.junit.jupiter.MockitoExtension;

import java.io.IOException;

import static org.mockito.ArgumentMatchers.eq;
import static org.mockito.Mockito.verify;
import static org.mockito.Mockito.when;

@ExtendWith(MockitoExtension.class)
public class FizzTests {

    @Mock
    private IFizzBuzzService fizzBuzzService;

    @Mock
    private IInputOutput inputOutput;

    @Test
    public void TestSingleFizz() throws IOException {
        when(inputOutput.hasNext()).thenReturn(true).thenReturn(false);
        when(inputOutput.nextInt()).thenReturn(5);
        when(fizzBuzzService.evaluate(5)).thenReturn("buzz");

        new FizzBuzz(inputOutput, fizzBuzzService).run();

        verify(inputOutput).print(eq("buzz"));
    }

    @Test
    public void TestSingleFizzBuzz() throws IOException {
        when(inputOutput.hasNext()).thenReturn(true).thenReturn(false);
        when(inputOutput.nextInt()).thenReturn(15);
        when(fizzBuzzService.evaluate(15)).thenReturn("fizzbuzz");

        new FizzBuzz(inputOutput, fizzBuzzService).run();

        verify(inputOutput).print(eq("fizzbuzz"));
    }
}
