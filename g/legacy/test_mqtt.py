import unittest
from unittest.mock import patch
import os
import paho.mqtt.client as mqtt

from g_mqtt import g_mqttConnect, g_mqttPublish

class TestMqtt(unittest.TestCase):
    
    def setUp(self):
        self.client = mqtt.Client(mqtt.CallbackAPIVersion.VERSION1, "tester")
        
    @patch('g_mqtt.g_mqttConnect')
    def test_connect(self, mock_connect):
        mock_connect.return_value = True
        
        res = mock_connect(self.client, "localhost")
        
        self.assertTrue(res)
        
    @patch('g_mqtt.g_mqttPublish')
    def test_g_mqttPublish(self, mock_publish):
        mock_publish.return_value = True
        res = mock_publish("tester", "tester")
        
        self.assertTrue(res)
        
        
if __name__ == "__main__":
    unittest.main()