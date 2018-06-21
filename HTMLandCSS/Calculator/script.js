var act = document.getElementById('act'); // add Span element

/* Added Button Element */
var plusButton = document.getElementById('plus');
var minusButton = document.getElementById('minus');
var multiButton = document.getElementById('multi');
var divideButton = document.getElementById('divide');

/* Added onClick Function in plus, minus, multi, divide */
plusButton.onclick = function() { calculate(1) }
minusButton.onclick = function() { calculate(2) }
multiButton.onclick = function() { calculate(3) }
divideButton.onclick = function() { calculate(4) }

/* Calculate function */
function calculate(ch) {
    var value1 = document.getElementById('value1');
    var value2 = document.getElementById('value2');

    if (ch == 1) {
        document.getElementById("act").innerHTML = "+";
        var total = parseFloat(value1.value) + parseFloat(value2.value);
        document.getElementById('display').innerHTML = total;
    } else if (ch == 2) {
        document.getElementById("act").innerHTML = "-";
        var total = parseFloat(value1.value) - parseFloat(value2.value);
        document.getElementById('display').innerHTML = total;
    } else if (ch == 3) {
        document.getElementById("act").innerHTML = "&times;";
        var total = parseFloat(value1.value) * parseFloat(value2.value);
        document.getElementById('display').innerHTML = total;
    } else if (ch == 4) {
        document.getElementById("act").innerHTML = "&divide;";
        var total = parseFloat(value1.value) / parseFloat(value2.value);
        document.getElementById('display').innerHTML = total;
    } else {
        console.log('Hello');
    }
}