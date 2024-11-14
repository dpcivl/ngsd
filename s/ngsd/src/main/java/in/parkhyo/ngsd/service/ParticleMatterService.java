package in.parkhyo.ngsd.service;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import in.parkhyo.ngsd.mapper.ParticleMatterMapper;

@Service
public class ParticleMatterService {

    private final ParticleMatterMapper particleMatterMapper;

    @Autowired
    public ParticleMatterService(ParticleMatterMapper particleMatterMapper) {
        this.particleMatterMapper = particleMatterMapper;
    }

    public List<Double> findParticleValuesByLocation(String location) {
        return List.of(50.0, 25.5, 34.0);
        //return particleMatterMapper.findParticleValuesByLocation(location);
    }

}
