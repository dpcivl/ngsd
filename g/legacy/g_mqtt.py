import paho.mqtt.client as mqtt

# VERSION1 is deprecated
client = mqtt.Client(mqtt.CallbackAPIVersion.VERSION2, "tester")

def g_mqttConnect(client, host_ip):
    
    client.connect(host_ip, 1883)
    return True

def g_mqttPublish(client, topic, message):
    # client.publish(topic, message)
    client.publish(topic, message)
    return True