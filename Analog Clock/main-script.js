//  angle for hour hand=360/12H+ 30/60M= 30h+0.5m 
// angle for minute hand= (1min=6degree)=Mmin=6degree 
//  angle for second hand= 1sec=6degree 

setInterval(() => {
    d = new Date();
    htime = d.getHours();
    mtime = d.getMinutes();
    stime = d.getSeconds();

    hrotation = 30 * htime + mtime / 2 + stime / 120;
    mrotation = 6 * mtime + stime / 10;
    srotation = 6 * stime;

    hour.style.transform = `rotate(${hrotation}deg)`;
    minute.style.transform = `rotate(${mrotation}deg)`;
    second.style.transform = `rotate(${srotation}deg)`;


}, 1000);