let screen = document.getElementById('screen');
let buttons = document.querySelectorAll('button');
let svalue = '';
for (let item of buttons) {
    item.addEventListener('click', (e) => {
       let buttonText = e.target.innerText;
        console.log('Button text is ', buttonText);
        if (buttonText == 'X') {
            buttonText = '*';
            svalue += buttonText;
            screen.value = svalue;
        }
        else if (buttonText == 'C') {
            svalue = "";
            screen.value = svalue;
        }
        else if (buttonText == '=') {
            screen.value = eval(svalue);
            svalue = "";

        }
        else {
            svalue += buttonText;
            screen.value = svalue;
        }

    })
}

