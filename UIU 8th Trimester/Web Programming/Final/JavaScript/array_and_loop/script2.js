//  for loop and function

//========================
/// create a function to find out all the numbers that divides n

let n = Number(prompt("enter the number"))

function find_dividend(n) {

    for (let i = 1; i <= n; i++) {
        if (n % i == 0)
            console.log("divisible by", i)
    }

}

find_dividend(n)



// differences with c:
// 1. there is no main function. is executed from top to bottom
// 2. there is no data type. just let and const
// 3. difference in input and output procedure ( input through HTML/prompt, output through console)










