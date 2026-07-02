// array=====================

let numbers= [2,3,4,5]
console.log("numbers",numbers)

// add element at the last
numbers.push(6)
console.log("numbers after push",numbers)
// remove element from the last
numbers.pop()
console.log("numbers after pop",numbers)
// add element at the begining
numbers.unshift(6)
console.log("numbers after unshift",numbers)
// remove element from the begining
numbers.shift()
console.log("numbers after shift",numbers)


numbers.push([6,7,8,9])
console.log("numbers after pushing an array",numbers)
numbers.pop()
console.log("numbers after pop",numbers)

concated_array=numbers.concat([6,7,8,9])
console.log("new array after concating an array",concated_array)


console.log("element at index 2:",numbers[2])

console.log("index of 5: ", numbers.indexOf(5))


console.log("number array:",numbers)
even_numbers=numbers.filter(number => number%2==0) // returns a new array
// filter such that the number is a prime 

// inside filter, we can pass
// 1. every element (number)
// 2. that element's index (index)
// 3. the actual full array (array)

prime_numbers=numbers.filter((number,index,array) =>{
    // think it like a function where number is the parameter
    // return true if you want to choose that element
    // otherwise return false

    // console.log("the index of number ",number,index, array)
    // return true;
    let i;
    for(i=2;i<number;i++)
    {
        if(number%i==0)
            return false;
    }
    return true;

})

// console.log("prime numbers", prime_numbers)


//===============================================
// take an array size and array elements input from user.
// then remove numbers that are bigger than both its previous and next number
// then add those numbers to their indices

// use: filter((number,index,array)=>


filtered_numbers = numbers.filter((number,index,array)=>{

    // just the removing part is coded here============
    let previous_number=array[index-1]
    let next_number= array[index+1]
    if(number>previous_number && number>next_number)
        return false
    else
        return true

})
















