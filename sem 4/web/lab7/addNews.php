<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="UTF-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <title>Update</title>
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
        <a href="loginPage.php">LOG IN</a>
        <a href="seeAllNews.php">SEE ALL</a>
        <a href="updateNews.php">UPDATE</a>
        <a href="addNews.php"><b>ADD</b></a>
      </div>
    </div>
    <div class="addForm">
      <h4>Please input the information about the news you want to add:</h4>
      <div class="input">
        <label>Title of the article: </label>
        <input type="text" /><br /><br />
      </div>
      <div class="input">
        <lable>Producer: </lable>
        <input type="text" /><br /><br />
      </div>
      <div class="input">
        <lable>Category: </lable>
        <input type="text" /><br /><br />
      </div>
      <div class="input">
        <lable>Date: </lable>
        <input type="date" /><br /><br />
      </div>
      <div class="input">
        <label>Text: </label>
        <input type="text" /><br /><br />
      </div>

      <input type="button" value="Submit" />
    </div>

    <style>
      .addForm {
        border-color: black;
        border-radius: 10px;
        border-style: solid;
        margin-left: auto; /* Align to the center */
        margin-right: auto; /* Align to the center */
        width: 60%; /* Set width to ensure it doesn't span the whole page */
        margin-top: 40px;
        text-align: center;
      }

      .input {
        display: flex;
        align-items: center;
        justify-content: center; /* Align text and input in the center */
      }
    </style>
  </body>
</html>
