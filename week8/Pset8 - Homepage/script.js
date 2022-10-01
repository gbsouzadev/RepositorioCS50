console.log('hi');

let btn1 = document.querySelector(".red")
let btn2 = document.querySelector(".green")
let btn3 = document.querySelector(".blue")
let js_article = document.querySelector(".js-article")

btn1.addEventListener('click', function(){
    js_article.style.backgroundColor = "#F29191";
    console.log
});

btn2.addEventListener('click', function(){
    js_article.style.backgroundColor = "#65E271";
});

btn3.addEventListener('click', function(){
    js_article.style.backgroundColor = "#9893DA";
});