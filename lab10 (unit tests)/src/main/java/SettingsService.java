import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.List;

public class SettingsService implements ISettingsService {
    private boolean useBazz;

    public SettingsService(ISettingsProvider settings) throws IOException {
        var settingsContent = settings.getSettings().split("\n");

        for (var line : settingsContent) {
            if (line.isBlank())
                continue;

            var lineSplitted = line.split("=");

            if (lineSplitted.length != 2)
                throw new IllegalArgumentException();

            var key = lineSplitted[0].strip();
            var value = lineSplitted[1].strip();

            if (key.equals("useBazz") && value.equals("true"))
                useBazz = true;
        }
    }

    @Override
    public boolean isUseBazz() {
        return useBazz;
    }
}
