package in.parkhyo.ngsd;

import static org.junit.jupiter.api.Assertions.assertEquals;

import org.junit.jupiter.api.Test;

public class ExampleTest {

    @Test
    public void testAddition() {
        int a = 10;
        int b = 20;
        int result = a + b;
        assertEquals(30, result, "10 + 20은 30이어야 합니다.");
    }
}
