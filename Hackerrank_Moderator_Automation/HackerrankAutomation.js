// node HackerrankAutomation.js --url=https://www.hackerrank.com --config=config.json

// npm init --yes
// npm install minimist
// npm install puppeteer-core

let minimist = require("minimist");
let puppeteer = require("puppeteer");
let fs = require("fs");

let args = minimist(process.argv);
// console.log(args.url);
// console.log(args.config);
let configJSON = fs.readFileSync(args.config, "utf-8"); // utf-8 we are reading this string in the form of
let configJSO = JSON.parse(configJSON);

// console.log(configJSO.userid);
// console.log(configJSO.password);
// console.log(configJSO.moderator);

// ####  ---By Promise method ----#####

//   let browserKaPromise = puppeteer.launch({headless: false});
//   browserKaPromise.then(function(browser){
//   let pagesKaPromise = browser.pages();
//     pagesKaPromise.then(function(pages){
//         let responseKaPromise = pages[0].goto(args.url);
//         responseKaPromise.then(function(response){
//             let browserCloseKaPromise = browser.close();
//             browserCloseKaPromise.then(function(){
//                 console.log("browser closed");
//             })
//         })
//     })
//   })

// IIFE -> Immediately invoked function execution
// (function(){

// })();

// we can write await only in that function that contains async in front of it

//####  ---By Async Await Method  ----#####

// (async () => {
//   let browser = await puppeteer.launch({headless: false});
//   let page = await browser.newPage();
//   await page.goto(args.url);
//   await page.screenshot({ path: 'example.png' });

//   await browser.close();
// })();

async function run(){
    // start the browser
    let browser = await puppeteer.launch({
        headless: false,
        args: [
            '--start-maximized'
        ],
        defaultViewport: null
    });

    // get the tab (there is only one tab)
    let pages = await browser.pages();
    let page = pages[0];
    
    // open the url
    await page.goto(args.url);

    // wait and then click on login on page1
    await page.waitForSelector("a[data-event-action='Login']");
    await page.click("a[data-event-action='Login']");
    
    // wait and then click on login on page2
    await page.waitForSelector("a[href='https://www.hackerrank.com/login']");
    await page.click("a[href='https://www.hackerrank.com/login']");
    
    // type userid
    await page.waitForSelector("input[name='username']");
    await page.type("input[name='username']", configJSO.userid, {delay: 28});
     
    // type password
    await page.waitForSelector("input[name='password']");
    await page.type("input[name='password']", configJSO.password, {delay: 28});
    
    // press click on login3 page3 
    await page.waitForSelector("button[data-analytics='LoginPassword']");
    await page.click("button[data-analytics='LoginPassword']");
    
    // click on compete
    await page.waitForSelector("a[data-analytics='NavBarContests']");
    await page.click("a[data-analytics='NavBarContests']");
    
    // click on manage contests
    await page.waitForSelector("a[href='/administration/contests/']");
    await page.click("a[href='/administration/contests/']");

    // find number of pages
    await page.waitForSelector("a[data-attr1='Last']");
    let numPages = await page.$eval("a[data-attr1='Last']", function(lastTag){ // $eval() - > gives specific -> first one
        let totpages = parseInt(lastTag.getAttribute("data-page"));
        return totpages;
    })

    console.log(numPages);

    // move through all pages
    for(let i = 1; i <= numPages; i++){
      await handleAllContestsOfAPage(page, browser);
    }

}

async function handleAllContestsOfAPage(page, browser){
    //do some code
    // find all urls of same page
    await page.waitForSelector("a.backbone.block-center");
    // contest outer urls
    let courls = await page.$$eval("a.backbone.block-center", function(atags){  //  $$eval() - > gives array
         let iurls = [];

         for(let i = 0; i < atags.length; i++){
             let url = atags[i].getAttribute("href");
             //inner urls
             iurls.push(url);
         }

         return iurls;
    });
    

    for(let i = 0; i < courls.length; i++){
        let curl = courls[i];

        let ctab = await browser.newPage();
        await SaveModeratorInContest(ctab, args.url + curl, configJSO.moderators)
        await ctab.close();
        await page.waitFor(3000);

    }
    //move to next page
    await page.waitFor(1500);
    await page.waitForSelector("a[data-attr1='Right']");
    await page.click("a[data-attr1='Right']");
}

async function SaveModeratorInContest(ctab, fullCurl, moderators){
    await ctab.bringToFront();
    await ctab.goto(fullCurl);
    await ctab.waitFor(3000);

    // click on moderators tab
    await ctab.waitForSelector("li[data-tab='moderators']");
    await ctab.click("li[data-tab='moderators']");
    for(let i = 0; i < moderators.length; i++){
        let moderator = moderators[i];
            // type in moderator
        await ctab.waitForSelector("input#moderator");
        await ctab.type("input#moderator", moderator, {delay: 50});

        await ctab.waitFor(700);
            // press enter
        await ctab.keyboard.press("Enter");
        await ctab.waitFor(700);
    }

}

run();


