package in.parkhyo.ngsd.example;

import org.eclipse.paho.client.mqttv3.IMqttMessageListener;
import org.eclipse.paho.client.mqttv3.MqttClient;
import org.eclipse.paho.client.mqttv3.MqttException;
import org.eclipse.paho.client.mqttv3.MqttMessage;
//import org.springframework.stereotype.Component;

public class MqttExample {

    private String latestMessage = "";  // 최근 수신된 메시지를 저장하는 변수

    public MqttExample(MqttClient mqttClient) throws MqttException {
        if (!mqttClient.isConnected()) {
            mqttClient.connect();
            System.out.println("MQTT 연결 성공");
        }

        mqttClient.subscribe("req/test", new IMqttMessageListener() {
            @Override
            public void messageArrived(String topic, MqttMessage message) throws Exception {
                latestMessage = new String(message.getPayload());
                System.out.println("Received message: " + latestMessage);  // 수신된 메시지를 콘솔에 출력
            }
        });
    }

    public String getLatestMessage() {
        return latestMessage;
    }
}
