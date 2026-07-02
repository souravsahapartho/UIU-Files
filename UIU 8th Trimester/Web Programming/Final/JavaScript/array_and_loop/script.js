// take two numbers as input, add, and show the larger number
// prompt: take string as input
let x=Number(prompt("give the first number"))
let y=Number(prompt("give the second number"))


// const variable:
// 1. assign value during initialization
// 2. can't be assigned later
// const z=100
// z=x+y // can't be done

// console.log("sum is:", x+y )

// if(x>y)
//     console.log("larger number is:", x)
// else if(y>x)
//     console.log("larger number is: ",y )





/// build a calculator
/// ask user the operation type: add, sub, mul, div
/// take two numbers
/// do the operation

let op=prompt("enter the operation type:")
if(op=="add")
    console.log("sum is",x+y)
else if(op=="sub")
    console.log("sub is:", x-y)
else if(op=="mul")
    console.log("multuply is",x*y)
else if(op=="div")
    console.log("sub is:", x/y)


