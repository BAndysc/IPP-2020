public class FizzBuzzService implements IFizzBuzzService {
    private boolean withBazz;

    public FizzBuzzService(boolean withBazz) {
        this.withBazz = withBazz;
    }

    @Override
    public String evaluate(int number) {
        String result = "";
        if (number % 3 == 0)
            result += "fizz";

        if (number % 5 == 0)
            result += "buzz";

        if (withBazz && number % 7 == 0)
            result += "bazz";

        if (result.isEmpty())
            result = Integer.toString(number);

        return result;
    }
}
