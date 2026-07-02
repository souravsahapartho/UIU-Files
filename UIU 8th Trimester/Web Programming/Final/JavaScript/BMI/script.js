// find sum of two numbers
// let i,j
// i = prompt("give the first number") // takes input as string 
// j = prompt("give the second number") 

// // typecast
// i=parseInt(i)
// j=parseInt(j)
// console.log("the sum is",i+j)





// take height, weight, and age as inputs.
// calculate the BMI. ( weight/height^2)
// for childs, BMI from 18 to 26 is healthy
// for adults, 18 to 24 is healthy


/// flow ==> 
/// trigger/event ( button click) ==> javascript call ==> 
/// read the input ==> process and show output

document.getElementById("input-taker").addEventListener("click", function () {
    /// everything after the click will be done here
    let height, weight, age;
    height = document.getElementById("height-input").value
    weight = document.getElementById("weight-input").value
    age = document.getElementById("age-input").value

    height = parseFloat(height)
    weight = parseFloat(weight)
    age = parseInt(age)

    let BMI = weight / (height * height) /// local variable

    if (BMI >= 18 && BMI <= 26 && age < 18)
        document.getElementById("show-output").innerHTML=`Your BMI is ${BMI}: healthy`
    else if (BMI >= 18 && BMI <= 24 && age >= 18)
        document.getElementById("show-output").innerHTML=`Your BMI is ${BMI}: healthy`
    else
        document.getElementById("show-output").innerHTML=`Your BMI is ${BMI}: unhealthy`

})







