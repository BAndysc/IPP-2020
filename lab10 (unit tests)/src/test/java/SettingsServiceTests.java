import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.extension.ExtendWith;
import org.mockito.Mock;
import org.mockito.junit.jupiter.MockitoExtension;

import java.io.IOException;

import static org.junit.jupiter.api.Assertions.assertThrows;
import static org.mockito.Mockito.when;

@ExtendWith(MockitoExtension.class)
public class SettingsServiceTests {
    @Mock
    private ISettingsProvider settingsProvider;

    @Test
    public void TestEmptyLine() throws IOException {
        when(settingsProvider.getSettings()).thenReturn("useBazz=false\n\nuseBazz=false");

        var service = new SettingsService(settingsProvider);

        Assertions.assertFalse(service.isUseBazz());
    }

    @Test
    public void TestInvalidLine() throws IOException {
        when(settingsProvider.getSettings()).thenReturn("useBazz");

        assertThrows(IllegalArgumentException.class, () -> new SettingsService(settingsProvider));
    }

    @Test
    public void TestValidUseBazz() throws IOException {
        when(settingsProvider.getSettings()).thenReturn("useBazz=true\nbebeb=false");

        var service = new SettingsService(settingsProvider);

        Assertions.assertTrue(service.isUseBazz());
    }
}
