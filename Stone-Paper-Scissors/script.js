let userScore = 0;
let computerscore = 0;
const userScore_span = document.getElementById("user-score");
const computerScore_span = document.getElementById("computer-score");
const scoreBoard_div = document.querySelector(".score-board");
const result_p = document.querySelector(".result >p");
const images = document.querySelector(".choices");

const happy = document.getElementById("win");
const sad = document.getElementById("lose");
const ok = document.getElementById("draw");

const actionmsg = document.getElementById("action-msg");

const rock = document.getElementById("r");
const paper = document.getElementById("p");
const scissor = document.getElementById("s");

function getComputerChoice() {
    const choices = ["r", "p", "s"];
    const randomNum = Math.trunc(Math.random() * 3);
    return choices[randomNum];
}
getComputerChoice();

function word(c) {
    if (c === "r") return "Rock";
    if (c === "p") return "Paper";
    return "Scissors";
}

happy.classList.add("hidden");
sad.classList.add("hidden");
ok.classList.add("hidden");

function win(userChoice, computerChoice) {
    userScore++;
    userScore_span.textContent = userScore;
    computerScore_span.innerHTML = computerscore;
    const smallU = "user".fontsize(3).sub();
    const smallC = "computer".fontsize(3).sub();
    result_p.innerHTML =
        word(userChoice) +
        smallU +
        " beats " +
        word(computerChoice) +
        smallC +
        ". You Win!🍧 ";
    happy.classList.remove("hidden");
    sad.classList.add("hidden");
    ok.classList.add("hidden");
    actionmsg.classList.add("hidden");
}

function lose(userChoice, computerChoice) {
    computerscore++;
    userScore_span.textContent = userScore;
    computerScore_span.innerHTML = computerscore;
    const smallU = "user".fontsize(3).sub();
    const smallC = "computer".fontsize(3).sub();
    console.log("hi");
    result_p.innerHTML =
        word(computerChoice) +
        smallC +
        " beats " +
        word(userChoice) +
        smallU +
        ". You Lose! 🍼 ";
    happy.classList.add("hidden");
    sad.classList.remove("hidden");
    ok.classList.add("hidden");
}

function draw(userChoice, computerChoice) {
    const smallU = "user".fontsize(3).sub();
    const smallC = "computer".fontsize(3).sub();
    result_p.innerHTML =
        word(userChoice) +
        smallU +
        " equals " +
        word(computerChoice) +
        smallC +
        ". It's a Draw! 🍭 ";
    happy.classList.add("hidden");
    sad.classList.add("hidden");
    ok.classList.remove("hidden");
}

function game(userChoice) {
    const computerChoice = getComputerChoice();

    switch (userChoice + computerChoice) {
        case "rs":
        case "pr":
        case "sp":
            win(userChoice, computerChoice);
            break;
        case "sr":
        case "rp":
        case "ps":
            lose(userChoice, computerChoice);
            break;
        case "rr":
        case "ss":
        case "pp":
            draw(userChoice, computerChoice);
            break;
    }
}

function main() {
    rock.addEventListener("click", function() {
        game("r");
    });

    paper.addEventListener("click", function() {
        game("p");
    });

    scissor.addEventListener("click", function() {
        game("s");
    });
}
main();