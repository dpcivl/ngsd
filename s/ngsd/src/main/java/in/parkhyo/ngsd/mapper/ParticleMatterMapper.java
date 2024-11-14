package in.parkhyo.ngsd.mapper;

import java.util.List;

import org.apache.ibatis.annotations.Mapper;

@Mapper
public interface ParticleMatterMapper {
    
    List<Double> findParticleValuesByLocation(String location);
}
