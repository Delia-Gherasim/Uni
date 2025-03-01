<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8" />
  <meta name="viewport" content="width=device-width, initial-scale=1.0" />
  <title>AllNews</title>
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
      <a href="loginPage.php">LOGIN</a>
      <a href="seeAllNews.php"><b>SEE ALL</b></a>
      <a href="addNews.php">ADD</a>
    </div>
  </div>

  <div class="filters">
    <div class="categoryFilter">
      <label for="dropDownCategory">Category:</label>
      <select id="dropDownCategory" onchange="updateFilters()">
        <option value="">All</option> 
        <option value="tragedy">Tragedy</option>
        <option value="health">Health</option>
        <option value="society">Society</option>
      </select>
    </div>
    <div class="datesFilter">
      <div class="date">
        <label for="start">Start date:</label>
        <input type="date" id="start" onchange="updateFilters()" />
      </div>
      <div class="date">
        <label for="end">End date:</label>
        <input type="date" id="end" onchange="updateFilters()" />
      </div>
    </div>
  </div>
<style>
    .filters {
      display: flex;
      justify-content: space-evenly;
      text-align: center;
      margin-top: 20px;
      margin-bottom: 20px;
    }

    .datesFilter {
      display: flex;
      justify-content: space-around;
    }
    .date {
      margin-left: 10px;
      margin-right: 10px;
    }

    .article {
      border-style: solid;
      border-color: gray;
      border-radius: 20px;
      width: 80%;
      height: fit-content;
      margin-bottom: 20px;
    }
    .allNews {
display: flex;
flex-direction: column;
align-items: center;
margin-top: 20px;
}

  </style>
  <div class="allNews"></div>

  <script>
    function fetchNews(queryParams = '') {
      var xhr = new XMLHttpRequest();
      xhr.open('GET', 'seeAll.php?' + queryParams, true); 
      xhr.onload = function() {
        if (xhr.status >= 200 && xhr.status < 300) {
          var data = JSON.parse(xhr.responseText);
          renderNews(data); 
        } else {
          console.error('Error fetching news', xhr.status);
        }
      };
      xhr.send();
    }

    function updateFilters() {
      var selectedCategory = document.getElementById('dropDownCategory').value;
      var startDate = document.getElementById('start').value;
      var endDate = document.getElementById('end').value;

      var queryParams = [];

      if (selectedCategory && selectedCategory !== '') {
        queryParams.push('category=' + encodeURIComponent(selectedCategory));
      }

      if (startDate && endDate) {
        queryParams.push('startDate=' + encodeURIComponent(startDate));
        queryParams.push('endDate=' + encodeURIComponent(endDate));
      }

      fetchNews(queryParams.join('&'));
    }

  function renderNews(data) {
    var allNewsDiv = document.querySelector('.allNews');
    allNewsDiv.innerHTML = ''; 
    
    data.forEach(function(news) {
      var articleDiv = document.createElement('div');
      articleDiv.classList.add('article');

      var titleHeading = document.createElement('h3');
      titleHeading.textContent = news.title;

      var updateButton = document.createElement('button');
      updateButton.textContent = 'Update';
      updateButton.onclick = function() {
        window.location.href = 'updateNews.php?id=' + news.id;
      };

      var detailsDiv = document.createElement('div'); 
      detailsDiv.classList.add('details'); 

      var authorDiv = document.createElement('div');
      authorDiv.textContent = 'Author: ' + news.producer;

      var dateDiv = document.createElement('div');
      dateDiv.textContent = 'Date: ' + news.date;

      var textParagraph = document.createElement('p');
      textParagraph.textContent = news.text;

      detailsDiv.appendChild(authorDiv);
      detailsDiv.appendChild(dateDiv);

      articleDiv.appendChild(titleHeading);
      articleDiv.appendChild(updateButton);
      articleDiv.appendChild(detailsDiv);
      articleDiv.appendChild(textParagraph);

      allNewsDiv.appendChild(articleDiv); 
    });
  }

    window.onload = function() {
      fetchNews();
    };
  </script>
</body>
</html>