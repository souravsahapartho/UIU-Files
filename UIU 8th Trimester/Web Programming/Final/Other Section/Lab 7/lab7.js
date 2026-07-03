//replace(old, new)

let word = "Hello world, hello";

// let newWord = word.replaceAll("Hello", "Bye");
console.log(word);
console.log(word.includes("world"))
// console.log(newWord);

let sentence = "Mango,Lichi,Jackfruit";
let sentenceWords = sentence.split("Lichi");
console.log(sentenceWords);
console.log(word.indexOf("w"));

console.log(word.repeat(3));

console.log(word.slice(6));

function abbreviation(name){
    let arr = name.split(" ");
    let ans = "";
    for(let i of arr){
        ans += i.charAt(0) +".";

    }
    return ans;
}
console.log(abbreviation("Mahmudul Hasan"));

//constant value
const a =100;

//filtering of arrays

let people = [
    {name: "A", age: 21},
    {name: "B", age: 17},
    {name: "C", age: 26}
];

let adults = people.filter(x => x.age>=18 );
console.log(adults);

let arr1 = [20, 1, 51, 15, 108];
//for ascending sort of numbers
arr1.sort((a,b)=> a-b);
console.log(arr1);
//for descending sort of numbers
arr1.sort((a,b)=> b-a);
console.log(arr1);

//Number VS parseFloat
//For strings Number converts it to NaN (undefined)
//For string starting with a number along with a mix of string, parseFloat converts the first part into number
console.log(Number(document.getElementById("password").value)) ;








//Spring 25 Que 1
let attempts = 0;
function checkStrength(){
    attempts++;
    let score = 0;
    

    let userPass = document.getElementById("password").value;
    if(userPass.length < 6){
        document.getElementById("result").innerText = 
        "Min. 6 charactrers required";
    }
    else{
        //length
        score += (Math.floor((userPass.length-6)/2))*10;
        

        if(/[A-Z]/.test(userPass))
            score+=15;
        if(/[a-z]/.test(userPass))
            score+=15;
        if(/[0-9]/.test(userPass))
            score+=20;
        if(/[!@#$%^&*]/.test(userPass))
            score+=25;
        document.getElementById("result").innerText = score;
        console.log(score); 

        if (score > 100)
            alert("Perfect password");
        else if(score>91)
            document.getElementById("result").innerText = "Very Strong";
        else if (score > 71)
            document.getElementById("result").innerText = "Strong";
        else if (score > 51)
            document.getElementById("result").innerText = "Medium";
        else if (score > 31)
            document.getElementById("result").innerText = "Weak";
        else 
            document.getElementById("result").innerText = "Very Weak";

        if(attempts>8 && score <71)
            document.getElementById("result").innerText = "Need Practice";

        //to append in the paragraph field
        document.getElementById("result").innerText += " "+ score;

        //innerHTML processes the HTML tag vs innerTEXT prints the string as it is
        document.getElementById("result").innerHTML += "<b>Hello world</b>";
    }
}

//Call the function when button is clicked
let btnCheck = document.getElementById("checkPasswordBtn");
btnCheck.addEventListener("click", checkStrength);





