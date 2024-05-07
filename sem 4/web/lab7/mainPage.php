<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="UTF-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <title>CoolNews</title>
  </head>
  <body>
    <?php
phpinfo();
?>
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
            background-color: pink;
            text-align: center;
          }
        </style>
        <a href="mainPage.phps"><b>MAIN PAGE</b></a>
        <a href="loginPage.php">LOGIN</a>
        <a href="seeAllNews.php">SEE ALL</a>
        <a href="updateNews.php">UPDATE</a>
        <a href="addNews.php">ADD</a>
      </div>
    </div>
    <div class="latestNews"></div>
  </body>
</html>
