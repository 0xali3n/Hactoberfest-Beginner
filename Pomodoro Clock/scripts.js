$(document).ready(function(){
    var minutes = 0;
    var restMinutes = 0;
    var buttonSet = 1;
    var buttonStartStop = 1;
    var counter = 0;
    var counterSec = 59;
    var counterDis;
    var control = 1;
    var clearIntControl = 1;
    var timerSec;
    
    //   function to display timers setting
    function  timerSetting(){
     $(".timerPeriod").html("<p>" +minutes+ " mins 00 secs</p>");
    $(".restPeriod").html("<p>" +restMinutes+ " mins 00 secs</p>");
    }
   
  //   display timer settings on screen
     $(".timerPeriod").html("<p>" +minutes+ " mins 00 secs</p>");
    $(".restPeriod").html("<p>" +restMinutes+ " mins 00 secs</p>");
    
    
  //   display set time of counter timer on buttonSetTimeTo when page loads
    $(".buttonSetTimeTo").html("<p>Set Time For Timer</p>");
    
  //   display set time of rest period timer or counter timer options on buttonSetTimeTo when on click
    $(".buttonSetTimeTo").on("click",function(){
      if (buttonSet === 1){
        buttonSet = 2;
      }
      else{
        buttonSet = 1;
      }
      if (buttonSet === 1){
        $(".buttonSetTimeTo").html("<p>Set Time For Timer</p>");
      }
      else {
        $(".buttonSetTimeTo").html("<p>Set Time For Rest Period</p>")
      }
    });
    
  //   on click function for subtract button
    $(".buttonSub").on("click", function(){
      if (buttonStartStop != 2){
      if (buttonSet === 1){
        if (minutes > 0){
        minutes--;
        }
      }
      
      else{
        if (restMinutes > 0){
        restMinutes--;
      }
      }
       timerSetting();
      }
    });
    
  //   on click button function for addition button
      $(".buttonAdd").on("click", function(){
        if (buttonStartStop != 2){
        if (buttonSet === 1){
          if (minutes < 999){
          minutes++;
      }
        }
      else{
        if (restMinutes < 999){
        restMinutes++;
      }
      }
        timerSetting();
        }
    });
    
  //   convert the set minutes to seconds for timer
    $(".buttonStart").on("click", function(){
  
      if (buttonStartStop === 1){
      $(".buttonStart").html("<p>Stop Timer</p>");
      var timerSecondNo1 = (minutes * 60) * 1000;
      var timerSeconds = timerSecondNo1;  
      var restTimerSeconds = (restMinutes * 60) * 1000;
      var buttonRestOrTimer = 1;
      var time = minutes - 1;
        buttonStartStop = 2;
        clearIntControl = false;
      }
      else{
        clearIntControl = true;
        buttonStartStop = 1;
      }
  
  //       function call from setInterval to countdown
             function onScreenTimer(){     
                 if (timerSeconds > 0){
  //               prefix a zero if sec below 10
                    if (counterSec < 10){
                      counterDis = "0" +counterSec;
                    }
                    else{
                      counterDis = counterSec;
                    }
            timerSeconds = timerSeconds - 1000;
                    if (control === 1){
                      $(".timerPeriod").html("<p>" +time+ " mins " + counterDis + " secs</p>");
                      $(".restPeriod").html("<p>" +restMinutes+ " mins 00 secs</p>");    
                    }
                       if (control === 2){
                      $(".timerPeriod").html("<p>" +minutes+ " mins 00 secs</p>");
                      $(".restPeriod").html("<p>" +time+ " mins " + counterDis + " secs</p>");    
                    }
            counter++;
            counterSec--;
            counterDis;
  //        reduce total minutes by 1 after 60 secs
            if (counter === 60){
            counter = 0;
            time = time - 1;
            counterSec = 59;
          }
          }    
              else{
                if (control === 1){
                counterSec = 59;
                control = 2;
                time = restMinutes - 1;
                timerSeconds = restTimerSeconds;
                onScreenTimer();
              }
                else if (control === 2){
                  time = minutes -1;
                  timerSeconds = timerSecondNo1;
                  control = 1;
                  onScreenTimer();
                }
              }
             }
                
  
    if (buttonRestOrTimer === 1){
      timerSec = setInterval(onScreenTimer, 1000);
    }  
      if (clearIntControl){
        clearInterval(timerSec);
       $(".buttonStart").html("<p>Start Timer</p>");
        minutes = 0;
        restMinutes = 0;
        timerSecondNo1 = 0;
        timerSeconds = 0;
        restTimerSeconds = 0;
        counterSec = 59;
        counter = 0;
           $(".timerPeriod").html("<p>" +minutes+ " mins 00 secs</p>");
    $(".restPeriod").html("<p>" +restMinutes+ " mins 00 secs</p>");
      }
  
  
    });
    
    //   on click button function to reset all values to 0
        $(".buttonReset").on("click", function(){
          minutes = 0;
          restMinutes = 0;
          timerSetting();
          buttonStartStop = 1;
          control = 1;
          counterSec = 59;
          clearIntControl = true;
          buttonSet = 1;
          clearInterval(timerSec);
          $(".buttonStart").html("<p>Start Timer</p>");
          $(".buttonSetTimeTo").html("<p>Set Time For Timer</p>");
    });
  });