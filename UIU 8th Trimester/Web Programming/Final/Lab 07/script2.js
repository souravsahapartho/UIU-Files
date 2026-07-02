
let total_price=0
let itemList=""
document.getElementById("add-to-cart-button").addEventListener("click",function(){
    // read the input
    let name= document.getElementById("name-field").value;
    let price= parseFloat(document.getElementById("price-field").value)
    let amount= parseFloat(document.getElementById("amount-field").value)

    let item_price= price*amount;
    total_price+=item_price

    itemList+=`your item is ${name}, price: ${item_price}<br>`

    document.getElementById("show-cart").innerHTML= itemList


})

document.getElementById("checkout-button").addEventListener("click",function(){
    document.getElementById("show-total").innerHTML=`your total is ${total_price}`
})