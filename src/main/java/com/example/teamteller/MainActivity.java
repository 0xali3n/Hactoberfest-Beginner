package com.example.teamteller;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Spinner;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }
    public void showTeam(View view)
    {
        Spinner sp=(Spinner)findViewById(R.id.spinner);
        String cap=String.valueOf(sp.getSelectedItem());

        Intent intent=new Intent(this,MainActivity2.class);
        intent.putExtra("message",cap);
        startActivity(intent);
    }
}