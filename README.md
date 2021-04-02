# GoogleIoT

## Team Members

### 1. Abhay Tyagi
### 2. Manohar Singh Rajawat
### 3. Payal Singh
### 4.  Vijayalaxmi Patil

- CSU Website Tutorial Hosting - http://csweb01.csueastbay.edu/~rg8643/googleiot/index.html


This project is based on nodemcu mictocontroller board.

### Introduction to Google Cloud IoT


#### 1. What is Google IOT cloud


Google IoT services collects real time data from IoT devices. They collect data at the edge or in the cloud.This is a fully managed service provided by Google. It allows to us to securely connect, ingest and manage data from IoT devices. The combination of Cloud IoT Core with other services on Google's cloud platform provide us a complete package to collect, manage, process,analyze and visualize Iot data. 



### 2. Benefits Of Google Cloud for IoT devices

IoT(Internet of Things) generates lots of data. We need an efficient,affordable and  scalable method to manage these devices.There comes Google cloud in picture.  It provides  a coherent mechanism to handle the informations generated by the devices. Google Cloud provides a platform to store, analyze and process the data.  


####  Key Features of Google cloud IoT

1. **Google cloud provides tools for all our IoT applications starting fom ingestion to intelligence.**
2. **It lets us automatically predicts when equipment needs maintenance.**
3. **It provides feature of Real-time asset tracking.**



### 3. Device Management in Google Cloud:

#### 1. IoT Core device manager:

This is a fully managed service. IoT Core device manager manages the devices in the google cloud.It handles registration, authentication, and authorization inside the Google Cloud resource hierarchy as well as device metadata stored in the cloud. It has the ability to send device configuration from the service to devices.

#### 2. Ingestion:

It is a process of importing data from devices into the Google Cloud services. Depending upon the data like whether it is telemetry or operational information about the devices, Google cloud provides different ingestion services.

#### 3. IoT Core MQTT:

MQTT stands for Message Queue Telemetry Transport. It is a messgaing protocol for the Internet of Things.
It is an OASIS standard protocol used for IoT connectivity.
This is very simple and lightweight messaging protocol. It is basically designed for the devices which has low bandwdth,high-latency. 
 



IoT Core provides a secure MQTT messaging protocol for IoT devices and they are managed by IoT core. The IoT core MQTT directly connects with Google cloud Pub/Sub. The advantages of using this protocol is that with the help of configuration management feature, it can send real-time telemetry data and  can immediately receive messages sent from the cloud to the device.

#### 4.Pub/Sub

It gives globally durable message ingestion service. It helps to connect to other Google Cloud services like ingestion, data pipe lines and storage systems. If we create topics for streams/channels , we can enable different components of our application in order to subscribe to certain streams of data. We do not need to construct subscriber-specific channels on our IoT devices.




### Introduction to Project on Google IoT

#### Project Title: Google Based IoT Cloud Service -   Weather Temperature Monitoring

#### Hardware Requirements:
1. Microcontroller -  Nodemcu esp8266 
2. Sensor -  BME 280
3. Breadboard
4. Jumper Wires
5. USB cable


### Flow Diagram Of Project

![flowdiagram](images/project_flowDiagram.jpg)


### Steps

#### 1. Read data From the sensor with microcontroller

ESP8266 Arduino code prints BME280 sensor data temperature, pressure, humidity, altitude to the Arduino Serial Plotter (9600)

####  2. MQTT bridge 

MQTT client running on ESP8266  collects data from BME280 and sends to Google cloud IoT

It uses Google Cloud IoT Core JWT and Arduino MQTT libraries

##### a. MQTT Client

Uses the Google Cloud IoT Core JWT and Arduino MQTT libraries

##### b. MQTT Bridge

Connects IoT device to Google Cloud IoT Core using MQTT Mosquitto.





#### 3. Setup MQTT in google cloud




##### 1. Creating Google Pub/Sub Topic in Google Cloud

