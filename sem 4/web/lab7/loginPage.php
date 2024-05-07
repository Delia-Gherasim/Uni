<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="UTF-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <title>LogIn</title>
  </head>
  <body>
    <div class="header">
      <h2>Welcome to the cool news page</h2>
      <div class="navBar">
        <style>
          .navBar {
            display: flex;
            justify-content: space-between;
            align-items: center;
          }
          .header {
            height: fit-content;
            width: 100%;
            background-color: aquamarine;
            text-align: center;
          }
        </style>
        <a href="mainPage.php">MAIN PAGE</a>
        <a href="loginPage.php"><b>LOGIN</b></a>
        <a href="seeAllNews.php">SEE ALL</a>
        <a href="updateNews.php">UPDATE</a>
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
      </div>
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
