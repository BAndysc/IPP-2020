import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.extension.ExtendWith;
import org.mockito.junit.jupiter.MockitoExtension;

@ExtendWith(MockitoExtension.class)
public class FizzBuzzTest {

    @Test
    public void TestFizz() {
        FizzBuzzService fizzBuzzService = new FizzBuzzService(false);

        Assertions.assertEquals("fizz", fizzBuzzService.evaluate(3));
        Assertions.assertEquals("fizz", fizzBuzzService.evaluate(6));
        Assertions.assertEquals("fizz", fizzBuzzService.evaluate(9));
    }

    @Test
    public void TestBuzz() {
        FizzBuzzService fizzBuzzService = new FizzBuzzService(false);

        Assertions.assertEquals("buzz", fizzBuzzService.evaluate(5));
        Assertions.assertEquals("buzz", fizzBuzzService.evaluate(10));
        Assertions.assertEquals("buzz", fizzBuzzService.evaluate(20));
    }

    @Test
    public void TestNotBazz() {
        FizzBuzzService fizzBuzzService = new FizzBuzzService(false);

        Assertions.assertEquals("7", fizzBuzzService.evaluate(7));
    }

    @Test
    public void TestBazz() {
        FizzBuzzService fizzBuzzService = new FizzBuzzService(true);

        Assertions.assertEquals("bazz", fizzBuzzService.evaluate(7));
    }
}
