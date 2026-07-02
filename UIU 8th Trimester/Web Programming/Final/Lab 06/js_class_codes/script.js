//==============================
/// implement a calculator 
/// at first take input what operation to do ( add, sub, mul, div)
/// then take two numbers, apply that operation
///==============================

let op=prompt("enter the operation type");
let x=Number(prompt("enter the first number"));
let y=Number(prompt("enter the second number"));

if(op=="add")
    console.log("sum:",x+y);
else if(op=="sub")
    console.log("sub:",x-y);
else if(op=="mul")
    console.log("mul:",x*y);
else 
    console.log("div:",x/y)



