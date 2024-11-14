package in.parkhyo.ngsd.configuration;

import org.eclipse.paho.client.mqttv3.MqttClient;
import org.eclipse.paho.client.mqttv3.MqttConnectOptions;
import org.eclipse.paho.client.mqttv3.MqttException;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

@Configuration
public class MqttConfiguration {

    @Bean
    public MqttClient mqttClient() throws MqttException {
        String brokerUrl = "tcp://localhost:1883";
        String clientId = "test-client";
        MqttClient client = new MqttClient(brokerUrl, clientId);

        MqttConnectOptions options = new MqttConnectOptions();
        options.setAutomaticReconnect(true);
        options.setCleanSession(true);
        client.connect(options);
        options.setConnectionTimeout(10); // 연결 제한 시간 설정
        return client;
    }
}
