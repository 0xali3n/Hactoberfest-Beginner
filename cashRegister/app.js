const billInput = document.querySelector("#billAmount");
const nextBtn = document.querySelector("#next");

const afterNext = document.querySelector(".after-next")
const cashInput = document.querySelector("#cashAmount");
const checkBtn = document.querySelector("#check");
const reloadBtn = document.querySelector("#reload");

const message = document.querySelector("#error-message");
const table = document.querySelector(".change-table");
const noOfNotes = document.querySelectorAll(".no-of-notes");

var notes = [2000, 500, 100, 20, 10, 5, 1];

table.style.display = "none";
afterNext.style.display = "none";


function validate() {
    table.style.display = "none";
    afterNext.style.display = "none";
    hideMessage();

    if (Number(billInput.value) > 0) {
        afterNext.style.display = "block";
    } else {
        showMessage("invalid bill Amount");
    }
}

function validatingBillAndCashAmt() {
    table.style.display = "none";
    hideMessage();
    var bill = Number(billInput.value);
    var cash = Number(cashInput.value);

    if (bill > 0 && cash > 0) {
        if (bill === cash) {
            showMessage("no amount to be returned");
        } else if (cash > bill) {
            var amountToBeReturned = cash - bill;
            showMessage("change to be returned : " + amountToBeReturned);
            calculateChange(amountToBeReturned);
        } else {
            showMessage("Do you wanna wash plates!");
        }
    } else {
        showMessage("invalid cash Amount");
    }
}

function calculateChange(amountToBeReturned) {
    table.style.display = "block";
    for (var i = 0; i <= notes.length; i++) {
        const numberOfNotes = Math.trunc(amountToBeReturned / notes[i]);
        amountToBeReturned %= notes[i];
        noOfNotes[i].innerText = numberOfNotes;
    }
}

function hideMessage() {
    message.style.display = "none";
}

function showMessage(msg) {
    message.style.display = "block";
    message.innerText = msg;
}

function refresh() {
    window.location.reload("Refresh");
}

nextBtn.addEventListener("click", validate);

reloadBtn.addEventListener("click", refresh);

checkBtn.addEventListener("click", validatingBillAndCashAmt);