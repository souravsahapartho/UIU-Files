let numbers=[20,7,5,4,8,10,2,4]

/// filter the array such that numbers 
// that are larger than both its 
/// previous and next number is removed

/// after filtering, add every number 
// with its index

// print the final array

let filtered_numbers= numbers.filter((number,index,array)=>{
    if(index==0)
    {
        // no previous number
        next_number=array[index+1]
        if(number>next_number)
            return false
        else return true;
    }
    if(index==numbers.length-1)
    {
        // no next number
        previous_number=array[index+1]
        if(number>previous_number)
            return false
        else return true;
    }
    previous_number=array[index-1]
    next_number=array[index+1]
    if(number>previous_number && number > next_number)
        return false
    else
        return true;
})

console.log("array after filter: ",filtered_numbers)
processed_array=filtered_numbers.map((number,index,array)=>{
    console.log(index,"th element:",number+index)
})

