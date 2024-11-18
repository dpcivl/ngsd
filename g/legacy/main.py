from g_mqtt import g_mqttConnect, g_mqttPublish
import paho.mqtt.client as mqtt

client = mqtt.Client(mqtt.CallbackAPIVersion.VERSION2, "tester")

#g_mqttConnect(client, "localhost")
#g_mqttPublish(client, "req/test", "Hello from g")

if __name__ == "__main__":
    g_mqttConnect(client, "localhost")
    g_mqttPublish(client, "req/test", "Hello from g")   