// array 

let numbers=[1,2,3,4,5]
console.log("the array is:",numbers)

//  add element at the end
numbers.push(6)
console.log("the array after push:",numbers)
// remove element from the end
numbers.pop()
console.log("the array after pop:",numbers)
// add element at the begining
numbers.unshift(0)
console.log("the array after unshift:",numbers)
// remove element from the begining
numbers.shift()
console.log("the array after shift",numbers)

sliced_array=numbers.slice(1,3) // slicing index 1 to just before 3
console.log("after slicing",sliced_array)

length=numbers.length
console.log("length of the array",length)

// searching========================
// search element using index
console.log("element at index 1:",numbers[1])
// find index of an element
console.log("index of  5:", numbers.indexOf(5) )




// java script array is different==================

// numbers.push([6,7,8,9])
// console.log("the updated numbers after array push: ",numbers)

concated_array=numbers.concat([6,7,8,9])
console.log("the concated array:",concated_array)


// *** filtering ***

/// filter the even numbers from an array

/// filter contains a boolean function=============
/// number: every element of the array
/// index: index of that number
/// array: the full array
even_numbers=numbers.filter((number,index,array)=>{

    console.log("the index of ", number,": ",index)
    console.log("full array",array)
    if(number%2==0)
        return true;
    else
        return false


})

console.log("filtered even numbers",even_numbers)















