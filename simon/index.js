
var userClickedPattern =[];
var buttonColors = ['green','red','yellow','blue'];
var gamePattern =[];

var level = 0;

function playSound(name){
  var audio = new Audio('sound/'+name+'.wav');
  audio.play();
}

function nextSequence(){
  userClickedPattern = [];
  var randomcolor = Math.floor(Math.random()*4);
  var randomChosenColor = buttonColors[randomcolor];
  gamePattern.push(randomChosenColor);
  $("#" + randomChosenColor).fadeOut(100).fadeIn(100);
  playSound(randomChosenColor);
  level++;
  $('h1').text('Level '+level);



}

$('.btn').click(function (){
  var  userChosenColour = this.id;
  playSound(userChosenColour);
  userClickedPattern.push(userChosenColour);
  console.log(userClickedPattern);
  animatePress(userChosenColour);
  checkAnswer(userClickedPattern.length-1);
});

function animatePress(currentColour){
  $("#"+currentColour).addClass('pressed').delay(100).queue(function(next){
    $(this).removeClass("pressed");
    next();
});

  // setTimeout(function () {
  //     $("#" + currentColor).removeClass("pressed");
  //   }, 100);
}
var x=0
$('h1').text('Press A Key to Start');
$(document).keypress(function (){
  while(x<1){
    $('h1').text('Level '+level);
    nextSequence();
    x++;
  }
});

function checkAnswer(currentLevel){
  if (gamePattern[currentLevel] === userClickedPattern[currentLevel]) {

      console.log("success");

      //4. If the user got the most recent answer right in step 3, then check that they have finished their sequence with another if statement.
      if (userClickedPattern.length === gamePattern.length){

        //5. Call nextSequence() after a 1000 millisecond delay.
        setTimeout(function () {
          nextSequence();
        }, 1000);

      }

    } else {

      console.log("wrong");
      console.log("wrong");
      playSound('wrong');
      $('body').addClass('game-over');
      setTimeout(function (){
        $('body').removeClass('game-over');
      },200);
      $("#level-title").text("Game Over, Press Any Key to Restart");
      startOver();

    }

}

function startOver(){
  level =0;
  gamePattern=[];
  started = 0;
}
