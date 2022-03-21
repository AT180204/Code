function validate()
{
    var username = document.getElementById("username").value;
    var password = document.getElementById("password").value;

    if(username.length <= 5 || username.length >= 15)
    {
        alert("Username khong hop le!");
        return;
    }
    if(password.length <= 8 || password.length >= 20)
    {
        alert("Password khong hop le!");
        return;
    } 
    if(/[A-Z]/.test(password.charAt(0)) && /[a-z]/.test(password) && /[0-9]/.test(password))
        alert("Du lieu gui di thanh cong!");
    else
        alert("Password khong hop le!");
    
}
