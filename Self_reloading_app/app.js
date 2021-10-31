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
// app.get("/w",(req,res)=>{
//     res.set("Content-Type", "text/html");
//       //OR
//     //res.setHeader("Content-Type", "text/html");
//     res.write("<h2> Thanks for introducing me to the songs of </h2>");
//     res.write("<h1>AP Dhillon</h1>");
//     res.write("<p>I'm addicted !</p>");
//     res.send();
// })
app.get("/file",(req,res)=>{
    res.sendFile(__dirname+"/index.html")///Users/sahilsoni/web/todolist-v1
    console.log(__dirname)
})
/*
app.get('/user/:uid/photos/:file', function(req, res){
    var uid = req.params.uid
      , file = req.params.file;
  
    req.user.mayViewFilesFrom(uid, function(yes){
      if (yes) {
        res.sendFile('/uploads/' + uid + '/' + file);
      } else {
        res.send(403, 'Sorry! you cant see that.');
      }
    });
});
*/

app.listen(3000,function (req,res) {
   console.log("server started on port:3000") 
});
