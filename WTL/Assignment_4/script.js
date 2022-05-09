const inputEl = document.getElementById("term");
const keys = document.querySelectorAll(".numK");
const opKs = document.querySelectorAll(".opK");
const calculateButton = document.querySelector(".calculateBtn");
const ansEl = document.getElementById("ansDiv");
const backSpace = document.getElementById("Backspace");

keys.forEach((k) => {
  k.addEventListener("click", () => {
    term.value += k.id;
    console.log(parseInt(k.id));
  });
});

opKs.forEach((sk) => {
  sk.addEventListener("click", () => {
    term.value += sk.id;
    console.log(sk.id);
  });
});

const calculate = () => {
  const regEx = /^\s*([-+]?)(\d+)(?:\s*([-+*\/])\s*((?:\s[-+])?\d+)\s*)+$/;
  const regEx2 = /^[\d\+\/\*\.\- \(\)]*$/;
  if (regEx2.test(term.value)) {
    setAnswerDiv(eval(term.value), "answer");
  } else {
    setAnswerDiv();
  }
};

calculateButton.addEventListener("click", () => {
  calculate();
});

backSpace.addEventListener("click", () => {
  const oldValue = term.value;
  console.log(term.value);
  term.value = oldValue.substring(0, oldValue.length - 1);
});

function setAnswerDiv(value, type) {
  if (type === "answer") {
    ansEl.style.color = "#00d111";
    ansEl.style.border = "2px solid #00d111";
    ansEl.innerHTML = value;
  } else {
    ansEl.innerHTML = "Invalid Input";
    ansEl.style.color = "#FF0000";
    ansEl.style.border = "2px solid #FF0000";
  }
}

document.addEventListener("keyup", (e) => {
  const keyPressed = e.code;
  const keyElement = document.getElementById(keyPressed);
  keyElement && keyElement.classList.remove("pressed");
  // console.log(keyElement.classList);
  // console.log(typeof Object.keys(Keys));
});

document.addEventListener("keydown", (e) => {
  const keyPressed = e.code;
  console.log(e.code);
  //To check code of button pressed

  const keyElement = document.getElementById(keyPressed);
  console.log(keyElement);
  keyElement && keyElement.classList.add("pressed");

  if (keyPressed === "Enter" || keyPressed === "Equal") {
    // console.log("calcPressed");
    calculate();
  }
  //getmodifierstate
});
