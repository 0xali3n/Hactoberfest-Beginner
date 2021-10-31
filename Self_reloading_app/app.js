//jshint esversion:6

const bodyParser = require("body-parser");
const express = require("express");

bodyParser
const app = express();

app.set("view engine",'ejs');

app.get("/",function (req,res) {
    var today = new Date();
    var day = "";
    //res.send(400); 
    if (today.getDay()===5) {
        //res.send("<h1>TGIF</h1>")
        day = "Friday";

    } else {
        //res.send("OGINF")
        day = "Not Friday"
    }
    res.render("list",{kindOfDay:day})
    //res.send(today.getDay()) err
    //console.log(today);

});


app.listen(3000,function (req,res) {
   console.log("server started on port:3000") 
});
