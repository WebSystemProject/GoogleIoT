
# MQTT

#### MQTT client running on ESP8266 to collect data from BME280 and sending to Google cloud IoT
   using Google Cloud IoT Core JWT and Arduino MQTT libraries

**MQTT Client**

Using the [Google Cloud IoT Core JWT](https://github.com/GoogleCloudPlatform/google-cloud-iot-arduino) and [Arduino MQTT](https://github.com/256dpi/arduino-mqtt) libraries


**MQTT Bridge**

Connect IoT device to Google Cloud IoT Core using MQTT Mosquitto.

##### Use Mosquitto to test the MQTT bridge - 

	#First, download root certificates
	$ curl https://pki.goog/roots.pem > roots.pem
	
	#Use Mosquitto to publish a message to the MQTT bridge
	mosquitto_pub \
	--host mqtt.googleapis.com \
	--port 8883 \
	--id projects/<your-project-id>/locations/<region-name>/registries/iotcore-registry/devices/<device-name> \
	--username unused \
	--pw "<your-jwt-token>" \
	--cafile ./roots.pem \
	--tls-version tlsv1.2 \
	--protocol-version mqttv311 \
	--debug \
	--qos 1 \
	--topic /devices/<device-name>/events \
	--message "Hello MQTT"


##### Pull the MQTT subscription to test

	$ gcloud pubsub subscriptions pull --auto-ack $PUBSUB_SUBSCRIPTION --limit=1