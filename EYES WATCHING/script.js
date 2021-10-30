// Create a media condition that targets viewports at least 768px wide
const mediaQuery = window.matchMedia("(max-width: 800px)");
// Check if the media query is true
if (mediaQuery.matches) {
  // Then trigger an alert
  alert("KINDLY OPEN IN DESKTOP ONLY, IT WORKS ONLY IF YOU USE WITH MOUSE 🖱");
}
//ADDING MOUSE MOVE EVENT LISTNER AND FUNCTION TO THE BODY
document.querySelector("body").addEventListener("mousemove", eyefun);
// MAIN FUNCTION
function eyefun() {
  const eye = document.querySelectorAll(".eye");
  eye.forEach(function (eye) {
    //getBoundingClientRect() - The returned value is a DOMRect object which is the smallest rectangle which contains the entire element, including its padding and border-width. The left, top, right, bottom, x, y, width, and height
    let x = eye.getBoundingClientRect().left + eye.clientWidth / 2;
    let y = eye.getBoundingClientRect().top + eye.clientHeight / 2;

    //The Math.atan2() function returns the angle in the plane (in radians) between the positive x-axis and the ray from (0,0) to the point (x,y), for Math.atan2(y,x).
    let radian = Math.atan2(event.pageX - x, event.pageY - y);

    let rotation = radian * (180 / Math.PI) * -1 + 270;
    eye.style.transform = "rotate(" + rotation + "deg)";
  });
}
