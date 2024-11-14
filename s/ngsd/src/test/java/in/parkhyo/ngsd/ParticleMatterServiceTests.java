package in.parkhyo.ngsd;

import static org.junit.jupiter.api.Assertions.assertEquals;
import java.util.List;

import org.junit.jupiter.api.Test;

public class ParticleMatterServiceTests {
    
    @Test
    public void testFindParticleValuesByLocation() {

        //Given
        String location = "Small room";
        List<Double> pm_values = List.of(50.0, 25.5, 34.0);
        
        //When
        List<Double> res = particleMatterService.findParticleValuesByLocation(location);

        //Then
        assertEquals(pm_values, res);
    }
}
