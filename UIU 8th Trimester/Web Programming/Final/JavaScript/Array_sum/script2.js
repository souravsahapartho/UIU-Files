// let arr = [1,2,3,4]
// arr.push(6) // add element at the end
// console.log("arr after push",arr)
// arr.pop() // remove element from the end
// console.log("arr after pop",arr)
// arr.unshift(6) // add element at the begining
// console.log("arr after unshift",arr)
// arr.shift() // remove element from the begining
// console.log("arr after shift",arr)

// arr.push([5,6,7,8])
// console.log("arr after pushing [5,6,7,8]",arr)
// arr.pop()

// arr=arr.concat([5,6,7,8])
// console.log("arr after concating [5,6,7,8]",arr)


// subarray= arr.slice(1,4)
// console.log("subarray of arr ",subarray)


// take an array as input through form, and show the sum 

//global variable
let arr = []
let sum = 0

document.getElementById("next-element-input").addEventListener("click",function(){

    element=document.getElementById("element-field").value 
    element=parseFloat(element)
    sum+=element
    arr.push(element)
})

document.getElementById("calculate-button").addEventListener("click",function(){
    // change the show-sum div

    document.getElementById("show-sum").innerHTML= `Your sum is ${sum}. <br> the array is ${arr}`
})







