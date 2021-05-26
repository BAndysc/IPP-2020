import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.List;

public class SettingsProvider implements ISettingsProvider {
    @Override
    public String getSettings() throws IOException {
         return Files.readString(Path.of("settings.ini"));
    }
}
