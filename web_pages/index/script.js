document.getElementById("helloForm").addEventListener("submit", function (event) {
    event.preventDefault();

    var name = document.getElementById("name").value;
    var greeting = "Hello, " + name + "!";
    
    document.getElementById("greeting").textContent = greeting;
});
