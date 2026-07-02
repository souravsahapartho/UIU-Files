
// let sum=0;

// // to track a tag, and to add an event tracker
// document.getElementById("input-button").addEventListener("click",function(){
//     // read the input
//     let input= document.getElementById("text-field");
//     /// parse the string to integer
//     let int_input=parseInt(input.value)
//        console.log(int_input);

//     // do something
//     sum+=int_input;

//     // show the output
//     document.getElementById("show-sum").innerHTML =`total sum is ${sum}`

// })



// ask users about their age, height, and weight.
// then find the BMI
// if the BMI is in between 18 to 26, report them 
// as healthy. 
// BMI = weight / height^2 
// weight in kg, height in meter. 
// if the person is not adult, the BMI should be 
// 18-24

// show the BMI and report if the person is healthy
// or not

let BMI=0

// to track a tag, and to add an event tracker
document.getElementById("input-button").addEventListener("click",function(){
    // read the input
    let age= document.getElementById("age-field");
    let weight= document.getElementById("weight-field");
    let height= document.getElementById("height-field");
    /// parse the string to integer
    let int_age=parseInt(age.value);
    console.log(int_age);
    let int_height=parseFloat(height.value);
    console.log(int_height);
    let int_weight=parseFloat(weight.value);
    console.log(int_weight);

    // do something
    BMI = int_weight/(int_height*int_height)

    let result="unhealthy"
    if(int_age<18 && BMI>=18 && BMI<=24)
        result="healthy"
    else if(int_age>=18 && BMI>=18 && BMI<=26)
        result="healthy"



    // show the output
    document.getElementById("show-results").innerHTML =`Your BMI is ${BMI}. You are ${result}`

})


