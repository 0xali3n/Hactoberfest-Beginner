let advice = document.querySelector(".advice");
let btn = document.querySelector(".btn");

btn.addEventListener("click", () => {
    getNewAdvice();
});

getNewAdvice = async () => {

    try{
        const url = "https://api.adviceslip.com/advice";
        const response = await fetch(url);
        if(response && response.ok){
            const data = await response.json();
            advice.innerHTML = data.slip.advice;
        }else{
            advice.innerHTML = "There's Some Error";  
        }
    }catch(err){
        advice.innerHTML = `There's Some Error in fetching data: ${err}`;  
    }
    

};

getNewAdvice();
