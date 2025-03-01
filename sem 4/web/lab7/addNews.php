<!DOCTYPE html>
<html lang="en">
  <?php
  session_start(); 
  if (!isset($_SESSION['username'])) { 
      header('Location: loginPage.php'); 
      exit();
  }
  ?>
  <head>
    <meta charset="UTF-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <title>Update</title>
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
        <a href="loginPage.php">LOG IN</a>
        <a href="seeAllNews.php">SEE ALL</a>
        <!-- <a href="updateNews.php">UPDATE</a> -->
        <a href="addNews.php"><b>ADD</b></a>
      </div>
    </div>
    <div class="addForm">
    <h4>Please input the information about the news you want to add:</h4>
    <div class="input">
        <label>Id: </label>
        <input type="text" id="id" />
        <br /><br />
      </div>
     <div class="input">
        <label>Title of the article: </label>
        <input type="text" id="title" />
        <br /><br />
      </div>
      <div class="input">
        <label>Producer: </label>
        <input type="text" id="producer" />
        <br /><br />
      </div>
      <div class="input">
        <label>Category: </label>
        <input type="text" id="category" />
        <br /><br />
      </div>
      <div class="input">
        <label>Date: </label>
        <input type="date" id="date" />
        <br /><br />
      </div>
      <div class="input">
        <label>Text: </label>
        <input type="text" id="text" />
        <br /><br />
      </div>

      <input type="button" value="Submit" onclick="submitUpdate()" />
    </div>

    <style>
      .addForm {
        border-color: black;
        border-radius: 10px;
        border-style: solid;
        margin-left: auto;
        margin-right: auto; 
        width: 60%;
        margin-top: 40px;
        text-align: center;
      }

      .input {
        display: flex;
        align-items: center;
        justify-content: center; 
      }
    </style>
    <script>
       function submitUpdate() {
        const id = document.getElementById('id').value;
        const title = document.getElementById('title').value;
        const producer = document.getElementById('producer').value;
        const category = document.getElementById('category').value;
        const date = document.getElementById('date').value;
        const text = document.getElementById('text').value;

        const xhr = new XMLHttpRequest();
        xhr.open('POST', `addLogic.php?`, true);
        xhr.setRequestHeader('Content-Type', 'application/x-www-form-urlencoded');

        const data = `id=${encodeURIComponent(id)}&title=${encodeURIComponent(title)}&producer=${encodeURIComponent(producer)}&category=${encodeURIComponent(category)}&date=${encodeURIComponent(date)}&text=${encodeURIComponent(text)}`;

        xhr.send(data);
      }
    </script>
  </body>
</html>