To create a Cloud Pub/Sub topic, run:

	gcloud pubsub topics create mytopic
![create pub/sub topic ](images/createpubsubTopic.jpg)

##### 2. Creating Subscription on Pub/Sub

![create Subscription on Pub/Sub ](images/createSubscriptionPubSub.jpg)


##### 3. publishing Message on Pub sub
![publishing Message on Pub sub](images/publishMessagePubSub.jpg)


##### 4. listening on pub/sub
![listening on pub/sub](images/listeningPubSub.jpg)



#### 4. Registtry and device creation on Google Cloud

#####  Create Registry for the Project

![registry1](images/registry_devices/registry1.png)


#####  Set Registry Properties 

![registry2](images/registry_devices/registry2.png)


##### In cloud Pub/Sub topics create a topic

![registry3](images/registry_devices/registry3.png)

![registry4](images/registry_devices/registry4.png)

##### Registry created details
![registry5](images/registry_devices/registry5.png)


##### Go to devices and select CREATE  A DEVICE

![devices1](images/registry_devices/devices1.png)

##### Add Device ID and click create
![devices2](images/registry_devices/devices2.png)


##### In Registry details you can see your device details
![devices3](images/registry_devices/devices3.png)

#### Setting up BigQuery

![bigQuery1](images/bigQuery/bigQuery1.png)

![bigQuery2](images/bigQuery/bigQuery2.png)

![bigQuery3](images/bigQuery/bigQuery3.png)

![bigQuery4](images/bigQuery/bigQuery4.png)

![bigQuery5](images/bigQuery/bigQuery5.png)


#### Setting up DataFlow

![DataFlow](images/dataFlow/dataFlow1.png)
![DataFlow](images/dataFlow/dataFlow2.png)
![DataFlow](images/dataFlow/dataFlow3.png)
![DataFlow](images/dataFlow/dataFlow4.png)


#### Setting up Google Storage

![googleStorage1](images/googleStorage/googleStorage1.png)
![googleStorage2](images/googleStorage/googleStorage2.png)
![googleStorage3](images/googleStorage/googleStorage3.png)
![googleStorage4](images/googleStorage/googleStorage4.png)
![googleStorage5](images/googleStorage/googleStorage5.png)
![googleStorage6](images/googleStorage/googleStorage6.png)
![googleStorage7](images/googleStorage/googleStorage7.png)

#### Setting up Pub-Sub


![pubSub1](images/pubSub/pubSub1.png)

![pubSub2](images/pubSub/pubSub2.png)

![pubSub3](images/pubSub/pubSub3.png)

![pubSub4](images/pubSub/pubSub4.png)

![pubSub5](images/pubSub/pubSub5.png)

![pubSub6](images/pubSub/pubSub6.png)

![pubSub7](images/pubSub/pubSub7.png)


### Future of Google IoT cloud 

Every year the number of IoT devices keep increasing. The data generated by these devices are very extensive. These data can be used to provide powerful insights. This is one of the biggest growth area especially with the arrival of 5G technology. The data generated by these IoT devices are different. Some of the data types are used to provide GPS co-ordinates, temperature, pressure, humidity, vehicle speed, etc. These are very complex data and need a reliable platform to analyze. Cloud Computing will help to analyze and provide insights on data. 

### Conclusion

As the number of IoT devices keeps increasing the data generated by them will increase multiple folds. Cloud Computing plays a major role in storing, analyzing and providing insights on the data. Google  Cloud offers a complete package where these data can be stored and analyzed. 


#### References 
1. https://mqtt.org/faq/
2. https://cloud.google.com/solutions/iot-overview
3. https://cloud.google.com/solutions/iot#section-7
4. https://cloud.google.com/solutions/iot
5. https://cloud.google.com
6. https://nodemcu.readthedocs.io/en/release/
7. https://protosupplies.com/product/gy-bme280-pressure-humidity-temperature-sensor-module/

 
 