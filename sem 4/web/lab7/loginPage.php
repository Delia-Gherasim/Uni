<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="UTF-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <title>LogIn</title>
  </head>
  <body>
    <div class="header">
      <h2>It's gonna be <b>LEGEN -</b> this is the news page homework <b>- DARY</b></h2>
      <div class="navBar">
        <style>
          .navBar {
            display: flex;
            justify-content: space-around;
            align-items: center;
          }
          .header {
            height: fit-content;
            width: 100%;
            background-color: aquamarine;
            text-align: center;
          }
        </style>
        <a href="loginPage.php"><b>LOGIN</b></a>
        <a href="seeAllNews.php">SEE ALL</a>
        <!-- <a href="updateNews.php">UPDATE</a> -->
        <a href="addNews.php">ADD</a>
      </div>
    </div>
    <div class="logIn">
      <div class="inputForm">
        <h3 class="inputTitle">Log In:</h3>
        <div class="input">
          <h4>Username:</h4>
          <input type="text" id="Username" /><br /><br />
        </div>
        <div class="input">
          <h4>Password:</h4>
          <input type="text" id="password" /><br /><br />
        </div>

        <input type="button" value="Submit" onclick="submitUpdate()" />
        <input type="button" value="LogOut" onclick="logout()" />
      </div>
      <script>
       function submitUpdate() {
        const user = document.getElementById('Username').value; 
        const password = document.getElementById('password').value;

        const xhr = new XMLHttpRequest();
        xhr.open('POST', 'loginLogic.php', true); 
        xhr.setRequestHeader('Content-Type', 'application/x-www-form-urlencoded');

        const data = `user=${encodeURIComponent(user)}&password=${encodeURIComponent(password)}`;

        xhr.send(data);
      }
      function logout() {
      const xhr = new XMLHttpRequest();
      xhr.open('POST', 'logOutLogic.php', true); 
      xhr.setRequestHeader('Content-Type', 'application/x-www-form-urlencoded');

      xhr.send(); 
    }


    </script>
      <style>
        .inputForm {
          border-color: black;
          border-radius: 10px;
          border-style: solid;
          margin-left: 40%;
          margin-right: 40%;
          margin-top: 40px;
          text-align: center;
        }
        .input {
          display: flex;
          align-items: center;
        }
        .inputTitle {
          align-self: center;
          position: relative;
        }
      </style>
    </div>
  </body>
</html>
