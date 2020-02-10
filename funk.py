import serial, time
import paho.mqtt.client as mqtt

with serial.Serial('/dev/ttyUSB0', 115200, timeout=1) as ser:
  time.sleep(3)

  def on_message(client, userdata, message):
    ser.write(message.payload)

  def on_connect(client, userdata, flags, resultcode):
    print('Connected: ' + str(resultcode))
    client.subscribe('funk')

  client = mqtt.Client()
  client.on_message = on_message
  client.on_connect = on_connect

  client.connect('localhost', 1883, 60)
  client.loop_forever()


  #ser.write(b'b')
  #ser.write(b'd')
