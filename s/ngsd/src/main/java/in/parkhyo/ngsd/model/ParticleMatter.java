package in.parkhyo.ngsd.model;

import java.time.LocalDateTime;

import lombok.Data;
import lombok.Getter;
import lombok.Setter;

@Getter
@Setter
@Data
public class ParticleMatter {

    private String id;
    private LocalDateTime timestamp;
    private Double pm10;
    private Double pm2_5;
    private Double pm1_0;
}