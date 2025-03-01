<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Update News</title>
  <?php
  session_start(); 
  if (!isset($_SESSION['username'])) { 
    header('Location: loginPage.php'); 
    exit();
  }
  ?>
  <script>
    function getQueryParameter(param) {
      const params = new URLSearchParams(window.location.search);
      return params.get(param);
    }

    function fetchNewsById(newsId) {
      const xhr = new XMLHttpRequest();
      xhr.open('GET', `getNewsById.php?id=${newsId}`, true);
      xhr.onload = function() {
        if (xhr.status >= 200 && xhr.status < 300) {
          const news = JSON.parse(xhr.responseText);
          console.log('Fetched news:', news);
          populateForm(news); 
        } else {
          console.error('Error fetching news', xhr.status);
        }
      };
      xhr.send();
    }

    function populateForm(news) {
  if (news && news.length > 0) {
    const newsItem = news[0]; 
    console.log('Populating with:', newsItem); 

    document.getElementById('title').value = newsItem.title;
    document.getElementById('producer').value = newsItem.producer;
    document.getElementById('category').value = newsItem.category;
    document.getElementById('date').value = newsItem.date;
    document.getElementById('text').value = newsItem.text;
  } else {
    console.error('News data not found');
  }
}

    function submitUpdate() {
      const newsId = getQueryParameter('id');
      const title = document.getElementById('title').value;
      const producer = document.getElementById('producer').value;
      const category = document.getElementById('category').value;
      const date = document.getElementById('date').value;
      const text = document.getElementById('text').value;

      const xhr = new XMLHttpRequest();
      xhr.open('POST', `updateLogic.php?id=${newsId}`, true);
      xhr.setRequestHeader('Content-Type', 'application/x-www-form-urlencoded');

      const data = `title=${encodeURIComponent(title)}&producer=${encodeURIComponent(producer)}&category=${encodeURIComponent(category)}&date=${encodeURIComponent(date)}&text=${encodeURIComponent(text)}`;

      xhr.send(data);
    }

    window.onload = function() {
      const newsId = getQueryParameter('id');
      if (newsId) {
        fetchNewsById(newsId); 
      } else {
        console.error('No ID found in URL');
      }
    };
  </script>
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
    .modifyDetails {
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
</head>
<body>
  <div class="header">
    <h2>It's gonna be <b>LEGEN -</b> this is the news page homework <b>- DARY</b></h2>
    <div class="navBar">
      <a href="loginPage.php">LOGIN</a>
      <a href="seeAllNews.php">SEE ALL</a>
      <a href="addNews.php">ADD</a>
    </div>
  </div>

  <div class="updateForm">
    <h4>Please input the information about the news you want to update:</h4>
    <div class="modifyDetails">
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
  </div>
</body>
</html>
