# funk - Radio Sockets Control

> Control radio sockets with your Raspberry Pi and Arduino Nano

- Flash [sketch_sender.ino](/sketch_sender.ino) on your Arduino Nano that is connected to a radio sender.
- Run [funk.py](/funk.py) which listens to the mqtt topic `funk`.
- Enable autostart
  - Add the file `funk.service` under `/lib/systemd/system` with permission 644:
    ```
    [Unit]
    Description=Funk
    After=multi-user.target

    [Service]
    Type=simple
    ExecStart=/usr/bin/python3 /home/pi/funk/funk.py
    Restart=on-abort

    [Install]
    WantedBy=multi-user.target
    ```
  - Enable the service:
    ```
    sudo systemctl daemon-reload
    sudo systemctl enable funk.service
    ```
