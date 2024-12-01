package com.example.joystickproject;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;
import androidx.appcompat.app.AppCompatActivity;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.URL;

import java.io.OutputStream;
import java.net.HttpURLConnection;
import java.net.URL;

public class MainActivity extends AppCompatActivity {

    private final String BASE_URL = "http://192.168.4.1/command?move=";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Button btnUp = findViewById(R.id.btnUp);
        Button btnDown = findViewById(R.id.btnDown);
        Button btnLeft = findViewById(R.id.btnLeft);
        Button btnRight = findViewById(R.id.btnRight);

        btnUp.setOnClickListener(v -> sendCommand("UP"));
        btnDown.setOnClickListener(v -> sendCommand("DOWN"));
        btnLeft.setOnClickListener(v -> sendCommand("LEFT"));
        btnRight.setOnClickListener(v -> sendCommand("RIGHT"));
    }

    private void sendCommand(String command) {
        new Thread(() -> {
            try {
                // Construct URL
                URL url = new URL(BASE_URL + command);

                // Open Connection
                HttpURLConnection connection = (HttpURLConnection) url.openConnection();
                connection.setRequestMethod("GET");
                connection.setConnectTimeout(5000);
                connection.setReadTimeout(5000);

                // Check Response
                int responseCode = connection.getResponseCode();
                if (responseCode == 200) {
                    BufferedReader in = new BufferedReader(new InputStreamReader(connection.getInputStream()));
                    String response = in.readLine();
                    in.close();
                    runOnUiThread(() -> Toast.makeText(this, "Command Sent: " + command, Toast.LENGTH_SHORT).show());
                } else {
                    runOnUiThread(() -> Toast.makeText(this, "Failed to send command. Response Code: " + responseCode, Toast.LENGTH_SHORT).show());
                }
                connection.disconnect();
            } catch (Exception e) {
                runOnUiThread(() -> Toast.makeText(this, "Error: " + e.getMessage(), Toast.LENGTH_LONG).show());
            }
        }).start();
    }
}