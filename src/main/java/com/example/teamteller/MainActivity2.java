package com.example.teamteller;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.widget.ImageView;
import android.widget.TextView;

public class MainActivity2 extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main2);
        Intent intent=getIntent();
        String msg=intent.getStringExtra("message");
        String t="";
        ImageView imageview = (ImageView)findViewById(R.id.imageView);

        switch(msg)
        {
            case "Dhoni":
                t="chennai\nsuper\nkings";
                imageview.setImageDrawable(getDrawable(R.drawable.csk));
                break;
            case "Virat":
                t="royal\nchallengers\nbangalore";
                imageview.setImageDrawable(getDrawable(R.drawable.rcb));
                break;
            case "Samsan":
                t="rajasthan\nroyals";
                imageview.setImageDrawable(getDrawable(R.drawable.rr));
                break;
            case "Morgan":
                t="kolkata\nknight\nriders";
                imageview.setImageDrawable(getDrawable(R.drawable.kkr));
                break;
            case "Rahul":
                t="punjab\nkings";
                imageview.setImageDrawable(getDrawable(R.drawable.pbk));
                break;
            case "Rohit":
                t="mumbai\nindians";
                imageview.setImageDrawable(getDrawable(R.drawable.mi));
                break;
            case "Iyer":
                t="delhi\ncapitals";
                imageview.setImageDrawable(getDrawable(R.drawable.dc));
                break;
            case "Williamson":
                t="sunrisers\nhyderabad";
                imageview.setImageDrawable(getDrawable(R.drawable.srh));
                break;
        }
        TextView textView=(TextView)findViewById(R.id.textView);
        textView.setText(t);
    }
}