let btn = document.getElementById("btn");
let inputText = document.getElementById("input-text");
let result = document.getElementById("result");
let i;

btn.addEventListener("click", function () {
  let txt = inputText.value;
  checkPalindrome(txt);
});
function checkPalindrome(txt) {
  let txt_new = txt.replace(/[^a-zA-z0-9]/g, "").toLowerCase();
  let len = txt_new.length;
  let halfLen = Math.floor(len / 2);

  for (i = 0; i < halfLen; i++) {
    if (txt_new[i] !== txt_new[len - 1 - i]) {
      result.textContent = "Nope! It is not Palindrome";
      return;
    }
    result.textContent = "Yes! It is Palindrome";
  }
}
