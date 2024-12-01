# Repository Name: **ESP32-Android-Joystick-Control**

## Features 🌟
- 🚀 **ESP32 Access Point Mode**: No need for external Wi-Fi networks.
- 🛠️ **Servo Motor Control**: Move servo motors with precise commands (UP, DOWN, LEFT, RIGHT).
- 🔌 **Android App Integration**: Sends HTTP commands to the ESP32 using a joystick interface.
- ✅ **Lightweight Communication**: Direct HTTP communication without Firebase or cloud dependencies.

---

## Components Used

### Hardware
- 👨‍🔧 **ESP32 Microcontroller**
- 🎡 **Two Servo Motors** (e.g., SG90)
- ⚡ **Power Supply**

### Software
- 💻 **Arduino IDE**: For ESP32 programming.
- 📺 **Android Studio**: For Android app development.
- 🔀 **ESPAsyncWebServer Library**: For handling HTTP requests on the ESP32.

---

## Folder Structure 📂
```
ESP32-Android-Joystick-Control
├── AndroidApp
│   ├── app
│   ├── build.gradle
│   └── MainActivity.java
├── ESP32
│   ├── esp32-servo-control.ino
│   └── libraries
├── README.md
```

---

## How It Works 📊
1. 🔰 **Setup the ESP32**:
   - Configure the ESP32 in Access Point mode.
   - Attach servo motors to designated GPIO pins.
   - Start the server to listen for `/command` requests with `move` parameters.

2. 📱 **Develop the Android App**:
   - Create a joystick-like interface with buttons (UP, DOWN, LEFT, RIGHT).
   - Send HTTP requests to the ESP32's IP (e.g., `192.168.4.1`).

3. ⚖️ **Control Servo Motors**:
   - Each button corresponds to a command (`UP`, `DOWN`, etc.) and moves the servo motors accordingly.

---

## Installation Steps ⛏
### ESP32 Setup
1. Install [Arduino IDE](https://www.arduino.cc/en/software).
2. Install the required libraries:
   - **ESPAsyncWebServer**
   - **ESP32Servo**
3. Flash the `esp32-servo-control.ino` sketch to the ESP32.

### Android App
1. Open the `AndroidApp` folder in Android Studio.
2. Sync the Gradle project.
3. Build and install the APK on your Android device.

---

## Usage Instructions 🔄
1. Connect your Android device to the ESP32 Wi-Fi AP (`ESP32_AP` with password `12345678`).
2. Open the app and use the joystick buttons to control the servo motors.
3. Observe the motors responding to each button press (UP, DOWN, LEFT, RIGHT).

---

## Demo 📹
*Add screenshots or videos showcasing the Android app interface and servo movement.*

---

## Contributors
This project was collaboratively developed by the following team members:

---

- [Muditha] SEU_IS_18_ICT_069
- [Nayanagith] SEU_IS_18_ICT_044

---

## Troubleshooting ⚠️
- **Command not working?**
   - Ensure your Android device is connected to the ESP32 Wi-Fi.
   - Verify the IP address is correctly set to `192.168.4.1` in the app.
- **Motors not moving?**
   - Check servo motor connections.
   - Ensure the ESP32 has sufficient power.

---

## Contributing 🔧
Contributions are welcome! Feel free to fork the repository and submit a pull request.

---

## License ©
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

---

## Acknowledgments 👏
- Inspired by IoT projects for servo motor control.
- Thanks to open-source contributors of ESPAsyncWebServer and ESP32Servo libraries.

